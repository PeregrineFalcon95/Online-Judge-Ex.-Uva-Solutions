#include<bits/stdc++.h>
using namespace std;
#define lld long long int
lld m;
lld bigmod(lld n, lld p)
{
    if(p==0) return 1;
    if(p%2==0)
    {
        lld r=bigmod(n,p/2);
        return ((r%m)*(r%m))%m;
    }
    else return ((n%m)*bigmod(n,p-1)%m)%m;
}
int main()
{
    lld n,p;
    while(scanf("%lld%lld%lld",&n,&p,&m)==3)
    {
        printf("%lld\n",bigmod(n,p));
    }
    return 0;
}

