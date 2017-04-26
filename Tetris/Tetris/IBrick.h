// IBrick.h: interface for the CIBrick class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IBRICK_H__6E51FC89_0C3E_4D64_844B_2BB26BE5490B__INCLUDED_)
#define AFX_IBRICK_H__6E51FC89_0C3E_4D64_844B_2BB26BE5490B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Brick.h"

class CIBrick : public CBrick  
{
public:
	int checkCollision(CBin* bin);
	void operator>>(unsigned char** binImage);
	void putAtTop(int newOrient,int newPosX);
};

#endif // !defined(AFX_IBRICK_H__6E51FC89_0C3E_4D64_844B_2BB26BE5490B__INCLUDED_)
