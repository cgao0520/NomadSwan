// Font.cpp: implementation of the CFont class.
//
//////////////////////////////////////////////////////////////////////

#include "font.h"
#include "5_7font.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


	class CFont8 : public CFont
	{
	public:
		CFont8(unsigned char* pBuff):CFont(pBuff){};
		CFont8(unsigned char* pBuff, const CRGBA& clr, const CRGBA& bk_clr):CFont(pBuff,clr,bk_clr){};
		inline int DrawChar(int nRow, int nCol, int nIndex, CRGBA color)
		{
			if( nIndex == ' ' - FONT8_ASC_START ) //����ǿո�,����,ֱ�ӷ���3,Ҳ����˵,ԭ�����λ��������,Ҳ�����в���
				return 3;
			
			int nWidth=0;
			if(nIndex > FONT8_ASC_COUNT || nIndex < 0)
				return nWidth;
			unsigned char * pLocation=nAsciiDot+nIndex*FONT8_ASC_WIDTH;
			unsigned char * ptemp=NULL;
			//int n=0;
			int i=0,j=0;
			int row=nRow,col=nCol;
			//uint16 color=RGB15(31,31,31)|BIT(15);
			
			for(i=0; i<FONT8_ASC_HEIGHT; i++)
			{
				ptemp=pLocation+i;
				for(j=0; j<FONT8_ASC_WIDTH; j++)
				{
					if( (*ptemp) & BIT(FONT8_ASC_WIDTH-j-1) )
					{
						//render.SetPixelA(buffer, row, col, color);//call SetPixelA() to alpha version
						SetPixel(row, col, color.GetRGB());//call SetPixel() no alpha version
						if( j > nWidth)
							nWidth=j;
					}
					else //����ɫ
						SetPixel(row, col, m_rgbBkColor.GetRGB());//call SetPixel() no alpha version
					col++;
				}
				col=nCol;
				row++;
			}
			if(	
				nIndex == '!'-FONT8_ASC_START ||
				nIndex == ','-FONT8_ASC_START ||
				nIndex == '.'-FONT8_ASC_START ||
				nIndex == '?'-FONT8_ASC_START ||
				nIndex == '"'-FONT8_ASC_START ||
				nIndex == ';'-FONT8_ASC_START ||
				nIndex == ':'-FONT8_ASC_START )
				return FONT8_ASC_WIDTH;
			else
				return nWidth+1;
		}
		
		STextPos DrawString(int row,int col,const char* p)
		{
			int nRowSpace=ROW_SPACE;//�м��
			int nColSpace=COL_SPACE;//�м��
			int w=0;
			char ch;
			int temp=0;
			const char* space=" ";
			STextPos pos;

// 			if(row<0 || col <0)
// 			{
// 				pos = m_CurTextPos;
// 				row = pos.row;
// 				col = pos.col;
// 			}
			
			if(row<0)
			{
				row = m_CurTextPos.row;
			}
			if(col<0)
			{
				col = m_CurTextPos.col;
			}
			
			while(*p != '\0')
			{
				ch=*p;
				switch(ch)
				{
				case '\n':
					col=0;
					row+=(FONT8_ASC_HEIGHT+nRowSpace);
					break;
				case '\t'://�����Լ��Ĵ���,��������4���ո�
					{
						for(temp=0; temp<TAB_SPACE_NUM;temp++)
						{
							pos=DrawString(row,col,space);
							row=pos.row;
							col=pos.col;
						}
					}
					break;
				default:
					w=DrawChar(row,col,ch-FONT8_ASC_START,m_rgbText);
					col+=(w+nColSpace);
					if(col+FONT8_ASC_WIDTH >= NM3D_WINDOW_WIDTH)
					{
						col=0;
						row+=(FONT8_ASC_HEIGHT+nRowSpace);
					}
					break;
				}			
				
				p++;
			}
			pos.row=row;
			pos.col=col;
			m_CurTextPos = pos;
			return pos;
		}
	}; //end of class defition 
