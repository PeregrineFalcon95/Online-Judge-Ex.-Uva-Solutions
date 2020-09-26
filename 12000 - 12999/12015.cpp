#include<bits/stdc++.h>
using namespace std;
#define sc scanf
#define pi printf
int main()
{
    char str[11][110];
    int ar[11],ar2[11],a,b,c,t;
    while(sc("%d",&t)==1)
    {
        int d=0;
        while(t--)
        {
            a=0;
            for(int i=0; i<10; i++)
            {
                sc("%s%d",&str[i],&ar[i]);
                if(ar[i]>a)a=ar[i];
            }
            b=0;
            for(int i=0; i<10; i++)
            {
                if(a==ar[i])ar2[b++]=i;
            }
            pi("Case #%d:\n",++d);
            for(int i=0; i<b; i++)
            {
                c=ar2[i];
                pi("%s\n",str[c]);
            }
        }
    }
    return 0;
}
