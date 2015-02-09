#ifndef __PLATFORM_H__
#define __PLATFORM_H__


#define PLATFORM_3DS // ---one of these two lines should be the first line of this file
//#define PLATFORM_WIN32 // /







#include "types.h"

void WsPlatformInit();

// return the system time, in milliseconds. The system time is the time elapsed since system was started.
DWORD WsPlatformGetTime();

#ifdef PLATFORM_3DS
	#include <3ds.h>
	void Sleep(int milliseconds);
#endif

#ifdef PLATFORM_WIN32
	#include <windows.h>
#endif

#endif //__PLATFORM_H__