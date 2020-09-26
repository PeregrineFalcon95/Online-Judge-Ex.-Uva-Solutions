#include<stdio.h>
#include<math.h>
int main()
{
    long long int n,a,b,c,x,y,row,column;
    while(scanf("%lld",&n)==1&&n!=0)
    {
        x=sqrt(n);
        if(x*x<n)
            x++;
        y=n-(x-1)*(x-1);
        if(x%2==0)
        {
            if(x>y)
            {
                column=y;
                row=x;
            }
            else
            {
                column=x;
                row=1+x*x-n;
            }
        }
        if(x%2!=0)
        {
            if(x>y)
            {
                column=x;
                row=y;
            }
            else
            {
                column=1+x*x-n;
                row=x;
            }
        }
        printf("%lld %lld\n",column,row);
    }
    return 0;
}

