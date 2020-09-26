#include<bits/stdc++.h>
using namespace std;
#define sc scanf
#define pi printf
#define lld long long int
int status[1002000];
int main()
{
    int n=1000001;
    for(int i=4; i<=n; i+=2)status[i]=1;
    status[1]=0;
    int a=sqrt(n);
    for(int i=3; i<=a; i+=2)
    {
        if(status[i]==0)
        {
            for(int j=i*i; j<=n; j+=2*i)status[j]=1;
        }
    }
    int m,t,b,e;
    while(sc("%d",&m)==1)
    {
        e=b=0;
        if(status[m]==0)
        {
            t=m;
            while(t!=0)
            {
                e*=10;
                e+=t%10;
                t/=10;
            }
            if(status[e]==0&&m!=e)b=1;
            else b=2;
        }
        if(b==0)pi("%d is not prime.\n",m);
        if(b==1)pi("%d is emirp.\n",m);
        if(b==2)pi("%d is prime.\n",m);
    }
    return 0;
}
