#include<stdio.h>
int main()
{
    while(1)
    {
        int n,i,f,l;
        scanf("%d",&n);
        if(n==0)
        {
            break;
        }
        else if(n<=2000000000)
        {
            while(n>9)
            {
                f=0;
                l=0;
                while(n!=0)
                {
                    l=n%10;
                    f+=l;
                    n=n/10;
                }
                n=f;
            }
            printf("%d\n",n);
        }
    }
    return 0;
}
