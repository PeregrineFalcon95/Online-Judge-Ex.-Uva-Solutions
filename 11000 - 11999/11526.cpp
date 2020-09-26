#include<bits/stdc++.h>
using namespace std;
#define lld long long int
int main()
{
    int t;
    while(scanf("%d",&t)==1)
    {
        while(t--)
        {
            lld n;
            scanf("%lld",&n);
            lld sq=sqrt(n);
            lld sum=0;
            for(int i=1; i<=sq; i++)
            {
                sum+=n/i;
            }
            sum=(2*sum)-sq*sq;
            printf("%lld\n",sum);
        }
    }
    return 0;
}

