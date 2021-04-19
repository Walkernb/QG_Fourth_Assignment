/**
*   颜色排序不稳定，在大数据量下会出错。
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>


int isSorted(int a[],int n)                 //判断数组是否有序
{
    for(int i=1;i<n;i++)
        if(a[i-1]>a[i]) return 0;
    return 1;
}

extern void MainInterFace();
extern void Test();                 //大数据量测试
extern void Test2();                //100*100k测试
extern void AppliySort();           //排序的应用

int main()
{

    int p=1;
    char c[20];
    while(p)
    {
        MainInterFace();
        scanf("%s",c);
        if(strlen(c)>1) printf("输入有误！\n");
        else
        {
            int n=c[0]-'0';
            switch(n)
            {
                case    1: Test();break;
                case    2: Test2();break;
                case    3: AppliySort();break;
                case    0:p=0;break;
                default:printf("输入的选择不在范围内！\n");
            }
        }
    }
    return 0;
}
