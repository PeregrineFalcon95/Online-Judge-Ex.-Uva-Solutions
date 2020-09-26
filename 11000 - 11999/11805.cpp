//UVA-11805
#include<stdio.h>
int main()
{
    int a,b,c,n,k,p,i,t;
    while(scanf("%d",&t)==1)
    {
        for(i=1; i<=t; i++)
        {
            scanf("%d %d %d",&n,&k,&p);
            if(n==p)
                a=k;
            else if(n>p)
            {
                a=k-(n-p);
                a=p+k;
                while(a>n)
                {
                    a-=n;
                }
                if(a==0)
                    a=n;
            }
            else if(n<p)
            {
                a=p+k;
                while(a>n)
                {
                    a-=n;
                }
                if(a==0)
                    a=n;
            }
            printf("Case %d: %d\n",i,a);
        }
    }
    return 0;
}
