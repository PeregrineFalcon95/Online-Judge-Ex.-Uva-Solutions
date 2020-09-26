#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n;
    scanf("%lld",&n);
    while(n--)
    {
        ll m,t=0,r=0,q=0,sum=0;
        vector < ll > digit;
        scanf("%lld",&m);
        t=m;
        while(t>0)
        {
            q++;
            r=t%10;
            t/=10;
            digit.push_back(r);
        }
        for(auto it : digit)sum+=(pow(it,q));
        if(sum==m)printf("Armstrong\n");
        else printf("Not Armstrong\n");
    }
    return 0;
}

