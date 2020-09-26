//problem: 10055
#include<stdio.h>
int main()
{
    long long int a,b,c;
    while(scanf("%lld %lld",&a,&b)==2)
    {
        if(a>b)
            c=a-b;
        else
            c=b-a;
        printf("%lld\n",c);
    }
    return 0;
}
