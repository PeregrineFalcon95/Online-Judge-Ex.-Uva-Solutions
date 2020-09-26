#include<stdio.h>
int main()
{
    int a,b,c;
    while(scanf("%d",&a)==1&&a!=0)
    {
        c=0;
        while(a>2)
        {
            b=a%3;
            a/=3;
            c+=a;
            a=a+b;
        }
        if(a==2)
            printf("%d\n",c+1);
        else
            printf("%d\n",c);
    }
    return 0;
}
