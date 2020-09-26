#include<bits/stdc++.h>
using namespace std;
int status[20000100];
#define sc scanf
#define pi printf
int main()
{
    int a,k,l,t,b,c;
    int n=20000002;
    a=sqrt(n);
    for(int i=3; i<=a; i+=2)
    {
        if(status[i]==0)
        {
            for(int j=i*i; j<=n; j+=2*i)status[j]=1;
        }
    }
    int ara[200000];
    b=0;
    for(int i=3;i<=n;i+=2)
    {
        if(status[i]==0&&status[i+2]==0)ara[++b]=i;
    }
    while(sc("%d",&t)==1)
    {
        pi("(%d, %d)\n",ara[t],ara[t]+2);
    }
    return 0;
}
