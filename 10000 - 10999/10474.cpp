#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,q,m=0;
    while(scanf("%d%d",&n,&q)==2&&(n!=0||q!=0))
    {
        vector<int>v;
        int a,query[q];
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a);
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        for(int i=0; i<q; i++)scanf("%d",&query[i]);
        printf("CASE# %d:\n",++m);
        for(int i=0; i<q; i++)
        {
            vector<int>::iterator it;
            it=lower_bound(v.begin(),v.end(),query[i]);
            if(*it!=query[i])printf("%d not found\n",query[i]);
            else printf("%d found at %d\n",query[i],(it-v.begin())+1);
        }
    }
    return 0;
}

