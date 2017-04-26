// LBrick.cpp: implementation of the CLBrick class.
//
//////////////////////////////////////////////////////////////////////

#include "LBrick.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

int CLBrick::checkCollision(CBin* bin)
{
	int width,height,orientation,posX,posY;
	unsigned char** image;
	width=bin->getWidth();
	height=bin->getHeight();
	image=new unsigned char* [height];
	for(int i=0;i<height;i++)
		image[i]=new unsigned char [width];
	bin->getImage(image);
	orientation=getOrientation();
	posX=getPosX();
	if(posX>40)
		posX-=41;
	posY=getPosY();
	if(0==orientation)//L-brick״̬0
	{//ש�������߽�
		if((posX<0)||(posX+1>width-1)||
			(posY<0)||(posY+2>height-1))
			return 0;
		//ש�����������̶�ש��
		if((image[posY][posX]!=0)||
			(image[posY+1][posX]!=0)||
			(image[posY+2][posX]!=0)||
			(image[posY+2][posX+1]!=0))
			return 0;
	}
	if(1==orientation)//L-brick״̬1
	{//ש�������߽�
		if((posX<0)||(posX+2>width-1)||
			(posY-1<0)||(posY>height-1))
			return 0;
		//ש�����������̶�ש��
		if((image[posY][posX]!=0)||
			(image[posY][posX+1]!=0)||
			(image[posY][posX+2]!=0)||
			(image[posY-1][posX+2]!=0))
			return 0;
	}
	if(2==orientation)//L-brick״̬2
	{//ש�������߽�
		if((posX-1<0)||(posX>width-1)||
			(posY-2<0)||(posY>height-1))
			return 0;
		//ש�����������̶�ש��
		if((image[posY-2][posX-1]!=0)||
			(image[posY-2][posX]!=0)||
			(image[posY-1][posX]!=0)||
			(image[posY][posX]!=0))
			return 0;
	}
	/*������
	  ��
	*/
	if(3==orientation)//L-brick״̬3
	{//ש�������߽�
		if((posX-2<0)||(posX>width-1)||
			(posY<0)||(posY+1>height-1))
			return 0;
		//ש�����������̶�ש��
		if((image[posY][posX-2]!=0)||
			(image[posY][posX-1]!=0)||
			(image[posY][posX]!=0)||
			(image[posY+1][posX-2]!=0))
			return 0;
	}
	return 1;
}
void CLBrick::operator>>(unsigned char** binImage)
{
	int orientation,posX,posY;
	unsigned char colour;
	posX=getPosX();
	if(posX>40)
		posX-=41;
	posY=getPosY();
	orientation=getOrientation();
	colour=getColour();
		if(0==orientation)//L-brick״̬0
		{
			binImage[posY][posX]=colour;
			binImage[posY+1][posX]=colour;
			binImage[posY+2][posX]=colour;
			binImage[posY+2][posX+1]=colour;
		}
		if(1==orientation)//L-brick״̬1
		{
			binImage[posY][posX]=colour;
			binImage[posY][posX+1]=colour;
			binImage[posY][posX+2]=colour;
			binImage[posY-1][posX+2]=colour;
		}
		if(2==orientation)//L-brick״̬2
		{
			binImage[posY-2][posX-1]=colour;
			binImage[posY-2][posX]=colour;
			binImage[posY-1][posX]=colour;
			binImage[posY][posX]=colour;
		}
		if(3==orientation)//L-brick״̬3
		{
			binImage[posY][posX-2]=colour;
			binImage[posY][posX-1]=colour;
			binImage[posY][posX]=colour;
			binImage[posY+1][posX-2]=colour;
		}
}
void CLBrick::putAtTop(int newOrient,int newPosX)
{
	setPosX(newPosX);
	setOrientation(newOrient);
	switch(newOrient)
	{
	case 0:
		setPosY(0);
		break;
	case 1:
		setPosY(1);
		break;
	case 2:
		setPosY(2);
		break;
	case 3:
		setPosY(0);
		break;
	}
}


