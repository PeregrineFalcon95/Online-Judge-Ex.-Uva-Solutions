#include<stdio.h>
int main()
{
    int a,b,c,t;
    while(scanf("%d",&t)==1)
    {
        while(t--)
        {
            scanf("%d %d %d",&a,&b,&c);
            if(a>=c+b||b>=a+c||c>=a+b||a<=0||b<=0||c<=0)
                printf("Wrong!!\n");
            else
                printf("OK\n");
        }
    }
    return 0;
}

