#include<stdio.h>
int main()
{
    long long int a,b,c,d,e,f,g,h,i,j,n;
    i=1;
    while(i<101)
    {
        scanf("%lld",&a);
        if(a<0)
            break;
        c=0;
        e=1;
        while(a>0)
        {
            b=a%3;
            c=c+b*e;
            a/=3;
            e*=10;
        }
        printf("%lld\n",c);
        i++;
    }
    return 0;
}
