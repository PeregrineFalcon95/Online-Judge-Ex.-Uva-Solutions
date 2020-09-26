#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,n,t,m=0,c=0;
    while(scanf("%d%d",&n,&t)==2)
    {
        map<int,int>mp;
        vector<int>v[100010];
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a);
            if(mp.find(a)==mp.end())mp[a]=m++;
            v[mp[a]].push_back(i);
        }
        for(int i=0; i<t; i++)
        {
            scanf("%d%d",&a,&b);
            b=mp[b];
            if(v[b].size()<a)printf("0\n");
            else printf("%d\n",v[b][a-1]);
        }
    }
    return 0;
}

















#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        int a;
        vector<int>v[1000020];
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a);
            v[a].push_back(i);
        }
        int qu[m][2];
        for(int i=0; i<m; i++)scanf("%d%d",&qu[i][0],&qu[i][1]);
        for(int i=0; i<m; i++)
        {
            if(v[qu[i][1]].size()<qu[i][0])printf("0\n");
            else printf("%d\n",v[qu[i][1]][qu[i][0]-1]);
        }
    }
    return 0;
}

