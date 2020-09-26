#include<bits/stdc++.h>
using namespace std;
#define sc scanf
#define pi printf
#define lld long long int
int main()
{
    int t,a,b,c,d,l,u;
    while(sc("%d",&t)==1)
    {
        while(t--)
        {
            sc("%d%d",&l,&u);
            d=b=0;
            c=1;
            for(int i=u; i>=l&&u!=1; i--)
            {
                a=sqrt(i);
                d=0;
                for(int j=1; j<=a; j++)
                {
                    if(i%j==0&&i!=1)
                    {
                        d++;
                        if(i/j!=j&&i/j<=i/2)d++;
                    }
                }
                if(d>=b)
                {
                    c=i;
                    b=d;
                }
            }
            pi("Between %d and %d, %d has a maximum of %d divisors.\n",l,u,c,++b);
        }
    }
    return 0;
}
