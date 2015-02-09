// Font.h: interface for the CFont class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FONT_H__9DA912C9_F93E_4ED9_BD51_672A30C1BDE6__INCLUDED_)
#define AFX_FONT_H__9DA912C9_F93E_4ED9_BD51_672A30C1BDE6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "config.h"


#define FONT8_ASC_COUNT			95	//总字符数
#define FONT8_ASC_START			32	//起始字符
#define FONT8_ASC_WIDTH			8	//每个字符的宽度(像素)
#define FONT8_ASC_HEIGHT		8	//每个字符的高度(像素)

#define ROW_SPACE			1	//行间距(像素)
#define COL_SPACE			1	//列间距(像素)
#define TAB_SPACE_NUM		4	//每个TAB转换成几个空格输出

#define NM3D_WINDOW_WIDTH	320 // the width of 3DS bottom screen

class CRGBA
{
	public:
		#ifdef NMGB_PLATFORM_3DS
			unsigned int data;
			unsigned int GetRGB(){return data;}
		#else
			unsigned short data;
			unsigned short GetRGB(){return data;}
		#endif
		
	CRGBA(unsigned char r, unsigned char g, unsigned char b, unsigned char a){data=r<<16 | g<<8 | b;}
	CRGBA(){data=0;}
	CRGBA(const CRGBA& clr) {data = clr.data;}	
	const CRGBA& operator = (const CRGBA& clr){data = clr.data; return *this;}
	
	//unsigned char r(){data}
	
	virtual ~CRGBA(){};
};

	enum EFontType
	{
		enFont8
	};

	struct STextPos
	{
		int row;
		int col;
	} ;

	class CFont
	{
	public:
		CFont(unsigned char* pBuff)
		{
			m_enCurFontType = enFont8;
			m_CurTextPos.row = m_CurTextPos.col = 0;
			m_pBuff = pBuff;
			m_rgbText = CRGBA(255,255,255,255);
		};
		CFont(unsigned char* pBuff, const CRGBA& clr, const CRGBA& bk_clr)
		{
			m_enCurFontType = enFont8;
			m_CurTextPos.row = m_CurTextPos.col = 0;
			m_pBuff = pBuff;
			m_rgbText = clr;
			m_rgbBkColor = bk_clr;
		};		
		virtual ~CFont(){};
		//////////////////////////////////////////////////////////////////////////
		virtual inline int DrawChar(int nRow, int nCol, int nIndex, CRGBA color)=0;
		virtual STextPos DrawString(int row,int col,const char* p)=0;
		inline void ResetPos()
		{
			m_CurTextPos.row = m_CurTextPos.col = 0;
		}
		inline void ResetPos(int row, int col)
		{
			m_CurTextPos.row = row;
			m_CurTextPos.col = col;
		}
		inline void SetCurFont(EFontType enFT=enFont8)
		{
			m_enCurFontType = enFT;
		}
		EFontType GetCurFont()
		{
			return m_enCurFontType;
		}
		CRGBA SetTextColor(CRGBA rgba, CRGBA bk)
		{
			CRGBA t = m_rgbText;
			m_rgbText = rgba;
			m_rgbBkColor = bk;
			return t;
		}
		
 		inline void SetPixel(int y, int x, unsigned int color) //only be used for 3DS
		{
			static int x_,y_,yy,base_index;
			x_ = 239 - y;
			y_ = x;
			yy=(y_<<8)-(y_<<4);
			base_index = 3*(x_+yy);
			m_pBuff[base_index] 	= color & 0xff;				//b
			m_pBuff[base_index+1]	= (color>>8) & 0xff;	//g
			m_pBuff[base_index+2]	= (color>>16) & 0xff;	//r
		}			
	protected:
		EFontType	m_enCurFontType;
		STextPos	m_CurTextPos;
		unsigned char*	m_pBuff;
		CRGBA		m_rgbText;
		CRGBA		m_rgbBkColor;
	};

#endif // !defined(AFX_FONT_H__9DA912C9_F93E_4ED9_BD51_672A30C1BDE6__INCLUDED_)
