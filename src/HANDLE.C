/****************************************************************/
/*    COPYRIGHT NOTICE                                          */
/*    Copyright (c) 2012,   智能双电梯仿真系统（C语言版）            */
/*    All rights reserved.                                      */
/*                                                              */
/*    @file handle.c                                            */
/*    @brief intro:                                             */
/*                information handling including：Change        */ 
/*                between pages，distribute the corresponding   */
/*                collect_page founction                        */
/*    @version final                                            */
/*    @author fengyecl                                          */
/*    @date 2012年10月3 日                                       */
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
#include"handle.h"

/*************************Founction*************************************************/
//Name: page_mode                                                                  //
//Remarks: void page_mode(int op[2],int *ce)                                       //
//feature: 实现页面切换（欢迎界面，主界面，帮助界面，各个界面上中英文切换）                   //
/***********************************************************************************/
void page_mode( int op[2], int *ce, int *mouseX, int *mouseY, int *button)
{
    cleardevice();
    switch(op[1])
    {
        case MODE0://中英文切换
        {
               *ce = !(*ce);
               op[1] = op[0];
               delay(100);
               break;
        }
        case MODE1://进入欢迎界面
        {
               fore(ce);
               collect_page(1,op,mouseX,mouseY,button);
               break;
        }
        case MODE2://进入主界面
        {

               major(ce);
               control(op,ce,mouseX,mouseY,button);
               break;
        }
        case MODE3://进入帮助界面
        {
               help_index(ce);
               collect_page(3,op,mouseX,mouseY,button);
               break;
        }
        case MODE4://退出程序
        {
               quit();
               //delay(60);
               break;
        }
        case MODE5://帮助界面中使用指南
        {
               help_index(ce);
               help_guide(ce);
               collect_page(3,op,mouseX,mouseY,button);
               break;
        }
        case MODE6://帮助界面中系统简介
        {
            help_index(ce);
            help_sys(ce);
            collect_page(3,op,mouseX,mouseY,button);
            break;
        }
        case MODE7://帮助界面中关于我们
        {
            help_index(ce);
            help_us(ce);
            collect_page(3,op,mouseX,mouseY,button);
            break;
        }

    }
    page_mode(op,ce,mouseX,mouseY,button);

}
/*************************Founction*************************************************/
//Name: lift_mode                                                                  //
//Remarks: void lift_mode(*mp,struct Lift *lift_a,struct Lift *lift_b)             //
//feature: 实现电梯按键信号的处理                                                      //
/***********************************************************************************/
void lift_mode( int *mp, struct Lift *lift_a, struct Lift *lift_b, int *button_out)
{
    int m=(*lift_a).flo_line;
    int n=(*lift_b).flo_line;

    /********************电梯内部按键需求信号的处理*********************************/
    if( ((*mp) >= 1) && ((*mp) <= 8) )                         //将电梯A内部需求信号存入结构体中
    {
        if( (*mp) >= (8.0-((float)m-115.0)/35.0) )      //判断内部需求是在目前电梯坐在层的上方或下方
        {
            (*lift_a).callup[*mp] = 1;

        }
        else if( (*mp) < (8.0-((float)m-115.0)/35.0) )
        {
            (*lift_a).calldown[*mp] = 1;
        }

        (*lift_a).button_in[(*mp)] = 1;

    }

    if( ((*mp) >= 9) && ((*mp) <= 16) )                        //将电梯B内部需求信号存入结构体中
    {
        *mp = *mp-8;                                    //将*mp的电梯楼层对应起来
        if( (*mp) >= (8.0-((float)n-115.0)/35.0) )      //判断内部需求是在目前电梯坐在层的上方或下方
        {
            (*lift_b).callup[*mp] = 1;

        }
        else if( (*mp) < (8.0-((float)n-115.0)/35.0) )
        {
            (*lift_b).calldown[*mp] = 1;
        }
        (*lift_b).button_in[(*mp)] = 1;
    }

    /*******************电梯外部按键需求信号的处理******************************/
    if(((*mp) >= 17) && ((*mp) <= 23) )
    {
        strategy( (*mp-16) , lift_a, lift_b );
        button_out[(*mp-16)] = 1;
    }

    if(((*mp) >= 24) && ((*mp) <= 30) )
    {
        strategy( (*mp-22) , lift_a, lift_b );
        button_out[*mp-16] = 1;
    }

    liftcall_calculate(lift_a);
    liftcall_calculate(lift_b);


    /*******************电梯门开关按键需求信号的处理******************************/
    if( (*mp) == 37)
    {
        (*lift_a).door_call = CLOSE;
    }
    if( (*mp) == 38)
    {
        (*lift_a).door_call = OPEN;

        if(((*lift_a).flo_line-115)%35 == 0)
        {
            (*lift_a).callup[(*lift_a).flo_state] = 1;
        }
    }
    if( (*mp) == 39)
    {
        (*lift_b).door_call = CLOSE;
    }
    if( (*mp) == 40)
    {
        (*lift_b).door_call = OPEN;

        if(((*lift_b).flo_line-115)%35 == 0)
        {
            (*lift_b).callup[(*lift_b).flo_state] = 1;
        }
    }

    /*******************电梯门紧急情况按键需求信号的处理******************************/
    if((*mp) == 31)
    {
        (*lift_a).urge_call = !(*lift_a).urge_call;
        delay(100);
    }
    if((*mp) == 34)
    {
        (*lift_b).urge_call = !(*lift_b).urge_call;
        delay(100);
    }

    *mp = 0;//*mp置零，避免重复执行鼠标点击的上一操作
}

/*************************Founction*************************************************/
//Name: liftcall_calculate                                                         //
//Remarks: liftcall_calculate(struct Lift *lift)                                   //
//feature: 求电梯需求信号的最大值、最小值                                               //
/***********************************************************************************/
void liftcall_calculate( struct Lift *lift)
{
    int i;

    for(i=8; i>0; i--)
    {
        if((*lift).callup[i] != 0)
        {
            (*lift).callup[MAX] = i;               //利用lift.callup[9]标记电梯中上行呼叫信号的最大值
            break;
        }

    }

    for(i=1; i<9; i++)
    {
        if((*lift).callup[i] != 0)
        {
            (*lift).callup[MIN] = i;                    //利用lift.callup[10]标记电梯中上行呼叫信号的最小值
            break;
        }
    }

    for(i=8; i>0; i--)
    {
        if((*lift).calldown[i] != 0)
        {
            (*lift).calldown[MAX] = i;                   //利用lift.calldown[9]标记电梯中下行呼叫信号的最大值
            break;
        }
    }

    for(i=1; i<9; i++)
    {
        if((*lift).calldown[i] != 0)
        {
            (*lift).calldown[MIN] = i;                  //利用lift.calldown[10]标记电梯中下行呼叫信号的最小值
            break;
        }
    }

}
