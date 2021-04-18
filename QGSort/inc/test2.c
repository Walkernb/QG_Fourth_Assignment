#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define N 100
#define M 100000

extern void insertSort(int *a,int n);
extern int isSorted(int a[],int n);
extern void  MergeSort(int *a,int begin,int mid,int end,int *temp);
extern void MergeArray(int *a,int begin,int mid,int end,int *temp);
extern void QuickSort(int *a, int begin, int end);
extern void RadixCountSort(int *a,int size);
extern void CountSort(int *a, int size , int Max);
extern void QuickSort2(int *a, int begin, int end);
extern int GetMid(int *a, int begin, int end);
extern void QuickSort_Recursion(int *a,int len);

void Test2()
{
    clock_t start,finish,sum=0;
    int j=0;
    int a[105];
    srand((unsigned int)time(0));
    while(j<M)
    {
        for(int i=0;i<N;i++)
            a[i]=rand()%100+1;
        start=clock();
        insertSort(a,N);
        finish=clock();
        if(isSorted(a,N))   sum+=(finish-start);
        else
        {
            printf("��������ʧ�ܣ�\n");
            return ;
        }
        j++;
    }
    printf("����������ʱ��%lf ms\n",(double)sum);
    sum=0;
    j=0;

    while(j<M)
    {
        int *temp;
        for(int i=0;i<N;i++)
            a[i]=rand()%100+1;
        start=clock();
        MergeSort(a,0,(N-1)/2,N-1,temp);
        finish=clock();
        if(isSorted(a,N))   sum+=(finish-start);
        else
        {
            printf("�鲢����ʧ�ܣ�\n");
            return ;
        }
        j++;
    }
    printf("�鲢������ʱ��%lf ms\n",(double)sum);
    sum=0;
    j=0;

    while(j<M)
    {
        for(int i=0;i<N;i++)
            a[i]=rand()%100+1;
        start=clock();
        QuickSort(a,0,N-1);
        finish=clock();
        if(isSorted(a,N))   sum+=(finish-start);
        else
        {
            printf("��������ʧ�ܣ�\n");
            return ;
        }
        j++;
    }
    printf("����������ʱ��%lf ms\n",(double)sum);
    sum=0;
    j=0;

    while(j<M)
    {
        for(int i=0;i<N;i++)
            a[i]=rand()%100+1;
        start=clock();
        QuickSort2(a,0,N-1);
        finish=clock();
        if(isSorted(a,N))   sum+=(finish-start);
        else
        {
            printf("��������(������)ʧ�ܣ�\n");
            return ;
        }
        j++;
    }
    printf("��������(������)��ʱ��%lf ms\n",(double)sum);
    sum=0;
    j=0;

    while(j<M)
    {
        for(int i=0;i<N;i++)
            a[i]=rand()%100+1;
        start=clock();
        RadixCountSort(a,N);
        finish=clock();
        if(isSorted(a,N))   sum+=(finish-start);
        else
        {
            printf("������������ʧ�ܣ�\n");
            return ;
        }
        j++;
    }
    printf("��������������ʱ��%lf ms\n",(double)sum);
    sum=0;
    j=0;

    while(j<M)
    {
        for(int i=0;i<N;i++)
            a[i]=rand()%100+1;
        start=clock();
        CountSort(a,N,100);
        finish=clock();
        if(isSorted(a,N))   sum+=(finish-start);
        else
        {
            printf("��������ʧ�ܣ�\n");
            return ;
        }
        j++;
    }
    printf("����������ʱ��%lf ms\n",(double)sum);
    sum=0;
    j=0;

    while(j<M)
    {
        for(int i=0;i<N;i++)
            a[i]=rand()%100+1;
        start=clock();
        QuickSort_Recursion(a,100);
        finish=clock();
        if(isSorted(a,N))   sum+=(finish-start);
        else
        {
            printf("��������ʧ�ܣ�\n");
            return ;
        }
        j++;
    }
    printf("��������(�ǵݹ�)��ʱ��%lf ms\n",(double)sum);
    sum=0;
    j=0;
}
