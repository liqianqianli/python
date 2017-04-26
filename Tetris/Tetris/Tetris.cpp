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
#define NUM_BRICK_TYPES 7//ש�����״���������Ѿ������ש�����޸�
void Welcome(void);//��Ϸ��ӭ����
void GotoXY(int x,int y);//�趨���λ��
void Display(unsigned char** img,unsigned char** img1,int score,int score1);//��ʾ��Ϸ���棬imgΪ��Ϸ����Ӧ�Ķ�ά����
void Pause();//��ͣ����
void main()
{
	srand((unsigned int)time(NULL));
	unsigned int binWidth,binHeight;
	CBin* tetrisBin=NULL;//ָ����Ϸ���������ָ��
	CBin* tetrisBin1=NULL;
	unsigned char** outputImage=NULL;//������ʾĿ��
	unsigned char** outputImage1=NULL;
	//ע�⣺outputImage������CBin�����image
	CBrick* activeBrick=NULL;//ָ��ǰ��������ש���ָ�룬ע��ָ������
	CBrick* activeBrick1=NULL;
	int difficulty=500;//�Ѷ�
	unsigned int i=0;
	unsigned int j=0;
	int gameOver=0;//��Ϸ�Ƿ����
	int brickInFlight=0,brickInFlight1=0;//ש���Ƿ��ڷ���״̬
	int brickType=0,brickType1=0;//ש�����
	unsigned int initOrientation=0,initOrientation1=0;//��ʼ״̬
	int notCollide=0,notCollide1=0;//ש���Ƿ��ͻ
	int arrowKey=0,arrowKey1=0;
	int score=0,score1=0;//��¼����
	int success=0,success1=0;//��¼�ĸ����Ӯ��,0�������ˣ�1����Ӯ��
	binWidth=10;//��Ϸ���Ŀ��
	binHeight=20;//��Ϸ���ĸ߶�
	tetrisBin=new CBin(binWidth,binHeight);//������Ϸ��������
	tetrisBin1=new CBin(binWidth,binHeight);
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
				//û��ש������ʱ����Ҫ�½�һ��ש��
				//�½�ש����Ҫ����ö�ש�����״�ͳ�ʼ״̬
				if(!brickInFlight)
				{
					brickType=rand()%NUM_BRICK_TYPES+1;
					initOrientation=(unsigned int)(rand()%4);
					//��ԭ���Ķ���if����Ϊswitch��䣬�����ж�

					switch(brickType)
					{
					case 1:
						activeBrick=new CIBrick;//��̬����I��ש�����
						break;
					case 2:
						activeBrick=new CLBrick;//��̬����L��ש�����
						break;
					case 3:
						activeBrick=new CLLBrick;//��̬����LL��ש�����
						break;
					case 4:
						activeBrick=new COBrick;//��̬����O��ש�����
						break;
					case 5:
						activeBrick=new CZBrick;//��̬����Z��ש�����
						break;
					case 6:
						activeBrick=new CZZBrick;//��̬����ZZ��ש�����
						break;
					case 7:
						activeBrick=new CTBrick;//��̬����T��ש�����
						break;
					default :
						brickInFlight=0;//ϵͳ��������������������ʱ�����´���
						break;
					}
					
					activeBrick->setColour((unsigned char)brickType);//��̬��̬�Ե�����
					activeBrick->putAtTop(initOrientation,binWidth/2);//��̬��̬�Ե�����
					notCollide=activeBrick->checkCollision(tetrisBin);//����Ƿ��ͻ
				}
				if(!brickInFlight1)
				{
					brickType1=rand()%NUM_BRICK_TYPES+1;
					initOrientation1=(unsigned int)(rand()%4);
					//��ԭ���Ķ���if����Ϊswitch��䣬�����ж�
					switch(brickType1)
					{
					case 1:
						activeBrick1=new CIBrick;//��̬����I��ש�����
						break;
					case 2:
						activeBrick1=new CLBrick;//��̬����L��ש�����
						break;
					case 3:
						activeBrick1=new CLLBrick;//��̬����LL��ש�����
						break;
					case 4:
						activeBrick1=new COBrick;//��̬����O��ש�����
						break;
					case 5:
						activeBrick1=new CZBrick;//��̬����Z��ש�����
						break;
					case 6:
						activeBrick1=new CZZBrick;//��̬����ZZ��ש�����
						break;
					case 7:
						activeBrick1=new CTBrick;//��̬����T��ש�����
						break;
					default :
						brickInFlight1=0;//ϵͳ��������������������ʱ�����´���
						break;
					}
					
					activeBrick1->setColour((unsigned char)brickType1);//��̬��̬�Ե�����
					activeBrick1->putAtTop(initOrientation1,binWidth/2+40);//��̬��̬�Ե�����
					notCollide1=activeBrick1->checkCollision(tetrisBin1);//����Ƿ��ͻ
				}
				if((notCollide)&&(notCollide1))
				{
					if(notCollide)
					{
						//�½���ש��ͬ��Ϸ���Ķ���û�г�ͻ���Ϳ���������
						brickInFlight=1;
						tetrisBin->getImage(outputImage);//������Ϸ������image��outputImage
						activeBrick->operator>>(outputImage);//�����ǰ��������ש���ӳ��outputImage
						Display(outputImage,outputImage1,score,score1);//��ʾoutputImage
					}
					if(notCollide1)
					{
						//�½���ש��ͬ��Ϸ���Ķ���û�г�ͻ���Ϳ���������
						brickInFlight1=1;
						tetrisBin1->getImage(outputImage1);//������Ϸ������image1��outputImage1
						activeBrick1->operator>>(outputImage1);//�����ǰ��������ש���ӳ��outputImage1
						Display(outputImage,outputImage1,score,score1);//��ʾoutputImage1
					}
				}
				else
				{
					if(notCollide)
						success=1;
					if(notCollide1)
						success1=1;
					//�½�ש��ͬ��Ϸ���Ķ����г�ͻ
					//�������ʣ��ռ��Ѿ��Ų�����ש�飬��Ϸ����
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
						switch(arrowKey)//��ҵĿ��ƣ���ĸ��
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
						
						
						tetrisBin->getImage(outputImage);//������Ļ��ʾ
						//������Ϸ�������ڲ�ͼ��outputImage
						activeBrick->operator>>(outputImage);
						//�����ǰ�����ӳ��outputImage
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
							break;//ϵͳ��������Ԥ֪�����������������
						}
						
						
						tetrisBin1->getImage(outputImage1);//������Ļ��ʾ
						//������Ϸ�������ڲ�ͼ��outputImage1
						activeBrick1->operator>>(outputImage1);
						//�����ǰ�����ӳ��outputImage1
						Display(outputImage,outputImage1,score,score1);
					}
					
					
				}
				Sleep(difficulty);
				notCollide=activeBrick->shiftDown(tetrisBin);//ש�鿿��������
				notCollide1=activeBrick1->shiftDown(tetrisBin1);//ש�鿿��������
				if(notCollide)
				{
					tetrisBin->getImage(outputImage);
					activeBrick->operator>>(outputImage);
				}
				else
				{
					//ש�����ڵײ����Ѿ��̶���ש���ϣ���������
					brickInFlight=0;
					
					
					tetrisBin->getImage(outputImage);
					activeBrick->operator>>(outputImage);
					tetrisBin->setImage(outputImage);
					
					
					Display(outputImage,outputImage1,score,score1);
					
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
				if(notCollide1)
				{
					tetrisBin1->getImage(outputImage1);
					activeBrick1->operator>>(outputImage1);
				}
				else
				{
					//ש�����ڵײ����Ѿ��̶���ש���ϣ���������
					brickInFlight1=0;
					
					
					tetrisBin1->getImage(outputImage1);
					activeBrick1->operator>>(outputImage1);
					tetrisBin1->setImage(outputImage1);
					
					
					Display(outputImage,outputImage1,score,score1);
					
					switch(tetrisBin1->removeFullLines())//����Ƿ���Ҫ����
					{
						//�Ƿַ�ʽ�����ﻹ����ʵ�ָ����ӵļƷַ�ʽ
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
					tetrisBin1->getImage(outputImage1);//������к󣬸����ⲿͼ�����
				}
				Display(outputImage,outputImage1,score,score1);
		}
		}
		}
	


		GotoXY(35,24);
		printf("Game Over!\n\t");
		if(success)
			printf("���ֿ��Ƶ����ʧ�ܣ���ĸ���Ƶ����ʤ��!");
		else
			printf("��ĸ���Ƶ����ʧ�ܣ����ֿ��Ƶ����ʤ��!");
		getch();
		for(i=0;i<binHeight;i++)//�ͷŶ�̬���ٵĿռ�
			delete[] outputImage[i];
		delete[] outputImage;
		
		
		for(i=0;i<binHeight;i++)//�ͷŶ�̬���ٵĿռ�
			delete[] outputImage1[i];
		delete[] outputImage1;
		
		
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
void Display(unsigned char** img,unsigned char** img1,int score,int score1)//��ʾ��Ϸ���棬imgΪ��Ϸ����Ӧ�Ķ�ά����
{
	int i,j;
	GotoXY(1,1);
	for(i=0;i<20;i++)
	{
		printf("��");//���1�����ǽ
		for(j=0;j<10;j++)
		{
			if(0==img[i][j])
				printf("  ");
			else
				printf("��");
		}
		printf("��");//���1���ұ�ǽ
		for(j=0;j<9;j++)
			printf("  ");
		printf("��");//���2�����ǽ
		for(j=0;j<10;j++)
		{
			if(0==img1[i][j])
				printf("  ");
			else
				printf("��");
		}
		printf("��\n");//���2���ұ�ǽ
	}
	for(i=0;i<12;i++)
		printf("��");//�����Ϸ���ĵײ����1
	for(i=0;i<9;i++)
		printf("  ");//����м�Ŀո�
	for(i=0;i<12;i++)
		printf("��");//�����Ϸ���ĵײ����2
	GotoXY(25,4);
	printf("��ת----w/W!");
	GotoXY(25,5);
	printf("����----a/A!");//�����Ļ������ʾ
	GotoXY(25,6);
	printf("����----s/S!");
	GotoXY(25,7);
	printf("����----d/D!");
	GotoXY(25,8);
	printf("��ͣ----p/P!");
	GotoXY(25,9);
	printf("�˳�----q/Q!");
	GotoXY(25,10);
	printf("SCORE:%d",score);//�������
	GotoXY(25,11);
	printf("LEVEL=%d",score/100);//����ȼ�
	GotoXY(67,4);
	printf("��ת----8!");
	GotoXY(67,5);
	printf("����----4!");//�����Ļ������ʾ
	GotoXY(67,6);
	printf("����----5!");
	GotoXY(67,7);
	printf("����----6!");
	GotoXY(67,8);
	printf("��ͣ----9!");
	GotoXY(67,9);
	printf("�˳�----7!");
	GotoXY(67,10);
	printf("SCORE:%d",score1);//�������
	GotoXY(67,11);
	printf("LEVEL=%d",score1/100);//����ȼ�
}
void Pause()//��ͣ����
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
	//������ͣ��ָ���Ϸʱȥ��Pause!��ʾ
}