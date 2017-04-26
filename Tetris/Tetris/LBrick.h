// LBrick.h: interface for the CLBrick class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LBRICK_H__63C95420_7BD4_4D86_A1DA_0C10F2A7550A__INCLUDED_)
#define AFX_LBRICK_H__63C95420_7BD4_4D86_A1DA_0C10F2A7550A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Brick.h"

class CLBrick : public CBrick  
{
public:
	int checkCollision(CBin* bin);
	void operator>>(unsigned char** binImage);
	void putAtTop(int newOrient,int newPosX);
};

#endif // !defined(AFX_LBRICK_H__63C95420_7BD4_4D86_A1DA_0C10F2A7550A__INCLUDED_)
