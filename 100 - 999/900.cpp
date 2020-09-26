#include<stdio.h>
int main()
{
    long long int a,b,c,d,i,n;
    while(scanf("%lld",&n)==1&&n!=0)
    {
        a=0;
        b=1;
        for(i=1; i<=n; i++)
        {
            c=a+b;
            a=b;
            b=c;
        }
        printf("%lld\n",c);
    }
    return 0;
}
