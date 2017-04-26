// Bin.cpp: implementation of the CBin class.
//
//////////////////////////////////////////////////////////////////////

#include "Bin.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
//******************���캯��
CBin::CBin(unsigned int w,unsigned int h)
{
	width=w;
	height=h;
	image=new unsigned char*[height];
	for(unsigned int i=0;i<height;i++)
	{
		image[i]=new unsigned char[width];

		for(unsigned int j=0;j<width;j++)
			image[i][j]=0;
	}
}
//******************��������
CBin::~CBin()
{
	for(unsigned int i=0;i<height;i++)
		delete image[i];
	delete[] image;
}
//**************��ȡӳ������
void CBin::getImage(unsigned char** destImage)
{
	for(unsigned int i=0;i<height;i++)
		for(unsigned int j=0;j<width;j++)
			destImage[i][j]=image[i][j];
}
//**********************����ӳ������
void CBin::setImage(unsigned char** srcImage)
{
	for(unsigned int i=0;i<height;i++)
		for(unsigned int j=0;j<width;j++)
			image[i][j]=srcImage[i][j];
}
//******************ɾ������
unsigned int CBin::removeFullLines()
{
	unsigned int flag,EmptyLine=0;
	unsigned int i,j,m;
	for(i=0;i<height;i++)
	{
		flag=0;//���һ���Ƿ�����
		for(j=0;j<width;j++)
		{
			if(image[i][j]==0)
				flag=1;
		}
		if(flag==0)//һ����ȫ������
		{
			for(m=i;m>0;m--)//ɾ�����У���������
				for(j=0;j<width;j++)
					image[m][j]=image[m-1][j];
				for(j=0;j<width;j++)
					image[0][j]=0;
				EmptyLine++;//��¼ɾ��������
		}
	}
	return EmptyLine;
}