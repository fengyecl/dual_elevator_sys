/**********************************************************************************/
/*    COPY RIGHT NOTICE                                                           */
/*    Copy right (c) 2012,   ����˫���ݷ���ϵͳ��C���԰棩                             */
/*    All rights reserved.                                                        */
/*                                                                                */
/*    @file collect.c                                                             */
/*    @brief intro:                                                               */
/*            Information collection including page switching and                 */
/*           elevator buttons                                                     */  
/*                                                                                */
/*    @version final                                                              */
/*    @author fengyecl                                                            */
/*    @date 2012��10��4��                                                          */
/*                                                                                */
/*    �޶�˵��������汾                                                             */
/**********************************************************************************/
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<process.h>
#include<dos.h>
#include<stdlib.h>
#include<math.h>
#include"collect.h"

/*************************Founction********************************************************/
//Name: collect_page                                                                      //
//Remarks: void collect_page(int page,int op[2], int *mouseX, int *mouseY,int *button)    //
//feature: �ռ�ҳ���л���Ϣ������Ϣ�洢��OP������                                               //
/******************************************************************************************/
void collect_page( int page, int op[2], int *mouseX, int *mouseY, int *button)
{
    int flag=0;

    mou_shape(*mouseX,*mouseY);

    do
    {
        mou_dis(mouseX,mouseY,button);

        if(mou_click(565,430,610,450,button,mouseX,mouseY))//��Ӣ���л�
        {

            op[0] = op[1];
            op[1] = MODE0;
            flag = 1;
        }

        switch(page)//page=1�ڻ�ӭ���棻page=3ʱ�ڰ�������
        {
            case 1:
            {
                if(mou_click(420,200,540,280,button,mouseX,mouseY))//����������
                {
                    op[1] = MODE2;
                    flag = 1;
                }
                else if(mou_click(260,260,380,340,button,mouseX,mouseY))//�����������
                {
                    op[1] = MODE3;
                    flag = 1;
                }
                else if(mou_click(100,320,220,400,button,mouseX,mouseY))//�����˳�����
                {
                    op[1] = MODE4;
                    flag = 1;
                }
                break;
            }

            case 3:
            {
                if(mou_click(55,195,177,220,button,mouseX,mouseY))//ʹ��ָ��
                {
                    op[1] = MODE5;
                    flag = 1;
                }
                else if(mou_click(55,265,177,290,button,mouseX,mouseY))//ϵͳ���
                {
                    op[1] = MODE6;
                    flag = 1;
                }
                else if(mou_click(55,335,177,360,button,mouseX,mouseY)) //��������
                {
                    op[1] = MODE7;
                    flag = 1;
                }
                else if(mou_click(515,430,560,450,button,mouseX,mouseY))//�˻ػ�ӭ����
                {
                    op[1] = MODE1;
                    flag = 1;
                }
                break;
            }
        }//switch
    }while(flag == 0);
}

/*************************Founction************************************************************/
//Name: collect_lift                                                                          //
//Remarks: void collect_lift(int op[2],int *ce,int *mp,int *mouseX,int *mouseY,int *button)   //
//feature: �ռ����ݰ�����Ϣ������Ϣ�洢��mp��                                                      //
/**********************************************************************************************/
void collect_lift( int op[2], int *ce, int *mp, int *mouseX, int *mouseY, int *button)
{
    int i;
    int flag = 0;

    /*************ҳ���л�����***************************/
    if(mou_click(515,430,560,450,button,mouseX,mouseY))//�˳�����ӭ����
    {
        op[1] = MODE1;
        flag = 1;
    }
    else if(mou_click(465,430,510,450,button,mouseX,mouseY))//�����������
    {
        op[1] = MODE3;
        flag = 1;
    }
    else if(mou_click(565,430,610,450,button,mouseX,mouseY))//��Ӣ���л�
    {
        op[0] = op[1];
        op[1] = MODE0;
        flag = 1;
    }

    if(flag == 1)
    {
        page_mode(op,ce,mouseX,mouseY,button);
    }
    else
    {
    /*************************�����ڲ�¥�㰴��***************************/
        for(i=0; i<4; i++)   //A_1_4
        {
            if(mou_click(455,110+12*i,465,130+12*i,button,mouseX,mouseY))
            {
                *mp = i + 1;
            }
        }

        for(i=0; i<4; i++)   //A_5_8
        {
            if(mou_click(467,103+12*i,477,123+12*i,button,mouseX,mouseY))
            {
                *mp = i + 5;
            }
        }

        for(i=0; i<4; i++)   //B_1_4
        {
            if(mou_click(455,260+12*i,465,280+12*i,button,mouseX,mouseY))
            {
                *mp = i + 9;
            }
        }

        for(i=0; i<4; i++)   //B_5_8
        {
            if(mou_click(467,253+12*i,477,273+12*i,button,mouseX,mouseY))
            {
                *mp = i + 13;
            }
        }

        /*********************�����ⲿ�����а���***************************/
        if(mou_click(207,400-35*1,219,418-35*1,button,mouseX,mouseY))  //1_up
        {
            *mp= 16 + 1;
        }
        for(i=2; i<8; i++)   //2_7_up
        {
            if(mou_click(200,400-35*i,212,418-35*i,button,mouseX,mouseY))
            {
                *mp = 16 + i;
            }
        }
        for(i=2; i<8; i++)   //2_7_down
        {
            if(mou_click(215,400-35*i,227,418-35*i,button,mouseX,mouseY))
            {
                *mp = 22 + i;
            }
        }
        if(mou_click(207,400-35*8,219,418-35*8,button,mouseX,mouseY))  //8_down
        {
            *mp = (22 + 8);
        }
       /*************��������������***************************/

        if(mou_click(435,123+18*1,445,131+18*i,button,mouseX,mouseY))
        {
            *mp = 31 ;
        }


        if(mou_click(435,273+18*1,445,281+18*i,button,mouseX,mouseY))
        {
            *mp = 34 ;
        }
        /************************�����Ű���*******************************/
        for(i=0; i<2; i++)
        {
            if(mou_click(483+i*15,130,493+i*15,145,button,mouseX,mouseY))
            {
                *mp = 37 + i;
            }
        }
        for(i=0; i<2; i++)
        {
            if(mou_click(483+i*15,280,493+i*15,295,button,mouseX,mouseY))
            {
                *mp = 39 + i;
            }
        }
    }
}