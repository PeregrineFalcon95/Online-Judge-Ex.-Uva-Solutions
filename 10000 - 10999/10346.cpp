#include<stdio.h>
int main()
{
    int n,k,sum,l;
    while(scanf("%d %d",&n,&k)==2)
    {
        sum=n;
        while(n>=k)
        {
            l=n/k;
            sum+=l;
            n=(n%k)+(n/k);
        }
        printf("%d\n",sum);
    }
    return 0;
}
