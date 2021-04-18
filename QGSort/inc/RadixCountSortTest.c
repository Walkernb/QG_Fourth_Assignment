#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define max 200000
#define mid 50000
#define min 10000

extern int isSorted(int a[],int n);
int b[max+5];
int c[max+5];
void RadixCountSort(int *a,int size)
{
    int d[10];
    int i,k,m=0;
    for(i=0;i<size;i++)
    {
        int j=0;
        k=a[i];
        while(k!=0) k/=10,  j++;
        if(j>m) m=j;
    }
    int j=0,p=1;
    while(j<m)
    {
         memset(d,0,sizeof(d));
         for(i=0;i<size;i++)
        {
            int n=a[i]/p;
            k=n%10;
            d[k]++;
        }
        for(i=1;i<10;i++)   d[i]+=d[i-1];
        for(i=size-1;i>=0;i--)
        {
            int n=a[i]/p;
            int t=n%10;
            d[t]--;
            k=d[t];
            c[k]=a[i];
        }
        for(i=0;i<size;i++) a[i]=c[i];
        j++;
        p*=10;
    }
}

void RadixMinTest()
{
    srand((unsigned int)time(0));
    for(int i=0;i<min;i++)
    {
        b[i]=rand()+1;
    }
    clock_t start=clock();
    RadixCountSort(b,min);
    clock_t finish=clock();
    if(isSorted(b,min))
        printf("%lf ms\n",(double)(finish-start));
    else    printf("排序失败！\n");
    //for(int i=min-50;i<min;i++)  printf("%d\n",b[i]);
}

void RadixMidTest()
{
    srand((unsigned int)time(0));
    for(int i=0;i<mid;i++)
    {
        b[i]=rand()+1;
    }
    clock_t start=clock();
    RadixCountSort(b,mid);
    clock_t finish=clock();
    if(isSorted(b,mid))
        printf("%lf ms\n",(double)(finish-start));
    else    printf("排序失败！\n");
    //for(int i=mid-50;i<mid;i++)  printf("%d\n",b[i]);
}

void RadixMaxTest()
{
    srand((unsigned int)time(0));
    for(int i=0;i<max;i++)
    {
        b[i]=rand()+1;
    }
    clock_t start=clock();
    RadixCountSort(b,max);
    clock_t finish=clock();
    if(isSorted(b,max))
        printf("%lf ms\n",(double)(finish-start));
    else    printf("排序失败！\n");
    //for(int i=max-50;i<max;i++)  printf("%d\n",b[i]);
}

void RadixCountTest()
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
            case 1:RadixMinTest();break;
            case 2:RadixMidTest();break;
            case 3:RadixMaxTest();break;
            default:printf("输入的选择不在范围内！\n");
        }
    }
}
