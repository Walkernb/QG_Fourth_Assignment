
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

extern void insertTest();
extern void MergeTest();
extern void QuickTest();
extern void RadixCountTest();
extern void CountTest();
extern void enQuickTest();
void QR_Test();

void interFace()
{
    int i;
    printf("\n");
    for(i=0;i<35;i++)   printf(" ");
    for(i=0;i<40;i++)   printf("*");    printf("\n");

    for(i=0;i<35;i++)   printf(" ");    printf("*");
    printf("     1        ��������                ");     printf("*\n");

    for(i=0;i<35;i++)   printf(" ");    printf("*");
    printf("     2        �鲢����                ");     printf("*\n");

    for(i=0;i<35;i++)   printf(" ");    printf("*");
    printf("     3        ��������                ");     printf("*\n");

    for(i=0;i<35;i++)   printf(" ");    printf("*");
    printf("     4        ��������(������)      ");     printf("*\n");

    for(i=0;i<35;i++)   printf(" ");    printf("*");
    printf("     5        ��������(�ǵݹ�)        ");     printf("*\n");

    for(i=0;i<35;i++)   printf(" ");    printf("*");
    printf("     6        ��������                ");     printf("*\n");

    for(i=0;i<35;i++)   printf(" ");    printf("*");
    printf("     7        ������������            ");     printf("*\n");

    for(i=0;i<35;i++)   printf(" ");
    for(i=0;i<40;i++)   printf("*");    printf("\n");

    printf("���������ѡ��");
}

void Test()
{
    int p=1;
    char c[20];
    interFace();
    scanf("%s",c);
    if(strlen(c)>1) printf("��������\n");
    else
    {
        int n=c[0]-'0';
        switch(n)
        {
            case 1:insertTest();break;
            case 2:MergeTest();break;
            case 3:QuickTest();break;
            case 4:enQuickTest();break;
            case 5:QR_Test();break;
            case 6:CountTest();break;
            case 7:RadixCountTest();break;
            default:printf("�����ѡ���ڷ�Χ�ڣ�\n");
        }
    }
}
