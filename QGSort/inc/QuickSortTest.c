/**
*   快速排序的大数据量测试  
*/


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define max 200000
#define mid 50000
#define min 10000

extern int isSorted(int a[],int n);
int b[max+5];
void QuickSort(int *a, int begin, int end)
{
    if(begin>=end)  return ;
    int low=begin,high=end,key=a[begin];
    while(low!=high)
    {
        while(a[high]>=key)
        {
            if(low==high)   break;
            high--;
        }
        if(high!=low)   a[low]=a[high];
        while(a[low]<=key)
        {
            if(low==high)   break;
            low++;
        }
        if(high!=low)   a[high]=a[low];
    }
    a[low]=key;
    QuickSort(a,begin,low-1);
    QuickSort(a,low+1,end);
}

void QuickMinTest()
{
    srand((unsigned int)time(0));
    for(int i=0;i<min;i++)
    {
        b[i]=rand()+1;
    }
    clock_t start=clock();
    QuickSort(b,0,min-1);
    clock_t finish=clock();
    if(isSorted(b,min))
        printf("%lf ms\n",(double)(finish-start));
    else    printf("排序失败！\n");
    //for(int i=min-50;i<min;i++)  printf("%d\n",b[i]);
}

void QuickMidTest()
{
    srand((unsigned int)time(0));
    for(int i=0;i<mid;i++)
    {
        b[i]=rand()*2+1;
    }
    clock_t start=clock();
    QuickSort(b,0,mid-1);
    clock_t finish=clock();
    if(isSorted(b,mid))
        printf("%lf ms\n",(double)(finish-start));
    else    printf("排序失败！\n");
    //for(int i=mid-50;i<mid;i++)  printf("%d\n",b[i]);
}

void QuickMaxTest()
{
    srand((unsigned int)time(0));
    for(int i=0;i<max;i++)
    {
        b[i]=rand()*10+1;
    }
    clock_t start=clock();
    QuickSort(b,0,max-1);
    clock_t finish=clock();
    if(isSorted(b,max))
        printf("%lf ms\n",(double)(finish-start));
    else    printf("排序失败！\n");
    //for(int i=max-50;i<max;i++)  printf("%d\n",b[i]);
}

void QuickTest()
{
    char b[20];
    clock_t start,finish;
    srand((unsigned int)time(0));
    printf("1       测试10000数据量\n");
    printf("2       测试50000数据量\n");
    printf("3       测试200000数据量\n");
    printf("请输入你的选择：");
    scanf("%s",b);
    if(strlen(b)>1) printf("输入错误！");
    else
    {
        int i=b[0]-'0';
        switch(i)
        {
            case 1:QuickMinTest();break;
            case 2:QuickMidTest();break;
            case 3:QuickMaxTest();break;
            default:printf("输入的选择不在范围内！\n");
        }
    }
}

