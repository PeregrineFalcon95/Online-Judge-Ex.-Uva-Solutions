
#include<stdio.h>
int main()
{
    int c,e,t;
    double a,b,d;
    while(scanf("%d",&t)==1)
    {
        e=0;
        while(t--)
        {
            d=0;
            scanf("%lf %lf",&a,&b);
            if(b>0)
            d=b*0.55556;
            d=d+a;
            printf("Case %d: %.2lf\n",++e,d);
        }
    }
    return 0;
}









