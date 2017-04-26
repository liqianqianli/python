// Brick.cpp: implementation of the CBrick class.
//
//////////////////////////////////////////////////////////////////////

#include "Brick.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
//**************×óÒÆ
int CBrick::shiftLeft(CBin* bin)
{
	int posX;
	posX=getPosX();
	setPosX(posX-1);
	if(checkCollision(bin)==0)
	{
		setPosX(posX);
		return 0;
	}
	return 1;
}
//**************ÓÒÒÆ
int CBrick::shiftRight(CBin* bin)
{
	int posX;
	posX=getPosX();
	setPosX(posX+1);
	if(checkCollision(bin)==0)
	{
		setPosX(posX);
		return 0;
	}
	return 1;
}
//**************ÏÂÂä
int CBrick::shiftDown(CBin* bin)
{
	int posY;
	posY=getPosY();
	setPosY(posY+1);
	if(checkCollision(bin)==0)
	{
		setPosY(posY);
		return 0;
	}
	return 1;
}
//****************Ðý×ª
int CBrick::rotateClockwise(CBin* bin)
{
	int Orientation;
	Orientation=getOrientation();
	setOrientation((Orientation+1)%4);
	if(checkCollision(bin)==0)
	{
		setOrientation(Orientation-1);
		return 0;
	}
	return 1;
}