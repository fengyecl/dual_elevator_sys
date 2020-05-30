/****************************************************************/
/*    COPYRIGHT NOTICE                                          */
/*    Copyright (c) 2012,   智能双电梯系统设计（C语言版）            */
/*    All rights reserved.                                      */
/*                                                              */
/*    @file strategy.c                                          */
/*    @brief intro:                                             */
/*                (1)calculate the time_move and time_stay      */
/*                (2)compare time_a and time_b                  */
/*                (3)distribute the extern callup and calldown  */
/*    @version final                                            */
/*    @author fengyecl                                          */
/*    @date 2012年10月9日                                        */
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
#include"strategy.h"

/*************************Founction***********************************************/
//Name: strategy                                                                 //
//Remarks: strategy(int flo_goal, int flo_state, int mov_state,int *callup_a,    //
//                        int *calldown_a, int *callup_b, int *calldown_b)       //  
//                                                                                //
//feature: 结合时间的比较结果，完成外部呼梯信号的分配                                   //
/*********************************************************************************/
void strategy(int flo_goal, struct Lift *lift_a, struct Lift *lift_b)
{
    int i, lift;

    int m = (*lift_a).flo_line;
    int n = (*lift_b).flo_line;

/**********************判断需求信号传给哪个电梯********************************/
    if((*lift_a).urge_call == OFF && (*lift_a).urge_call == OFF )
    {
        lift = time_compare( flo_goal, (*lift_a).flo_state, (*lift_a).mov_state[1], (*lift_a).callup, (*lift_a).calldown,
                     (*lift_b).flo_state, (*lift_b).mov_state[1], (*lift_b).callup, (*lift_b).calldown );
    }

    else if((*lift_b).urge_call == ON && (*lift_a).urge_call == OFF )
    {
        lift = A;
    }

    else if((*lift_a).urge_call == ON && (*lift_b).urge_call == OFF )
    {
        lift = B;
    }


/**********************将需求信号写入电梯需求数组********************************/
    if(lift == A)
    {

        if( (float)flo_goal >= (8.0-((float)m-115.0)/35.0) )
        {
            (*lift_a).callup[flo_goal]=1;

        }
        else if( (float)flo_goal < (8.0-((float)m-115.0)/35.0) )
        {
            (*lift_a).calldown[flo_goal]=1;

        }
    }
    else if(lift == B)
    {
        if( (float)flo_goal >= (8.0-((float)n-115.0)/35.0) )
        {
            (*lift_b).callup[flo_goal]=1;
        }
        else if( (float)flo_goal < (8.0-((float)n-115.0)/35.0) )
        {
            (*lift_b).calldown[flo_goal]=1;
        }
    }
}


/*************************Founction****************************************************/
//Name: time_compare                                                                  //
//Remarks: int time_compare(int flo_goal, int flo_state, int mov_state,               //
//                  int *callup_a, int *calldown_a, int *callup_b, int *calldown_b )  //
//feature: 完成A梯响应时间和B梯响应时间的比较                                              //
/**************************************************************************************/

int time_compare( int flo_goal, int flo_state_a, int mov_state_a, int *callup_a, int *calldown_a, int flo_state_b, int mov_state_b, int *callup_b, int *calldown_b)
{
    int time_a, time_b;

    time_a = time_move(flo_goal,flo_state_a,mov_state_a,callup_a,calldown_a)  +  time_stay(flo_goal,flo_state_a,mov_state_a,callup_a,calldown_a);
    time_b = time_move(flo_goal,flo_state_b,mov_state_b,callup_b,calldown_b)  +  time_stay(flo_goal,flo_state_b,mov_state_b,callup_b,calldown_b);

    if(time_a <= time_b)
    {
        return (A);
    }
    else
    {
        return (B);
    }

}


/*************************Founction************************************************/
//Name: time_move                                                                  //
//Remarks: int time_move(int m,int n,int mov_state,int *callup,int *calldown)      //
//feature: 计算电梯达到目标楼层时移动需要的时间                                          //
/*********************************************************************************/
int time_move(int m,int n,int mov_state,int *callup,int *calldown)
{
    int time,flo_max,flo_min;

    flo_min = min(calldown[MIN], callup[MIN]);//计算电梯需求最低楼层
    flo_max = max(calldown[MAX], callup[MAX]);//计算电梯需求最高楼层

    if(m == n)                      //即呼梯信号就是在当前楼层产生
    {
        time = 0;
    }
    else if(m > n)                  //即呼梯信号在当前楼层上方产生
    {
        if(mov_state != DOWN)
        {
            time = (m-n)*TMOVE;
        }
        else if(mov_state == DOWN)
        {
            time = (m+n-2*flo_min)*TMOVE;
        }
    }
    else                         //即呼梯信号就是在当前楼层下方产生
    {
        if(mov_state != UP)
        {
            time = (n-m)*TMOVE;
        }
        else if(mov_state == UP)
        {
            time = (2*flo_max-n-m)*TMOVE;
        }
    }
    return(time);
}



/*************************Founction***********************************************/
//Name: time_stay                                                                //
//Remarks: int time_stay(int m,int n,int mov_state,int *callup,int *calldown)    //
//feature: 计算电梯达到目标楼层时停留需要的时间                                        //
/*********************************************************************************/

int time_stay( int m, int n, int mov_state, int *callup, int *calldown)
{
    int i;
    int stay_num = 0;
    int time, flo_max, flo_min;

    flo_min = min(calldown[MIN],callup[MIN]);//计算电梯需求最低楼层
    flo_max = max(calldown[MAX],callup[MAX]);//计算电梯需求最高楼层

    if(m > n)                //m为目标楼层，n为现在楼层
    {
        if(mov_state==UP || mov_state==STAY)
        {
            for(i=n+1; i<m; i++)
            {
                if( (callup[i]) == 1)
                {
                    stay_num++;
                }
            }
        }
        if(mov_state == DOWN)
        {
            for(i=flo_min; i<n; i++)//现在楼层至最低目标楼层之间需要停留次数
            {
                if(callup[i]==1 || calldown[i]==1)
                {
                    stay_num++;
                }
            }

            for(i=n+1; i<m; i++)      //现在楼层径直向上至此次目标楼层之间需要停留次数
            {
                if((callup[i]) == 1)
                {
                    stay_num++;
                }
            }
        }
    }
    if(m<n)                     //m为目标楼层，n为现在楼层
    {
        if(mov_state==DOWN || mov_state==STAY)   //现在楼层至最低目标楼层之间需要停留次数
        {
            for(i=m+1;i<n;i++)
            {
                if((calldown[i]) == 1)
                {
                    stay_num++;;
                }
            }
        }

        if(mov_state == UP)
        {
            for(i=n+1; i<=flo_max; i++)//现在楼层至最低目标楼层之间需要停留次数
            {
                if(callup[i]==1 || calldown[i]==1)
                {
                    stay_num++;
                }
            }

            for(i=m+1; i<n; i++)      //现在楼层径直向上至此次目标楼层之间需要停留次数
            {
                if((calldown[i]) == 1)
                {
                    stay_num++;
                }
            }
        }
    }

    time = stay_num*TSTAY;
    return (time);
}


