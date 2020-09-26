#include<stdio.h>
int main()
{
    unsigned long long int a,b,c,i,n;
    while(scanf("%llu",&n)==1)
    {
        a=0;
        for(i=1; i<=n; i+=2)
        {
            a+=i;
        }
        b=((a*2)-1);
        c=b+(b-2)+(b-4);
        printf("%llu\n",c);
    }
    return 0;
}
