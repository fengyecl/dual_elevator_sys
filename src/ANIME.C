/****************************************************************/
/*    COPYYRIGHT NOTICE                                         */
/*    Copyright (c) 2012,   智能双电梯仿真系统（C语言版）            */
/*    All rights reserved.                                      */
/*                                                              */
/*    @file anime.c                                             */
/*    @brief intro:                                             */
/*                Start and exit program animation              */
/*                                                              */
/*    @version final                                            */
/*    @author fengyecl                                          */
/*    @date 2012年10月1日                                        */
/*                                                              */
/*    修订说明：最初版本                                           */
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
//feature: 程序开始动画（具体解析见报告）                                  //
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
//feature: 程序关闭动画（具体解析见报告）                             //
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
	rectangle(0,0,639,479);//填充背景为绿色
	setfillstyle(1,GREEN);
	floodfill(110,110,GREEN);

	setcolor(BLACK);
	for(i=300; i>=10; i--)//画缩小的绿色棱形
	{
		line(midx,midy-2*i,midx+2*i,midy);
		line(midx+2*i,midy,midx,midy+2*i);
		line(midx,midy+2*i,midx-2*i,midy);
		line(midx-2*i,midy,midx,midy-2*i);
		delay(3);
	}
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	setcolor(GREEN);
	circle(30,80,15);//画左边的圆
	circle(610,80,15);//画右边的圆
	setfillstyle(1,GREEN);
	floodfill(30,80,GREEN);//填充左边的圆
	floodfill(610,80,GREEN);//填充右边的圆

	size_a = imagesize(0,45,45,95);//将左边的圆的图形存入buffer_a中
	buffer_a = malloc(size_a);
	getimage(0,45,45,95,buffer_a);

	size_b = imagesize(595,45,639,95);//将右边的圆的图形存入buffer_b中
	buffer_b = malloc(size_b);
	getimage(595,45,639,95,buffer_b);
	for(i=1; i<=100; i++)
	{
		m_a = (0+2*i);
		n_a = (45+i*i/70);
		m_b = (595-2*i);
		n_b = (45+i*i/70);
		putimage(m_a,n_a,buffer_a,COPY_PUT);//画左边的圆做平抛运动
		putimage(m_b,n_b,buffer_b,COPY_PUT);//画右边的圆做平抛运动
		line(midx-20-2*i,midy,midx-18-2*i,midy);
		line(midx+18+2*i,midy,midx+20+2*i,midy);
		delay(3);
	}

	size_a = imagesize(200,205,245,238);//将左边碰撞后弹起的圆的图形存入buffer_a中
	buffer_a = malloc(size_a);
	getimage(200,205,245,238,buffer_a);

	size_b = imagesize(395,205,439,238);//将右边碰撞后弹起的圆的图形存入buffer_b中
	buffer_b = malloc(size_b);
	getimage(395,205,439,238,buffer_b);
	for(i=1;i<=75;i++)
	{
		m_a = (200+1*i);
		n_a = (205-2*i+i*i/70);
		m_b = (395-1*i);
		n_b = (205-2*i+i*i/70);
		putimage(m_a,n_a,buffer_a,COPY_PUT);//画左边的圆弹起
		putimage(m_b,n_b,buffer_b,COPY_PUT);//画右边的圆弹起
		setcolor(BLACK);
		line(m_a,n_a+33+1,m_a+45,n_a+33+1);//用黑线画左边的圆运动轨迹
		line(m_a,n_a+33+2,m_a+45,n_a+33+2);
		line(m_b,n_b+33+1,m_b+45,n_b+33+1);//用黑线画右边的圆运动轨迹
		line(m_b,n_b+33+2,m_b+45,n_b+33+2);
		delay(3);
	}
	setcolor(BROWN);
	settextstyle(1,0,1);
	outtextxy(290,140,"Bye");
	setcolor(BROWN);
	outtextxy(321,140,"Bye");

	setcolor(BROWN);
	hanhuaxy(200,320,"谢     谢     使     用",3,BROWN);
	delay(3000);
	exit(0);
}
