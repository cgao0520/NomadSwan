#include "platform.h"
#include "oswan.h"

#ifdef PLATFORM_3DS

	static u64 start_time;

	void WsPlatformInit()
	{
		app_new_rom = 1;
		start_time = osGetTime();
	}

	DWORD WsPlatformGetTime()
	{
		DWORD now = (osGetTime() - start_time) & 0xffffffff;
		return now;
	}
	
	void Sleep(int milliseconds)
	{
		u64 last=osGetTime();
		while((osGetTime()-last)<milliseconds);
	}


#endif //PLATFORM_3DS







#ifdef PLATFORM_WIN32

	void WsPlatformInit()
	{
		app_new_rom = 1;
	}

	DWORD WsPlatformGetTime()
	{
		return timeGetTime();
	}

#endif //PLATFORM_WIN32