// Bin.h: interface for the CBin class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BIN_H__1B4A9579_1261_43A0_81B7_E9A04B812D5E__INCLUDED_)
#define AFX_BIN_H__1B4A9579_1261_43A0_81B7_E9A04B812D5E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CBin  
{
protected:
	unsigned int width;
	unsigned int height;
	unsigned char** image;
public:
	CBin(unsigned int w,unsigned int h);
	~CBin();
	unsigned int getWidth()
	{
		return width;
	}
	unsigned int getHeight()
	{
		return height;
	}
	void getImage(unsigned char** destImage);
	void setImage(unsigned char** srcImage);
	unsigned int removeFullLines();
};

#endif // !defined(AFX_BIN_H__1B4A9579_1261_43A0_81B7_E9A04B812D5E__INCLUDED_)
