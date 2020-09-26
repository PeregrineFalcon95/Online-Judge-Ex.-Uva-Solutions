#include<bits/stdc++.h>
using namespace std;
bool status[102];
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
void seive();
int main()
{
    seive();
    int n;
    while(scanf("%d",&n)==1&&n!=0)
    {
        int ara[101];
        memset(ara, 0, sizeof ara);
        for(int i=2; i<=n; i++)
        {
            int c=i;
            if(status[c]==0)ara[c]++;
            else
            {
                for(int j=0; j<25; j++)
                {
                    while(c%prime[j]==0){ara[prime[j]]++;c/=prime[j];}
                    if(prime[j]>c)break;
                }
            }
        }
        printf("%3d! =",n);
        int d=0,e=0;
        for(int i=2; i<=n; i++)
        {
            if(i==53)printf("\n");
            if(ara[i] && i!=53){printf("%3d",ara[i]);/*d++;*/}
            else if(i==53){printf("%9d",ara[i]);}
        }
        printf("\n");
    }
    return 0;
}
void seive()
{
    int n=101;
    int sq=sqrt(n);
    status[0]=1;
    status[1]=1;
    for(int i=4; i<=n; i+=2)status[i]=1;
    for(int i=3; i<=sq; i+=2)
    {
        if(status[i]==0){for(int j=i*i; j<=n; j+=2*i)status[j]=1;}
    }
}
