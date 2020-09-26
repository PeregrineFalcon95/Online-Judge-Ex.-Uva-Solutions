#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,t=0,n,k,x;
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d%d%d",&n,&k,&x);
        int mi=0,ans=(n*(n+1))/2;
        for(int i=x; i<x+k; i++)mi+=i;
        printf("Case %d: %d\n",++t,ans-mi);
    }
    return 0;
}
