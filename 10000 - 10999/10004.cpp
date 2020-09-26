#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,l;
    while(scanf("%d",&n)==1&&n!=0)
    {
        scanf("%d",&l);
        vector<int>edge[n];
        int a,b,start;
        for(int i=0; i<l; i++)
        {
            scanf("%d%d",&a,&b);
            if(i==0)start=a;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        queue<int>qu;
        qu.push(start);
        char color[l*2];
        memset(color,'w',l*2);
        int c=0;
        while(!qu.empty())
        {
            if(c==1)break;
            int v=qu.front();
            qu.pop();
            for(int i=0; i<edge[v].size(); i++)
            {
                int u=edge[v][i];
                if(color[u]=='w')
                {
                    if(color[v]=='r')color[u]='b';
                    else color[u]='r';
                    qu.push(u);
                }
                else if(color[v]==color[u])
                {
                    printf("NOT BICOLORABLE.\n");
                    c=1;
                    break;
                }
            }
        }
        if(c==0)printf("BICOLORABLE.\n");
    }
    return 0;
}
