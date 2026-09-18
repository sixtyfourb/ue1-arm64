/*=============================================================================
	UnGoldNative.cpp: Natives Unreal 226 declares that UT99 436 does not.

	All three belong to Engine.TimeDemo, which writes its per-cycle results to
	a text file. They bind by symbol name rather than by native index, so each
	has to exist or loading Engine.u aborts.
=============================================================================*/

#include "EnginePrivate.h"

IMPLEMENT_CLASS(ATimeDemo);

//
// Open the timedemo log. Script keeps the handle in `var int FileAr`, so the
// C++ side owns the FArchive and script only ever tests it against zero.
//
void ATimeDemo::execOpenFile( FFrame& Stack, RESULT_DECL )
{
	guard(ATimeDemo::execOpenFile);
	P_FINISH;

	if( FileAr )
	{
		delete FileAr;
		FileAr = NULL;
	}
	FileAr = GFileManager->CreateFileWriter( TEXT("TimeDemo.csv"), FILEWRITE_Append );

	unguard;
}

void ATimeDemo::execWriteToFile( FFrame& Stack, RESULT_DECL )
{
	guard(ATimeDemo::execWriteToFile);
	P_GET_STR(Text);
	P_FINISH;

	if( FileAr )
	{
		// FArchive is a byte sink, not an output device: write the line out as
		// ANSI, which is what every other tool reading a timedemo csv expects.
		FString Line = Text + TEXT("\r\n");
		TArray<ANSICHAR> Ansi( Line.Len() );
		for( INT i=0; i<Line.Len(); i++ )
			Ansi(i) = ToAnsi( (*Line)[i] );
		if( Ansi.Num() )
			FileAr->Serialize( &Ansi(0), Ansi.Num() );
	}

	unguard;
}

void ATimeDemo::execCloseFile( FFrame& Stack, RESULT_DECL )
{
	guard(ATimeDemo::execCloseFile);
	P_FINISH;

	if( FileAr )
	{
		delete FileAr;
		FileAr = NULL;
	}

	unguard;
}

IMPLEMENT_FUNCTION( ATimeDemo, -1, execOpenFile );
IMPLEMENT_FUNCTION( ATimeDemo, -1, execWriteToFile );
IMPLEMENT_FUNCTION( ATimeDemo, -1, execCloseFile );

/*-----------------------------------------------------------------------------
	The End.
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
	UConsole layout.

	Engine.Console is hand-written in UnCon.h rather than generated into
	EngineClasses.h, so scripts/ue1-layout.py cannot rewrite it - its parser
	stops at DECLARE_CLASS, which a hand-written header puts first. The offsets
	it computes are pinned here instead, so the block cannot drift unnoticed.
-----------------------------------------------------------------------------*/

template< int Actual, int Expected > struct ConsoleOffset;
template< int Same > struct ConsoleOffset<Same,Same> { typedef int Matches; };

#define checkConsoleOffset(member,off) \
	static_assert( __builtin_offsetof(UConsole,member)==off, \
		"UConsole::" #member " is not where Engine.Console puts it" ); \
	(void)sizeof( ConsoleOffset< (int)__builtin_offsetof(UConsole,member), off >::Matches )

static void UConsoleLayoutChecks()
{
	checkConsoleOffset( Viewport, 72 );
	checkConsoleOffset( HistoryTop, 80 );
	checkConsoleOffset( HistoryBot, 84 );
	checkConsoleOffset( HistoryCur, 88 );
	checkConsoleOffset( TypedStr, 92 );
	checkConsoleOffset( History, 108 );
	checkConsoleOffset( Scrollback, 364 );
	checkConsoleOffset( numLines, 368 );
	checkConsoleOffset( TopLine, 372 );
	checkConsoleOffset( TextLines, 376 );
	checkConsoleOffset( MsgTime, 380 );
	checkConsoleOffset( MsgText, 384 );
	checkConsoleOffset( MsgType, 1408 );
	checkConsoleOffset( MsgPlayer, 1664 );
	checkConsoleOffset( MsgTick, 2176 );
	checkConsoleOffset( BorderSize, 2432 );
	checkConsoleOffset( ConsoleLines, 2436 );
	checkConsoleOffset( BorderLines, 2440 );
	checkConsoleOffset( BorderPixels, 2444 );
	checkConsoleOffset( ConsolePos, 2448 );
	checkConsoleOffset( ConsoleDest, 2452 );
	checkConsoleOffset( FrameX, 2456 );
	checkConsoleOffset( FrameY, 2460 );
	checkConsoleOffset( ConBackground, 2464 );
	checkConsoleOffset( Border, 2472 );
	checkConsoleOffset( TimeDemo, 2484 );
	checkConsoleOffset( LoadingMessage, 2496 );
	checkConsoleOffset( SavingMessage, 2512 );
	checkConsoleOffset( ConnectingMessage, 2528 );
	checkConsoleOffset( PausedMessage, 2544 );
	checkConsoleOffset( PrecachingMessage, 2560 );
	static_assert( sizeof(UConsole)==2576, "UConsole is not Engine.Console's size" );
}
