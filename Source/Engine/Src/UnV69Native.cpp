/*=============================================================================
	UnV69Native.cpp: Native functions that package version 69 (OldUnreal 469)
	added to Engine.

	Version 68 packages never declare these, so the engine only needs them to
	load retail GOTY data.  Each is bound by symbol name rather than by native
	index - UFunction::Bind looks up int<Class>exec<Name> in the package's
	shared object - so all four have to exist or the load aborts with
	"Can't find '...' in 'Engine.dll'".
=============================================================================*/

#include "EnginePrivate.h"

/*-----------------------------------------------------------------------------
	Download cache.
-----------------------------------------------------------------------------*/

//
// A downloaded package lands in GSys->CachePath as <GUID><CacheExt> (see
// UFileChannel::Destroy), which loses the name the package had on the server.
// 469's menu lets you browse that cache and promote an entry back to a real
// package, so it needs the mapping; UT keeps it in cache.ini beside the files,
// one "<GUID>=<Filename>" line per entry.
//
static FString CacheIni()
{
	return GSys->CachePath * TEXT("cache.ini");
}

//
// List the cache. Entries are the files actually present, so a cache.ini that
// has drifted from the directory cannot conjure an entry that is not there.
//
static void GetCacheEntries( TArray<FString>& Guids, TArray<FString>& Names )
{
	TArray<FString> Files = GFileManager->FindFiles( *(GSys->CachePath * TEXT("*") + GSys->CacheExt), 1, 0 );
	for( INT i=0; i<Files.Num(); i++ )
	{
		// Strip CacheExt to recover the GUID the file is named for.
		FString Guid = Files(i);
		if( Guid.Len() > GSys->CacheExt.Len() )
			Guid = Guid.Left( Guid.Len() - GSys->CacheExt.Len() );

		FString Name;
		if( !GConfig->GetString( TEXT("Cache"), *Guid, Name, *CacheIni() ) || Name==TEXT("") )
			Name = Files(i);

		new(Guids)FString(Guid);
		new(Names)FString(Name);
	}
}

void AActor::execGetCacheEntry( FFrame& Stack, RESULT_DECL )
{
	guard(AActor::execGetCacheEntry);

	P_GET_INT(Num);
	P_GET_STR_REF(Guid);
	P_GET_STR_REF(Filename);
	P_FINISH;

	TArray<FString> Guids, Names;
	GetCacheEntries( Guids, Names );

	if( Num>=0 && Num<Guids.Num() )
	{
		*Guid     = Guids(Num);
		*Filename = Names(Num);
		*(DWORD*)Result = 1;
	}
	else
	{
		*Guid     = TEXT("");
		*Filename = TEXT("");
		*(DWORD*)Result = 0;
	}

	unguard;
}

//
// Promote a cache entry to a real package: move <GUID><CacheExt> out of the
// cache and into whichever Paths directory takes files of that extension, then
// drop the cache.ini record. Fails rather than guessing when the entry has no
// name to give it, or when no configured path claims the extension.
//
void AActor::execMoveCacheEntry( FFrame& Stack, RESULT_DECL )
{
	guard(AActor::execMoveCacheEntry);

	P_GET_STR(Guid);
	P_GET_STR_OPTX(NewFilename,TEXT(""));
	P_FINISH;

	*(DWORD*)Result = 0;

	FString Src = GSys->CachePath * Guid + GSys->CacheExt;
	if( GFileManager->FileSize(*Src) >= 0 )
	{
		FString Name = NewFilename;
		if( Name==TEXT("") )
			GConfig->GetString( TEXT("Cache"), *Guid, Name, *CacheIni() );

		INT Dot = Name.InStr( TEXT("."), 1 );
		if( Dot!=INDEX_NONE )
		{
			FString Ext = Name.Mid( Dot );	// includes the dot

			// Pick the Paths entry whose glob ends in this extension. Paths
			// look like "../Textures/*.utx"; the directory is what precedes
			// the '*'.
			FString Dir;
			for( INT i=0; i<GSys->Paths.Num(); i++ )
			{
				FString Path = GSys->Paths(i);
				INT Star = Path.InStr( TEXT("*") );
				if( Star!=INDEX_NONE && appStricmp( *Path.Mid(Star+1), *Ext )==0 )
				{
					Dir = Path.Left( Star );
					break;
				}
			}

			if( Dir!=TEXT("") && GFileManager->Move( *(Dir + Name), *Src ) )
			{
				// The file has left the cache, so its record leaves too.
				TMultiMap<FString,FString>* Sec = GConfig->GetSectionPrivate( TEXT("Cache"), 0, 0, *CacheIni() );
				if( Sec )
				{
					Sec->Remove( *Guid );
					GConfig->Flush( 0, *CacheIni() );
				}
				*(DWORD*)Result = 1;
			}
		}
	}

	unguard;
}

/*-----------------------------------------------------------------------------
	Stubs.
-----------------------------------------------------------------------------*/

//
// 469 ships a skeletal animation system this engine does not have - there is
// no USkeletalMesh here, and Engine.Animation is the placeholder class in
// UnAudio.h. Nothing in the retail content calls this, so linking an animation
// is a no-op rather than a guess at semantics we cannot implement.
//
void AActor::execLinkSkelAnim( FFrame& Stack, RESULT_DECL )
{
	guard(AActor::execLinkSkelAnim);
	P_GET_OBJECT(UObject,Anim);
	P_FINISH;
	unguard;
}

//
// 469 added this so a player cannot wear a skin from a package that does not
// belong to their mesh; Pawn.uc uses it as "bProscribed = !CheckValidSkinPackage(...)".
// Version 68 had no such check and proscribed nothing, so answering yes keeps
// skin selection behaving exactly as it does on v68 data.
//
void APawn::execCheckValidSkinPackage( FFrame& Stack, RESULT_DECL )
{
	guard(APawn::execCheckValidSkinPackage);
	P_GET_STR(SkinPack);
	P_GET_STR(MeshName);
	P_FINISH;
	*(DWORD*)Result = 1;
	unguard;
}

/*-----------------------------------------------------------------------------
	The End.
-----------------------------------------------------------------------------*/
