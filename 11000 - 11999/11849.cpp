#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2&&(n&&m))
    {
        map < int , int > mp;
        int b=m+n,ans=0;
        for(int i=0; i<b; i++){int a;scanf("%d",&a);if(mp.find(a)!=mp.end())ans++;mp[a]++;}
        printf("%d\n",ans);
    }
    return 0;
}
