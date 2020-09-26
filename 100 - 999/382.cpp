#include<stdio.h>
int main()
{
    int n,sum,i;
    printf("PERFECTION OUTPUT\n");
    while(scanf("%d",&n)==1)
    {
        if(n==0)
        {
            printf("END OF OUTPUT\n");
            break;
        }
        sum=0;
        for(i=1; i<=n/2; i++)
        {
            if(n%i==0)
                sum+=i;
        }
        if(sum==n)
            printf("%5d  PERFECT\n",n);
        if(sum>n)
            printf("%5d  ABUNDANT\n",n);
        if(sum<n)
            printf("%5d  DEFICIENT\n",n);
    }
    return 0;
}
