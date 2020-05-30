 /****************************************************************/
/*    COPYYRIGHT NOTICE                                         */
/*    Copyright (c) 2012,   智能双电梯仿真系统（C语言版）            */
/*    All rights reserved.                                      */
/*                                                              */
/*    @file main.c                                              */
/*    @brief intro:                                             */
/*                (1)Initialize graph                           */
/*                (2)Choose Chinese or Englise                  */
/*                (3)Goto the founction control()               */
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
#include"main.h"

void main()
{
    int page = 1;//page代表页面：1欢迎界面，2主界面，3帮助界面
    int op[2] = {0,1};//op[1]代表选项,op[0]为中英文切换时的选项暂时存储
    int ce = EN;//，ce表示中英文
    
    int driver = DETECT;
    int mode = 0;
    //registerbgidriver(EGAVGA_driver);

    int mouseX, mouseY, button=0;
    int xmin = 1, xmax = 640, ymin = 1, ymax = 480;
    initgraph(&driver, &mode, "");                   //图形初始化
    mou_init(xmin, xmax, ymin, ymax);                //鼠标初始化

    cleardevice();
    start();             //开始动画
    fore(ce);            //欢迎界面
    collect_page(page, op, &mouseX, &mouseY, &button);
    page_mode(op, &ce, &mouseX, &mouseY, &button);
}
