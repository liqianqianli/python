// Brick.h: interface for the CBrick class.
//
//////////////////////////////////////////////////////////////////////
#include"Bin.h"
#if !defined(AFX_BRICK_H__1166BA05_4D8E_48EF_8EB6_F69BBE261E2D__INCLUDED_)
#define AFX_BRICK_H__1166BA05_4D8E_48EF_8EB6_F69BBE261E2D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CBrick  
{
protected:
	int orientation;//状态
	int posX;//特定点X坐标
	int posY;//特定点Y坐标
	unsigned char colour;//颜色
public:
	int getOrientation()//获取状态
	{
		return orientation;
	}
	int getPosX()//获取位置X坐标
	{
		return posX;
	}
	int getPosY()//获取位置Y坐标
	{
		return posY;
	}
	unsigned char getColour()//获取颜色
	{
		return colour;
	}
	void setOrientation(int newOrient)//设置状态
	{
		orientation=newOrient;
	}
	void setPosX(int newPosX)//设置位置X坐标
	{
		posX=newPosX;
	}
	void setPosY(int newPosY)//设置位置Y坐标
	{
		posY=newPosY;
	}
	void setColour(unsigned char newColour)//设置颜色
	{
		colour=newColour;
	}
	int shiftLeft(CBin* bin);//左移
	int shiftRight(CBin* bin);//右移
	int shiftDown(CBin* bin);//下落
	int rotateClockwise(CBin* bin);//旋转
	virtual int checkCollision(CBin* bin)=0;//冲突检查
	virtual void operator>>(unsigned char** binImage)=0;//设置游戏面板
	virtual void putAtTop(int newOrient,int newPosX)=0;//置顶
};

#endif // !defined(AFX_BRICK_H__1166BA05_4D8E_48EF_8EB6_F69BBE261E2D__INCLUDED_)
