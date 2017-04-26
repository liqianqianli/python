// LLBrick.h: interface for the CLLBrick class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LLBRICK_H__CEC58C8B_0636_41DE_BFA2_6597B01EE224__INCLUDED_)
#define AFX_LLBRICK_H__CEC58C8B_0636_41DE_BFA2_6597B01EE224__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Brick.h"

class CLLBrick : public CBrick  
{
public:
	int checkCollision(CBin* bin);
	void operator>>(unsigned char** binImage);
	void putAtTop(int newOrient,int newPosX);
};

#endif // !defined(AFX_LLBRICK_H__CEC58C8B_0636_41DE_BFA2_6597B01EE224__INCLUDED_)
