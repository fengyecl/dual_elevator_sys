 /****************************************************************/
/*    COPYYRIGHT NOTICE                                         */
/*    Copyright (c) 2012,   ����˫���ݷ���ϵͳ��C���԰棩            */
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
#include"main.h"

void main()
{
    int page = 1;//page����ҳ�棺1��ӭ���棬2�����棬3��������
    int op[2] = {0,1};//op[1]����ѡ��,op[0]Ϊ��Ӣ���л�ʱ��ѡ����ʱ�洢
    int ce = EN;//��ce��ʾ��Ӣ��
    
    int driver = DETECT;
    int mode = 0;
    //registerbgidriver(EGAVGA_driver);

    int mouseX, mouseY, button=0;
    int xmin = 1, xmax = 640, ymin = 1, ymax = 480;
    initgraph(&driver, &mode, "");                   //ͼ�γ�ʼ��
    mou_init(xmin, xmax, ymin, ymax);                //����ʼ��

    cleardevice();
    start();             //��ʼ����
    fore(ce);            //��ӭ����
    collect_page(page, op, &mouseX, &mouseY, &button);
    page_mode(op, &ce, &mouseX, &mouseY, &button);
}