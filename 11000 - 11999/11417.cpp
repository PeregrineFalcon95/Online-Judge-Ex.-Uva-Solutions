#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)==1&&n!=0)
    {
        int ans=0;
        for(int i=1; i<n; i++){for(int j=i+1; j<=n; j++){ans+=__gcd(i,j);}}
        printf("%d\n",ans);
    }
    return 0;
}

