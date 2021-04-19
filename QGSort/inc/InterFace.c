/**
*   用户界面 
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void MainInterFace()
{
    int i;
    for(i=0;i<35;i++)   printf(" ");
    for(i=0;i<40;i++)   printf("*");    printf("\n");

    for(i=0;i<35;i++)   printf(" ");
    printf("**");
    printf("    1       大量数据测试排序        ");
    printf("**\n");

    for(i=0;i<35;i++)   printf(" ");
    printf("**");
    printf("    2       100数据*100k次测试      ");
    printf("**\n");

    for(i=0;i<35;i++)   printf(" ");
    printf("**");
    printf("    3       排序的应用              ");
    printf("**\n");

    for(i=0;i<35;i++)   printf(" ");
    printf("**");
    printf("    0       退出                    ");
    printf("**\n");

    for(i=0;i<35;i++)   printf(" ");
    for(i=0;i<40;i++)   printf("*");    printf("\n");

    printf("请输入你的选择：");
}
