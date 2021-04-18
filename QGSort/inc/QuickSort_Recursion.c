#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include <math.h>
#define max 200000
#define Mid 50000
#define min 10000


extern int isSorted(int a[],int n);
int b[max+5];

typedef struct Node
{
    int left;
    int right;
    struct Node *next;
}Node;

typedef struct Stack
{
    Node *data;
    int top;
}Stack;

int GetMid(int *a, int begin, int end)          //找中间枢纽
{
    int key=a[begin];
    while(begin<end)
    {
        while(begin<end)
        {
            if(key<a[end])
                end--;
            else
            {
                a[begin]=a[end];
                begin++;
                break;
            }
        }
        while(begin<end)
        {
            if(a[begin]<key)    begin++;
            else
            {
                a[end]=a[begin];
                end--;
                break;
            }
        }
    }
    a[end]=key;
    return begin;
}

void QuickSort_Recursion(int *a,int len)
{
    Stack s;

    s.top=0;
    s.data=NULL;
    Node *node=(Node *)malloc(sizeof(Node)),*node2;
    node->left=0;
    node->right=len-1;
    node->next=s.data;
    s.data=node;
    s.top++;

    while(s.top>0)
    {
        s.top--;                                //出栈
        node=s.data;
        s.data=node->next;
        int mid=GetMid(a,node->left,node->right);

        if(mid-node->left>1)
        {
            node2=(Node *)malloc(sizeof(Node));             //入栈
            node2->left=node->left;
            node2->right=mid-1;
            node2->next=s.data;
            s.data=node2;
            s.top++;
        }

        if(node->right-mid>1)
        {
            node2=(Node *)malloc(sizeof(Node));             //入栈
            node2->left=mid+1;
            node2->right=node->right;
            node2->next=s.data;
            s.data=node2;
            s.top++;
        }
        free(node);
    }
    free(s.data);
}



void QR_MinTest()
{
    srand((unsigned int)time(0));
    for(int i=0;i<min;i++)
    {
        b[i]=rand()+1;
    }
    clock_t start=clock();
    QuickSort_Recursion(b,min);
    clock_t finish=clock();
    if(isSorted(b,min))
        printf("%lf ms\n",(double)(finish-start));
    else    printf("排序失败！\n");
    //for(int i=min-50;i<min;i++)  printf("%d\n",b[i]);
}

void QR_MidTest()
{
    srand((unsigned int)time(0));
    for(int i=0;i<Mid;i++)
    {
        b[i]=rand()*2+1;
    }
    clock_t start=clock();
    QuickSort_Recursion(b,Mid);
    clock_t finish=clock();
    if(isSorted(b,Mid))
        printf("%lf ms\n",(double)(finish-start));
    else    printf("排序失败！\n");
    //for(int i=mid-50;i<mid;i++)  printf("%d\n",b[i]);
}

void QR_MaxTest()
{
    srand((unsigned int)time(0));
    for(int i=0;i<max;i++)
    {
        b[i]=rand()*10+1;
    }
    clock_t start=clock();
    QuickSort_Recursion(b,max);
    clock_t finish=clock();
    if(isSorted(b,max))
        printf("%lf ms\n",(double)(finish-start));
    else    printf("排序失败！\n");
    //for(int i=max-50;i<max;i++)  printf("%d\n",b[i]);
}

void QR_Test()
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
            case 1:QR_MinTest();break;
            case 2:QR_MidTest();break;
            case 3:QR_MaxTest();break;
            default:printf("输入的选择不在范围内！\n");
        }
    }
}
