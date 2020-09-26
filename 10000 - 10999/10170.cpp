#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n,m;
    while(scanf("%lld%lld",&n,&m)==2)
    {
        ll ans=n;
        while(1)
        {
            if(ans>=m)break;
            ans+=(n+1);
            n++;
        }
        printf("%d\n",n);
    }
    return 0;
}

