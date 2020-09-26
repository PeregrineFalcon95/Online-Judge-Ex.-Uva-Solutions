#include<bits/stdc++.h>
using namespace std;
bool status[1000020];
vector < int > prime;
void seive();
void cheker(int n);
int main()
{
    seive();
    int n;
    while(scanf("%d",&n)==1 && n!=0)
    {
        cheker(n);
    }
    return 0;
}
void seive()
{
    int n=1000000;
    int sq=sqrt(n+1);
    int wj=0;
    prime.push_back(2);
    status[1]=1;
    for(int i=4; i<=n; i+=2)status[i]=1;
    for(int i=3; i<=sq; i+=2)
    {
        if(!status[i])
        {
            prime.push_back(i);
            wj=i;
            for(int j=i*i; j<=n; j+=(i+i))status[j]=1;
        }
    }
    for(int i=wj+2; i<=n; i+=2)
    {
        if(!status[i])prime.push_back(i);
    }
}
void cheker(int n)
{
    int wj=0,fi=0,se=0,first=n;
    int sz=prime.size();
    int jerry=n/2;
    if(n&1)jerry++;
    for(int i=0; i!=sz; i++)
    {
        int wz=n-prime[i];
        if(prime[i]>jerry)break;
        if(!status[wz]){fi=prime[i];se=wz;wj=1;break;}
    }
    printf("%d:\n",n);
    if(wj)printf("%d+%d\n",fi,se);
    else printf("NO WAY!\n");
}
