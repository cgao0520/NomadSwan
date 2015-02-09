#ifndef __TYPES_H__
#define __TYPES_H__

#include <string.h> //for memset()

#ifdef PLATFORM_3DS
	#define BOOL	int
	#define BYTE	unsigned char
	#define WORD	unsigned short
	#define DWORD	unsigned int
	#define CONST	const
	#define	INT		int
	#define UINT	unsigned int
	#define LONG	long
	#define LPCSTR	const char*
	#define PCSTR	LPCSTR
	#define HWAVEOUT	void*
	#define BOOLEAN	int

	typedef struct tagRECT
	{
		LONG    left;
		LONG    top;
		LONG    right;
		LONG    bottom;
	} RECT, *PRECT;
	
	#define ZeroMemory(Destination,Length) memset((Destination),0,(Length))

#else
	#define BIT(n) (1 << n)
	
	#include <windows.h>
#endif

#endif //__TYPES_H__


