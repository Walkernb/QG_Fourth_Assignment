/**
*应用排序算法
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int FindMid(int *a,int left,int right)
{
    int key=a[left];
    while(left<right)
    {
        while(left<right&&key<a[right])
            right--;
        if(left<right)  a[left]=a[right],   left++;
        while(left<right&&key>a[left])
            left++;
        if(left<right)  a[right]=a[left],   right--;
    }
    a[left]=key;
    return left;
}

void GetNumber()               //找第K大的数
{
    printf("请输入数组的长度：");
    int size;
    scanf("%d",&size);
    printf("请输入数组：");
    int a[size];
    for(int j=0;j<size;j++) scanf("%d",&a[j]);
    printf("请输入要查找数字的位置：");
    int n;
    scanf("%d",&n);

    int i=FindMid(a,0,size-1);
    int l=0, r=size;
    while(i!=n-1)
    {
        if(i>n-1)
        {
            r=i;
            i=FindMid(a,l,r-1);
        }
        else
        {
            l=i+1;
            i=FindMid(a,l,r-1);
        }
    }
    printf("No.%d：%d\n",n,a[i]);
}


void ColorSort()
{
    printf("程序将随机生成指定长度的数组,请输入数组长度：");
    int size;
    scanf("%d",&size);
    printf("随机生成的数组：");

    int a[size+1];
    srand((unsigned int)time(0));
    for(int i=0;i<size;i++)
    {
        a[i]=rand()%3;
        printf("%d ",a[i]);
        if(i%20==0&&i!=0)   printf("\n");
    }
    printf("\n");

    int p,p1,p2,k;
    p=p1=0; p2=size-1;
    for(;p<=p2;p++)
    {
        if(a[p2]==2)    p2--;
        if(a[p2]==0)    k=a[p2],    a[p2]=a[p1],    a[p1]=k,     p1++;
        if(a[p1]==0)    p1++;
        if(a[p1]==2)    k=a[p2],    a[p2]=a[p1],    a[p1]=k,    p2--;
        if(a[p]==0&&p>p1)     k=a[p1],    a[p1]=a[p],     a[p]=k,     p1++;
        if(a[p]==2)     k=a[p2],    a[p2]=a[p],     a[p]=k,     p2--;
    }
    printf("经过排序后的数组：");
    for(int i=0;i<size;i++)
    {
        printf("%d ",a[i]);
        if(i%20==0&&i!=0)   printf("\n");
    }
    printf("\n");
}

void AppliySort()
{
    int n;
    char c[20];
    printf("1       颜色排序\n");
    printf("2       找到第K大数\n");
    printf("请输入你的选择：");
    scanf("%s",c);
    if(strlen(c)>1)
    {
        printf("输入有误！\n");
        return ;
    }
    else
    {
        int n=c[0]-'0';
        switch(n)
        {
            case 1:ColorSort() ;break;
            case 2:GetNumber() ;break;
            default:printf("输入不在范围内！\n");
        }
    }
}
