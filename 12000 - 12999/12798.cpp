#include<bits/stdc++.h>
using namespace std;
#define sc scanf
#define pi printf
int main()
{
    int ar[102][102],k,l,m,n,a,b;
    while(sc("%d%d",&k,&l)==2)
    {
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<l;j++)sc("%d",&ar[i][j]);
        }
        a=0;
        for(int i=0;i<k;i++)
        {
            b=0;
            for(int j=0;j<l;j++)
            {
                if(ar[i][j]>0)b++;
            }
            if(b==l)a++;
        }
        pi("%d\n",a);
    }
    return 0;
}

