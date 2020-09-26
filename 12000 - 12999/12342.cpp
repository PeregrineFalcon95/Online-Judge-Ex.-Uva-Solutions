#include<bits/stdc++.h>
using namespace std;
#define sc scanf
#define pi printf
#define lld long long int
int main()
{
    lld in,n,t,a,b;
    double tx;
    while(sc("%lld",&n)==1)
    {
        t=0;
        while(n--)
        {
            tx=0;
            sc("%lld",&in);
            b=in;
            if(in>180000)
            {
                in-=180000;
                if(in<300000)tx+=(in*0.10);
                if(in>=300000)
                {
                    tx+=30000;
                    in-=300000;
                    if(in<400000)tx+=(in*0.15);
                    if(in>=400000)
                    {
                        tx+=60000;
                        in-=400000;
                        if(in<300000)tx+=(in*0.20);
                        if(in>=300000)
                        {
                            tx+=60000;
                            in-=300000;
                            if(in>0)
                            {
                                tx+=(in*0.25);
                            }
                        }
                    }
                }
            }
            a=tx;
            if(a<tx)a++;
            if(a<2000&&b>180000)a=2000;

            pi("Case %lld: %lld\n",++t,a);
        }
    }
    return 0;
}

