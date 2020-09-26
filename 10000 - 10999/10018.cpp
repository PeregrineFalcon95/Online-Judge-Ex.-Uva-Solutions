#include<stdio.h>
int main()
{
    long int t,n,m,p,r,i,j,k,rev,q,add,s,count;
    while(scanf("%ld",&t)==1)
    {
        for(i=1; i<=t; i++)
        {
            scanf("%ld",&n);
            count=q=s=0;
            while(count==0)
            {
                m=n;
                rev=0;
                while(m != 0)
                {
                    r=m%10;
                    rev=rev*10+r;
                    m/=10;
                }
                if(n==rev && q!=0)
                {
                    count=1;
                    break;
                }
                n+=rev;
                s++;;
                q=1;
            }
            printf("%ld %ld\n",s,n);
        }
    }
    return 0;
}
