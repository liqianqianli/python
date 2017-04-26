// OBrick.h: interface for the COBrick class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OBRICK_H__F92D67D5_0335_4D7F_B14C_7DE6D2770D49__INCLUDED_)
#define AFX_OBRICK_H__F92D67D5_0335_4D7F_B14C_7DE6D2770D49__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Brick.h"

class COBrick : public CBrick  
{
public:
	int checkCollision(CBin* bin);
	void operator>>(unsigned char** binImage);
	void putAtTop(int newOrient,int newPosX);
};

#endif // !defined(AFX_OBRICK_H__F92D67D5_0335_4D7F_B14C_7DE6D2770D49__INCLUDED_)
