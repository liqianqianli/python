// OBrick.cpp: implementation of the COBrick class.
//
//////////////////////////////////////////////////////////////////////

#include "OBrick.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

int COBrick::checkCollision(CBin* bin)
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
	//¡õ¡ö
	//¡ö¡ö
	if(0==orientation)//O-brick×´Ì¬0
	{//×©¿éÅöµ½±ß½ç
		if((posX<0)||(posX+1>width-1)||
			(posY<0)||(posY+1>height-1))
			return 0;
		//×©¿éÅöµ½ÆäËû¹Ì¶¨×©¿é
		if((image[posY][posX]!=0)||
			(image[posY][posX+1]!=0)||
			(image[posY+1][posX]!=0)||
			(image[posY+1][posX+1]!=0))
			return 0;
	}
	//¡ö¡õ
	//¡ö¡ö
	if(1==orientation)//O-brick×´Ì¬1
	{//×©¿éÅöµ½±ß½ç
		if((posX-1<0)||(posX>width-1)||
			(posY<0)||(posY+1>height-1))
			return 0;
		//×©¿éÅöµ½ÆäËû¹Ì¶¨×©¿é
		if((image[posY][posX-1]!=0)||
			(image[posY][posX]!=0)||
			(image[posY+1][posX-1]!=0)||
			(image[posY+1][posX]!=0))
			return 0;
	}
	//¡ö¡ö
	//¡ö¡õ
	if(2==orientation)//O-brick×´Ì¬2
	{//×©¿éÅöµ½±ß½ç
		if((posX-1<0)||(posX>width-1)||
			(posY-1<0)||(posY>height-1))
			return 0;
		//×©¿éÅöµ½ÆäËû¹Ì¶¨×©¿é
		if((image[posY-1][posX-1]!=0)||
			(image[posY-1][posX]!=0)||
			(image[posY][posX]!=0)||
			(image[posY][posX-1]!=0))
			return 0;
	}
	//¡ö¡ö
	//¡õ¡ö
	if(3==orientation)//O-brick×´Ì¬3
	{//×©¿éÅöµ½±ß½ç
		if((posX<0)||(posX+1>width-1)||
			(posY-1<0)||(posY>height-1))
			return 0;
		//×©¿éÅöµ½ÆäËû¹Ì¶¨×©¿é
		if((image[posY-1][posX]!=0)||
			(image[posY-1][posX+1]!=0)||
			(image[posY][posX+1]!=0)||
			(image[posY][posX]!=0))
			return 0;
	}
	return 1;
}
void COBrick::operator>>(unsigned char** binImage)
{
	int orientation,posX,posY;
	unsigned char colour;
	posX=getPosX();
	if(posX>40)
		posX-=41;
	posY=getPosY();
	orientation=getOrientation();
	colour=getColour();
		if(0==orientation)//O-brick×´Ì¬0
		{
			binImage[posY][posX]=colour;
			binImage[posY][posX+1]=colour;
			binImage[posY+1][posX]=colour;
			binImage[posY+1][posX+1]=colour;
		}
		if(1==orientation)//O-brick×´Ì¬1
		{
			binImage[posY][posX-1]=colour;
			binImage[posY][posX]=colour;
			binImage[posY+1][posX-1]=colour;
			binImage[posY+1][posX]=colour;
		}
		if(2==orientation)//O-brick×´Ì¬2
		{
			binImage[posY-1][posX]=colour;
			binImage[posY-1][posX-1]=colour;
			binImage[posY][posX]=colour;
			binImage[posY][posX-1]=colour;
		}
		if(3==orientation)//O-brick×´Ì¬3
		{
			binImage[posY-1][posX+1]=colour;
			binImage[posY-1][posX]=colour;
			binImage[posY][posX+1]=colour;
			binImage[posY][posX]=colour;
		}
}
void COBrick::putAtTop(int newOrient,int newPosX)
{
	setPosX(newPosX);
	setOrientation(newOrient);
	switch(newOrient)
	{
	case 0:
		setPosY(0);
		break;
	case 1:
		setPosY(0);
		break;
	case 2:
		setPosY(1);
		break;
	case 3:
		setPosY(1);
		break;
	}
}

