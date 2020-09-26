#include<bits/stdc++.h>
using namespace std;
long long int ans;
long long int recurse(long long int n)
{
    if(n<=1&&ans!=0)return 1;
    ans++;
    if(n&1) recurse(3*n+1);
    else recurse(n/2);
}
int main()
{
    long long int n,m,l,h,maximum,number;
    while(scanf("%lld%lld",&l,&h)==2&&(l!=0||h!=0))
    {
        ans=0,maximum=0;
        n=max(l,h);
        m=min(l,h);
        for(long long int i=m; i<=n; i++)
        {
            ans=0;
            recurse(i);
            if(ans>maximum)
            {
                maximum=ans;
                number=i;
            }
        }
        printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",m,n,number,maximum);
    }
    return 0;
}
