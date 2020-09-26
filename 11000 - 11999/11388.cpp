#include<stdio.h>
int main()
{
    int a,b,t;
    while(scanf("%d",&t)==1)
    {
        while(t--)
        {
            scanf("%d %d",&a,&b);
            if(b%a==0)
                printf("%d %d\n",a,b);
            else
                printf("-1\n");
        }
    }
    return 0;
}

