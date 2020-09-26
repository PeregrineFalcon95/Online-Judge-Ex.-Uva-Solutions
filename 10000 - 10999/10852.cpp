#include<bits/stdc++.h>
using namespace std;
bool status[10021];
vector < int > prime;
void seive();
void solution(int n);
int main()
{
    seive();
    int n,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        solution(n);
    }
    return 0;
}
void seive()
{
    int n=10020;
    int sq=sqrt(n+1);
    prime.push_back(2);
    int wz=0;
    for(int i=3; i<=sq; i+=2)
    {
        if(!status[i])
        {
            wz=i;
            prime.push_back(i);
            for(int j=(i*i); j<=n; j+=(i+i))status[j]=1;
        }
    }
    for(int i=wz+2; i<=n; i+=2)
    {
        if(!status[i])prime.push_back(i);
    }
}
void solution(int n)
{
    vector <int >::iterator low=lower_bound(prime.begin(),prime.end(),n);
    int lo=low-prime.begin();
    int p=1;
    int mx=0,pri=0;
    int limit;
    if(n%2==0)limit=(n+2)/2;
    else limit=(n+1)/2;
    while(1)
    {
        for(int i=1; i<=limit; i++)
        {
            int x=prime[lo];
            int a=x*i;
            if(a>n){lo--;break;}
            if(a<=n && (i+1)*x>n && n-(i*x) > mx)
            {
                pri=x;
                mx=n-(i*x);
            }
        }
        if(lo<0)break;
    }
    printf("%d\n",pri);
    return;
}
