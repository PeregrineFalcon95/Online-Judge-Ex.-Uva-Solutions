#include<stdio.h>
int main()
{
    long long int a,b,c;
    while(scanf("%lld",&a)==1)
    {
        if(a<0)
        {
            if(a%2==0)
                printf("Underflow!\n");
            else
                printf("Overflow!\n");
        }
        else if(a<8)
            printf("Underflow!\n");
        else if(a>13)
            printf("Overflow!\n");
        else
        {
            c=1;
            for(b=a; b>0; b--)
            {
                c*=b;
            }
            printf("%lld\n",c);
        }
    }
    return 0;
}
