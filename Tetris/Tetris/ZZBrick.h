// ZZBrick.h: interface for the CZZBrick class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ZZBRICK_H__A6BBE160_9A76_4E06_AAEA_38EAC5A3EC22__INCLUDED_)
#define AFX_ZZBRICK_H__A6BBE160_9A76_4E06_AAEA_38EAC5A3EC22__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Brick.h"

class CZZBrick : public CBrick  
{
public:
	int checkCollision(CBin* bin);
	void operator>>(unsigned char** binImage);
	void putAtTop(int newOrient,int newPosX);
};

#endif // !defined(AFX_ZZBRICK_H__A6BBE160_9A76_4E06_AAEA_38EAC5A3EC22__INCLUDED_)
