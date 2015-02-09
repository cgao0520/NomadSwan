////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////
//
//
//
//
//
//
//
////////////////////////////////////////////////////////////////////////////////

#ifndef __DRAW_H__
#define __DRAW_H__
//#include <ddraw.h>

#define DS_1		1
#define DS_2		2
#define DS_3		3
#define DS_4		4
#define DS_FULL		0xFF

//extern LPDIRECTDRAW7	lpDD;
//extern int				PixelDepth;
//extern DWORD			RBitMask, GBitMask, BBitMask;
extern int				SftR, SftG, SftB;
//extern int				FullFrag;

void	screenshot(void);
//void	WsDrawClear(void);
int		WsDrawInit(void);
void	WsDrawResize();
//int		WsDrawCreate(HWND hWnd);
//void	WsDrawDone(void);
//void	WsDrawRelease(void);
//int		WsDrawFrame(void);
//int		WsDrawFlip(void);
void DrawAFrame(u8* framebuffer);
int		WsDrawLCDSegment(void);

inline void putpixel_FB(int y,int x,u8* buffer,u32 r,u32 g,u32 b)
{
	static int x_/*,y_*/,yy;
	x_ = 239 - y;
	//y_ = x;
	
	yy=(x<<8)-(x<<4);
	yy=(yy+x_)*3;
	buffer[yy] = b;
	buffer[yy+1] = g;
	buffer[yy+2] = r;
}

#endif
