#include<bits/stdc++.h>
using namespace std;
#define sc scanf
#define pi printf
#define lld long long int
int status[1000200];
int main()
{
    int n=1000002,a;
    a=sqrt(n);
    for(int i=4; i<=n; i+=2)status[i]=1;
    status[1]=1;
    for(int i=3; i<=a; i+=2)
    {
        if(status[i]==0)
        {
            for(int j=i*i; j<=n; j+=2*i)status[j]=1;
        }
    }
    int t,b,c;
    while(sc("%d",&t)==1&&t!=0)
    {
        b=0;
        a=sqrt(t);
        if(t%2==0||status[t]==0)b++;
        if(status[t]!=0)
        {
            for(int i=3; i<=t/2; i+=2)
            {
                if(t%i==0)
                {
                    if(status[i]==0)b++;
                }
            }
        }
        if(t==1)pi("1 : 0\n");
        if(t!=1) pi("%d : %d\n",t,b);
    }
    return 0;
}
