/****************************************************************************/
/*    COPYRIGHT NOTICE                                                      */
/*    Copyright (c) 2012,   智能双电梯仿真系统（C语言版）                        */
/*    All rights reserved.                                                  */
/*                                                                          */
/*    @file hanhua.c                                                        */
/*    @brief intro:                                                         */
/*                 To form the founction                                    */
/*                    void hanhuaxy(int x,int y,char *s,int size,int color) */
/*                    which is used to display Chines Characters (*s)       */
/*                    form the point(x,y) in size whith color               */
/*    @version final                                                        */
/*    @author fengyecl                                                      */
/*    @date 2012年10月10日                                                   */
/*                                                                          */
/*     修订说明：最初版本                                                      */
/****************************************************************************/
#include<stdio.h>
#include<graphics.h>
#include"hanhua.h"

void hanhuaxy( int x, int y, char *s, int size, int color)
{
    FILE *hzk_fp;
    char word[2]={'a','\0'};
    if((hzk_fp = fopen("hzk16","rb"))==NULL)
    {
        outtextxy(5,5,"the hzk16 can't open!");
        getch();
        return;
    }

    while (x<640 && (*s!=NULL))
    {
        if((int)(*s)>0&&(int)(*s)<128)/*ASCII可表示*/
        {
            setwritemode(COPY_PUT);
            settextstyle(0,0,size);
            word[0]=*s;
            outtextxy(x,y+5,word);
            x += 10;
            s += 1;
        }
        else
        {
            dis_hzk(x,y,s,color,size,hzk_fp);
            x += 20;  //汉字间距调整
            s += 2;
        }
    }

    fclose(hzk_fp);
}

void get_hzk( char incode[], char mat[], FILE *hzk_fp)//获取汉字
{
    unsigned char qh,wh;
    unsigned long offset;
    qh = incode[0] - 0xa0;
    wh = incode[1] - 0xa0;
    offset = (94*(qh-1)+(wh-1))*32L;
    fseek(hzk_fp,offset,SEEK_SET);
    fread(mat,32,1,hzk_fp);
}

void dis_hzk( int x0, int y0, char code[], int color, int size, FILE *hzk_fp)//汉字显示
{
    unsigned char mask[] = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
    int i,j,x,y,pos,n,m;
    char mat[32];
    get_hzk(code,mat,hzk_fp);
    y = y0;
    for (i = 0; i < 16; ++i)
    {
        x = x0;
        pos = 2*i;
        for(j = 0; j < 16; ++j)
        {
            for(n = 0; n < size; n++)//单个汉字大小控制
            {
                for(m = 0; m < size; m++)
                {
                    if ((mask[j%8]&mat[pos+j/8]) != NULL)
                    {
                        putpixel(x+n,y+m,color);
                    }
                }
            }
            x += size;
        }
        y += size;
    }
}
