/****************************************************************************/
/*    COPYRIGHT NOTICE                                                      */
/*    Copyright (c) 2012,   智能双电梯仿真系统（C语言版）                       */
/*    All rights reserved.                                                  */
/*                                                                          */
/*    @file display.c                                                       */
/*    @brief intro:                                                         */
/*                 contains the founctions used to draw screen and button   */   
/*    @version final                                                        */
/*    @author fengyecl                                                      */
/*    @date 2012年10月10日                                                   */
/*                                                                          */
/*    修订说明：最初版本                                                       */
/****************************************************************************/
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<process.h>
#include<dos.h>
#include<stdlib.h>
#include<time.h>
#include "display.h"

/*************************Founction************************************/
//Name:dis_button_in                                                  //   
//Remarks: void dis_button_in(int button_in[9], int lift)             //
//feature: 电梯内部按钮显示（具体解析见报告）                               //
/**********************************************************************/
void dis_button_in( int button_in[9], int lift)
{
    int i = lift;
    int j;
    for(j=1; j<=8; j++)
    {
        if(button_in[j] == ON)
        {
            setcolor(RED);
        }
        else
        {
            setcolor(BLUE);                
        }
            
        if(j >= 1 && j <= 4)
        {
            circle(460, 104+150*i+12*j, 5);
            }
        if(j >= 5 && j <= 8)
        {
            circle(472, 97+150*i+12*(j-4), 5);
        }
        settextstyle(0,0,1);
        if(j == 1)
        {
            outtextxy(457, 113+150*i, "1");  
        }
        if(j == 2)
        {
            outtextxy(457, 125+150*i, "2");
        }
        if(j == 3)
        {
            outtextxy(457, 137+150*i, "3");
        }
        if(j == 4)
        {
            outtextxy(457, 149+150*i, "4");
        }
        if(j == 5)
        {
            outtextxy(469, 106+150*i, "5");
        }
        if(j == 6)
        {
            outtextxy(469,118+150*i,"6");
        }
        if(j == 7)
        {
            outtextxy(469, 130+150*i, "7");
        }
        if(j == 8)
        {
            outtextxy(469, 142+150*i, "8");
        }
    }
        
}

/*************************Founction*************************************/
//Name:dis_button_out                                                  //   
//Remarks: void dis_button_out(int button_out[15])                     //
//feature: 电梯外部按钮显示（具体解析见报告）                                //
/***********************************************************************/ 
 
void dis_button_out( int button_out[15])
 {
    int i;
    int tri[9];
    for(i = 1; i <= 14; i++)
    {
        if(button_out[i] == ON)
        {
            setcolor(BROWN);
            setfillstyle(SOLID_FILL, RED);    
        }
        else if(button_out[i] == OFF)
        {
            setcolor(DARKGRAY);
            setfillstyle(SOLID_FILL,DARKGRAY);
        }
        
        if(i == 1)
        {
            tri[0] = 213;
            tri[1] = 406-35*1;
            tri[2] = 210;
            tri[3] = 412-35*1;
            tri[4] = 216;
            tri[5] = 412-35*1;
            tri[6] = 213;
            tri[7] = 406-35*1;

            fillpoly(3,tri);
        }
        else if(i >= 2 && i <= 7)
        {    
            tri[0] = 206;
            tri[1] = 406-35*i;
            tri[2] = 203;
            tri[3] = 412-35*i;
            tri[4] = 209;
            tri[5] = 412-35*i;
            tri[6] = 206;
            tri[7] = 406-35*i;
            
            fillpoly(3,tri);            
        }
    
        else if(i >= 8&&i <= 13)
        {

            tri[0] = 218;
            tri[1] = 406-35*(i-6);
            tri[2] = 224;
            tri[3] = 406-35*(i-6);
            tri[4] = 221;
            tri[5] = 412-35*(i-6);
            tri[6] = 218;
            tri[7] = 406-35*(i-6);
            
            fillpoly(3,tri);
        }
        else if(i == 14)
        {
            tri[0] = 210;
            tri[1] = 406-35*8;
            tri[2] = 216;
            tri[3] = 406-35*8;
            tri[4] = 213;
            tri[5] = 412-35*8;
            tri[6] = 210;
            tri[7] = 406-35*8;
            
            fillpoly(3,tri);            
        }
    }
    
 }

/*************************Founction***********************************/
//Name: dis_number                                                   //   
//Remarks: void dis_number(int flo_state, int lift)                  //
//feature: 电梯内外显示屏中的显示（具体解析见报告）                         //
/*********************************************************************/
void dis_screen( int flo_state, int mov_state, int lift)
{
    dis_number(flo_state, lift);
    dis_arrow(mov_state, lift);
}


void dis_number( int flo_state, int lift)
{
    int i;
    setwritemode(COPY_PUT);
    setcolor(RED);
    switch(flo_state)
    {
        case 0:
        {
            for(i=1; i<9; i++)
            {
                clean_out_num(lift, i);
                //outtextxy(171+70*lift, 370-35*(i-1), "!");
            }
            clean_in_num(lift);
            //outtextxy(490, 100+150*lift, "!");
            break;
        }
        case 1:
        {
            for(i=1; i<9; i++)
            {
                clean_out_num(lift, i);
                outtextxy(171+70*lift, 370-35*(i-1), "1");
            }
            clean_in_num(lift);
            outtextxy(490, 100+150*lift, "1");
            break;
        }
        case 2:
        {
            for(i=1; i<9; i++)
            {
                clean_out_num(lift,i);
                outtextxy(171+70*lift, 370-35*(i-1), "2");
            }
            clean_in_num(lift);
            outtextxy(490, 100+150*lift, "2");
            break;
        }
        case 3:
        {
            for(i=1; i<9; i++)
            {
                clean_out_num(lift,i);
                outtextxy(171+70*lift, 370-35*(i-1), "3");
            }
            clean_in_num(lift);
            outtextxy(490, 100+150*lift, "3");
            break;
        }
        case 4:
        {
            for(i=1; i<9; i++)
            {
                clean_out_num(lift,i);
                outtextxy(171+70*lift, 370-35*(i-1), "4");
            }
            clean_in_num(lift);
            outtextxy(490, 100+150*lift, "4");
            break;
        }
        case 5:
        {
            for(i=1; i<9; i++)
            {
                clean_out_num(lift,i);
                outtextxy(171+70*lift, 370-35*(i-1), "5");
            }
            clean_in_num(lift);
            outtextxy(490, 100+150*lift, "5");
            break;
        }
        case 6:
        {
            for(i=1; i<9; i++)
            {
                clean_out_num(lift,i);
                outtextxy(171+70*lift, 370-35*(i-1), "6");
            }
            clean_in_num(lift);
            outtextxy(490, 100+150*lift, "6");
            break;
        }
        case 7:
        {
            for(i=1; i<9; i++)
            {
                clean_out_num(lift,i);
                outtextxy(171+70*lift, 370-35*(i-1), "7");
            }
            clean_in_num(lift);
            outtextxy(490, 100+150*lift, "7");
            break;
        }
        case 8:
        {
            for(i=1; i<9; i++)
            {
                clean_out_num(lift, i);
                outtextxy(171+70*lift, 370-35*(i-1), "8");
            }
            clean_in_num(lift);
            outtextxy(490, 100+150*lift, "8");
            break;
        
        }
    }
}


void dis_arrow( int mov_state, int lift)
{
    int floor=1;
    setcolor(RED);
    setwritemode(COPY_PUT);
    setlinestyle(0,0,1);
/****************电梯外部显示屏中方向箭头修改**************************/
    for(floor=1; floor<=8; floor++)
    {
        clean_out_arrow(lift,floor);        
        if(mov_state == UP)
        {
            line(187+70*lift,375-35*(floor-1),187+70*lift,366-35*(floor-1));//lift表示电梯A或B，55为其电梯外部显示频x坐标间距；
            line(187+70*lift,366-35*(floor-1),183+70*lift,372-35*(floor-1));//floor表示楼层，35为楼层y坐标间距
            line(187+70*lift,366-35*(floor-1),191+70*lift,372-35*(floor-1));
                        
        }
        else if(mov_state == DOWN)
        {
            line(187+70*lift,366-35*(floor-1),187+70*lift,375-35*(floor-1));
            line(187+70*lift,375-35*(floor-1),183+70*lift,368-35*(floor-1));
            line(187+70*lift,375-35*(floor-1),191+70*lift,368-35*(floor-1));

        }
    }
/****************电梯内部显示屏中方向箭头修改**************************/    
    clean_in_arrow(lift);
    if(mov_state == UP)
    {
        line(505,107+150*lift,505,98+150*lift);
        line(505,98+150*lift,501,104+150*lift);
        line(505,98+150*lift,509,104+150*lift);
    }
    else if(mov_state == DOWN)
    {
        line(505,107+150*lift,505,98+150*lift);
        line(505,107+150*lift,501,101+150*lift);
        line(505,107+150*lift,509,101+150*lift);
    }
            
}

void clean_out_num( int lift, int i)//清除电梯外显示屏数字
{
    setfillstyle(SOLID_FILL,BLACK);
    bar(166+70*lift,365-35*(i-1),179+70*lift,383-35*(i-1));
}


void clean_in_num( int lift)//清除电梯显示屏数字
{
    setfillstyle(SOLID_FILL,BLACK);
    bar(486,94+150*lift,496,106+150*lift);
}


void clean_out_arrow( int lift, int i)//清除电梯外显示屏的箭头
{
    setfillstyle(SOLID_FILL,BLACK);
    bar(181+70*lift,381-35*(i-1),194+70*lift,362-35*(i-1));
}


void clean_in_arrow( int lift)//清除电梯内显示屏的箭头
{
    setfillstyle(SOLID_FILL,BLACK);
    bar(498,98+150*lift,509,110+150*lift);
}
/*************************Founction***********************************/
//Name: person                                                       //   
//Remarks: void person(int lift_ab,int *man_a,int *man_b)            //
//feature: 电梯内人员增减显示（具体解析见报告）                            //
/*********************************************************************/

void dis_person( int m, int n)
{
        int i;

        int a[] = {480,150,430,180,520,180,570,150,480,150};
        int b[] = {480,300,430,330,520,330,570,300,480,300};
    
        setfillstyle(1,GREEN);//将电梯里的人抹去
        setcolor(BLUE);
        
        if(m == A)
        {
            fillpoly(5,a);
        }
        else if(m == B)
        {
            fillpoly(5,b);
        }
        setcolor(BROWN);
        if(n<6)//重画人
        {
            for(i=0; i<n; i++)
            {                
                rectangle(480+14*i,152+150*m,490+14*i,164+150*m);
                line(481+14*i,157+150*m,483+14*i,154+150*m);
                line(485+14*i,157+150*m,487+14*i,154+150*m);
                line(485+14*i,162+150*m,487+14*i,159+150*m);
                line(483+14*i,154+150*m,485+14*i,157+150*m);
                line(487+14*i,154+150*m,489+14*i,157+150*m);
                line(483+14*i,159+150*m,485+14*i,162+150*m);
            }
        }
        else if( n>=6 && n<10)
        {
            for(i=0; i<5; i++)
            {                
                rectangle(480+14*i,152+150*m,490+14*i,164+150*m);
                line(481+14*i,157+150*m,483+14*i,154+150*m);
                line(485+14*i,157+150*m,487+14*i,154+150*m);
                line(485+14*i,162+150*m,487+14*i,159+150*m);
                line(483+14*i,154+150*m,485+14*i,157+150*m);
                line(487+14*i,154+150*m,489+14*i,157+150*m);
                line(483+14*i,159+150*m,485+14*i,162+150*m);
            }
            for(i=5;i<n;i++)
            {
                rectangle(454+14*(i-5),166+150*m,464+14*(i-5),178+150*m);
                line(457+14*(i-5),178+150*m,457+14*(i-5),173+150*m);
                line(461+14*(i-5),178+150*m,461+14*(i-5),173+150*m);
                line(457+14*(i-5),173+150*m,461+14*(i-5),173+150*m);
                line(455+14*(i-5),172+150*m,458+14*(i-5),168+150*m);
                line(463+14*(i-5),172+150*m,460+14*(i-5),168+150*m);
            }
        }
}