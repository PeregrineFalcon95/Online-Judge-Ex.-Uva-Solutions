#include<bits/stdc++.h>
using namespace std;
#define sc scanf
#define pi printf
int ar[1010];
int main()
{
    int a,b,c,n,t;
    for(int i=1;i<=1000;i++)
    {
        int sum=0;
        for(int j=1;j<=i;j++)
        {
            if(i%j==0)sum+=j;
        }
        ar[i]=sum;
    }
    a=0;
    while(sc("%d",&n)==1&&n!=0)
    {
        if(n==1)pi("Case %d: 1\n",++a);
        else
        {
            b=0;
            for(int i=n;i>0;i--)
            {
                if(ar[i]==n)
                {
                    b=i;
                    break;
                }
            }
            if(b>0)pi("Case %d: %d\n",++a,b);
            else pi("Case %d: -1\n",++a);
        }
    }
    return 0;
}
