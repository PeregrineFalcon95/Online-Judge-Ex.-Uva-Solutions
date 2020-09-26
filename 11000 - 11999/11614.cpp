#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
int main()
{
    ll n,m;
    scanf("%llu",&n);
    while(n--)
    {
        scanf("%llu",&m);
        ll ans=(sqrt(1+8*m)-1)/2;
        printf("%llu\n",ans);
    }
    return 0;
}
