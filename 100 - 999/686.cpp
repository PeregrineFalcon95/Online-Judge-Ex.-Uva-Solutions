#include<bits/stdc++.h>
using namespace std;
bool status[32800];
int prime[3550];
void sieve();
int main()
{
    sieve();
    int n;
    while(scanf("%d",&n)==1&&n!=0)
    {
        int ans=0,m=n/2;
        for(int i=1; ; i++)
        {
            if(prime[i]*2>=n+1)break;
            int t=n-prime[i];
            if(status[t]==0)ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
void sieve()
{
    int a=1,n=32800;
    int sq=sqrt(n);
    for(int i=4; i<=n; i+=2)status[i]=1;
    prime[a++]=2;
    for(int i=3; i<=sq; i+=2)
    {
        if(status[i]==0)
        {
            prime[a++]=i;
            for(int j=i*i; j<=n; j+=2*i)status[j]=1;
        }
    }
    for(int i=183; i<=n; i+=2)
    {
        if(status[i]==0)prime[a++]=i;
    }
}

