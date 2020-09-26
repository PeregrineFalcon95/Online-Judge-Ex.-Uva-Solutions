#include<bits/stdc++.h>
using namespace std;
#define sc scanf
#define pi printf
int main()
{
    int a,b,c=0,n,m;
    while(sc("%d%d",&n,&m)==2&&(n!=0&&m!=0))
    {
        a=n/m;
        if(a>=0&&a<=26)
        {
            if(n%m==0)pi("Case %d: %d\n",++c,a-1);
            else pi("Case %d: %d\n",++c,a);
        }
        else pi("Case %d: impossible\n",++c);
    }
    return 0;
}
