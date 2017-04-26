#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include"Bin.h"
#include"Brick.h"
#include"IBrick.h"
#include"LBrick.h"
#include"LLBrick.h"
#include"OBrick.h"
#include"TBrick.h"
#include"ZBrick.h"
#include"ZZBrick.h"
#define NUM_BRICK_TYPES 7//砖块的形状数，根据已经定义的砖块数修改
void Welcome(void);//游戏欢迎界面
void GotoXY(int x,int y);//设定输出位置
void Display(unsigned char** img,int score);//显示游戏界面，img为游戏面板对应的二维数组
void Pause();//暂停功能
void main()
{
	srand((unsigned int)time(NULL));
	unsigned int binWidth,binHeight;
	CBin* tetrisBin=NULL;//指向游戏面板类对象的指针
	unsigned char** outputImage=NULL;//用于显示目的
	//注意：outputImage独立于CBin对象的image
	CBrick *activeBrick=NULL;//指向当前正在下落砖块的指针，注意指针类型
	int difficulty=500;//难度
	unsigned int i=0;
	unsigned int j=0;
	int gameOver=0;//游戏是否结束
	int brickInFlight=0;//砖块是否处于飞行状态
	int brickType=0;//砖块类别
	unsigned int initOrientation=0;//初始状态
	int notCollide=0;//砖块是否冲突
	int arrowKey=0;
	int score=0;//记录分数
	binWidth=10;//游戏面板的宽度
	binHeight=20;//游戏面板的高度
	tetrisBin=new CBin(binWidth,binHeight);//创建游戏面板类对象
	Welcome();//显示欢迎界面
	GotoXY(1,1);
	//为游戏面板对应的二维数组动态开辟空间
	outputImage=new unsigned char* [binHeight];
	for(i=0;i<binHeight;i++)
	{
		outputImage[i]=new unsigned char [binWidth];
		for(unsigned int j=0;j<binWidth;j++)
			outputImage[i][j]=0;
	}
	Display(outputImage,score);
	while(!gameOver)
	{
		if(!brickInFlight)
		{
			//没有砖块落下时，需要新建一个砖块
			//新建砖块需要随机置顶砖块的形状和初始状态
			brickType=rand()%NUM_BRICK_TYPES+1;
			initOrientation=(unsigned int)(rand()%4);
			brickType=3;
			initOrientation=0;
			if(1==brickType)
				activeBrick=new CIBrick;//动态生成I型砖块对象
			else if(2==brickType)
				activeBrick=new CLBrick;//动态生成L型砖块对象
			else if(3==brickType)
				activeBrick=new CLLBrick;//动态生成LL型砖块对象
			else if(4==brickType)
				activeBrick=new COBrick;//动态生成O型砖块对象
			else if(5==brickType)
				activeBrick=new CZBrick;//动态生成Z型砖块对象
			else if(6==brickType)
				activeBrick=new CZZBrick;//动态生成ZZ型砖块对象
			else if(7==brickType)
				activeBrick=new CTBrick;//动态生成T型砖块对象

			activeBrick->setColour((unsigned char)brickType);//动态多态性的提现
			activeBrick->putAtTop(initOrientation,binWidth/2);//动态多态性的提现
			notCollide=activeBrick->checkCollision(tetrisBin);//检查是否冲突
		
			if(notCollide)
			{
				//新建的砖块同游戏面板的顶部没有冲突，就可以下落了
				brickInFlight=1;
				tetrisBin->getImage(outputImage);//拷贝游戏面板类的image到outputImage
				activeBrick->operator >>(outputImage);//输出当前正在下落砖块的映像到outputImage
				Display(outputImage,score);//显示outputImage
			}
			else
			{
				//新建砖块同游戏面板的顶部有冲突
				//表明面板剩余空间已经放不下新砖块，游戏结束
				gameOver=1;
				delete activeBrick;
				brickInFlight=0;
			}
		}
		else
		{
			if(kbhit())
			{
				arrowKey=getch();
				if(arrowKey=='d'||arrowKey=='D')
					activeBrick->shiftRight(tetrisBin);
				else if(arrowKey=='a'||arrowKey=='A')
					activeBrick->shiftLeft(tetrisBin);
				else if(arrowKey=='w'||arrowKey=='W')
					activeBrick->rotateClockwise(tetrisBin);
				else if(arrowKey=='s'||arrowKey=='S')
				{
					while(activeBrick->shiftDown(tetrisBin)) ;
				}
				else if(arrowKey=='p')
					Pause();

				tetrisBin->getImage(outputImage);//更新屏幕显示
				//拷贝游戏面板类的内部图像到outputImage
				activeBrick->operator >>(outputImage);
				//输出当前下落的映像到outputImage
				Display(outputImage,score);
			}
			Sleep(difficulty);
			notCollide=activeBrick->shiftDown(tetrisBin);//砖块靠重力下落
			if(notCollide)
			{
				tetrisBin->getImage(outputImage);
				activeBrick->operator >>(outputImage);
			}
			else
			{
				//砖块落在底部或已经固定的砖块上，不再下落
				brickInFlight=0;
				tetrisBin->getImage(outputImage);
				activeBrick->operator >>(outputImage);
				tetrisBin->setImage(outputImage);
				Display(outputImage,score);
				switch(tetrisBin->removeFullLines())//检查是否需要消行
				{
					//记分方式。这里还可以实现更复杂的计分方式
				case 1:
					score++;
					break;
				case 2:
					score+=3;
					break;
				case 3:
					score+=5;
					break;
				case 4:
					score+=8;
					break;
				default:
					break;
				}
				switch(score/100)//等级确定
				{
				case 0:
					difficulty=500;
					break;
				case 1:
					difficulty=200;
					break;
				case 2:
					difficulty=100;
					break;
				default:
					difficulty=50;
					break;
				}
				tetrisBin->getImage(outputImage);//检查消行后，更新外部图像面板
			}
			Display(outputImage,score);
		}
		}
		GotoXY(1,24);
		printf("Game Over");
		getch();
		for(i=0;i<binHeight;i++)//释放动态开辟的空间
			delete[] outputImage[i];
		delete[] outputImage;
}
void Welcome(void)//游戏欢迎界面
{  
	printf("                                                                            \n");  
	printf("                                                                            \n");  
	printf("                                                                            \n");  
	printf("■■■■■■■                                      ■■■                  \n");  
	printf("■■■■■■■                ■■■                ■■■                  \n");  
	printf("    ■■■                    ■■■                                        \n");  
	printf("    ■■■      ■■■■■    ■■■■  ■■■  ■  ■■■    ■■■■■    \n");  
	printf("    ■■■    ■■■■■■■  ■■■■  ■■■■■  ■■■  ■■■■■■■  \n");  
	printf("    ■■■    ■■■  ■■■  ■■■    ■■■■■  ■■■  ■■■  ■■■  \n");  
	printf("    ■■■    ■■■■■■■  ■■■    ■■■      ■■■  ■■■          \n");  
	printf("    ■■■    ■■■■■■■  ■■■    ■■■      ■■■    ■■■■      \n");  
	printf("    ■■■    ■■■          ■■■    ■■■      ■■■      ■■■■■  \n");  
	printf("    ■■■    ■■■  ■■■  ■■■    ■■■      ■■■          ■■■  \n");  
	printf("    ■■■    ■■■  ■■■  ■■■    ■■■      ■■■  ■■■  ■■■  \n");  
	printf("    ■■■    ■■■■■■■  ■■■■  ■■■      ■■■  ■■■■■■■  \n");  
	printf("    ■■■      ■■■■■    ■■■■  ■■■      ■■■    ■■■■■    \n");  
	printf("                                                                            \n");  
	printf("                                                                            \n");  
	printf("                                                                            \n");  
	printf("[旋转：W/8 下落：X/2 左移：A/4 右移：D/6 瞬间下落：S/5 暂停：P 退出：Q]\n");  
	printf("*平均每提高100分 速度会加快一个级别\n");  
	printf("*瞬间下落：S/5 为快速下落 按下后直接落到底部\n");  
	system("pause");  
	system("cls");  //调用清屏命令
}
void GotoXY(int x,int y)//设定输出位置
{
	COORD c;
	c.X=x-1;
	c.Y=y-1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void Display(unsigned char** img,int score)//显示游戏界面，img为游戏面板对应的二维数组
{
	int i,j;
	GotoXY(1,1);
	for(i=0;i<20;i++)
	{
		printf("■");//左边墙
		for(j=0;j<10;j++)
		{
			if(0==img[i][j])
				printf("  ");
			else
				printf("□");
		}
		printf("■\n");//右边墙
	}
	for(i=0;i<12;i++)
		printf("■");//输出游戏面板的底部
	GotoXY(30,5);
	printf("SCORE:%d",score);//输出分数
	GotoXY(30,6);
	printf("LEVEL=%d",score/100);//输出等级
}
void Pause()//暂停功能
{
	char c;
	GotoXY(1,23);
	printf("Pause!");
	do
	{
		c=getch();
	}
	while(c!='p');
}