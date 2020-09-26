#include<stdio.h>
int main()
{
    int a,b,c;
    while(scanf("%d %d %d",&a,&b,&c)==3&&(a!=0||b!=0||c!=0))
    {
        a*=a;
        b*=b;
        c*=c;
        if(a==b+c||b==a+c||c==a+b)
            printf("right\n");
        else
            printf("wrong\n");
    }
    return 0;
}

