/*=============================================================================
	UnGoldClasses.h: Native classes Unreal 226 has and UT99 436 does not.

	Generated headers come from EngineClasses.h; this holds the classes that
	only exist on the 226 side, so regenerating that file leaves them alone.
=============================================================================*/

#ifndef _UNGOLDCLASSES_H_
#define _UNGOLDCLASSES_H_

//
// The timedemo runner. Its member order is Engine.TimeDemo's property order -
// UStruct::Link decides the offsets and this only mirrors them - and FileAr is
// script's `var int FileAr` standing in for a pointer, which is why
// GetPlaceholderSize carries an entry for it.
//
class ENGINE_API ATimeDemo : public AInfo
{
public:
	FArchive*	FileAr GCC_PACK(4);
	FLOAT		TimePassed;
	FLOAT		TimeDilation;
	FLOAT		StartTime;
	FLOAT		LastSecTime;
	FLOAT		LastCycleTime;
	FLOAT		LastFrameTime;
	FLOAT		SquareSum;
	INT			FrameNum;
	INT			FrameLastSecond;
	INT			FrameLastCycle;
	INT			CycleCount;
	INT			QuitAfterCycles;
	FString		CycleMessage GCC_PACK(4);
	FString		CycleResult GCC_PACK(4);
	BITFIELD	bSaveToFile:1 GCC_PACK(4);
	BITFIELD	bFirstFrame:1;
	FLOAT		LastSec GCC_PACK(4);
	FLOAT		MinFPS;
	FLOAT		MaxFPS;
	// Every member C++ would align to 8 is packed to 4: script puts three of
	// them on 4-but-not-8 offsets, and leaving the class 8-aligned would pad
	// its size from script's 780 out to 784.
	class AInterpolationPoint*	OldPoint GCC_PACK(4);
	class AActor*				NewPoint GCC_PACK(4);	// TimeDemoInterpolationPoint, script-only.
	class UConsole*				Console GCC_PACK(4);

	DECLARE_CLASS(ATimeDemo,AInfo,0)
	NO_DEFAULT_CONSTRUCTOR(ATimeDemo)

	DECLARE_FUNCTION(execOpenFile);
	DECLARE_FUNCTION(execWriteToFile);
	DECLARE_FUNCTION(execCloseFile);
};

#endif
