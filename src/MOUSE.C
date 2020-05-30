/**********************************************************************************/
/*    COPYRIGHT NOTICE                                                            */
/*    Copyright (c) 2012,   ����˫���ݷ���ϵͳ��C���԰棩                              */
/*    All rights reserved.                                                        */
/*                                                                                */
/*    @file mouse.c                                                               */
/*    @brief intro:                                                               */
/*                To model the founction of mouse().                              */  
/*                                                                                */
/*    @version final                                                              */
/*    @author fengyecl                                                            */
/*    @date 2012��10��4��                                                          */
/*                                                                                */
/*    �޶�˵��������汾                                                             */
/**********************************************************************************/
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<process.h>
#include<dos.h>
#include<stdlib.h>
#include<math.h>
#include"mouse.h"

   
void mou_shape( int x, int y)// �����״
{
    int shape[10];

    shape[0] = x;
    shape[1] = y;
    shape[2] = x+16;
    shape[3] = y+12;
    shape[4] = x+8;
    shape[5] = y+12;
    shape[6] = x+5;
    shape[7] = y+19;
    shape[8] = x;
    shape[9] = y;

    setwritemode(XOR_PUT);  //�����
    setcolor(WHITE);
    setlinestyle(0,0,1);
    drawpoly(5, shape);
}
void mou_init( int xmi, int xma, int ymi, int yma)//����ʼ��
{
    union REGS regs;
    regs.x.ax = 0;
    int86(51,&regs,&regs);

    regs.x.ax = 7;
    regs.x.cx = xmi;
    regs.x.dx = xma;
    int86(51, &regs, &regs);

    regs.x.ax = 8;
    regs.x.cx = ymi;
    regs.x.dx = yma;
    int86(51, &regs, &regs);

    regs.x.ax = 4;
    regs.x.cx = 320;
    regs.x.dx = 240;
    int86(51, &regs, &regs);

}

void mou_dis( int *mx, int *my, int *button)//�����ʾ
{

    union REGS regs;
    int xx0 = (*mx), yy0 = (*my);
    int xnew,ynew;
    delay(10);
    regs.x.ax = 3;
    int86(51,&regs,&regs);

    xnew = regs.x.cx;
    ynew = regs.x.dx;
    (*button) = regs.x.bx;

    mou_shape(xx0,yy0);//����ԭλ�õ������״
    mou_shape(xnew,ynew);//����λ���ϻ������״
    (*mx) = xnew;
    (*my) = ynew;
}

int mou_click( int x1, int y1, int x2, int y2, int *button, int *x, int *y)//�����
{
    if( (*x>x1) && (*x<x2) && (*y>y1) && (*y<y2) && (*button==1) )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
