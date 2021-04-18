#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#define max 200000
#define mid 50000
#define min 10000

int b[max];
extern int isSorted(int a[],int n);

void QuickSort2(int *a, int begin, int end)                             //已头、中、尾，三者间的中位数为枢纽数
{
    if(begin>=end)  return ;
    int low=begin,high=end,middle=(low+high)/2,key=a[middle];
    if(a[low]<=a[middle]&&a[middle]<=a[high]||a[high]<=a[middle]&&a[middle]<a[begin])   //中 为枢纽数
    {
        int v=a[low];
        a[low]=a[middle];
        a[middle]=v;
    }
    else    if(a[middle]<=a[begin]&&a[begin]<=a[high]||a[high]<=a[begin]&&a[begin]<=a[middle])  //头 为枢纽数
    {
        key=a[begin];
    }
    else                                                                                     //尾  为枢纽数
    {
        int v=a[high];
        a[high]=a[low];
        a[low]=v;
        key=v;
    }
    while(low!=high)
    {
        while(low<high&&a[high]>=key)
            high--;
        if(high!=low)
            a[low]=a[high];
        while(low<high&&a[low]<=key)
            low++;
        if(high!=low)   a[high]=a[low];
    }
    a[low]=key;
    QuickSort2(a,begin,low-1);
    QuickSort2(a,low+1,end);
}


void QuickMinTest2()
{
    srand((unsigned int)time(0));
    for(int i=0;i<min;i++)
    {
        b[i]=rand()+1;
    }
    clock_t start=clock();
    QuickSort2(b,0,min-1);
    clock_t finish=clock();
    if(isSorted(b,min))
        printf("%lf ms\n",(double)(finish-start));
    else    printf("排序失败！\n");
    //for(int i=min-50;i<min;i++)  printf("%d\n",b[i]);
}

void QuickMidTest2()
{
    srand((unsigned int)time(0));
    for(int i=0;i<mid;i++)
    {
        b[i]=rand()*2+1;
    }
    clock_t start=clock();
    QuickSort2(b,0,mid-1);
    clock_t finish=clock();
    if(isSorted(b,mid))
        printf("%lf ms\n",(double)(finish-start));
    else    printf("排序失败！\n");
    //for(int i=mid-50;i<mid;i++)  printf("%d\n",b[i]);
}

void QuickMaxTest2()
{
    srand((unsigned int)time(0));
    for(int i=0;i<max;i++)
    {
        b[i]=rand()*10+1;
    }
    clock_t start=clock();
    QuickSort2(b,0,max-1);
    clock_t finish=clock();
    if(isSorted(b,max))
        printf("%lf ms\n",(double)(finish-start));
    else    printf("排序失败！\n");
    //for(int i=max-50;i<max;i++)  printf("%d\n",b[i]);
}


void enQuickTest()
{
    char c[20];
    clock_t start,finish;
    srand((unsigned int)time(0));
    printf("1       测试10000数据量\n");
    printf("2       测试50000数据量\n");
    printf("3       测试200000数据量\n");
    printf("请输入你的选择：");
    scanf("%s",c);
    if(strlen(c)>1) printf("输入错误！");
    else
    {
        int i=c[0]-'0';
        switch(i)
        {
            case 1:QuickMinTest2();break;
            case 2:QuickMidTest2();break;
            case 3:QuickMaxTest2();break;
            default:printf("输入的选择不在范围内！\n");
        }
    }
}
