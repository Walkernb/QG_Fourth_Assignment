#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define max 200000
#define min 10000
#define mid 50000

extern int isSorted(int a[],int n);
int b[max+5];
int d[mid];
int c[max+5];
void CountSort(int *a, int size , int Max)
{
    memset(d,0,sizeof(d));
    int i,k;
    for(i=0;i<size;i++)
        d[a[i]]++;
    for(i=1;i<=Max;i++)
        d[i]+=d[i-1];
    for(i=size-1;i>=0;i--)
    {
        d[a[i]]--;
        k=d[a[i]];
        c[k]=a[i];
    }
    for(i=0;i<size;i++) a[i]=c[i];
}

void CountMinTest()
{
    srand((unsigned int)time(0));
    int Max=0;
    for(int i=0;i<min;i++)
    {
        b[i]=rand()/3+1;
        Max=Max>b[i]?Max:b[i];
    }
    clock_t start=clock();
    CountSort(b,min,Max);
    clock_t finish=clock();
    if(isSorted(b,min))
        printf("%lf ms\n",(double)(finish-start));
    else    printf("����ʧ�ܣ�\n");
}

void CountMidTest()
{
    srand((unsigned int)time(0));
    int Max=0;
    for(int i=0;i<mid;i++)
    {
        b[i]=rand()/3+1;
        Max=Max>b[i]?Max:b[i];
    }
    clock_t start=clock();
    CountSort(b,mid,Max);
    clock_t finish=clock();
    if(isSorted(b,mid))
        printf("%lf ms\n",(double)(finish-start));
    else    printf("����ʧ�ܣ�\n");
}

void CountMaxTest()
{
    srand((unsigned int)time(0));
    int Max=0;
    for(int i=0;i<max;i++)
    {
        b[i]=rand()/3+1;
        Max=Max>b[i]?Max:b[i];
    }
    clock_t start=clock();
    CountSort(b,max,Max);
    clock_t finish=clock();
    if(isSorted(b,max))
        printf("%lf ms\n",(double)(finish-start));
    else    printf("����ʧ�ܣ�\n");
}

void CountTest()
{
    char b[20];
    clock_t start,finish;
    srand((unsigned int)time(0));
    printf("1       ����10000������\n");
    printf("2       ����50000������\n");
    printf("3       ����200000������\n");
    printf("���������ѡ��");
    scanf("%s",b);
    if(strlen(b)>1) printf("�������");
    else
    {
        int i=b[0]-'0';
        switch(i)
        {
            case 1:CountMinTest();break;
            case 2:CountMidTest();break;
            case 3:CountMaxTest();break;
            default:printf("�����ѡ���ڷ�Χ�ڣ�\n");
        }
    }
}
