/*=============================================================================
	UnCanvas.cpp: Unreal canvas rendering.
	Copyright 1997-1999 Epic Games, Inc. All Rights Reserved.

Revision history:
	* Created by Tim Sweeney
	* 31/3/99 Updated revision history - Jack Porter
=============================================================================*/

#include "EnginePrivate.h"
#include "UnRender.h"

/*-----------------------------------------------------------------------------
	UCanvas scaled sprites.
-----------------------------------------------------------------------------*/

//
// Draw arbitrary aligned rectangle.
//
void UCanvas::DrawTile
(
	UTexture*		Texture,
	FLOAT			X,
	FLOAT			Y,
	FLOAT			XL,
	FLOAT			YL,
	FLOAT			U,
	FLOAT			V,
	FLOAT			UL,
	FLOAT			VL,
	FSpanBuffer*	SpanBuffer,
	FLOAT			Z,
	FPlane			Color,
	FPlane			Fog,
	DWORD			PolyFlags
)
{
	guard(UCanvas::DrawTile);
	check(Texture);

	// Compute clipping region.
	FLOAT ClipY0 = /*SpanBuffer ? SpanBuffer->StartY :*/ 0;
	FLOAT ClipY1 = /*SpanBuffer ? SpanBuffer->EndY   :*/ Frame->FY;

	// Reject.
	if( XL<=0.f || YL<=0.f || X+XL<=0.f || Y+YL<=ClipY0 || X>=Frame->FX || Y>=ClipY1 )
		return;

	// Clip.
	if( X<0.f )
		{FLOAT C=X*UL/XL; U-=C; UL+=C; XL+=X; X=0.f;}
	if( Y<0.f )
		{FLOAT C=Y*VL/YL; V-=C; VL+=C; YL+=Y; Y=0.f;}
	if( XL>Frame->FX-X )
		{UL+=(Frame->FX-X-XL)*UL/XL; XL=Frame->FX-X;}
	if( YL>Frame->FY-Y )
		{VL+=(Frame->FY-Y-YL)*VL/YL; YL=Frame->FY-Y;}

	// Draw it.
	FTextureInfo Info;
	if( !GIsEditor )
		Texture = Texture->Get( Viewport->CurrentTime );
	Texture->Lock( Info, Viewport->CurrentTime, -1, Viewport->RenDev );
	FLOAT UF = Info.UScale * Info.USize / Texture->USize; U *= UF; UL *= UF;
	FLOAT VF = Info.VScale * Info.VSize / Texture->VSize; V *= VF; VL *= VF;
	Viewport->RenDev->DrawTile( Frame, Info, X, Y, XL, YL, U, V, UL, VL, SpanBuffer, Z, Color, Fog, PolyFlags | (Texture->PolyFlags&PF_Masked) );
	Texture->Unlock( Info );

	unguard;
}

//
// Draw titling pattern.
//
void UCanvas::DrawPattern
(
	UTexture*		Texture,
	FLOAT			X,
	FLOAT			Y,
	FLOAT			XL,
	FLOAT			YL,
	FLOAT			Scale,
	FLOAT			OrgX,
	FLOAT			OrgY,
	FSpanBuffer*	SpanBuffer,
	FLOAT			Z,
	FPlane			Color,
	FPlane			Fog,
	DWORD			PolyFlags
)
{
	guard(UCanvas::DrawPattern);
	DrawTile( Texture, X, Y, XL, YL, (X-OrgX)*Scale + Texture->USize, (Y-OrgY)*Scale + Texture->VSize, XL*Scale, YL*Scale, SpanBuffer, Z, Color, Fog, PolyFlags );
	unguard;
}

//
// Draw a scaled sprite.  Takes care of clipping.
// XSize and YSize are in pixels.
//
void UCanvas::DrawIcon
(
	UTexture*			Texture,
	FLOAT				ScreenX, 
	FLOAT				ScreenY, 
	FLOAT				XSize, 
	FLOAT				YSize, 
	FSpanBuffer*		SpanBuffer,
	FLOAT				Z,
	FPlane				Color,
	FPlane				Fog,
	DWORD				PolyFlags
)
{
	guard(UCanvas::DrawIcon);
	DrawTile( Texture, ScreenX, ScreenY, XSize, YSize, 0, 0, Texture->USize, Texture->VSize, SpanBuffer, Z, Color, Fog, PolyFlags );
	unguard;
}

/*-----------------------------------------------------------------------------
	Clip window.
-----------------------------------------------------------------------------*/

void UCanvas::SetClip( INT X, INT Y, INT XL, INT YL )
{
	guard(UCanvas::SetClip);

	CurX  = 0;
	CurY  = 0;
	OrgX  = X;
	OrgY  = Y;
	ClipX = XL;
	ClipY = YL;

	unguard;
}

/*-----------------------------------------------------------------------------
	UCanvas basic text functions.
-----------------------------------------------------------------------------*/

//
// Draw a character.
//
static inline void DrawChar
(
	DWORD			Flags,
	UCanvas*		Canvas,
	FTextureInfo&	Info,
	INT				X,
	INT				Y,
	INT				XL,
	INT				YL,
	INT				U, 
	INT				V, 
	INT				UL, 
	INT				VL, 
	FPlane			Color
)
{
	guardSlow(DrawChar);

	// Reject.
	FSceneNode* Frame=Canvas->Frame;
	if( !(Flags & PF_Invisible) && X+XL>0 && Y+YL>0 && X<Frame->X && Y<Frame->Y && XL>0 && YL>0 )
	{
		// Clip.
		if( X<0 )
			{INT C=X*UL/XL; U-=C; UL+=C; XL+=X; X=0;}
		if( Y<0 )
			{INT C=Y*VL/YL; V-=C; VL+=C; YL+=Y; Y=0;}
		if( XL>Frame->X-X )
			{UL+=(Frame->X-X-XL)*UL/XL; XL=Frame->X-X;}
		if( YL>Frame->Y-Y )
			{VL+=(Frame->Y-Y-YL)*VL/YL; YL=Frame->Y-Y;}

		// Draw. The destination size is XL,YL - upstream passed UL,VL here,
		// which pinned every glyph to one texel per pixel and left the XL,YL
		// parameters dead. They are honoured now so text can be scaled; a caller
		// wanting the old behaviour simply passes XL==UL.
		Frame->Viewport->RenDev->DrawTile( Frame, Info, X, Y, XL, YL, U, V, UL, VL, NULL, Canvas->Z, Color, FPlane(0,0,0,0), Flags );
	}
	unguardSlow;
}

//
// Draw a string of characters.
// - returns pixels drawn
//
//
// Scale factor for canvas text. The fonts are 1998 bitmaps blitted one texel
// to one pixel, which on a 1080p handheld leaves kill messages a couple of
// millimetres tall. Which font a message uses is chosen by name in script
// compiled into the retail packages, so it cannot be changed from outside;
// the size can only be changed here, at the blit. The source stays the glyph
// and the destination is scaled, with the advance and the reported text
// extents scaled to match so wrapping and centring still line up.
//
// Which text the scale reaches is decided by the font, not by who is drawing.
// UWindow draws every menu string with Root.Fonts[], loaded from UWindowFonts,
// and picks Tahoma10 or Tahoma20 out of it according to GUIScale - so menu text
// already sizes itself, and scaling it again makes strings overflow windows
// UWindow has no way to grow, which is a menu squished together rather than a
// larger one. Every other font is named in compiled script with no setting
// behind it, and is what this scale exists for.
//
// Keying on the font is what makes Unreal work. Its UPakConsole draws the
// in-game messages itself, in the same PostRender that puts up the menus, so
// nothing scoped to the console can tell the two apart; UT99 hands its messages
// to the HUD instead, which is the only reason a console-wide flag looked right.
static UBOOL IsMenuFont( UFont* Font )
{
	if( !Font )
		return 0;
	UObject* Package = Font;
	while( Package->GetOuter() )
		Package = Package->GetOuter();
	return appStricmp( Package->GetName(), TEXT("UWindowFonts") )==0;
}

static inline FLOAT GetFontScale( UCanvas* Canvas, UFont* Font )
{
	if( IsMenuFont( Font ) )
		return 1.f;
	FLOAT Scale = 1.f;
	if( Canvas && Canvas->Viewport )
		Scale = Canvas->Viewport->GetOuterUClient()->FontScale;
	// Absent from the ini reads back as 0, which means "unset", not "invisible".
	return Scale > 0.f ? Clamp( Scale, 0.25f, 8.f ) : 1.f;
}

static inline INT DrawString
(
	DWORD			Flags, 
	UCanvas*		Canvas, 
	UFont*			Font, 
	INT				DrawX, 
	INT				DrawY,
	const TCHAR*	Text, 
	FPlane			Color, 
	UBOOL			bClip, 
	UBOOL			bHandleApersand,
	FLOAT			Scale
)
{
	guardSlow(DrawString);

	// Font texture pages.
	FTextureInfo Infos[5];
	Infos[0].Texture=Infos[1].Texture=Infos[2].Texture=Infos[3].Texture=Infos[4].Texture=NULL;

	// Draw all characters in string.
	INT LineX = 0;
	INT bDrawUnderline = 0;
	INT UnderlineWidth = 0;
	for( INT i=0; Text[i]; i++ )
	{
		INT bUnderlineNext = 0;
		INT Ch = (TCHARU)Text[i];

		// Handle ampersand underlining.
		if( bHandleApersand )
		{
			if( bDrawUnderline )
				Ch = (TCHARU)('_');
			if( Text[i]=='&' )
			{
				if( !Text[i+1] )
					break; 
				if( Text[i+1]!='&' )
				{
					bUnderlineNext = 1;
					Ch = (TCHARU)Text[i+1];
				}
			}
		}

		// Process character if it's valid.
		INT NewPage = Ch / Font->CharactersPerPage;
		UTexture* Tex;
		if( NewPage<Font->Pages.Num() && (Tex=Font->Pages(NewPage).Texture)!=NULL )
		{
			INT        Index    = Ch - NewPage*Font->CharactersPerPage;
			FFontPage& PageInfo = Font->Pages(NewPage);
			if( Index<PageInfo.Characters.Num() )
			{
				// Get proper font page.
				FTextureInfo& Info = Infos[Min<INT>( NewPage, 4 )];
				if( Info.Texture!=Tex )
				{
					if( Info.Texture )
						Info.Texture->Unlock( Info );
					Tex->Lock( Info, Canvas->Viewport->CurrentTime, 0, Canvas->Viewport->RenDev );
				}
				FFontCharacter& Char = PageInfo.Characters(Index);

				// Compute character width.
				INT CharWidth;
				if( bDrawUnderline )
					CharWidth = Min(UnderlineWidth, Char.USize);
				else
					CharWidth = Char.USize;

				// Prepare for clipping.
				INT X      = LineX + DrawX;
				INT Y      = DrawY;
				INT CU     = Char.StartU;
				INT CV     = Char.StartV;
				INT CUSize = CharWidth;
				INT CVSize = Char.VSize;
				// Destination extent; equal to the source when Scale is 1, so the
				// unscaled path stays exactly what it was.
				INT DUSize = appRound( CUSize * Scale );
				INT DVSize = appRound( CVSize * Scale );

				// Draw if it passes clip test.
				if
				(	(!bClip)
				||	(X+DUSize>0 && X<=Canvas->ClipX && Y+DVSize>0 && Y<=Canvas->ClipY) )
				{
					if( bClip )
					{
						// Clip on screen and take the matching bite out of the glyph,
						// so a part-clipped character is cropped, not squashed.
						if( X        < 0             ) { INT C=-X;                            CU+=appRound(C/Scale); CUSize-=appRound(C/Scale); DUSize-=C; X=0; }
						if( Y        < 0             ) { INT C=-Y;                            CV+=appRound(C/Scale); CVSize-=appRound(C/Scale); DVSize-=C; Y=0; }
						if( X+DUSize > Canvas->ClipX ) { INT C=(INT)(X+DUSize-Canvas->ClipX); DUSize-=C;             CUSize-=appRound(C/Scale); }
						if( Y+DVSize > Canvas->ClipY ) { INT C=(INT)(Y+DVSize-Canvas->ClipY); DVSize-=C;             CVSize-=appRound(C/Scale); }
					}
					DrawChar( Flags, Canvas, Info, (INT) (Canvas->OrgX+X), (INT) (Canvas->OrgY+Y), DUSize, DVSize, CU, CV, CUSize, CVSize, Color );
				}

				// Update underline status.
				if( bDrawUnderline )
					CharWidth = UnderlineWidth;

				if( !bUnderlineNext )
					LineX += (INT) (appRound( CharWidth * Scale ) + Canvas->SpaceX);
				else
					UnderlineWidth = Char.USize;

				bDrawUnderline = bUnderlineNext;
			}
		}
	}

	// Unlock font pages.
	for( INT i=0; i<5; i++ )
		if( Infos[i].Texture )
			Infos[i].Texture->Unlock( Infos[i] );

	return LineX;
	unguardSlow;
}

//
// Get a character's dimensions.
//
static inline void GetCharSize( UFont* Font, TCHAR InCh, INT& Width, INT& Height, FLOAT Scale )
{
	guardSlow(GetCharSize);
	Width = 0;
	Height = 0;
	INT Ch    = (TCHARU)InCh;
	INT Page  = Ch / Font->CharactersPerPage;
	INT Index = Ch - Page * Font->CharactersPerPage;
	if( Page<Font->Pages.Num() && Index<Font->Pages(Page).Characters.Num() )
	{
		FFontCharacter& Char = Font->Pages(Page).Characters(Index);
		Width = appRound( Char.USize * Scale );
		Height = appRound( Char.VSize * Scale );
	}
	unguardSlow;
}

//
// Compute size and optionally print text with word wrap.
//!!For the next generation, redesign to ignore CurX,CurY.
//
void VARARGS UCanvas::WrappedPrint( ERenderStyle Style, INT& XL, INT& YL, UFont* Font, UBOOL Center, const TCHAR* Text )
{
	guard(UCanvas::WrappedPrint);
	if( ClipX<0 || ClipY<0 )
		return;
	if( (Font==LargeFont || Font==BigFont) && appStricmp(UObject::GetLanguage(),TEXT("INT")) )
		Font = MedFont;//BigFont;!!
	check(Font);
	const FLOAT TextScale = GetFontScale( this, Font );
	FPlane DrawColor = Color.Plane();

	// Generate flags.
	DWORD PolyFlags
	=	(PF_NoSmooth | PF_Masked | PF_RenderHint)
	|(	(Style==STY_None       ) ? PF_Invisible
	:	(Style==STY_Translucent) ? PF_Translucent
	:	(Style==STY_Modulated  ) ? PF_Modulated
	:	                           0);

	// Process each word until the current line overflows.
	XL = YL = 0;
	do
	{
		INT iCleanWordEnd=0, iTestWord;
		INT TestXL=(INT)CurX, CleanXL=0;
		INT TestYL=0,    CleanYL=0;
		UBOOL GotWord=0;
		for( iTestWord=0; Text[iTestWord]!=0 && Text[iTestWord]!='\n'; )
		{
			INT ChW, ChH;
			GetCharSize(Font, Text[iTestWord], ChW, ChH, TextScale);
			TestXL              += (INT) (ChW + SpaceX);
			TestYL               = Max( TestYL, ChH + (INT)SpaceY );
			if( TestXL>ClipX )
				break;
			iTestWord++;
			UBOOL WordBreak = Text[iTestWord]==' ' || Text[iTestWord]=='\n' || Text[iTestWord]==0;
			if( WordBreak || !GotWord )
			{
				iCleanWordEnd = iTestWord;
				CleanXL       = TestXL;
				CleanYL       = TestYL;
				GotWord       = GotWord || WordBreak;
			}
		}
		if( iCleanWordEnd==0 )
			break;

		// Sucessfully split this line, now draw it.
		if( Style!=STY_None && OrgY+CurY<Frame->Y && OrgY+CurY+CleanYL>0 )
		{
			FString TextLine(Text);
			INT LineX = Center ? (INT) (CurX+(ClipX-CleanXL)/2) : (INT) (CurX);
			LineX += DrawString( PolyFlags, this, Font, LineX, (INT) CurY, *(TextLine.Left(iCleanWordEnd)), DrawColor, 0, 0, TextScale );
			CurX = LineX;
		}

		// Update position.
		CurX  = 0;
		CurY += CleanYL;
		YL   += CleanYL;
		XL    = Max(XL,CleanXL);
		Text += iCleanWordEnd;

		// Skip whitespace after word wrap.
		while( *Text==' ' )
			Text++;
	}
	while( *Text );

	unguardf(( TEXT("(%s)"), Text ));
}

/*-----------------------------------------------------------------------------
	UCanvas derived text functions.
-----------------------------------------------------------------------------*/

//
// Calculate the size of a string built from a font, word wrapped
// to a specified region.
//
void UCanvas::WrappedStrLenf( UFont* Font, INT& XL, INT& YL, const TCHAR* Fmt, ... )
{
	TCHAR Text[4096];
	GET_VARARGS( Text, ARRAY_COUNT(Text), Fmt );

	guard(UCanvas::WrappedStrLenf);
	WrappedPrint( STY_None, XL, YL, Font, 0, Text );
	unguard;
}

//
// Wrapped printf.
//
void VARARGS UCanvas::WrappedPrintf( UFont* Font, UBOOL Center, const TCHAR* Fmt, ... )
{
	TCHAR Text[4096];
	GET_VARARGS( Text, ARRAY_COUNT(Text), Fmt );

	guard(UCanvas::WrappedPrintf);
	INT XL=0, YL=0;
	WrappedPrint( STY_Normal, XL, YL, Font, Center, Text );
	unguard;
}

/*-----------------------------------------------------------------------------
	UCanvas object functions.
-----------------------------------------------------------------------------*/

void UCanvas::Init( UViewport* InViewport )
{
	guard(UCanvas::UCanvas);
	Viewport = InViewport;
	unguard;
}
void UCanvas::Update( FSceneNode* InFrame )
{
	guard(UCanvas::Update);
	// Call UnrealScript to reset.
	eventReset();

	// Copy size parameters from viewport.
	Frame = InFrame;
	ClipX = Frame->X;
	X = (INT) ClipX;
	ClipY = Frame->Y;
	Y = (INT) ClipY;

	unguard;
}

/*-----------------------------------------------------------------------------
	UCanvas natives.
-----------------------------------------------------------------------------*/

void UCanvas::execStrLen( FFrame& Stack, RESULT_DECL )
{
	guard(UCanvas::execStrLen);

	P_GET_STR(InText);
	P_GET_FLOAT_REF(XL);
	P_GET_FLOAT_REF(YL);
	P_FINISH;

	INT XLi, YLi;
	INT OldCurX, OldCurY;
	OldCurX = (INT) CurX;
	OldCurY = (INT) CurY;
	CurX = 0;
	CurY = 0;
	WrappedStrLenf( Font, XLi, YLi, TEXT("%s"), *InText );
	CurY = OldCurY;
	CurX = OldCurX;
	*XL = XLi;
	*YL = YLi;

	unguard;
}
IMPLEMENT_FUNCTION( UCanvas, 464, execStrLen );

void UCanvas::execDrawText( FFrame& Stack, RESULT_DECL )
{
	guard(UCanvas::execDrawText);
	P_GET_STR(InText);
	P_GET_UBOOL_OPTX(CR,1);
	P_FINISH;
	if( !Font )
	{
		Stack.Logf( TEXT("DrawText: No font") );
		return;
	}
	INT XL=0, YL=0;
	if( Style!=STY_None )
		WrappedPrint( (ERenderStyle)Style, XL, YL, Font, bCenter, *InText );
	CurX += XL;
	CurYL = Max(CurYL,(FLOAT)YL);
	if( CR )
	{
		CurX  = 0;
		CurY += CurYL;
		CurYL = 0;
	}

	unguardexec;
}
IMPLEMENT_FUNCTION( UCanvas, 465, execDrawText );

void UCanvas::execDrawTile( FFrame& Stack, RESULT_DECL )
{
	guard(UCanvas::execDrawTile);
	P_GET_OBJECT(UTexture,Tex);
	P_GET_FLOAT(XL);
	P_GET_FLOAT(YL);
	P_GET_FLOAT(U);
	P_GET_FLOAT(V);
	P_GET_FLOAT(UL);
	P_GET_FLOAT(VL);
	P_FINISH;
	if( !Tex )
	{
		Stack.Logf( TEXT("DrawTile: Missing Texture") );
		return;
	}
	if( Style!=STY_None ) DrawTile
	(
		Tex,
		OrgX+CurX,
		OrgY+CurY,
		XL,
		YL,
		U,
		V,
		UL,
		VL,
		NULL,
		Z,
		Color.Plane(),
		FPlane(0,0,0,0),
		PF_TwoSided | (Style==STY_Translucent ? PF_Translucent : Style==STY_Modulated ? PF_Modulated : 0) | (bNoSmooth ? PF_NoSmooth : 0)
	);
	CurX += XL + SpaceX;
	CurYL = Max(CurYL,YL);
	unguardexec;
}
IMPLEMENT_FUNCTION( UCanvas, 466, execDrawTile );

void UCanvas::execDrawActor( FFrame& Stack, RESULT_DECL )
{
	guard(UCanvas::execDrawActor);
	P_GET_OBJECT(AActor, Actor);
	P_GET_UBOOL(WireFrame);
	P_GET_UBOOL_OPTX(ClearZ, 0);
	P_FINISH;

	INT OldRendMap;
	OldRendMap = Viewport->Actor->RendMap;
	if( WireFrame )
		Viewport->Actor->RendMap = REN_Wire;
	Actor->bHidden = 0;
	if( ClearZ )
		Viewport->RenDev->ClearZ( Frame );
	Render->DrawActor( Frame, Actor );
	Actor->bHidden = 1;
	Viewport->Actor->RendMap = OldRendMap;

	unguardexec;
}
IMPLEMENT_FUNCTION( UCanvas, 467, execDrawActor );

void UCanvas::execDrawClippedActor( FFrame& Stack, RESULT_DECL )
{
	guard(UCanvas::execDrawClippedActor);
	P_GET_OBJECT(AActor, Actor);
	P_GET_UBOOL(WireFrame);
	P_GET_INT(X);
	P_GET_INT(Y);
	P_GET_INT(XB);
	P_GET_INT(YB);
	P_GET_UBOOL_OPTX(ClearZ, 0);
	P_FINISH;
	
	INT OldX, OldY, OldXB, OldYB;
	INT OldRendMap;

	OldX = Frame->X;
	OldY = Frame->Y;
	OldXB = Frame->XB;
	OldYB = Frame->YB;

	Frame->X = X;
	Frame->Y = Y;
	Frame->XB = XB;
	Frame->YB = YB;

	FVector V(0,0,0);
	FRotator R(0,0,0);

	Frame->ComputeRenderCoords( V, R );
	Frame->ComputeRenderSize();

	OldRendMap = Viewport->Actor->RendMap;
	if (WireFrame)
		Viewport->Actor->RendMap = REN_Wire;
	Actor->bHidden = 0;
	if (ClearZ)
		Viewport->RenDev->ClearZ(Frame);
	Render->DrawActor(Frame, Actor);
	Actor->bHidden = 1;
	Viewport->Actor->RendMap = OldRendMap;
	
	Frame->X = OldX;
	Frame->Y = OldY;
	Frame->XB = OldXB;
	Frame->YB = OldYB;
	Frame->ComputeRenderSize();

	unguardexec;
}
IMPLEMENT_FUNCTION( UCanvas, 471, execDrawClippedActor );

void UCanvas::execDrawTileClipped( FFrame& Stack, RESULT_DECL )
{
	guard(UCanvas::execDrawTileClipped);
	P_GET_OBJECT(UTexture,Tex);
	P_GET_FLOAT(XL);
	P_GET_FLOAT(YL);
	P_GET_FLOAT(U);
	P_GET_FLOAT(V);
	P_GET_FLOAT(UL);
	P_GET_FLOAT(VL);
	P_FINISH;
	if( !Tex )
	{
		Stack.Logf( TEXT("DrawTileClipped: Missing Texture") );
		return;
	}

	// Clip to ClipX and ClipY
	if( XL > 0 && YL > 0 )
	{		
		if( CurX<0 )
			{FLOAT C=CurX*UL/XL; U-=C; UL+=C; XL+=CurX; CurX=0;}
		if( CurY<0 )
			{FLOAT C=CurY*VL/YL; V-=C; VL+=C; YL+=CurY; CurY=0;}
		if( XL>ClipX-CurX )
			{UL+=(ClipX-CurX-XL)*UL/XL; XL=ClipX-CurX;}
		if( YL>ClipY-CurY )
			{VL+=(ClipY-CurY-YL)*VL/YL; YL=ClipY-CurY;}
	
		if( Style!=STY_None ) 
			DrawTile
			(
				Tex,
				OrgX+CurX,
				OrgY+CurY,
				XL,
				YL,
				U,
				V,
				UL,
				VL,
				NULL,
				Z,
				Color.Plane(),
				FPlane(0,0,0,0),
				PF_TwoSided | (/*Style==STY_Masked ? PF_Masked :*/ Style==STY_Translucent ? PF_Translucent : Style==STY_Modulated ? PF_Modulated : 0) | (bNoSmooth ? PF_NoSmooth : 0)
			);

		CurX += XL + SpaceX;
		CurYL = Max(CurYL,YL);
	}

	unguardexec;
}
IMPLEMENT_FUNCTION( UCanvas, 468, execDrawTileClipped );

void UCanvas::execDrawTextClipped( FFrame& Stack, RESULT_DECL )
{
	guard(UCanvas::execDrawTextClipped);
	P_GET_STR(InText);
	P_GET_UBOOL_OPTX(CheckHotKey, 0);
	P_FINISH;

	if( !Font )
	{
		Stack.Logf( TEXT("DrawTextClipped: No font") );
		return;
	}

	if( (Font==LargeFont || Font==BigFont) && appStricmp(UObject::GetLanguage(),TEXT("INT")) )
		Font = MedFont;//BigFont;//!!
	check(Font);

	// Generate flags.
	DWORD PolyFlags
	=	(PF_NoSmooth | PF_Masked | PF_RenderHint)
	|(	(Style==STY_None       ) ? PF_Invisible
	:	(Style==STY_Translucent) ? PF_Translucent
	:	(Style==STY_Modulated  ) ? PF_Modulated
	:	                           0);

	FPlane DrawColor = Color.Plane();
	DrawString( PolyFlags, this, Font, (INT) CurX, (INT) CurY, *InText, DrawColor, 1, CheckHotKey, GetFontScale(this, Font) );

	unguardexec;
}
IMPLEMENT_FUNCTION( UCanvas, 469, execDrawTextClipped );

void UCanvas::execTextSize( FFrame& Stack, RESULT_DECL )
{
	guard(UCanvas::execTextSize);
	P_GET_STR(InText);
	P_GET_FLOAT_REF(XL);
	P_GET_FLOAT_REF(YL);
	P_FINISH;

	if( !Font )
	{
		Stack.Logf( TEXT("TextSize: No font") );
		return;
	}

	INT XLi = 0;
	INT YLi = 0;
	INT W, H;

	for( INT i=0; (*InText)[i]; i++)
	{
		GetCharSize( Font, (*InText)[i], W, H, GetFontScale(this, Font) );
		
		XLi += W;
		if(YLi < H)
			YLi = H;	
	}
	
	*XL = XLi;
	*YL = YLi;

	unguardexec;
}
IMPLEMENT_FUNCTION( UCanvas, 470, execTextSize );

// execDrawPortal
// Written by Andrew Scheidecker
// Edited by Brandon Reinhart
void UCanvas::execDrawPortal( FFrame& Stack, RESULT_DECL )
{
	guard(UCanvas::execDrawPortal);
	P_GET_INT(X);
	P_GET_INT(Y);
	P_GET_INT(Width);
	P_GET_INT(Height);
	P_GET_OBJECT(AActor,CamActor);
	P_GET_VECTOR(CamLocation);
	P_GET_ROTATOR(CamRotation);
	P_GET_INT_OPTX(FOV, 90);
	P_GET_UBOOL_OPTX(ClearZ, 1);
	P_FINISH;

	FSceneNode* NewNode;
	FScreenBounds Bounds;

	FLOAT SavedFovAngle = Viewport->Actor->FovAngle;
	Viewport->Actor->FovAngle = FOV;
	NewNode = Render->CreateMasterFrame
	(
		Viewport,
		CamLocation,
		CamRotation,
		&Bounds
	);
	check( NewNode );

	NewNode->XB = X;
	NewNode->YB = Y;
	NewNode->X = Width;
	NewNode->Y = Height;
	NewNode->ComputeRenderSize();

	if( ClearZ )
		GRenderDevice->ClearZ( NewNode );

	Render->DrawWorld( NewNode );
	Render->FinishMasterFrame();

	Viewport->Actor->FovAngle = SavedFovAngle;

	unguardexec;
}
IMPLEMENT_FUNCTION( UCanvas, 480, execDrawPortal );

IMPLEMENT_CLASS(UCanvas);

/*-----------------------------------------------------------------------------
	The End.
-----------------------------------------------------------------------------*/
