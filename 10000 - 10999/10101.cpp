#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,b,c,n,m=0;
    while(scanf("%lld",&n)==1)
    {
        c=0;
        printf("%4d.",++m);
        a=n/100000000000000;
        b=n%100000000000000;
        if(a>0)
        {
            printf(" %lld kuti",a);
            c++;
        }
        a=b/1000000000000;
        b=b%1000000000000;
        if(a>0)
        {
            printf(" %lld lakh",a);
            c++;
        }
        a=b/10000000000;
        b=b%10000000000;
        if(a>0)
        {
            printf(" %lld hajar",a);
            c++;
        }
        a=b/1000000000;
        b=b%1000000000;
        if(a>0)
        {
            printf(" %lld shata",a);
            c++;
        }
        a=b/10000000;
        b=b%10000000;
        if(a>0)
        {
            if(a>0)printf(" %lld kuti",a);
            c++;
        }
        else if(n>9999999)
        {
            printf(" kuti");
            c++;
        }
        a=b/100000;
        b=b%100000;
        if(a>0)
        {
            printf(" %lld lakh",a);
            c++;
        }
        a=b/1000;
        b=b%1000;
        if(a>0)
        {
            printf(" %lld hajar",a);
            c++;
        }
        a=b/100;
        b=b%100;
        if(a>0)
        {
            printf(" %lld shata",a);
            c++;
        }
        a=b/1;
        b=b%1;
        if(a>0)
        {
            printf(" %lld",a);

            c++;
        }
        if(a==0&&c==0)printf(" 0");
        printf("\n");
    }
    return 0;
}

