#include<bits/stdc++.h>
using namespace std;
bool status[1000020];
vector < int > prime;
void seive();
void solution(int l, int u);
int main()
{
    seive();
    int t,l,u;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&l,&u);
        solution(l,u);
    }
    return 0;
}
void seive()
{
    int n=1000010;
    int sq=sqrt(n);
    int wz=0;
    prime.push_back(2);
    for(int i=3; i<=sq; i+=2)
    {
        if(!status[i])
        {
            prime.push_back(i);
            wz=i;
            for(int j=i*i; j<=n; j+=(i+i))status[j]=1;
        }
    }
    for(int i=wz+2; i<=n; i+=2){if(!status[i])prime.push_back(i);}
}
void solution(int l, int u)
{
    if(l<2)l=2;
    vector < int >::iterator low=lower_bound(prime.begin(),prime.end(),l);
    int lower=low-prime.begin();
    vector < int > ::iterator hi=upper_bound(prime.begin(), prime.end(),u);
    int upper=hi-prime.begin();
    map < int, int > mp;
    int mx=0;
    if(prime[upper]>u)upper--;
    for(int i=lower; i<=upper; i++)
    {
        if(i==lower)continue;
        int a=prime[i]-prime[i-1];
        mp[a]++;
        if(mp[a]>mx)mx=mp[a];
    }
    vector < int > ans;
    for(map<int, int >::iterator it=mp.begin(); it!=mp.end(); it++)
    {
        if(it->second == mx)
        {
            ans.push_back(it->first);
        }
    }
    if(ans.size()>1 || ans.empty())printf("No jumping champion\n");
    else printf("The jumping champion is %d\n",ans.back());
}
