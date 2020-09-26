#include<stdio.h>
int main()
{
    long long int n,i,num,a,sum,b,c;
    while(scanf("%lld",&n)==1)
    {
        for(i=1; i<=n; i++)
        {
            scanf("%lld",&num);
            a=num;
            while(1)
            {
                b=a;
                sum=0;
                while(b>0)
                {
                    c=b%10;
                    c*=c;
                    sum+=c;
                    b/=10;
                }
                a=sum;
                if(a<=9)
                {
                    break;
                }
            }
            if(a==1)
                printf("Case #%lld: %lld is a Happy number.\n",i,num);
            else
                printf("Case #%lld: %lld is an Unhappy number.\n",i,num);
        }
    }
    return 0;
}
