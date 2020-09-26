#include<stdio.h>
#include<math.h>
int main()
{
    double r;
    int a,b,count,i;
    while(scanf("%d %d",&a,&b)<=201 && a!=0 && b!=0)
    {
        count=0;
        for(i=a; i<=b; i++)
        {
            r=sqrt(i);
            if(r-(int)r==0)
                count++;
        }
        printf("%d\n",count);
    }
    return 0;
}

