// TBrick.h: interface for the CTBrick class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TBRICK_H__F3A3EDC3_37AA_4D57_82BF_9E82F3B623F9__INCLUDED_)
#define AFX_TBRICK_H__F3A3EDC3_37AA_4D57_82BF_9E82F3B623F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Brick.h"

class CTBrick : public CBrick  
{
public:
	int checkCollision(CBin* bin);
	void operator>>(unsigned char** binImage);
	void putAtTop(int newOrient,int newPosX);
};

#endif // !defined(AFX_TBRICK_H__F3A3EDC3_37AA_4D57_82BF_9E82F3B623F9__INCLUDED_)
