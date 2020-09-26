#include<stdio.h>
int main()
{
    long long int a,b,c,d,e,f,g,h;
    while(scanf("%lld",&a)==1&&a>=0)
    {
        f=g=b=0;
        c=d=1;
        h=e=2;
        if(a==0)
            printf("0 1\n");
        else if(a==1)
            printf("1 2\n");
        else
        {
            while(h<=a)
            {
                f=b+c+1;
                b=c;
                c=f;
                g=d+e+1;
                d=e;
                e=g;
                h++;
            }
            printf("%lld %lld\n",f,g);
        }
    }
    return 0;
}
