#include<bits/stdc++.h>
using namespace std;
#define sc scanf
#define pi printf
int main()
{
    int a,b=0,c,n,t,m;
    while(sc("%d",&n)==1&&n>0)
    {
        a=0;
        c=1;
        while(n>c)
        {
            c=c*2;
            a++;
        }
        pi("Case %d: %d\n",++b,a);
    }
    return 0;
}
