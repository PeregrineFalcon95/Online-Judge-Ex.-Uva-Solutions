#include<stdio.h>
int main()
{
    long long int a,b,c,d,t;
    while(scanf("%lld",&t)==1)
    {
        d=1;
        while(t--)
        {
            scanf("%lld %lld %lld",&a,&b,&c);
            if(a>=b+c||b>=a+c||c>=a+b||a<=0||b<=0||c<=0)
                printf("Case %lld: Invalid\n",d++);
            else if(a==b&&b==c)
                printf("Case %lld: Equilateral\n",d++);
            else if((a==b)||(b==c)||(c==a))
                printf("Case %lld: Isosceles\n",d++);
            else
                printf("Case %lld: Scalene\n",d++);
        }
    }
    return 0;
}

