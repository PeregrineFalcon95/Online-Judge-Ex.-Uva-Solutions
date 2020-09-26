#include<stdio.h>
int main()
{
    int a,b,c,i;
    while(scanf("%d",&a)==1&&a!=0)
    {
        if(a<=100)
            printf("f91(%d) = 91\n",a);
        if(a>=101)
            printf("f91(%d) = %d\n",a,a-10);
    }
    return 0;
}
