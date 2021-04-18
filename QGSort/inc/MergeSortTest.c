#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define max 200000
#define min 10000
#define Mid 50000

extern int isSorted(int a[],int n);
int b[max+5];

void  MergeSort(int *a,int begin,int mid,int end,int *temp)
{
    if(begin==end)  return ;
    if(begin==mid){
        if(a[begin]>a[end])
        {
            temp=(int *)malloc(sizeof(int));
            *temp=a[begin];
            a[begin]=a[end];
            a[end]=*temp;
            free(temp);
        }
        return ;
    }
    MergeSort(a,begin,(begin+mid)/2,mid,temp);
    MergeSort(a,mid+1,(mid+1+end)/2,end,temp);
    MergeArray(a,begin,mid,end,temp);
}

void MergeArray(int *a,int begin,int mid,int end,int *temp)
{
    int b[end+1];
    int k=begin, t=mid+1,i;
    for(i=begin;i<=end;i++)
    {
        if(k>mid)
        {
            b[i]=a[t];
            t++;
            continue;
        }
        if(t>end)
        {
            b[i]=a[k];
            k++;
            continue;
        }
        if(a[k]>=a[t])
        {
            b[i]=a[t];
            t++;
        }
        else
        {
            b[i]=a[k];
            k++;
        }
    }
    for(i=begin;i<=end;i++)
        a[i]=b[i];

}

void MergeMinTest()            //测试10000数据量
{
    int *temp;
    srand((unsigned int)time(0));
    for(int i=0;i<min;i++)
    {
        b[i]=rand()+1;
    }
    clock_t start=clock();
    MergeSort(b,0,(min-1)/2,min-1,temp);
    clock_t finish=clock();
    if(isSorted(b,min))
        printf("%lf ms\n",(double)(finish-start));
    else    printf("排序失败！\n");
    //for(int i=min-50;i<min;i++)  printf("%d\n",b[i]);
}

void MergeMidTest()            //测试50000数据量
{
    int *temp;
    srand((unsigned int)time(0));
    for(int i=0;i<Mid;i++)
    {
        b[i]=rand()*2+1;
    }
    clock_t start=clock();
    MergeSort(b,0,(Mid-1)/2,Mid-1,temp);
    clock_t finish=clock();
    if(isSorted(b,Mid))
        printf("%lf ms\n",(double)(finish-start));
    else    printf("排序失败！\n");
    //for(int i=Mid-50;i<Mid;i++)  printf("%d\n",b[i]);
}

void MergeMaxTest()
{
    int *temp;
    srand((unsigned int)time(0));
    for(int i=0;i<max;i++)
    {
        b[i]=rand()*10+1;
    }
    clock_t start=clock();
    MergeSort(b,0,(max-1)/2,max-1,temp);
    clock_t finish=clock();
    if(isSorted(b,max))
        printf("%lf ms\n",(double)(finish-start));
    else    printf("排序失败！\n");
    //for(int i=max-50;i<max;i++)  printf("%d\n",b[i]);
}

void MergeTest()
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
            case 1:MergeMinTest();break;
            case 2:MergeMidTest();break;
            case 3:MergeMaxTest();break;
            default:printf("输入的选择不在范围内！\n");
        }
    }
}
