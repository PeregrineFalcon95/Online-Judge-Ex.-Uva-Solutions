#include<stdio.h>
#include<math.h>
int main()
{
    long long int a,b;
    while(scanf("%lld",&a)==1 && a!=0)
    {
        b=sqrt(a);
        b=b*b;
        if(a==b)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
