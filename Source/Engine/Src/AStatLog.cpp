/*=============================================================================
	AStatLog.cpp: Unreal Tournament stat logging.
	Copyright 1997-1999 Epic Games, Inc. All Rights Reserved.

	Revision history:
		* Created by Tim Sweeney
=============================================================================*/

#include "EnginePrivate.h"

/*-----------------------------------------------------------------------------
	Stat Log Implementation.
-----------------------------------------------------------------------------*/

#if ENGINE_VERSION>=230
IMPLEMENT_CLASS(AMutator);
#endif









void AStatLog::execGetGMTRef( FFrame& Stack, RESULT_DECL )
{
	guard(AStatLog::execGetGMTRef);
	P_FINISH;

	*(FString*)Result = appGetGMTRef();

	unguardexec;
}

void AStatLog::execGetMapFileName( FFrame& Stack, RESULT_DECL )
{
	guard(AStatLog::execGetMapFileName);
	P_FINISH;

	*(FString*)Result = XLevel->URL.Map;

	unguardexec;
}

void AStatLogFile::execGetPlayerChecksum( FFrame& Stack, RESULT_DECL )
{
	guard(AStatLogFile::execGetPlayerChecksum);
	P_GET_STR(PlayerName);
	P_GET_STR(Secret);
	P_FINISH;

	FMD5Context PContext;
	appMD5Init( &PContext );
	appMD5Update( &PContext, (BYTE*)*PlayerName, PlayerName.Len()*sizeof(TCHAR) );
	appMD5Update( &PContext, (BYTE*)*Secret, Secret.Len()*sizeof(TCHAR) );
	BYTE Digest[16];
	appMD5Final( Digest, &PContext );

	FString Checksum;
	for( INT i=0; i<16; i++ )
		Checksum += FString::Printf( TEXT("%02x"), Digest[i] );
	*(FString*)Result = Checksum;

	unguardexec;
}

void AStatLogFile::execOpenLog( FFrame& Stack, RESULT_DECL )
{
	guard(AStatLogFile::execOpenLog);
	P_FINISH;

	GFileManager->MakeDirectory( TEXT("..") PATH_SEPARATOR TEXT("Logs") );
	LogAr = (PTRINT) GFileManager->CreateFileWriter( *StatLogFile, FILEWRITE_EvenIfReadOnly );
	if( bWorld )
	{
		Context = (PTRINT) new FMD5Context;
		appMD5Init((FMD5Context*) Context);
	}
	unguardexec;
}

void AStatLogFile::execCloseLog( FFrame& Stack, RESULT_DECL )
{
	guard(AStatLogFile::execCloseLog);
	P_FINISH;

	if( Context )
		delete (FMD5Context*)Context;
	Context = 0;

	if( LogAr )
		delete (FArchive*)LogAr;
	LogAr = 0;

	GFileManager->Move( *StatLogFinal, *StatLogFile, 1, 1, 1 );

	unguardexec;
}

void AStatLogFile::execWatermark( FFrame& Stack, RESULT_DECL )
{
	guard(AStatLogFile::execWatermark);
	P_GET_STR(EventString);
	P_FINISH;

	// Update the context...
	EventString += TEXT("\r\n");
	appMD5Update( (FMD5Context*) Context, (BYTE*)*EventString, EventString.Len()*sizeof(TCHAR) );

	unguardexec;
}

void AStatLogFile::execGetChecksum( FFrame& Stack, RESULT_DECL )
{
	guard(AStatLogFile::execGetChecksum);
	P_FINISH;
	FString Checksum;

	BYTE Secret[16];	// Must be bytes.  Used by MD5.
	Secret[0] = 'M';
	Secret[5] = 'p';
	Secret[2] = 'y';
	Secret[3] = 'f';
	Secret[1] = '4';
	Secret[11] = 'd';
	Secret[7] = '9';
	Secret[4] = 'G';
	Secret[12] = 'D';
	Secret[6] = '6';
	Secret[9] = 'e';
	Secret[10] = 'J';
	Secret[14] = '1';
	Secret[15] = 'q';
	Secret[8] = 'k';
	Secret[13] = 'V';

	BYTE Digest[16];

	appMD5Update( (FMD5Context*) Context, Secret, 16 );
	appMD5Final( Digest, (FMD5Context*) Context ); // Outputs a 16 byte digest.

	// Copy each byte into a string of arbitrary character size. (UNICODE safe.)
	INT i;
	for (i=0; i<16; i++) {
		Checksum += FString::Printf(TEXT("%02x"), Digest[i]);
	}
	*(FString*)Result = Checksum;

	unguardexec;
}

void AStatLogFile::execFileFlush( FFrame& Stack, RESULT_DECL )
{
	guard(AStatLogFile::execFileFlush);
	P_FINISH;

	if( LogAr )
		((FArchive*)LogAr)->Flush();

	unguardexec;
}

void AStatLogFile::execFileLog( FFrame& Stack, RESULT_DECL )
{
	guard(AStatLogFile::execFileLog);
	P_GET_STR(EventString);
	P_FINISH;

	#if _MSC_VER
	FString LogString = EventString + TEXT("\r\n");
	if( bWorld )
	{
		FString EncodedString;
		for( INT i=0; i<LogString.Len(); i++ )
		{
			TCHAR c = 0;
			BYTE* a = (BYTE*) &(*LogString)[i];
			BYTE* b = (BYTE*) &c;
			for( INT j=0; j<sizeof(TCHAR); j++ )
				b[j] = a[j] ^ 0xa7;
			EncodedString += FString::Printf(TEXT("%c"), c);
		}
		if ( LogAr )
			((FArchive*)LogAr)->Serialize( const_cast<TCHAR*>(*EncodedString), EncodedString.Len()*sizeof(TCHAR) );
	} else {
		if( LogAr )
			((FArchive*)LogAr)->Serialize( const_cast<TCHAR*>(*LogString), LogString.Len()*sizeof(TCHAR) );
	}
	#else
	// Emulate UNICODE for Linux.
	TCHAR* LogString = (TCHAR*) appMalloc( EventString.Len() * 2 + 4, TEXT("Temporary String Memory") );
	for( INT i=0; i<EventString.Len(); i++ )
	{
		LogString[i*2] = (*EventString)[i];
		LogString[i*2 + 1] = 0;
	}
	LogString[ EventString.Len()*2 ] = '\r';
	LogString[ EventString.Len()*2 + 1 ] = 0;
	LogString[ EventString.Len()*2 + 2 ] = '\n';
	LogString[ EventString.Len()*2 + 3 ] = 0;
	if( bWorld )
	{
		TCHAR* EncodedString = (TCHAR*) appMalloc( EventString.Len() * 2 + 4, TEXT("Temporary String Memory") );
		for( INT i=0; i<EventString.Len()*2 + 4; i++ )
		{
			TCHAR c = 0;
			BYTE* a = (BYTE*) &(LogString[i]);
			BYTE* b = (BYTE*) &c;
			for( INT j=0; j<sizeof(TCHAR); j++ )
				b[j] = a[j] ^ 0xa7;
			EncodedString[i] = c;
		}
		if ( LogAr )
			((FArchive*)LogAr)->Serialize( const_cast<TCHAR*>(EncodedString), EventString.Len() * 2 + 4 );
		appFree( EncodedString );
	} else {
		if( LogAr )
			((FArchive*)LogAr)->Serialize( const_cast<TCHAR*>(LogString), EventString.Len() * 2 + 4 );
	}
	appFree( LogString );
	#endif

	unguardexec;
}

/*-----------------------------------------------------------------------------
	The end.
-----------------------------------------------------------------------------*/
