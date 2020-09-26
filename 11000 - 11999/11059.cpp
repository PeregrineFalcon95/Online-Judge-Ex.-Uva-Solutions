#include<bits/stdc++.h>
using namespace std;
#define sc scanf
#define pi printf
int main()
{
    int a,d=0,i,j,k,ar[20];
    while(sc("%d",&a)==1)
    {
        for(i=0;i<a;i++)sc("%d",&ar[i]);
        long long int b=0;
        for(i=0;i<a;i++)
        {
            for(j=i;j<a;j++)
            {
                long long int c=1;
                for(k=i;k<=j;k++)
                {
                    c*=ar[k];
                }
                if(c>b)b=c;
            }
        }
        pi("Case #%d: The maximum product is %lld.\n\n",++d,b);
    }
    return 0;
}
