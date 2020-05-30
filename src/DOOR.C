/****************************************************************/
/*    COPYRIGHT NOTICE                                          */
/*    Copyright (c) 2012,   ����˫���ݷ���ϵͳ��C���԰棩            */
/*    All rights reserved.                                      */
/*                                                              */
/*    @file door.c                                              */
/*    @brief intro:                                             */
/*                open and close door                           */
/*                                                              */
/*    @version final                                            */
/*    @author fengyecl                                          */
/*    @date 2012��10��8��                                        */
/*                                                              */
/*     �޶�˵��������汾                                          */
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

/********************��һ�ν���door()������Ĳ���*************************/
    if( (*p) == 542)                            
    {        
        (*lift).mov_state[0] = (*lift).mov_state[1];    //�˶����ƴ洢    
        (*lift).mov_state[1] = STAY;                    //�˶�״̬�ı�Ϊֹͣ
        (*lift).door_flag = 0;
        (*lift).door_call = NONE;
        /*
        sound(1500); //�����ſ�������
        delay(50);
        nosound();
        */

        randomize();                         //ģ�������������
        while( (*man) == man_flag )
        {
            (*man) = random(10);
        }
    }


    setwritemode(COPY_PUT);

    if( (*lift).door_state == CLOSE)       //�����Ŵ�
    {
        q = 543 + ( 543-(*p) );
        setcolor(BLACK);
        line( (*p), 96+150*i, (*p), 149+150*i);
        line( q, 96+150*i, q, 149+150*i);
        (*p)--;
        delay(40);

    /******�ж��������Ƿ�ı�״̬Ϊ�رյ�����*****/
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

    if((*lift).door_state == OPEN)              //�����Źر�
    {
        setcolor(DARKGRAY);
        (*p)++;
        q = 543 + ( 543-(*p) );
        line( (*p), 95+150*i, (*p), 149+150*i);
        line( q, 95+150*i, q, 149+150*i);
        delay(40);

        /********�ж��������Ƿ�ı�״̬Ϊ�򿪵�����*****/
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

/***************���һ���뿪door()������Ĳ���******************/
    if( (*p) == 542 )
    {
        (*lift).callup[ (*lift).flo_state ] = 0;//������������
        (*lift).calldown[ (*lift).flo_state ] = 0;//������������
        (*lift).callup[MAX] = 0;
        (*lift).callup[MIN] = 0;
        (*lift).calldown[MAX] = 0;
        (*lift).calldown[MIN] = 0;
        (*lift).door_flag = 1;

        /********�Źرպ󣬱������а�ť����***********/
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