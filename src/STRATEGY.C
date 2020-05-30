/****************************************************************/
/*    COPYRIGHT NOTICE                                          */
/*    Copyright (c) 2012,   ����˫����ϵͳ��ƣ�C���԰棩            */
/*    All rights reserved.                                      */
/*                                                              */
/*    @file strategy.c                                          */
/*    @brief intro:                                             */
/*                (1)calculate the time_move and time_stay      */
/*                (2)compare time_a and time_b                  */
/*                (3)distribute the extern callup and calldown  */
/*    @version final                                            */
/*    @author fengyecl                                          */
/*    @date 2012��10��9��                                        */
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
#include"strategy.h"

/*************************Founction***********************************************/
//Name: strategy                                                                 //
//Remarks: strategy(int flo_goal, int flo_state, int mov_state,int *callup_a,    //
//                        int *calldown_a, int *callup_b, int *calldown_b)       //  
//                                                                                //
//feature: ���ʱ��ıȽϽ��������ⲿ�����źŵķ���                                   //
/*********************************************************************************/
void strategy(int flo_goal, struct Lift *lift_a, struct Lift *lift_b)
{
    int i, lift;

    int m = (*lift_a).flo_line;
    int n = (*lift_b).flo_line;

/**********************�ж������źŴ����ĸ�����********************************/
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


/**********************�������ź�д�������������********************************/
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
//feature: ���A����Ӧʱ���B����Ӧʱ��ıȽ�                                              //
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
//feature: ������ݴﵽĿ��¥��ʱ�ƶ���Ҫ��ʱ��                                          //
/*********************************************************************************/
int time_move(int m,int n,int mov_state,int *callup,int *calldown)
{
    int time,flo_max,flo_min;

    flo_min = min(calldown[MIN], callup[MIN]);//��������������¥��
    flo_max = max(calldown[MAX], callup[MAX]);//��������������¥��

    if(m == n)                      //�������źž����ڵ�ǰ¥�����
    {
        time = 0;
    }
    else if(m > n)                  //�������ź��ڵ�ǰ¥���Ϸ�����
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
    else                         //�������źž����ڵ�ǰ¥���·�����
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
//feature: ������ݴﵽĿ��¥��ʱͣ����Ҫ��ʱ��                                        //
/*********************************************************************************/

int time_stay( int m, int n, int mov_state, int *callup, int *calldown)
{
    int i;
    int stay_num = 0;
    int time, flo_max, flo_min;

    flo_min = min(calldown[MIN],callup[MIN]);//��������������¥��
    flo_max = max(calldown[MAX],callup[MAX]);//��������������¥��

    if(m > n)                //mΪĿ��¥�㣬nΪ����¥��
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
            for(i=flo_min; i<n; i++)//����¥�������Ŀ��¥��֮����Ҫͣ������
            {
                if(callup[i]==1 || calldown[i]==1)
                {
                    stay_num++;
                }
            }

            for(i=n+1; i<m; i++)      //����¥�㾶ֱ�������˴�Ŀ��¥��֮����Ҫͣ������
            {
                if((callup[i]) == 1)
                {
                    stay_num++;
                }
            }
        }
    }
    if(m<n)                     //mΪĿ��¥�㣬nΪ����¥��
    {
        if(mov_state==DOWN || mov_state==STAY)   //����¥�������Ŀ��¥��֮����Ҫͣ������
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
            for(i=n+1; i<=flo_max; i++)//����¥�������Ŀ��¥��֮����Ҫͣ������
            {
                if(callup[i]==1 || calldown[i]==1)
                {
                    stay_num++;
                }
            }

            for(i=m+1; i<n; i++)      //����¥�㾶ֱ�������˴�Ŀ��¥��֮����Ҫͣ������
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

