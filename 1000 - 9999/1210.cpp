#include<bits/stdc++.h>
using namespace std;
bool status[10020];
vector < int > prime;
void seive();
void solution(int n);
int main()
{
    seive();
    int n;
    while(scanf("%d",&n)==1 && n!=0)
    {
        solution(n);
    }
    return 0;
}
void seive()
{
    int n=10001;
    int sq=sqrt(n);
    prime.push_back(2);
    int wz=0;
    for(int i=3; i<=sq; i+=2)
    {
        if(!status[i])
        {
            wz=i;
            prime.push_back(i);
            for(int j=i*i; j<=n; j+=(i+i))status[j]=1;
        }
    }
    for(int i=wz+2; i<=n; i+=2){if(!status[i])prime.push_back(i);}
}
void solution(int n)
{
    int sz=prime.size();
    deque < int > dq;
    int sum=0;
    int ans=0;
    for(int i=0; i!=sz; i++)
    {
        while(sum>n)
        {
            sum-=dq.front();
            dq.pop_front();
        }
        if(sum==n){sum-=dq.front();dq.pop_front();ans++;}
        dq.push_back(prime[i]);
        sum+=prime[i];
        if(prime[i]>n)break;
    }
    printf("%d\n",ans);
}
