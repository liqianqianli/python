#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<string.h>
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
void Display(unsigned char** img,unsigned char** img1,int score,int score1);//显示游戏界面，img为游戏面板对应的二维数组
void Pause();//暂停功能
void main()
{
	srand((unsigned int)time(NULL));
	unsigned int binWidth,binHeight;
	CBin* tetrisBin=NULL;//指向游戏面板类对象的指针
	CBin* tetrisBin1=NULL;
	unsigned char** outputImage=NULL;//用于显示目的
	unsigned char** outputImage1=NULL;
	//注意：outputImage独立于CBin对象的image
	CBrick* activeBrick=NULL;//指向当前正在下落砖块的指针，注意指针类型
	CBrick* activeBrick1=NULL;
	int difficulty=500;//难度
	unsigned int i=0;
	unsigned int j=0;
	int gameOver=0;//游戏是否结束
	int brickInFlight=0,brickInFlight1=0;//砖块是否处于飞行状态
	int brickType=0,brickType1=0;//砖块类别
	unsigned int initOrientation=0,initOrientation1=0;//初始状态
	int notCollide=0,notCollide1=0;//砖块是否冲突
	int arrowKey=0,arrowKey1=0;
	int score=0,score1=0;//记录分数
	int success=0,success1=0;//记录哪个玩家赢了,0代表输了，1代表赢了
	binWidth=10;//游戏面板的宽度
	binHeight=20;//游戏面板的高度
	tetrisBin=new CBin(binWidth,binHeight);//创建游戏面板类对象
	tetrisBin1=new CBin(binWidth,binHeight);
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
	GotoXY(41,1);
	outputImage1=new unsigned char* [binHeight];
	for(i=0;i<binHeight;i++)
	{
		outputImage1[i]=new unsigned char [binWidth];
		for(unsigned int j=0;j<binWidth;j++)
			outputImage1[i][j]=0;
	}
	
	
	Display(outputImage,outputImage1,score,score1);
	while(!gameOver)
	{
		{
			if((!brickInFlight)||(!brickInFlight1))
			{
				//没有砖块落下时，需要新建一个砖块
				//新建砖块需要随机置顶砖块的形状和初始状态
				if(!brickInFlight)
				{
					brickType=rand()%NUM_BRICK_TYPES+1;
					initOrientation=(unsigned int)(rand()%4);
					//将原来的多重if语句改为switch语句，减少判断

					switch(brickType)
					{
					case 1:
						activeBrick=new CIBrick;//动态生成I型砖块对象
						break;
					case 2:
						activeBrick=new CLBrick;//动态生成L型砖块对象
						break;
					case 3:
						activeBrick=new CLLBrick;//动态生成LL型砖块对象
						break;
					case 4:
						activeBrick=new COBrick;//动态生成O型砖块对象
						break;
					case 5:
						activeBrick=new CZBrick;//动态生成Z型砖块对象
						break;
					case 6:
						activeBrick=new CZZBrick;//动态生成ZZ型砖块对象
						break;
					case 7:
						activeBrick=new CTBrick;//动态生成T型砖块对象
						break;
					default :
						brickInFlight=0;//系统发生错误，生成其他的数时，从新创建
						break;
					}
					
					activeBrick->setColour((unsigned char)brickType);//动态多态性的提现
					activeBrick->putAtTop(initOrientation,binWidth/2);//动态多态性的提现
					notCollide=activeBrick->checkCollision(tetrisBin);//检查是否冲突
				}
				if(!brickInFlight1)
				{
					brickType1=rand()%NUM_BRICK_TYPES+1;
					initOrientation1=(unsigned int)(rand()%4);
					//将原来的多重if语句改为switch语句，减少判断
					switch(brickType1)
					{
					case 1:
						activeBrick1=new CIBrick;//动态生成I型砖块对象
						break;
					case 2:
						activeBrick1=new CLBrick;//动态生成L型砖块对象
						break;
					case 3:
						activeBrick1=new CLLBrick;//动态生成LL型砖块对象
						break;
					case 4:
						activeBrick1=new COBrick;//动态生成O型砖块对象
						break;
					case 5:
						activeBrick1=new CZBrick;//动态生成Z型砖块对象
						break;
					case 6:
						activeBrick1=new CZZBrick;//动态生成ZZ型砖块对象
						break;
					case 7:
						activeBrick1=new CTBrick;//动态生成T型砖块对象
						break;
					default :
						brickInFlight1=0;//系统发生错误，生成其他的数时，从新创建
						break;
					}
					
					activeBrick1->setColour((unsigned char)brickType1);//动态多态性的提现
					activeBrick1->putAtTop(initOrientation1,binWidth/2+40);//动态多态性的提现
					notCollide1=activeBrick1->checkCollision(tetrisBin1);//检查是否冲突
				}
				if((notCollide)&&(notCollide1))
				{
					if(notCollide)
					{
						//新建的砖块同游戏面板的顶部没有冲突，就可以下落了
						brickInFlight=1;
						tetrisBin->getImage(outputImage);//拷贝游戏面板类的image到outputImage
						activeBrick->operator>>(outputImage);//输出当前正在下落砖块的映像到outputImage
						Display(outputImage,outputImage1,score,score1);//显示outputImage
					}
					if(notCollide1)
					{
						//新建的砖块同游戏面板的顶部没有冲突，就可以下落了
						brickInFlight1=1;
						tetrisBin1->getImage(outputImage1);//拷贝游戏面板类的image1到outputImage1
						activeBrick1->operator>>(outputImage1);//输出当前正在下落砖块的映像到outputImage1
						Display(outputImage,outputImage1,score,score1);//显示outputImage1
					}
				}
				else
				{
					if(notCollide)
						success=1;
					if(notCollide1)
						success1=1;
					//新建砖块同游戏面板的顶部有冲突
					//表明面板剩余空间已经放不下新砖块，游戏结束
					gameOver=1;
					delete activeBrick;
					delete activeBrick1;
					brickInFlight1=0;
					brickInFlight=0;
					break;
				}
			}
			else
			{
				if(kbhit())
				{
					arrowKey=getch();
					if((arrowKey<49)||(arrowKey>58))
					{
						switch(arrowKey)//玩家的控制，字母方
						{				
						case 'd':
						case 'D':
							activeBrick->shiftRight(tetrisBin);
							break;
						case 'a':
						case 'A':
							activeBrick->shiftLeft(tetrisBin);
							break;
						case 'w':
						case 'W':
							activeBrick->rotateClockwise(tetrisBin);
							break;
						case 's':
						case 'S':
							while(activeBrick->shiftDown(tetrisBin)) ;
							break;
						case 'p':
						case 'P':
							Pause();
							break;
						case 'q':
						case 'Q':
							return;	
						default:
							break;
						}
						
						
						tetrisBin->getImage(outputImage);//更新屏幕显示
						//拷贝游戏面板类的内部图像到outputImage
						activeBrick->operator>>(outputImage);
						//输出当前下落的映像到outputImage
						Display(outputImage,outputImage1,score,score1);
					}
					
					
					else
					{
						switch(arrowKey)
						{
						case '6':
							activeBrick1->shiftRight(tetrisBin1);
							break;
						case '4':
							activeBrick1->shiftLeft(tetrisBin1);
							break;
						case '8':
							activeBrick1->rotateClockwise(tetrisBin1);
							break;
						case '5':
							while(activeBrick1->shiftDown(tetrisBin1)) ;
							break;
						case '9':
							Pause();
							break;
						case '7':
							return;
						default :
							break;//系统发生不可预知的输入错误，重新输入
						}
						
						
						tetrisBin1->getImage(outputImage1);//更新屏幕显示
						//拷贝游戏面板类的内部图像到outputImage1
						activeBrick1->operator>>(outputImage1);
						//输出当前下落的映像到outputImage1
						Display(outputImage,outputImage1,score,score1);
					}
					
					
				}
				Sleep(difficulty);
				notCollide=activeBrick->shiftDown(tetrisBin);//砖块靠重力下落
				notCollide1=activeBrick1->shiftDown(tetrisBin1);//砖块靠重力下落
				if(notCollide)
				{
					tetrisBin->getImage(outputImage);
					activeBrick->operator>>(outputImage);
				}
				else
				{
					//砖块落在底部或已经固定的砖块上，不再下落
					brickInFlight=0;
					
					
					tetrisBin->getImage(outputImage);
					activeBrick->operator>>(outputImage);
					tetrisBin->setImage(outputImage);
					
					
					Display(outputImage,outputImage1,score,score1);
					
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
				if(notCollide1)
				{
					tetrisBin1->getImage(outputImage1);
					activeBrick1->operator>>(outputImage1);
				}
				else
				{
					//砖块落在底部或已经固定的砖块上，不再下落
					brickInFlight1=0;
					
					
					tetrisBin1->getImage(outputImage1);
					activeBrick1->operator>>(outputImage1);
					tetrisBin1->setImage(outputImage1);
					
					
					Display(outputImage,outputImage1,score,score1);
					
					switch(tetrisBin1->removeFullLines())//检查是否需要消行
					{
						//记分方式。这里还可以实现更复杂的计分方式
					case 1:
						score1++;
						break;
					case 2:
						score1+=3;
						break;
					case 3:
						score1+=5;
						break;
					case 4:
						score1+=8;
						break;
					default:
						break;
					}					
					tetrisBin1->getImage(outputImage1);//检查消行后，更新外部图像面板
				}
				Display(outputImage,outputImage1,score,score1);
		}
		}
		}
	


		GotoXY(35,24);
		printf("Game Over!\n\t");
		if(success)
			printf("数字控制的玩家失败，字母控制的玩家胜利!");
		else
			printf("字母控制的玩家失败，数字控制的玩家胜利!");
		getch();
		for(i=0;i<binHeight;i++)//释放动态开辟的空间
			delete[] outputImage[i];
		delete[] outputImage;
		
		
		for(i=0;i<binHeight;i++)//释放动态开辟的空间
			delete[] outputImage1[i];
		delete[] outputImage1;
		
		
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
void Display(unsigned char** img,unsigned char** img1,int score,int score1)//显示游戏界面，img为游戏面板对应的二维数组
{
	int i,j;
	GotoXY(1,1);
	for(i=0;i<20;i++)
	{
		printf("■");//玩家1的左边墙
		for(j=0;j<10;j++)
		{
			if(0==img[i][j])
				printf("  ");
			else
				printf("□");
		}
		printf("■");//玩家1的右边墙
		for(j=0;j<9;j++)
			printf("  ");
		printf("■");//玩家2的左边墙
		for(j=0;j<10;j++)
		{
			if(0==img1[i][j])
				printf("  ");
			else
				printf("□");
		}
		printf("■\n");//玩家2的右边墙
	}
	for(i=0;i<12;i++)
		printf("■");//输出游戏面板的底部玩家1
	for(i=0;i<9;i++)
		printf("  ");//输出中间的空格
	for(i=0;i<12;i++)
		printf("■");//输出游戏面板的底部玩家2
	GotoXY(25,4);
	printf("旋转----w/W!");
	GotoXY(25,5);
	printf("左移----a/A!");//输出屏幕操作提示
	GotoXY(25,6);
	printf("下落----s/S!");
	GotoXY(25,7);
	printf("右移----d/D!");
	GotoXY(25,8);
	printf("暂停----p/P!");
	GotoXY(25,9);
	printf("退出----q/Q!");
	GotoXY(25,10);
	printf("SCORE:%d",score);//输出分数
	GotoXY(25,11);
	printf("LEVEL=%d",score/100);//输出等级
	GotoXY(67,4);
	printf("旋转----8!");
	GotoXY(67,5);
	printf("左移----4!");//输出屏幕操作提示
	GotoXY(67,6);
	printf("下落----5!");
	GotoXY(67,7);
	printf("右移----6!");
	GotoXY(67,8);
	printf("暂停----9!");
	GotoXY(67,9);
	printf("退出----7!");
	GotoXY(67,10);
	printf("SCORE:%d",score1);//输出分数
	GotoXY(67,11);
	printf("LEVEL=%d",score1/100);//输出等级
}
void Pause()//暂停功能
{
	char c;
	int i;
	GotoXY(1,23);
	printf("Pause!");
	GotoXY(43,23);
	printf("Pause!");
	do
	{
		fflush(stdin);
		c=getch();
	}
	while((c!='p')&&(c!='P')&&(c!='9'));
	GotoXY(1,23);
	printf("      ");
	GotoXY(43,23);
	printf("      ");
	//增加暂停后恢复游戏时去掉Pause!标示
}