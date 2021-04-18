#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define max 200000
#define mid 50000
#define min 10000

extern int isSorted(int a[],int n);
void insertSort(int *a,int n)       //²åÈëÅÅÐò
{
    int i,k,j;
    for(i=0;i<n;i++)
    {
        int t=i;
        for(j=t-1;j>=0;j--)
        {
            if(a[t]<a[j])
            {
                k=a[t];
                a[t]=a[j];
                a[j]=k;
                t=j;
            }
        }
    }
}

int b[max+5];

void insertMinTest()            //测试10000数据量
{
    srand((unsigned int)time(0));
    for(int i=0;i<min;i++)
    {
        b[i]=rand()+1;
    }
    clock_t start=clock();
    insertSort(b,min);
    clock_t finish=clock();
    if(isSorted(b,min))
        printf("%lf ms\n",(double)(finish-start));
    else    printf("排序失败！\n");
    //for(int i=min-50;i<min;i++)  printf("%d\n",b[i]);
}

void insertMidTest()            //测试50000数据量
{
    srand((unsigned int)time(0));
    for(int i=0;i<mid;i++)
    {
        b[i]=rand()*2+1;
    }
    clock_t start=clock();
    insertSort(b,mid);
    clock_t finish=clock();
    if(isSorted(b,mid))
        printf("%lf ms\n",(double)(finish-start));
    else    printf("排序失败！\n");
    //for(int i=mid-50;i<mid;i++)  printf("%d\n",b[i]);
}

void insertMaxTest()            //测试200000数据量
{
    srand((unsigned int)time(0));
    for(int i=0;i<max;i++)
    {
        b[i]=rand()*10+1;
    }
    clock_t start=clock();
    insertSort(b,max);
    clock_t finish=clock();
    if(isSorted(b,max))
        printf("%lf ms\n",(double)(finish-start));
    else    printf("排序失败！\n");
    //for(int i=min-50;i<min;i++)  printf("%d\n",b[i]);
}

void insertTest()
{
    char b[20];
    clock_t start,finish;
    srand((unsigned int)time(0));
    printf("1       test 10000 data size\n");
    printf("2       test 50000 data size\n");
    printf("3       test 200000 data size\n");
    printf("please input your selection:");
    scanf("%s",b);
    if(strlen(b)>1) printf("输入错误！");
    else
    {
        int i=b[0]-'0';
        switch(i)
        {
            case 1:insertMinTest();break;
            case 2:insertMidTest();break;
            case 3:insertMaxTest();break;
            default:printf("输入的选择不在范围内！\n");
        }
    }

}
