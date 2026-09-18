/*=============================================================================
	NOpenALThread.h: the sliver of threading API this driver needs.

	UE1-64bit, where this driver came from, gets these from its Core
	(Core/Inc/UnThread.h plus platform implementations of appMutex* and
	appThread*). UT99's Core has no threading API at all, and rather than
	graft one on - which would be a second place for the two engines to
	diverge - the driver carries its own. Only the music streaming thread and
	the mutex guarding the xmp player context use it, and only on Linux, so
	pthreads directly is enough.
=============================================================================*/

#ifndef NOPENAL_THREAD_H
#define NOPENAL_THREAD_H

#include <pthread.h>

typedef void* UTHREAD;
typedef void* THREAD_RET;
typedef THREAD_RET ( *THREAD_FUNC )( void* Arg );

inline UTHREAD appThreadSpawn( THREAD_FUNC Func, void* Arg, const char* Name, UBOOL bDetach, DWORD* OutThreadId )
{
	pthread_t* Thread = new pthread_t;
	if( pthread_create( Thread, nullptr, Func, Arg ) != 0 )
	{
		delete Thread;
		return nullptr;
	}
#ifdef __linux__
	if( Name )
		pthread_setname_np( *Thread, Name );	// silently truncated past 15 chars
#endif
	if( OutThreadId )
		*OutThreadId = (DWORD)(PTRINT)*Thread;
	// Detaching still hands the caller a handle, because it stores one and
	// calls appThreadJoin on shutdown; joining a detached thread is a no-op
	// below rather than undefined behaviour.
	if( bDetach )
		pthread_detach( *Thread );
	return (UTHREAD)Thread;
}

inline THREAD_RET appThreadJoin( UTHREAD Thread )
{
	if( !Thread )
		return nullptr;
	pthread_t* Handle = (pthread_t*)Thread;
	void* Ret = nullptr;
	pthread_join( *Handle, &Ret );	// returns EINVAL if detached; harmless
	delete Handle;
	return Ret;
}

// Recursive, because the music code locks around calls that lock again.
class FMutex
{
public:
	FMutex( const char* InName )
	{
		pthread_mutexattr_t Attr;
		pthread_mutexattr_init( &Attr );
		pthread_mutexattr_settype( &Attr, PTHREAD_MUTEX_RECURSIVE );
		pthread_mutex_init( &Handle, &Attr );
		pthread_mutexattr_destroy( &Attr );
	}
	~FMutex() { pthread_mutex_destroy( &Handle ); }

	void Lock()   { pthread_mutex_lock( &Handle ); }
	void Unlock() { pthread_mutex_unlock( &Handle ); }

private:
	pthread_mutex_t Handle;
};

class FScopedLock
{
public:
	FScopedLock( FMutex& InMutex ) : Mutex( InMutex ) { Mutex.Lock(); }
	~FScopedLock() { Mutex.Unlock(); }
private:
	FMutex& Mutex;
};

#endif
