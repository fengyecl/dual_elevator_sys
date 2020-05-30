/****************************************************************/
/*    COPYRIGHT NOTICE                                          */
/*    Copyright (c) 2012,   智能双电梯仿真系统（C语言版）            */
/*    All rights reserved.                                      */
/*                                                              */
/*    @file door.c                                              */
/*    @brief intro:                                             */
/*                open and close door                           */
/*                                                              */
/*    @version final                                            */
/*    @author fengyecl                                          */
/*    @date 2012年10月8日                                        */
/*                                                              */
/*     修订说明：最初版本                                          */
/****************************************************************/
#include<graphics.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include"door.h"

void door( struct Lift *lift, int i, int *button_out, int *man)
{
    int man_flag;
    int *p,q;
    
    man_flag = (*man);
    p = &( (*lift).door_line );

/********************第一次进入door()函数后的操作*************************/
    if( (*p) == 542)                            
    {        
        (*lift).mov_state[0] = (*lift).mov_state[1];    //运动趋势存储    
        (*lift).mov_state[1] = STAY;                    //运动状态改变为停止
        (*lift).door_flag = 0;
        (*lift).door_call = NONE;
        /*
        sound(1500); //电梯门开门声音
        delay(50);
        nosound();
        */

        randomize();                         //模拟进出电梯人数
        while( (*man) == man_flag )
        {
            (*man) = random(10);
        }
    }


    setwritemode(COPY_PUT);

    if( (*lift).door_state == CLOSE)       //电梯门打开
    {
        q = 543 + ( 543-(*p) );
        setcolor(BLACK);
        line( (*p), 96+150*i, (*p), 149+150*i);
        line( q, 96+150*i, q, 149+150*i);
        (*p)--;
        delay(40);

    /******判断条件，是否改变状态为关闭电梯门*****/
        if((*lift).door_call == CLOSE)
        {
            (*lift).door_state = OPEN;
            (*lift).door_call = NONE;
        }

        if( (*p) == 520)
        {
            (*lift).door_state = OPEN;
        }

    }

    if((*lift).door_state == OPEN)              //电梯门关闭
    {
        setcolor(DARKGRAY);
        (*p)++;
        q = 543 + ( 543-(*p) );
        line( (*p), 95+150*i, (*p), 149+150*i);
        line( q, 95+150*i, q, 149+150*i);
        delay(40);

        /********判断条件，是否改变状态为打开电梯门*****/
        if((*lift).door_call == OPEN)
        {
            (*lift).door_state = CLOSE;
            (*lift).door_call = NONE;
        }
        if( (*p) == 542)
        {
            (*lift).door_state = CLOSE;
        }
    }

/***************最后一次离开door()函数后的操作******************/
    if( (*p) == 542 )
    {
        (*lift).callup[ (*lift).flo_state ] = 0;//本层请求置零
        (*lift).calldown[ (*lift).flo_state ] = 0;//本层请求置零
        (*lift).callup[MAX] = 0;
        (*lift).callup[MIN] = 0;
        (*lift).calldown[MAX] = 0;
        (*lift).calldown[MIN] = 0;
        (*lift).door_flag = 1;

        /********门关闭后，本层所有按钮置零***********/
        (*lift).button_in[(*lift).flo_state] = 0;

        if((*lift).flo_state == 1)
        {
            button_out[1] = 0;
        }
        if( ( (*lift).flo_state>=2 ) && ( (*lift).flo_state<=7 ) )
        {
            button_out[(*lift).flo_state] = 0;
            button_out[((*lift).flo_state+6)] = 0;
        }
        if((*lift).flo_state == 8)
        {
            button_out[14] = 0;
        }
    }
}