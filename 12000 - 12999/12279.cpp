#include<bits/stdc++.h>
using namespace std;
#define sc scanf
#define pi printf
int main()
{
    int a,n,c=0,t;
    while(sc("%d",&t)==1&&t!=0)
    {
        a=0;
        for(int i=0;i<t;i++)
        {
            sc("%d",&n);
            if(n>0)a++;
            else a--;
        }
        pi("Case %d: %d\n",++c,a);
    }
    return 0;
}
