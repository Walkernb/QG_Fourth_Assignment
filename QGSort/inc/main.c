/**
*   ��ɫ�����ȶ����ڴ��������»����
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>


int isSorted(int a[],int n)
{
    for(int i=1;i<n;i++)
        if(a[i-1]>a[i]) return 0;
    return 1;
}

extern void MainInterFace();
extern void Test();
extern void Test2();
extern void AppliySort();

int main()
{

    int p=1;
    char c[20];
    while(p)
    {
        MainInterFace();
        scanf("%s",c);
        if(strlen(c)>1) printf("��������\n");
        else
        {
            int n=c[0]-'0';
            switch(n)
            {
                case    1: Test();break;
                case    2: Test2();break;
                case    3: AppliySort();break;
                case    0:p=0;break;
                default:printf("�����ѡ���ڷ�Χ�ڣ�\n");
            }
        }
    }
    return 0;
}
