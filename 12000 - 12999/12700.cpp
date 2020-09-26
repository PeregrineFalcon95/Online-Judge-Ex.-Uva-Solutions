#include<bits/stdc++.h>
using namespace std;
#define sc scanf
#define pi printf
int main()
{
    int b,w,a,t,n,c,m;
    char str[12];
    while(sc("%d",&c)==1)
    {
        m=0;
        while(c--)
        {
            sc("%d%s",&n,&str);
            b=w=a=t=0;
            for(int i=0; i<n; i++)
            {
                if(str[i]=='A')a++;
                else if(str[i]=='T')t++;
                else if(str[i]=='B')b++;
                else if(str[i]=='W')w++;
            }
            if(b>0&&w==0&&t==0)pi("Case %d: BANGLAWASH\n",++m);
            else if(w>0&&b==0&&t==0)pi("Case %d: WHITEWASH\n",++m);
            else if(b>w)pi("Case %d: BANGLADESH %d - %d\n",++m,b,w);
            else if(w>b)pi("Case %d: WWW %d - %d\n",++m,w,b);
            else if(w==b&&a!=n)pi("Case %d: DRAW %d %d\n",++m,w,t);
            else if(b==0&&w==0&&t==0&&a!=0)pi("Case %d: ABANDONED\n",++m);
        }
    }
    return 0;
}
