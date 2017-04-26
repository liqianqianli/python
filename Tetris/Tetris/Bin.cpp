// Bin.cpp: implementation of the CBin class.
//
//////////////////////////////////////////////////////////////////////

#include "Bin.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
//******************构造函数
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
//******************析构函数
CBin::~CBin()
{
	for(unsigned int i=0;i<height;i++)
		delete image[i];
	delete[] image;
}
//**************获取映像数据
void CBin::getImage(unsigned char** destImage)
{
	for(unsigned int i=0;i<height;i++)
		for(unsigned int j=0;j<width;j++)
			destImage[i][j]=image[i][j];
}
//**********************设置映像数据
void CBin::setImage(unsigned char** srcImage)
{
	for(unsigned int i=0;i<height;i++)
		for(unsigned int j=0;j<width;j++)
			image[i][j]=srcImage[i][j];
}
//******************删除整行
unsigned int CBin::removeFullLines()
{
	unsigned int flag,EmptyLine=0;
	unsigned int i,j,m;
	for(i=0;i<height;i++)
	{
		flag=0;//检查一行是否被填满
		for(j=0;j<width;j++)
		{
			if(image[i][j]==0)
				flag=1;
		}
		if(flag==0)//一行完全被填满
		{
			for(m=i;m>0;m--)//删除整行，依次下移
				for(j=0;j<width;j++)
					image[m][j]=image[m-1][j];
				for(j=0;j<width;j++)
					image[0][j]=0;
				EmptyLine++;//记录删除的行数
		}
	}
	return EmptyLine;
}