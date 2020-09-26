#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector < int >prime;
bool seive_status[47000];
void seive();
void seg_solution(ll l, ll u);
int main()
{
    seive();
    ll l,u;
    while(scanf("%lld%lld",&l,&u)==2)
    {
        seg_solution(l,u);
    }
    return 0;
}
void seive()
{
    int n=47000;
    int sq=sqrt(n);
    prime.push_back(2);
    int flag=0;
    for(int i=3; i<=sq; i+=2)
    {
        if(!seive_status[i])
        {
            flag=i;
            prime.push_back(i);
            for(int j=i*i; j<=n; j+=(i+i))seive_status[i]=1;
        }
    }
    for(int i=flag+2; i<=n; i+=2)
    {
        if(!seive_status[i])prime.push_back(i);
    }
}
void seg_solution(ll l, ll u)
{
    if(l==1)l++;
    vector < ll > seg_prime;
    int sq=sqrt(u);
    int range=u-l+1;
    int sz=prime.size();
    bool status[range];
    memset(status, 0 ,sizeof status);
    for(int i=0; i!=sz; i++)
    {
        if(prime[i]>sq)break;
        int p=prime[i];
        ll j=p*p;
        if(j<l)j=((l+p-1)/p)*p;
        for(; j<=u; j+=p)
        {
            status[j-l]=1;
        }
    }
    if(l<=2)seg_prime.push_back(2);
    for(ll i=l; i<=u; i++)
    {
        if(!status[i-l] && i&1)seg_prime.push_back(i);
    }
    ll mi_f,mi_s,mx_f,mx_s,jerry=0,mi_dis=INT_MAX,mx_dis=0;
    int wizer=seg_prime.size();
    for(int i=0; i!=wizer; i++)
    {
        int dis=seg_prime[i]-seg_prime[i-1];
        if(i && dis<mi_dis)
        {
            mi_f=seg_prime[i-1];
            mi_s=seg_prime[i];
            mi_dis=dis;
        }
        if(i && dis>mx_dis)
        {
            mx_f=seg_prime[i-1];
            mx_s=seg_prime[i];
            mx_dis=dis;
        }
    }
    if(mx_dis)
    {
        printf("%lld,%lld are closest, %lld,%lld are most distant.\n",mi_f,mi_s,mx_f,mx_s);
    }
    else printf("There are no adjacent primes.\n");
}

