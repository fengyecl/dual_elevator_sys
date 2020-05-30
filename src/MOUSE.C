/**********************************************************************************/
/*    COPYRIGHT NOTICE                                                            */
/*    Copyright (c) 2012,   智能双电梯仿真系统（C语言版）                              */
/*    All rights reserved.                                                        */
/*                                                                                */
/*    @file mouse.c                                                               */
/*    @brief intro:                                                               */
/*                To model the founction of mouse().                              */  
/*                                                                                */
/*    @version final                                                              */
/*    @author fengyecl                                                            */
/*    @date 2012年10月4日                                                          */
/*                                                                                */
/*    修订说明：最初版本                                                             */
/**********************************************************************************/
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<process.h>
#include<dos.h>
#include<stdlib.h>
#include<math.h>
#include"mouse.h"

   
void mou_shape( int x, int y)// 鼠标形状
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

    setwritemode(XOR_PUT);  //用异或
    setcolor(WHITE);
    setlinestyle(0,0,1);
    drawpoly(5, shape);
}
void mou_init( int xmi, int xma, int ymi, int yma)//鼠标初始化
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

void mou_dis( int *mx, int *my, int *button)//鼠标显示
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

    mou_shape(xx0,yy0);//消除原位置的鼠标形状
    mou_shape(xnew,ynew);//在新位置上画鼠标形状
    (*mx) = xnew;
    (*my) = ynew;
}

int mou_click( int x1, int y1, int x2, int y2, int *button, int *x, int *y)//鼠标点击
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

