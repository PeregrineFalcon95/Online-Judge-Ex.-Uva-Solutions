#include<bits/stdc++.h>
using namespace std;
#define sc scanf
#define pi printf
int status[1001000];
int main()
{
    int n=1000000;
    status[1]=1;
    int a=sqrt(n);
    for(int i=4; i<=n; i+=2)status[i]=1;
    for(int i=3; i<=a; i++)
    {
        if(status[i]==0)
        {
            for(int j=i*i; j<=n; j+=i)status[j]=1;
        }
    }
    //pi("%d\n",status[7]);
    int in,d=0,e;
    while(sc("%d",&in)==1&&in!=0)
    {
        for(int i=3; i<=(in-3); i++)
        {
            if((status[i])==0&&(status[in-i]==0))
            {
                pi("%d = %d + %d\n",in,i,in-i);
                d=1;
                break;
            }
        }
        if(d==0)pi("Goldbach's conjecture is wrong.\n");
    }
    return 0;
}
