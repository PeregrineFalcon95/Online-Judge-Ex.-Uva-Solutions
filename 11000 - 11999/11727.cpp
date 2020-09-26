//problem: 11727
#include<stdio.h>
int main()
{
    int T,a,b,c,i;
    scanf("%d",&T);
    if(T<20)
    {
        for(i=1; i<=T; i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            if(1000<=a<=10000 && 1000<=b<=10000 && 1000<=c<=10000)
            {
                if(a>b&&a>c)
                {
                    if(b>c)
                        printf("Case %d: %d\n",i,b);
                    else
                        printf("Case %d: %d\n",i,c);
                }
                if(b>a&&b>c)
                {
                    if(a>c)
                        printf("Case %d: %d\n",i,a);
                    else
                        printf("Case %d: %d\n",i,c);
                }
                if(c>a&&c>b)
                {
                    if(a>b)
                        printf("Case %d: %d\n",i,a);
                    else
                        printf("Case %d: %d\n",i,b);
                }
            }
        }
    }
    return 0;
}
