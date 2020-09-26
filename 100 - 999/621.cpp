#include<stdio.h>
int main()
{
    long long int a,b,c,d=0,e,f,i;
    while(scanf("%lld %lld",&a,&b)==2&&(a>0||b>0))
    {
        e=a;
        c=1;
        while(e!=1)
        {
            if(e%2==0)
                e/=2;
            else
                e=3*e+1;
            if(e>b)
                break;
            c++;
        }
        printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n",++d,a,b,c);
    }
    return 0;
}
