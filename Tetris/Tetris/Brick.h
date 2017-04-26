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
	int orientation;//״̬
	int posX;//�ض���X����
	int posY;//�ض���Y����
	unsigned char colour;//��ɫ
public:
	int getOrientation()//��ȡ״̬
	{
		return orientation;
	}
	int getPosX()//��ȡλ��X����
	{
		return posX;
	}
	int getPosY()//��ȡλ��Y����
	{
		return posY;
	}
	unsigned char getColour()//��ȡ��ɫ
	{
		return colour;
	}
	void setOrientation(int newOrient)//����״̬
	{
		orientation=newOrient;
	}
	void setPosX(int newPosX)//����λ��X����
	{
		posX=newPosX;
	}
	void setPosY(int newPosY)//����λ��Y����
	{
		posY=newPosY;
	}
	void setColour(unsigned char newColour)//������ɫ
	{
		colour=newColour;
	}
	int shiftLeft(CBin* bin);//����
	int shiftRight(CBin* bin);//����
	int shiftDown(CBin* bin);//����
	int rotateClockwise(CBin* bin);//��ת
	virtual int checkCollision(CBin* bin)=0;//��ͻ���
	virtual void operator>>(unsigned char** binImage)=0;//������Ϸ���
	virtual void putAtTop(int newOrient,int newPosX)=0;//�ö�
};

#endif // !defined(AFX_BRICK_H__1166BA05_4D8E_48EF_8EB6_F69BBE261E2D__INCLUDED_)
