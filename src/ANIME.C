/****************************************************************/
/*    COPYYRIGHT NOTICE                                         */
/*    Copyright (c) 2012,   ����˫���ݷ���ϵͳ��C���԰棩            */
/*    All rights reserved.                                      */
/*                                                              */
/*    @file anime.c                                             */
/*    @brief intro:                                             */
/*                Start and exit program animation              */
/*                                                              */
/*    @version final                                            */
/*    @author fengyecl                                          */
/*    @date 2012��10��1��                                        */
/*                                                              */
/*    �޶�˵��������汾                                           */
/****************************************************************/
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<process.h>
#include<dos.h>
#include<stdlib.h>
#include<math.h>
#include"anime.h"
/*************************Founction************************************/
//Name:start                                                          //
//Remarks: void start()                                               //
//feature: ����ʼ������������������棩                                  //
/**********************************************************************/
void start()
{
	int i, maxx, maxy, midx, midy;
	setbkcolor(BLACK);
	setcolor(GREEN);
	cleardevice();
	maxx = getmaxx();
	maxy = getmaxy();
	midx = maxx/2;
	midy = maxy/2;
	delay(4000);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	for(i=0; i<300; i++)
	{
		line(midx,midy-2*i,midx+2*i,midy);
		line(midx+2*i,midy,midx,midy+2*i);
		line(midx,midy+2*i,midx-2*i,midy);
		line(midx-2*i,midy,midx,midy-2*i);
	}
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
}
/*************************Founction************************************/
//Name:quit                                                           //
//Remarks: void quit()                                                //
//feature: ����رն�����������������棩                             //
/**********************************************************************/
void quit()
{
	int i,maxx,maxy,midx,midy;
	int size_a,m_a,n_a;
	int size_b,m_b,n_b;
	void *buffer_a;
	void *buffer_b;

	setbkcolor(BLACK);
	setcolor(GREEN);
	cleardevice();
	maxx = getmaxx();
	maxy = getmaxy();
	midx = maxx/2;
	midy = maxy/2;
	setwritemode(COPY_PUT);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	rectangle(0,0,639,479);//��䱳��Ϊ��ɫ
	setfillstyle(1,GREEN);
	floodfill(110,110,GREEN);

	setcolor(BLACK);
	for(i=300; i>=10; i--)//����С����ɫ����
	{
		line(midx,midy-2*i,midx+2*i,midy);
		line(midx+2*i,midy,midx,midy+2*i);
		line(midx,midy+2*i,midx-2*i,midy);
		line(midx-2*i,midy,midx,midy-2*i);
		delay(3);
	}
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	setcolor(GREEN);
	circle(30,80,15);//����ߵ�Բ
	circle(610,80,15);//���ұߵ�Բ
	setfillstyle(1,GREEN);
	floodfill(30,80,GREEN);//�����ߵ�Բ
	floodfill(610,80,GREEN);//����ұߵ�Բ

	size_a = imagesize(0,45,45,95);//����ߵ�Բ��ͼ�δ���buffer_a��
	buffer_a = malloc(size_a);
	getimage(0,45,45,95,buffer_a);

	size_b = imagesize(595,45,639,95);//���ұߵ�Բ��ͼ�δ���buffer_b��
	buffer_b = malloc(size_b);
	getimage(595,45,639,95,buffer_b);
	for(i=1; i<=100; i++)
	{
		m_a = (0+2*i);
		n_a = (45+i*i/70);
		m_b = (595-2*i);
		n_b = (45+i*i/70);
		putimage(m_a,n_a,buffer_a,COPY_PUT);//����ߵ�Բ��ƽ���˶�
		putimage(m_b,n_b,buffer_b,COPY_PUT);//���ұߵ�Բ��ƽ���˶�
		line(midx-20-2*i,midy,midx-18-2*i,midy);
		line(midx+18+2*i,midy,midx+20+2*i,midy);
		delay(3);
	}

	size_a = imagesize(200,205,245,238);//�������ײ�����Բ��ͼ�δ���buffer_a��
	buffer_a = malloc(size_a);
	getimage(200,205,245,238,buffer_a);

	size_b = imagesize(395,205,439,238);//���ұ���ײ�����Բ��ͼ�δ���buffer_b��
	buffer_b = malloc(size_b);
	getimage(395,205,439,238,buffer_b);
	for(i=1;i<=75;i++)
	{
		m_a = (200+1*i);
		n_a = (205-2*i+i*i/70);
		m_b = (395-1*i);
		n_b = (205-2*i+i*i/70);
		putimage(m_a,n_a,buffer_a,COPY_PUT);//����ߵ�Բ����
		putimage(m_b,n_b,buffer_b,COPY_PUT);//���ұߵ�Բ����
		setcolor(BLACK);
		line(m_a,n_a+33+1,m_a+45,n_a+33+1);//�ú��߻���ߵ�Բ�˶��켣
		line(m_a,n_a+33+2,m_a+45,n_a+33+2);
		line(m_b,n_b+33+1,m_b+45,n_b+33+1);//�ú��߻��ұߵ�Բ�˶��켣
		line(m_b,n_b+33+2,m_b+45,n_b+33+2);
		delay(3);
	}
	setcolor(BROWN);
	settextstyle(1,0,1);
	outtextxy(290,140,"Bye");
	setcolor(BROWN);
	outtextxy(321,140,"Bye");

	setcolor(BROWN);
	hanhuaxy(200,320,"л     л     ʹ     ��",3,BROWN);
	delay(3000);
	exit(0);
}