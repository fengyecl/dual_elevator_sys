//************************************************************************/
/*    COPYRIGHT NOTICE                                                   */
/*    Copyright (c) 2012,   智能双电梯仿真系统（C语言版）                     */
/*    All rights reserved.                                               */
/*                                                                       */
/*    @file interface.c                                                  */
/*    @brief intro:                                                      */
/*                draw interface including welcome, lift and help        */
/*    @version final                                                     */
/*    @author fengyecl                                                   */
/*    @date 2012年10月1日                                                 */
/*                                                                       */
/*    修订说明：最初版本                                                    */
/*************************************************************************/
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<process.h>
#include<dos.h>
#include<stdlib.h>
#include<math.h>
#include"surface.h"

/***************************Founction************************************/
//Name: fore                                                            //
//Remarks: fore(int *ce)                                                //
//feature: 欢迎界面绘制                                                   //
/************************************************************************/
void fore( int *ce)
{
    settextjustify(0,2);
    setwritemode(COPY_PUT);
    setbkcolor(GREEN);
    
    setcolor(DARKGRAY);
    bar3d(420,200,540,280,8,1);              //进入图框
    bar3d(260,260,380,340,8,1);              //帮助图框
    bar3d(100,320,220,400,8,1);              //退出图框
    bar3d(550,430,610,450,5,1);                 //中英文切换图框 
    
    setfillstyle(SOLID_FILL,YELLOW);
    floodfill(430,250,DARKGRAY);//ENTER
    floodfill(430,195,DARKGRAY);
    floodfill(545,240,DARKGRAY);    
    floodfill(280,300,DARKGRAY);//HELP
    floodfill(270,255,DARKGRAY);
    floodfill(385,300,DARKGRAY);
    floodfill(200,350,DARKGRAY);//EXIT    
    floodfill(110,315,DARKGRAY);
    floodfill(225,350,DARKGRAY);    
    floodfill(552,432,DARKGRAY);//EN/CN
    floodfill(580,428,DARKGRAY);
    floodfill(612,440,DARKGRAY);

    if(*ce == EN)
    {        
        settextstyle(3,0,4);
        setcolor(RED);
        outtextxy(50,50,"W e l c o m e  To");
        settextstyle(3,0,4);
        outtextxy(60,120,"simulation system of intelligent");
        outtextxy(220,170,"dual vator");

        settextstyle(0,0,2);
        setcolor(GREEN);
        outtextxy(445,231,"ENTER");
        setcolor(BLUE);
        outtextxy(295,291,"HELP");
        setcolor(RED);
        outtextxy(135,350,"EXIT");
        settextstyle(0,0,1);
        outtextxy(560,437,"EN/CN");
    }

    else if(*ce == CN)
    {
        hanhuaxy(100,50,"欢",2,RED);
        hanhuaxy(140,50,"迎",2,RED);
        hanhuaxy(180,50,"进",2,RED);
        hanhuaxy(220,50,"入",2,RED);
        hanhuaxy(60,120,"智",2,RED);
        hanhuaxy(100,120,"能",2,RED);
        hanhuaxy(140,120,"双",2,RED);
        hanhuaxy(180,120,"电",2,RED);
        hanhuaxy(220,120,"梯",2,RED);
        hanhuaxy(260,120,"仿",2,RED);
        hanhuaxy(300,120,"真",2,RED);
        hanhuaxy(340,120,"系",2,RED);
        hanhuaxy(380,120,"统",2,RED);

        hanhuaxy(445,225,"进",2,GREEN);
        hanhuaxy(485,225,"入",2,GREEN);
        hanhuaxy(285,285,"帮",2,BLUE);
        hanhuaxy(325,285,"助",2,BLUE);
        hanhuaxy(125,345,"退",2,RED);
        hanhuaxy(165,345,"出",2,RED);

        hanhuaxy(560,433,"中英",1,RED);
    }
}


/***************************Founction************************************/
//Name:major                                                            //
//Remarks: void major(int *ce)                                          //
//feature: 电梯主界面绘制                                                 //
/************************************************************************/

void major( int *ce)
{
    settextjustify(0,2);
    setbkcolor(BLACK);
    setwritemode(COPY_PUT);
    pic0();
    pic1();
    pic2(ce);
    pic3(ce);
    pic4();
    pic5(ce);
}

void pic0()                //画边框
{
    setcolor(GREEN);
    rectangle(0,0,639,479);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(100,100,GREEN);

    setcolor(LIGHTGRAY);
    rectangle(15,15,625,465);
    rectangle(20,20,620,460);
    setfillstyle(SOLID_FILL,LIGHTGRAY);
    floodfill(16,16,LIGHTGRAY);
}

void pic1()               //画边界和电梯区，按键区的背景
{
    setcolor(WHITE);
    line(20,65,390,65);                //标题下的白线

    setcolor(LIGHTGRAY);
    rectangle(390,20,400,460);           //纵向分界线
    setfillstyle(SOLID_FILL,LIGHTGRAY);
    floodfill(395,100,LIGHTGRAY);

    setcolor(DARKGRAY);                //A&B_之间的按键区
    rectangle(160,80,270,400);
    setfillstyle(SOLID_FILL,DARKGRAY);
    floodfill(200,100,DARKGRAY);

    setcolor(LIGHTGRAY);
    rectangle(50+220*0,80,160+220*0,400);
    setfillstyle(SOLID_FILL,LIGHTGRAY);    //A部分
    floodfill(100+220*0,100,LIGHTGRAY);

    setcolor(LIGHTGRAY);
    rectangle(50+220*1,80,160+220*1,400);
    setfillstyle(SOLID_FILL,LIGHTGRAY);    //B部分
    floodfill(100+220*1,100,LIGHTGRAY);
}

void pic2( int *ce)//画外部电梯框架
{
    int i;
    int a[] = {135,115,135,395,145,387,145,107,135,115};      //楼层侧面的大平行四边形个点坐标
    int b[] = {355,215,355,395,365,387,365,107,355,115};

    setcolor(BLUE);
    setfillstyle(SOLID_FILL,LIGHTGRAY);
    for(i=0;i<8;i++)       //画楼层
    {
        bar3d(65+220*0,360-35*i,135+220*0,395-35*i,10,1);   //A梯楼层
        bar3d(65+220*1,360-35*i,135+220*1,395-35*i,10,1);   //B梯楼层
    }
    for(i=360; i<=359+35; i++)
    {
        setcolor(DARKGRAY);
        line(66,i,134,i);
        line(66+220,i,134+220,i);
    }

    if(*ce == EN)
    {
        setcolor(BROWN);
        settextstyle(3,0,1);
        outtextxy(60,405,"elevator A");
        outtextxy(280,405,"elevator B");
        outtextxy(405,60,"inside of the elevator A");
        outtextxy(405,210,"inside of tne elevator B");
        settextstyle(1,0,2);
        outtextxy(55,30,"External simulation system");
    }
    else if(*ce == CN)
    {
        hanhuaxy(60,405,"电梯一",1,BROWN);
        hanhuaxy(280,405,"电梯二",1,BROWN);
        hanhuaxy(55,30,"外部电梯系统",1,BROWN);
    }

    setcolor(BLUE);
    drawpoly(5,a);         //画平行四边形
    drawpoly(5,b);
    setfillstyle(SOLID_FILL,DARKGRAY);           //填充平行四边形
    fillpoly(5,a);
    fillpoly(5,b);
   }


void pic3( int *ce)   //AB电梯内部视图
{
    int i;
    int a_int1[12],a_int2[11],a_int3[11],a_int4[11],a_int5[11],a_int6[11];
    int b_int1[11],b_int2[11],b_int3[11],b_int4[11],b_int5[11],b_int6[11];
    int a_in1[] = {480,90,480,150,430,180,430,120,480,90};
    int a_in2[] = {480,150,430,180,520,180,570,150,480,150};
    int a_in3[] = {484,134,484,141,488,138,484,134};
    int a_in4[] = {494,134,494,141,488,138,494,134};
    int a_in5[] = {503,134,503,141,499,138,503,134};
    int a_in6[] = {503,134,503,141,507,138,503,134};

    int b_in1[] = {480,240,480,300,430,330,430,270,480,240};
    int b_in2[] = {480,300,430,330,520,330,570,300,480,300};
    int b_in3[] = {484,284,484,291,488,288,484,284};
    int b_in4[] = {494,284,494,291,488,288,494,284};
    int b_in5[] = {503,284,503,291,499,288,503,284};
    int b_in6[] = {503,284,503,291,507,288,503,284};

    rectangle(480,90+150*0,570,150+150*0); //A梯内部正面
    rectangle(480,90+150*1,570,150+150*1); //B梯内部正面
    if(*ce == EN)
    {
        settextstyle(3,0,1);
        outtextxy(405,60,"inside of the elevator A");
        outtextxy(405,210,"inside of tne elevator B");
    }
    else if(*ce == CN)
    {
        hanhuaxy(405,60,"电梯A内部",1,BROWN);
        hanhuaxy(405,210,"电梯B内部",1,BROWN);
    }

    drawpoly(5,a_in1);                     //A梯边界四边形1
    drawpoly(5,a_in2);                     //B梯边界四边形2


    drawpoly(5,b_in1);                     //A梯边界四边形1
    drawpoly(5,b_in2);                     //B梯边界四边形2

    setfillstyle(SOLID_FILL,BLACK);
    rectangle(485,93+150*0,510,123+150*0);        //A显示屏
    rectangle(485,93+150*1,510,123+150*1);        //B显示屏
    floodfill(486,94+150*0,BLUE);
    floodfill(486,94+150*1,BLUE);

    setcolor(BLUE);
    for(i=0;i<4;i++)                       //A选层按键
    {
        circle(460,116+150*0+12*i,5);
        circle(472,109+150*0+12*i,5);
    }

    for(i=0;i<4;i++)                       //B选层按键
    {
        circle(460,116+150*1+12*i,5);
        circle(472,109+150*1+12*i,5);
    }

    settextstyle(0,0,1);
    outtextxy(457,113+150*0,"1");                //A选层按键标记
    outtextxy(457,125+150*0,"2");
    outtextxy(457,137+150*0,"3");
    outtextxy(457,149+150*0,"4");
    outtextxy(469,106+150*0,"5");
    outtextxy(469,118+150*0,"6");
    outtextxy(469,130+150*0,"7");
    outtextxy(469,142+150*0,"8");

    outtextxy(457,113+150*1,"1");                //B选层按键标记
    outtextxy(457,125+150*1,"2");
    outtextxy(457,137+150*1,"3");
    outtextxy(457,149+150*1,"4");
    outtextxy(469,106+150*1,"5");
    outtextxy(469,118+150*1,"6");
    outtextxy(469,130+150*1,"7");
    outtextxy(469,142+150*1,"8");

    setcolor(RED);
    //circle(440,127+150*0,8);                    //A紧急按键
    circle(440,145+150*0,8);                    //A出门键
    //circle(440,163+150*0,8);                    //A进门按键

    //circle(440,127+150*1,8);                    //B紧急按键
    circle(440,145+150*1,8);                    //B出门键
    //circle(440,163+150*1,8);                    //B进门按键

    setcolor(BLACK);
    //outtextxy(437,160+150*0,"I");               //A进门按键标记
    outtextxy(437,142+150*0,"!");               //A出门按键标记
    //outtextxy(437,124+150*0,"!");               //A紧急按键标记

    //outtextxy(437,160+150*1,"I");               //B进门按键标记
    outtextxy(437,142+150*1,"!");               //B出门按键标记
    //outtextxy(437,124+150*1,"!");               //B紧急按键标记

    setfillstyle(SOLID_FILL,LIGHTGRAY);
    setcolor(BLUE);
    bar3d(483,130+150*0,493,145+150*0,2,1);          //A门控按键关门
    bar3d(498,130+150*0,508,145+150*0,2,1);          //A门控按键开门
    line(488,132+150*0,488,143+150*0);               //A关门按键标记

    bar3d(483,130+150*1,493,145+150*1,2,1);          //B门控按键关门
    bar3d(498,130+150*1,508,145+150*1,2,1);          //B门控按键开门
    line(488,132+150*1,488,143+150*1);               //B关门按键标记

    drawpoly(4,a_in3);
    drawpoly(4,a_in4);
    line(503,132,503,143);               //A门按键标记
    drawpoly(4,a_in5);
    drawpoly(4,a_in6);

    drawpoly(4,b_in3);
    drawpoly(4,b_in4);
    line(503,282,503,293);             //B门按键标记
    drawpoly(4,b_in5);
    drawpoly(4,b_in6);

    setfillstyle(SOLID_FILL,LIGHTGRAY);         //画门框
    bar(515,90+150*0,570,95+150*0);
    bar(515,95+150*0,520,150+150*0);
    bar(566,95+150*0,570,150+150*0);

    bar(515,90+150*1,570,95+150*1);
    bar(515,95+150*1,520,150+150*1);
    bar(566,95+150*1,570,150+150*1);

    setcolor(BLUE);
    line(515,90+150*0,515,150+150*0);
    line(515,90+150*1,515,150+150*1);
    rectangle(480,90+150*0,570,150+150*0); //重画内部正面图
    rectangle(480,90+150*1,570,150+150*1);

    rectangle(520,95+150*0,566,150+150*0); //画电梯门
    rectangle(520,95+150*1,566,150+150*1);

    setfillstyle(SOLID_FILL,DARKGRAY);   //填充电梯门
    floodfill(530,110+150*0,BLUE);
    floodfill(530,110+150*1,BLUE);

    setcolor(BLACK);
    line(543,96+150*0,543,149+150*0);
    line(543,96+150*1,543,149+150*1);
}


void pic4()//画按钮区
{
    int i;
    setcolor(LIGHTGRAY);//画第1层按钮与显示屏
    setfillstyle(SOLID_FILL,LIGHTGRAY);//画按钮
    bar3d(207,400-35*1,219,418-35*1,2,1);

    setcolor(DARKGRAY);//画三角形
    line(213,406-35*1,210,412-35*1);
    line(213,406-35*1,216,412-35*1);
    line(210,412-35*1,216,412-35*1);
    setfillstyle(SOLID_FILL,DARKGRAY);
    floodfill(213,410-35*1,DARKGRAY);

    setcolor(LIGHTGRAY);//画显示屏
    setfillstyle(SOLID_FILL,BLACK);
    rectangle(235,395-35*1,265,420-35*1);
    rectangle(165,395-35*1,195,420-35*1);
    floodfill(236,396-35*1,LIGHTGRAY);
    floodfill(166,396-35*1,LIGHTGRAY);

    for(i=2;i<8;i++)   //画外部第2至第7层的按钮和显示屏
    {
        setcolor(LIGHTGRAY);//画按钮
        setfillstyle(SOLID_FILL,LIGHTGRAY);
        bar3d(200,400-35*i,212,418-35*i,2,1);
        bar3d(215,400-35*i,227,418-35*i,2,1);

        setcolor(DARKGRAY);//画按钮中心的三角形
        line(206,406-35*i,203,412-35*i);
        line(206,406-35*i,209,412-35*i);
        line(203,412-35*i,209,412-35*i);
        line(218,406-35*i,224,406-35*i);
        line(218,406-35*i,221,412-35*i);
        line(224,406-35*i,221,412-35*i);
        setfillstyle(SOLID_FILL,DARKGRAY);
        floodfill(206,409-35*i,DARKGRAY);
        floodfill(221,409-35*i,DARKGRAY);

        setcolor(LIGHTGRAY);//画显示屏
        setfillstyle(SOLID_FILL,BLACK);
        rectangle(235,395-35*i,265,420-35*i);
        rectangle(165,395-35*i,195,420-35*i);
        floodfill(236,396-35*i,LIGHTGRAY);
        floodfill(166,396-35*i,LIGHTGRAY);
    }

    setcolor(LIGHTGRAY);                      //画外部第8层的按钮和显示屏
    setfillstyle(SOLID_FILL,LIGHTGRAY);       //画按钮
    bar3d(207,400-35*8,219,418-35*8,2,1);

    setcolor(DARKGRAY);   //画按钮中心的三角形
    line(210,406-35*8,216,406-35*8);
    line(210,406-35*8,213,412-35*8);
    line(216,406-35*8,213,412-35*8);
    setfillstyle(SOLID_FILL,DARKGRAY);
    floodfill(213,409-35*8,DARKGRAY);

    setcolor(LIGHTGRAY); //画显示屏
    rectangle(235,395-35*8,265,420-35*8);
    rectangle(165,395-35*8,195,420-35*8);
    setfillstyle(SOLID_FILL,BLACK);
    floodfill(236,396-35*8,LIGHTGRAY);
    floodfill(166,396-35*8,LIGHTGRAY);

}

void pic5( int *ce)//画下方的三个按钮
{
    setfillstyle(SOLID_FILL,LIGHTGRAY);
    bar3d(565,430,610,450,3,1);
    bar3d(515,430,560,450,3,1);
    bar3d(465,430,510,450,3,1);
    floodfill(566,431,LIGHTGRAY);
    floodfill(516,431,LIGHTGRAY);
    floodfill(466,431,LIGHTGRAY);
    if(*ce == EN)
    {
        setcolor(RED);
        settextstyle(0,0,1);
        outtextxy(570,436,"EN/CN");
        outtextxy(520,436,"BACK");
        outtextxy(470,436,"HELP");
    }
    else if(*ce == CN)
    {
        hanhuaxy(470,433,"帮助",1,RED);
        hanhuaxy(520,433,"后退",1,RED);
        hanhuaxy(570,433,"中英",1,RED);
    }
}


/*************************Founction***********************************/
//Name: help_index                                                   //
//Remarks: void help_index(int *ce)                                  //
//feature: 帮助主界面绘制（具体解析见报告）                               //
/*********************************************************************/
void help_index( int *ce)
{
    settextjustify(0,2);
    setwritemode(COPY_PUT);
    setbkcolor(GREEN);
    setcolor(YELLOW);

    rectangle(15,15,620,465);
    rectangle(12,12,623,468);

    rectangle(55,195,177,220);//使用指南图框
    rectangle(53,193,179,222);

    rectangle(55,265,177,290);//系统简介图框
    rectangle(53,263,179,292);

    rectangle(55,335,177,360);//关于我们图框
    rectangle(53,333,179,362);

    rectangle(200,80,580,420);//内容图框
    rectangle(198,78,582,422);

    rectangle(515,430,560,450);//后退图框
    rectangle(513,428,562,452);

    rectangle(565,430,610,450);//中英文切换图框
    rectangle(563,428,612,452);


    ellipse(95,85,0,360,60,40);
    ellipse(95,85,0,360,62,42);

    if(*ce == EN)
    {
        settextstyle(0,0,3);
    outtextxy(50,75,"Help");
        settextstyle(0,0,1);
        outtextxy(80,205,"How to use");
        outtextxy(85,275,"System");
        outtextxy(80,345,"About us");
        outtextxy(520,437,"BACK");
        outtextxy(570,437,"EN/CN");
    }

    else if(*ce == CN)
    {
        hanhuaxy(60,70,"帮",2,YELLOW);
    hanhuaxy(100,70,"助",2,YELLOW);
        hanhuaxy(80,200,"使用说明",1,YELLOW);
        hanhuaxy(80,270,"软件简介",1,YELLOW);
        hanhuaxy(80,340,"关于我们",1,YELLOW);
        hanhuaxy(520,433,"后退",1,YELLOW);
        hanhuaxy(570,433,"中英",1,YELLOW);
    }
}

/*************************Founction***********************************/
//Name: help_guide                                                   //
//Remarks: void help_guide(int *ce)                                  //
//feature: 使用指南绘制（具体解析见报告）                                 //
/*********************************************************************/
void help_guide( int *ce)
{
    if(*ce == EN)
    {
        settextstyle(0,0,3);
        outtextxy(300,120,"Guide");
        settextstyle(0,0,1);
        outtextxy(240,180,"The system is just similar with normal");
        outtextxy(220,200,"lift. And it is buttoned by click mouse.");
        outtextxy(240,220,"What needs to notice is that in order");
        outtextxy(220,240,"to perform the scene of overweight,");
        outtextxy(220,260,"everyone comes in must button the coming");
        outtextxy(220,280,"button.The out door is just similar.");
        outtextxy(240,320,"Best Wishes!");
    }

    if(*ce == CN)
    {
        hanhuaxy(310,120,"使",2,YELLOW);
        hanhuaxy(350,120,"用",2,YELLOW);
        hanhuaxy(390,120,"指",2,YELLOW);
        hanhuaxy(430,120,"南",2,YELLOW);
        hanhuaxy(240,180,"本电梯仿真系统使用方法与常见的电",1,YELLOW);
        hanhuaxy(220,200,"梯基本相似，通过鼠标的左键点击来象",1,YELLOW);
        hanhuaxy(220,220,"征按下，需要特别注意的是：",1,YELLOW);
        hanhuaxy(240,240,"为了仿真模拟超重报警，本软件需每",1,YELLOW);
        hanhuaxy(220,260,"位乘客进入轿厢时，点击左侧的进入键，",1,YELLOW);
        hanhuaxy(220,280,"页面显示一个笑脸象征有一个乘客进入",1,YELLOW);
        hanhuaxy(220,300,"出门操作类似。",1,YELLOW);
        hanhuaxy(240,330,"祝您使用愉快！",1,YELLOW);
    }

}

/*************************Founction***********************************/
//Name: help_sys                                                     //
//Remarks: void help_sys(int *ce)                                    //
//feature: 系统简介绘制（具体解析见报告）                                 //
/*********************************************************************/
void help_sys( int *ce)
{
    if(*ce == EN)
    {
        settextstyle(0,0,3);
        outtextxy(300,120,"System");
        settextstyle(0,0,1);
        outtextxy(240,180,"The system mainly gets the info of button");
        outtextxy(220,200,"lift and deal the info.");
        outtextxy(240,220,"Then it will be used to control the door");
        outtextxy(220,240,"op[1]ening and the lift moving.");
        outtextxy(240,300,"Best Wishes!");
    }

    if(*ce == CN)
    {

        hanhuaxy(310,120,"系",2,YELLOW);
        hanhuaxy(350,120,"统",2,YELLOW);
        hanhuaxy(390,120,"简",2,YELLOW);
        hanhuaxy(430,120,"介",2,YELLOW);
        hanhuaxy(240,180,"本电梯仿真系统主要是对于电梯呼梯",1,YELLOW);
        hanhuaxy(220,200,"信号的采集与处理，并将相应的处理结",1,YELLOW);
        hanhuaxy(220,220,"果，通过轿厢和门的动画体现出来。",1,YELLOW);
        hanhuaxy(240,240,"本仿真系统的算法是基于相应时间最",1,YELLOW);
        hanhuaxy(220,260,"短这个基本的准则设计而成。",1,YELLOW);
        hanhuaxy(240,280,"系统运行基本稳定，符合智能要求。",1,YELLOW);
        hanhuaxy(240,320,"祝您使用愉快！",1,YELLOW);
    }

}

/*************************Founction***********************************/
//Name: help_us                                                      //
//Remarks: void help_us(int *ce)                                     //
//feature: 关于我们绘制（具体解析见报告）                                 //
/*********************************************************************/
void help_us( int *ce)
{
    if(*ce == EN)
    {
        settextstyle(0,0,3);
        outtextxy(300,120,"About Us");
        settextstyle(0,0,1);
        outtextxy(240,200,"the smater lift system is finished in");
        outtextxy(220,220,"one month.");
        outtextxy(240,240,"Name of editors:");
        outtextxy(240,260,"Feng Zhao,Pengcheng Yang");
        outtextxy(240,280,"Please connect us,if you need any help:");
    outtextxy(240,300,"Email:");
    }

    if(*ce == CN)
    {
        hanhuaxy(310,120,"关",2,YELLOW);
        hanhuaxy(350,120,"于",2,YELLOW);
        hanhuaxy(390,120,"我",2,YELLOW);
        hanhuaxy(430,120,"们",2,YELLOW);
        hanhuaxy(240,200,"本智能双电梯仿真系统历时一个月",1,YELLOW);
        hanhuaxy(220,220,"编写而成。",1,YELLOW);
        hanhuaxy(240,240,"编者姓名：",1,YELLOW);
        hanhuaxy(240,260,"赵峰、杨鹏程",1,YELLOW);
        hanhuaxy(240,280,"如果您需要帮助，请联系我们",1,YELLOW);
        hanhuaxy(240,300,"邮箱",1,YELLOW);
    }
    outtextxy(240,320,"fengyecl@hust.edu.cn");
}

