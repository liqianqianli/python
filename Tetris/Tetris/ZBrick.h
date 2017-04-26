// ZBrick.h: interface for the CZBrick class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ZBRICK_H__809CB78B_F777_4C41_B09E_A80873C2E62B__INCLUDED_)
#define AFX_ZBRICK_H__809CB78B_F777_4C41_B09E_A80873C2E62B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Brick.h"

class CZBrick : public CBrick  
{
public:
	int checkCollision(CBin* bin);
	void operator>>(unsigned char** binImage);
	void putAtTop(int newOrient,int newPosX);
};

#endif // !defined(AFX_ZBRICK_H__809CB78B_F777_4C41_B09E_A80873C2E62B__INCLUDED_)
