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
#define NUM_BRICK_TYPES 7//ש�����״���������Ѿ������ש�����޸�
void Welcome(void);//��Ϸ��ӭ����
void GotoXY(int x,int y);//�趨���λ��
void Display(unsigned char** img,int score);//��ʾ��Ϸ���棬imgΪ��Ϸ����Ӧ�Ķ�ά����
void Pause();//��ͣ����
void main()
{
	srand((unsigned int)time(NULL));
	unsigned int binWidth,binHeight;
	CBin* tetrisBin=NULL;//ָ����Ϸ���������ָ��
	unsigned char** outputImage=NULL;//������ʾĿ��
	//ע�⣺outputImage������CBin�����image
	CBrick *activeBrick=NULL;//ָ��ǰ��������ש���ָ�룬ע��ָ������
	int difficulty=500;//�Ѷ�
	unsigned int i=0;
	unsigned int j=0;
	int gameOver=0;//��Ϸ�Ƿ����
	int brickInFlight=0;//ש���Ƿ��ڷ���״̬
	int brickType=0;//ש�����
	unsigned int initOrientation=0;//��ʼ״̬
	int notCollide=0;//ש���Ƿ��ͻ
	int arrowKey=0;
	int score=0;//��¼����
	binWidth=10;//��Ϸ���Ŀ��
	binHeight=20;//��Ϸ���ĸ߶�
	tetrisBin=new CBin(binWidth,binHeight);//������Ϸ��������
	Welcome();//��ʾ��ӭ����
	GotoXY(1,1);
	//Ϊ��Ϸ����Ӧ�Ķ�ά���鶯̬���ٿռ�
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
			//û��ש������ʱ����Ҫ�½�һ��ש��
			//�½�ש����Ҫ����ö�ש�����״�ͳ�ʼ״̬
			brickType=rand()%NUM_BRICK_TYPES+1;
			initOrientation=(unsigned int)(rand()%4);
			brickType=3;
			initOrientation=0;
			if(1==brickType)
				activeBrick=new CIBrick;//��̬����I��ש�����
			else if(2==brickType)
				activeBrick=new CLBrick;//��̬����L��ש�����
			else if(3==brickType)
				activeBrick=new CLLBrick;//��̬����LL��ש�����
			else if(4==brickType)
				activeBrick=new COBrick;//��̬����O��ש�����
			else if(5==brickType)
				activeBrick=new CZBrick;//��̬����Z��ש�����
			else if(6==brickType)
				activeBrick=new CZZBrick;//��̬����ZZ��ש�����
			else if(7==brickType)
				activeBrick=new CTBrick;//��̬����T��ש�����

			activeBrick->setColour((unsigned char)brickType);//��̬��̬�Ե�����
			activeBrick->putAtTop(initOrientation,binWidth/2);//��̬��̬�Ե�����
			notCollide=activeBrick->checkCollision(tetrisBin);//����Ƿ��ͻ
		
			if(notCollide)
			{
				//�½���ש��ͬ��Ϸ���Ķ���û�г�ͻ���Ϳ���������
				brickInFlight=1;
				tetrisBin->getImage(outputImage);//������Ϸ������image��outputImage
				activeBrick->operator >>(outputImage);//�����ǰ��������ש���ӳ��outputImage
				Display(outputImage,score);//��ʾoutputImage
			}
			else
			{
				//�½�ש��ͬ��Ϸ���Ķ����г�ͻ
				//�������ʣ��ռ��Ѿ��Ų�����ש�飬��Ϸ����
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

				tetrisBin->getImage(outputImage);//������Ļ��ʾ
				//������Ϸ�������ڲ�ͼ��outputImage
				activeBrick->operator >>(outputImage);
				//�����ǰ�����ӳ��outputImage
				Display(outputImage,score);
			}
			Sleep(difficulty);
			notCollide=activeBrick->shiftDown(tetrisBin);//ש�鿿��������
			if(notCollide)
			{
				tetrisBin->getImage(outputImage);
				activeBrick->operator >>(outputImage);
			}
			else
			{
				//ש�����ڵײ����Ѿ��̶���ש���ϣ���������
				brickInFlight=0;
				tetrisBin->getImage(outputImage);
				activeBrick->operator >>(outputImage);
				tetrisBin->setImage(outputImage);
				Display(outputImage,score);
				switch(tetrisBin->removeFullLines())//����Ƿ���Ҫ����
				{
					//�Ƿַ�ʽ�����ﻹ����ʵ�ָ����ӵļƷַ�ʽ
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
				switch(score/100)//�ȼ�ȷ��
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
				tetrisBin->getImage(outputImage);//������к󣬸����ⲿͼ�����
			}
			Display(outputImage,score);
		}
		}
		GotoXY(1,24);
		printf("Game Over");
		getch();
		for(i=0;i<binHeight;i++)//�ͷŶ�̬���ٵĿռ�
			delete[] outputImage[i];
		delete[] outputImage;
}
void Welcome(void)//��Ϸ��ӭ����
{  
	printf("                                                                            \n");  
	printf("                                                                            \n");  
	printf("                                                                            \n");  
	printf("��������������                                      ������                  \n");  
	printf("��������������                ������                ������                  \n");  
	printf("    ������                    ������                                        \n");  
	printf("    ������      ����������    ��������  ������  ��  ������    ����������    \n");  
	printf("    ������    ��������������  ��������  ����������  ������  ��������������  \n");  
	printf("    ������    ������  ������  ������    ����������  ������  ������  ������  \n");  
	printf("    ������    ��������������  ������    ������      ������  ������          \n");  
	printf("    ������    ��������������  ������    ������      ������    ��������      \n");  
	printf("    ������    ������          ������    ������      ������      ����������  \n");  
	printf("    ������    ������  ������  ������    ������      ������          ������  \n");  
	printf("    ������    ������  ������  ������    ������      ������  ������  ������  \n");  
	printf("    ������    ��������������  ��������  ������      ������  ��������������  \n");  
	printf("    ������      ����������    ��������  ������      ������    ����������    \n");  
	printf("                                                                            \n");  
	printf("                                                                            \n");  
	printf("                                                                            \n");  
	printf("[��ת��W/8 ���䣺X/2 ���ƣ�A/4 ���ƣ�D/6 ˲�����䣺S/5 ��ͣ��P �˳���Q]\n");  
	printf("*ƽ��ÿ���100�� �ٶȻ�ӿ�һ������\n");  
	printf("*˲�����䣺S/5 Ϊ�������� ���º�ֱ���䵽�ײ�\n");  
	system("pause");  
	system("cls");  //������������
}
void GotoXY(int x,int y)//�趨���λ��
{
	COORD c;
	c.X=x-1;
	c.Y=y-1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void Display(unsigned char** img,int score)//��ʾ��Ϸ���棬imgΪ��Ϸ����Ӧ�Ķ�ά����
{
	int i,j;
	GotoXY(1,1);
	for(i=0;i<20;i++)
	{
		printf("��");//���ǽ
		for(j=0;j<10;j++)
		{
			if(0==img[i][j])
				printf("  ");
			else
				printf("��");
		}
		printf("��\n");//�ұ�ǽ
	}
	for(i=0;i<12;i++)
		printf("��");//�����Ϸ���ĵײ�
	GotoXY(30,5);
	printf("SCORE:%d",score);//�������
	GotoXY(30,6);
	printf("LEVEL=%d",score/100);//����ȼ�
}
void Pause()//��ͣ����
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