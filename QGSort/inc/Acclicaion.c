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

void GetNumber()               //�ҵ�K�����
{
    printf("����������ĳ��ȣ�");
    int size;
    scanf("%d",&size);
    printf("���������飺");
    int a[size];
    for(int j=0;j<size;j++) scanf("%d",&a[j]);
    printf("������Ҫ�������ֵ�λ�ã�");
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
    printf("No.%d��%d\n",n,a[i]);
}


void ColorSort()
{
    printf("�����������ָ�����ȵ�����,���������鳤�ȣ�");
    int size;
    scanf("%d",&size);
    printf("������ɵ����飺");

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
    printf("�������������飺");
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
    printf("1       ��ɫ����\n");
    printf("2       �ҵ���K����\n");
    printf("���������ѡ��");
    scanf("%s",c);
    if(strlen(c)>1)
    {
        printf("��������\n");
        return ;
    }
    else
    {
        int n=c[0]-'0';
        switch(n)
        {
            case 1:ColorSort() ;break;
            case 2:GetNumber() ;break;
            default:printf("���벻�ڷ�Χ�ڣ�\n");
        }
    }
}
