#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,num,a,b,ans;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        bool days[m+1];
        memset(days, 0, sizeof days);
        //for(int i=0; i<=m; i++)days[i]=0;
        scanf("%d",&num);
        for(int i=1; i<=num; i++)
        {
            scanf("%d",&a);
            b=a;
            while(m>=a)
            {
                days[a]=1;
                a+=b;
            }
        }
        ans=0,a=6,b=7;
        for(int i=1; i<=m; i++)
        {
            if(a!=i&&b!=i&&days[i]==1)ans++;
            if(a==i)a+=7;
            if(b==i)b+=7;
        }
        printf("%d\n",ans);
    }
    return 0;
}

