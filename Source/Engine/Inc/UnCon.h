/*=============================================================================
	UnCon.h: UConsole game-specific definition
	Copyright 1997-1999 Epic Games, Inc. All Rights Reserved.

	Contains routines for: Messages, menus, status bar
=============================================================================*/

#pragma pack (push,4) /* Match script class mirror layout */

/*------------------------------------------------------------------------------
	UConsole definition.
------------------------------------------------------------------------------*/

//
// Viewport console.
//
struct UConsole_eventMessage_Parms
{
	class APlayerReplicationInfo* PRI;
	FString S;
	class AZoneInfo* PZone;
	FName N;
};
struct UConsole_eventConnectFailure_Parms
{
    FString FailCode;
    FString URL;
};
// Declared in UnGoldClasses.h, which comes after this header.
class ATimeDemo;

class ENGINE_API UConsole : public UObject, public FOutputDevice
{
	DECLARE_CLASS(UConsole,UObject,CLASS_Transient)

	// Constructor.
	UConsole();

	// UConsole interface.
	virtual void _Init( UViewport* Viewport );
	virtual void PreRender( FSceneNode* Frame );
	virtual void PostRender( FSceneNode* Frame );
	virtual void Serialize( const TCHAR* Data, EName MsgType );
	virtual UBOOL GetDrawWorld();

	// Natives.
	DECLARE_FUNCTION(execConsoleCommand);
	DECLARE_FUNCTION(execSaveTimeDemo);

	// Script events.
    void eventMessage(class APlayerReplicationInfo* PRI, const FString& S, class AZoneInfo* PZone, FName Name)
    {
		UConsole_eventMessage_Parms Parms;
		Parms.PRI=PRI;
        Parms.S=S;
		Parms.PZone=PZone;
		Parms.N=Name;
        ProcessEvent(FindFunctionChecked(NAME_Message),&Parms);
    }
    void eventTick(FLOAT DeltaTime)
    {
        struct {FLOAT DeltaTime; } Parms;
        Parms.DeltaTime=DeltaTime;
        ProcessEvent(FindFunctionChecked(ENGINE_Tick),&Parms);
    }
    void eventVideoChange()
    {
        ProcessEvent(FindFunctionChecked(NAME_VideoChange),NULL);
    }
    void eventPostRender(class UCanvas* C)
    {
        struct {class UCanvas* C; } Parms;
        Parms.C=C;
        ProcessEvent(FindFunctionChecked(ENGINE_PostRender),&Parms);
    }
    void eventPreRender(class UCanvas* C)
    {
        struct {class UCanvas* C; } Parms;
        Parms.C=C;
        ProcessEvent(FindFunctionChecked(ENGINE_PreRender),&Parms);
    }
    DWORD eventKeyType(BYTE Key)
    {
        struct {BYTE Key; DWORD ReturnValue; } Parms;
        Parms.Key=Key;
        Parms.ReturnValue=0;
        ProcessEvent(FindFunctionChecked(NAME_KeyType),&Parms);
        return Parms.ReturnValue;
    }
    DWORD eventKeyEvent(BYTE Key, BYTE Action, FLOAT Delta)
    {
        struct {BYTE Key; BYTE Action; FLOAT Delta; DWORD ReturnValue; } Parms;
        Parms.Key=Key;
        Parms.Action=Action;
        Parms.Delta=Delta;
        Parms.ReturnValue=0;
        ProcessEvent(FindFunctionChecked(NAME_KeyEvent),&Parms);
        return Parms.ReturnValue;
    }
    void eventNotifyLevelChange()
    {
        ProcessEvent(FindFunctionChecked(NAME_NotifyLevelChange),NULL);
    }
    void eventConnectFailure(const FString& FailCode, const FString& URL)
    {
        UConsole_eventConnectFailure_Parms Parms;
        Parms.FailCode=FailCode;
        Parms.URL=URL;
        ProcessEvent(FindFunctionChecked(NAME_ConnectFailure),&Parms);
    }
	UBOOL IsTimeDemo()
	{
		return bTimeDemo;
	}
private:
	// Constants.
	enum {MAX_BORDER     = 6};
	enum {MAX_LINES		 = 64};
	enum {MAX_HISTORY	 = 16};

	// Variables.
public:
	// Variables, in Engine.Console's property order - UStruct::Link decides
	// the offsets and this only mirrors them. 226 keeps no timedemo state
	// here: it spawns a TimeDemo actor and drives it from script
	// (TimeDemo.DoSetup/TickTimeDemo/PostRender/DoShutdown), which is why
	// there is a TimeDemo reference in the middle of the bools and none of
	// UT99's inline frame counters, fps strings or Font.
    class UViewport* Viewport;
    INT HistoryTop;
    INT HistoryBot;
    INT HistoryCur;
    FStringNoInit TypedStr GCC_PACK(4);
    FStringNoInit History[16];
    INT Scrollback;
    INT numLines;
    INT TopLine;
    INT TextLines;
    FLOAT MsgTime;
    FStringNoInit MsgText[64];
    FName MsgType[64];
    class APlayerReplicationInfo* MsgPlayer[64];
    FLOAT MsgTick[64];
    INT BorderSize;
    INT ConsoleLines;
    INT BorderLines;
    INT BorderPixels;
    FLOAT ConsolePos;
    FLOAT ConsoleDest;
    FLOAT FrameX;
    FLOAT FrameY;
    class UTexture* ConBackground;
    class UTexture* Border;
    BITFIELD bNoStuff:1 GCC_PACK(4);
    BITFIELD bTyping:1;
    BITFIELD bTimeDemo:1;
    class ATimeDemo* TimeDemo GCC_PACK(4);
    BITFIELD bNoDrawWorld:1 GCC_PACK(4);
    FStringNoInit LoadingMessage GCC_PACK(4);
    FStringNoInit SavingMessage;
    FStringNoInit ConnectingMessage;
    FStringNoInit PausedMessage;
    FStringNoInit PrecachingMessage;
};

/*------------------------------------------------------------------------------
	The End.
------------------------------------------------------------------------------*/


#pragma pack (pop)
