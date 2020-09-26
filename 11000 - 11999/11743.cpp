#include<bits/stdc++.h>
using namespace std;
#define sc scanf
#define pi printf
int main()
{
    int n,ar[20],a,b,c,d,sum,i,j;
    while(sc("%d",&n)==1)
    {
        while(n--)
        {
            sum=0;
            sc("%d%d%d%d",&a,&b,&c,&d);
            for(i=16;i>=1;i--)
            {
                if(i>=13)
                {
                    ar[i]=a%10;
                    a/=10;
                }
                else if(i>=9)
                {
                    ar[i]=b%10;
                    b/=10;
                }
                else if(i>=5)
                {
                    ar[i]=c%10;
                    c/=10;
                }
                else
                {
                    ar[i]=d%10;
                    d/=10;
                }
            }
            sum+=(ar[2]+ar[4]+ar[6]+ar[8]+ar[10]+ar[12]+ar[14]+ar[16]);
            for(i=1;i<16;i++)
            {
                if(i%2!=0)
                {
                    ar[i]*=2;
                    if(ar[i]<10)sum+=ar[i];
                    else
                    {
                        sum+=ar[i]%10;
                        ar[i]/=10;
                        sum+=ar[i];
                    }
                }
            }
            if(sum%10==0)pi("Valid\n");
            else pi("Invalid\n");
        }
    }
    return 0;
}
