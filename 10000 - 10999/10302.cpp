//UVA-10302


#include<stdio.h>
int main()
{
    long long int i,x,sum;
    while(scanf("%lld",&x)==1)
    {
        sum=0;
        for(i=1;i<=x;i++)
        {
            sum+=(i*i*i);
        }
        printf("%lld\n",sum);
    }
    return 0;
}
