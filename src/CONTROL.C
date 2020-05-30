/****************************************************************/
/*    COPYRIGHT NOTICE                                          */
/*    Copyright (c) 2012,   ����˫���ݷ���ϵͳ��C���԰棩            */
/*    All rights reserved.                                      */
/*                                                              */
/*    @file control.c                                           */
/*    @brief intro:                                             */
/*                 Elevator movement control                    */   
/*    @version final                                            */
/*    @author fengyecl                                          */
/*    @date 2012��10��10��                                       */
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
#include"control.h"

/*************************Founction****************************************************/
//Name: control                                                                       //
//Remarks: void control(int op[2], int *ce, int *mouseX, int *mouseY,int *button)     //
//feature: �����˶����Ƽ�����ʵ��                                                         //
/**************************************************************************************/

void control( int op[2], int *ce, int *mouseX, int *mouseY, int *button)
{
    struct Lift lift_A, lift_B;
    struct Lift *lift_a, *lift_b;

    int flag,i,j;
    int *m,*n;                      //���ݻ��߱���

    int mp=0;
    int man_a, man_b;

    int button_out[15];//�����ⲿ�����洢

    for(i=0; i<15; i++)
    {
        button_out[i] = 0;
    }

    mou_shape(*mouseX,*mouseY);

    lift_a = &lift_A;
    lift_b = &lift_B;

/*****************���ݽṹ���ʼ��*************************/
    (*lift_a).flo_state = 1;
    (*lift_a).flo_line = 360;
    (*lift_a).mov_state[0] = STAY;
    (*lift_a).mov_state[1] = STAY;
    (*lift_a).door_line = 542;
    (*lift_a).door_call = NONE;
    (*lift_a).door_flag = 1;
    (*lift_a).door_state = CLOSE;
    (*lift_a).urge_call = OFF;
    for(i=0; i<11; i++)
    {
        (*lift_a).callup[i] = 0;
        (*lift_a).calldown[i] = 0;
    }

    for(i=0; i<9; i++)
    {
        (*lift_a).button_in[i] = 0;
    }

    (*lift_b).flo_state = 1;
    (*lift_b).flo_line = 360;
    (*lift_b).mov_state[0] = STAY;
    (*lift_b).mov_state[1] = STAY;
    (*lift_b).door_line = 542;
    (*lift_b).door_call = NONE;
    (*lift_b).door_flag = 1;
    (*lift_b).door_state = CLOSE;
    (*lift_b).urge_call = OFF;

    for(i=0; i<11; i++)
    {
        (*lift_b).callup[i] = 0;
        (*lift_b).calldown[i] = 0;
    }

    for(i=0;i<9;i++)
    {
        (*lift_b).button_in[i] = 0;
    }

    m=&((*lift_a).flo_line);
    n=&((*lift_b).flo_line);

    while(1)
    {
        mou_dis(mouseX, mouseY, button);

        collect_lift(op, ce, mp, mouseX, mouseY, button);
        lift_mode(mp, lift_a, lift_b, button_out);

        setwritemode(COPY_PUT);//�����ʾʱΪ���¥�㻭��Ϊ���ǣ�������ʵʱ�л�

        if((*lift_a).mov_state[1] == UP)
        {
            if((*lift_a).urge_call == OFF)
            {
                (*m)--;
            }
            setcolor(DARKGRAY);//��A��������
            line(66, (*m), 134, (*m));
            setcolor(LIGHTGRAY);
            line(66, 35+(*m), 134, 35+(*m));
            delay(20);

            if(((*m)-115)%35 == 0)
            {
                setfillstyle(1,LIGHTGRAY);//�������¥����ɫ����������ӡ�Ǵ���
                bar(66,115,134,(*m));
                bar(66,(*m)+35,134,394);

                (*lift_a).flo_state = (8-((*m)-115)/35);//����¥��
            }
        }
        if( (((*m)-115)%35==0) && ((*lift_a).callup[(8-((*m)-115)/35)]==1) )
        {
            door(lift_a, A, button_out, &man_a);

        }

        if((*lift_a).mov_state[1] == DOWN)
        {
            if((*lift_a).urge_call == OFF)
            {
                (*m)++;
            }
            setcolor(LIGHTGRAY);//��A��������
            line(66,(*m),134,(*m));
            setcolor(DARKGRAY);
            line(66,35+(*m),134,35+(*m));
            delay(20);

            if(((*m)-115)%35 == 0)
            {
                setfillstyle(1,LIGHTGRAY);
                bar(66,115,134,(*m));
                bar(66,(*m)+35,134,394);
                (*lift_a).flo_state = (8-((*m)-115)/35);//����¥��
            }

        }
        if( (((*m)-115)%35==0) && ((*lift_a).calldown[(8-((*m)-115)/35)]==1) )
        {
            door(lift_a, A, button_out, &man_a);
        }


        if((*lift_b).mov_state[1] == UP)
        {
            if((*lift_b).urge_call == OFF)
            {
                (*n)--;
            }
            setcolor(DARKGRAY);//��b��������
            line(66+220,(*n),134+220,(*n));
            setcolor(LIGHTGRAY);
            line(66+220,35+(*n),134+220,35+(*n));
            delay(20);

            if(((*n)-115)%35 == 0)
            {
                setfillstyle(1,LIGHTGRAY);
                bar(66+220,115,134+220,(*n));
                bar(66+220,(*n)+35,134+220,394);

                (*lift_b).flo_state = (8-((*n)-115)/35);//����¥��
            }
        }
        if( ( ((*n)-115)%35==0) && ( (*lift_b).callup[ (8- ((*n)-115)/35) ]==1) )
        {
            door(lift_b, B, button_out, &man_b);
        }


        if((*lift_b).mov_state[1] == DOWN)
        {
            if((*lift_b).urge_call == OFF)
            {
                (*n)++;
            }
            setcolor(LIGHTGRAY);//������b����
            line(66+220*1, (*n), 134+220*1, (*n));
            setcolor(DARKGRAY);
            line(66+220*1, 35+(*n), 134+220*1, 35+(*n));
            delay(20);

            if(((*n)-115)%35 == 0)//����¥��
            {
                setfillstyle(1,LIGHTGRAY);
                bar(66+220,115,134+220,(*n));
                bar(66+220,(*n)+35,134+220,394);

                (*lift_b).flo_state = (8-((*n)-115)/35);
            }
        }

        if( (((*n)-115)%35==0) && ( (*lift_b).calldown[ (8-((*n)-115)/35) ]==1) )
        {
            door(lift_b, B, button_out, &man_b);
        }

        mov_next(lift_a);
        mov_next(lift_b);

     /****************��ʾ����****************/
        dis_button_in( (*lift_a).button_in, A);
        dis_button_in( (*lift_b).button_in, B);
        dis_button_out(button_out);
        dis_person(A, man_a);
        dis_person(B, man_b);

        if( (*lift_a).urge_call == OFF )
        {
            dis_screen( (*lift_a).flo_state, (*lift_a).mov_state[0], A);
        }
        else if( (*lift_a).urge_call == ON )
        {
            dis_screen( 0, STAY, A);
        }

        if( (*lift_b).urge_call == OFF )
        {
            dis_screen( (*lift_b).flo_state, (*lift_b).mov_state[0], B);
        }
        else if( (*lift_b).urge_call == ON )
        {
            dis_screen( 0, STAY, B);
        }


        setcolor(BLUE);
        for(i=A;i<=B;i++)
        {
            for(j=0;j<=8;j++)
            {
                line(66+220*i, 395-35*j, 134+220*i, 395-35*j);
            }
        }


        /*
        if( ( (*lift_a).urge_call == ON ) || ( (*lift_b).urge_call == ON ) )//������ť���º󣬾�������
        {
            sound(2500);
            delay(100);
            nosound();
        }
        */
        //check(lift_a,A);
        //check(lift_b,B);
    }
}
/*************************Founction************************************************/
//Name: mov_next                                                                  //
//Remarks: void mov_next(struct Lift *lift)                                       //
//feature: �жϵ����˶�����                                                          //
/**********************************************************************************/
void mov_next( struct Lift *lift)
{
    int i, flag=0;
    if( (*lift).door_flag == 1)
    {
        if( (*lift).mov_state[0]==STAY || (*lift).mov_state[0]==UP )
        {
            for(i=(*lift).flo_state; i<=max((*lift).callup[MAX], (*lift).calldown[MAX]); i++)//�жϱ��������Ƿ��к�������
            {

                if((*lift).callup[i] == 1)
                {
                    (*lift).mov_state[1] = UP;
                    (*lift).mov_state[0] = UP;
                    flag = UP;

                    break;
                }
            }
            if(flag == STAY)
            {
                for(i=min((*lift).callup[MIN], (*lift).calldown[MIN]); i<=(*lift).flo_state; i++)//�жϱ��������Ƿ��к�������
                {
                    if((*lift).calldown[i] == 1)
                    {
                        (*lift).mov_state[1] = DOWN;
                        (*lift).mov_state[0] = DOWN;
                        flag = DOWN;
                        break;
                    }
                }
                if(flag == STAY)
                {
                    (*lift).mov_state[1] = STAY;
                    (*lift).mov_state[0] = STAY;
                    //printf("%d",flag);
                }
            }
        }//UP||STAY;

        else if((*lift).mov_state[0] == DOWN)
        {
            for(i=min((*lift).callup[MIN], (*lift).calldown[MIN]); i<=(*lift).flo_state; i++)//�жϱ��������Ƿ��к�������
            {
                if((*lift).calldown[i] == 1)
                {
                    (*lift).mov_state[1] = DOWN;
                    (*lift).mov_state[0] = DOWN;
                    flag = DOWN;
                    break;
                }
            }
            if(flag == STAY)
            {
                for(i=(*lift).flo_state; i<=max((*lift).callup[MAX], (*lift).calldown[MAX]); i++)//�жϱ��������Ƿ��к�������
                {
                    if((*lift).callup[i] == 1)
                    {
                        (*lift).mov_state[1] = UP;
                        (*lift).mov_state[0] = UP;
                        flag = UP;
                        break;
                    }
                }
                if(flag == STAY)
                {
                    (*lift).mov_state[1] = STAY;
                    (*lift).mov_state[0] = STAY;
                }
            }
        }//mov_state==DOWN;
    }//door_flag=1;
}


/*************************Founction*******************************************/
//Name: check                                                                //
//Remarks: void check(struct Lift *lift, int lift_ab)                        //
//feature: ʵʱ�����ݽṹ�������ݱ仯�����ڵ��Գ����ά��                          //
/*****************************************************************************/
void check( struct Lift *lift, int lift_ab)
{
    int i;
    char check[31];

    check[7] = '*';
    check[18] = '*';

    check[30] = '\0';

    check[0] = 48 + (*lift).flo_state;
    check[1] = 48 + (*lift).mov_state[0];
    check[2] = 48 + (*lift).mov_state[1];
    check[3] = 48 + (*lift).door_call;
    check[4] = 48 + (*lift).door_flag;
    check[5] = 48 + (*lift).door_state;
    check[6] = 48 + (*lift).urge_call;
    for(i=1; i<11; i++)
    {
        check[7+i] = (*lift).callup[i] + 48;
        check[19+i] = (*lift).calldown[i] + 48;
    }

    setcolor(RED);
    if(lift_ab == A)
    {
        outtextxy(10, 470, check);
    }
    else if(lift_ab == B)
    {
        outtextxy(320, 470, check);
    }
    delay(10);

    setfillstyle(SOLID_FILL, GREEN);
    setcolor(GREEN);
    bar(5,470,640,480);

}
