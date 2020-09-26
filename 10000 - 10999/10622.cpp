#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n;
    while(scanf("%lld",&n)==1 && n!=0)
    {
        ll mx=0,f=0;
        if(n>0)
        {
            ll sq=sqrt(n+1);
            for(ll i=2; i<=sq; i++)
            {
                for(ll j=2; j<=32; j++)
                {
                    double jerry=pow(i,j);
                    if(jerry>n)break;
                    if(n==jerry && mx<j)
                    {
                        mx=j;
                        break;
                    }
                }
            }
        }
        else
        {
            ll a=abs(n);
            ll sq = sqrt(a+1);
            for(ll i=-2; i>=-sq; i--)
            {
                for(ll j=2; j<=32; j++)
                {
                    double jerry=pow(i,j);
                    if(jerry<n && jerry<0)break;
                    if(n==jerry && mx<j)
                    {
                        mx=j;
                        break;
                    }
                }
            }
        }
        if(mx)printf("%lld\n",mx);
        else printf("1\n");
    }
    return 0;
}
