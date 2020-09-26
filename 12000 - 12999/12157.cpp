#include<bits/stdc++.h>
using namespace std;
#define sc scanf
#define pi printf
int main()
{
    int ar[22],t,n,a,b,c,mi,ju;
    while(sc("%d",&t)==1)
    {
        a=0;
        while(t--)
        {
            sc("%d",&n);
            mi=ju=0;
            for(int i=0;i<n;i++)
            {
                sc("%d",&b);
                c=b;
                while(c>=0)
                {
                    c-=60;
                    ju+=15;
                }
                while(b>=0)
                {
                    b-=30;
                    mi+=10;
                }
            }
            if(ju<mi)pi("Case %d: Juice %d\n",++a,ju);
            else if(mi<ju)pi("Case %d: Mile %d\n",++a,mi);
            else pi("Case %d: Mile Juice %d\n",++a,ju);
        }
    }
    return 0;
}
