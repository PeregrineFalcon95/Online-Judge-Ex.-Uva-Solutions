#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,t,a,b,c;
    while(scanf("%d",&n)==1)
    {
        t=0;
        while(n--)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(a<=20&&b<=20&&c<=20)printf("Case %d: good\n",++t);
            else printf("Case %d: bad\n",++t);
        }
    }
    return 0;
}
