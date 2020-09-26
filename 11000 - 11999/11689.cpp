#include<bits/stdc++.h>
using namespace std;
#define sc scanf
#define pi printf
int main()
{
    int t,a,b,c,d;
    while(sc("%d",&t)==1)
    {
        while(t--)
        {
            sc("%d%d%d",&a,&b,&c);
            a+=b;
            d=0;
            while(a>=c)
            {
                d+=a/c;
                b=a%c;
                a/=c;
                a+=b;
            }
            pi("%d\n",d);
        }
    }
    return 0;
}
