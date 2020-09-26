#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,t=0;
    scanf("%d",&n);
    while(n--)
    {
        if(t)printf("\n");
        t++;
        int a,b;
        scanf("%d%d",&a,&b);
        vector < int > graph[a+2];
        int c,d;
        for(int i=0; i<b; i++)
        {
            scanf("%d%d",&c,&d);
            graph[c].push_back(d);
            graph[d].push_back(c);
        }
        bool visited[a+1];
        memset(visited, 0, sizeof visited);
        int level[a+2];
        memset(level, 0, sizeof level);
        queue < int > qu;
        qu.push(0);
        visited[0]=1;
        while(!qu.empty())
        {
            int front_=qu.front();
            int sz=graph[front_].size();
            qu.pop();
            for(int i=0; i!=sz; i++)
            {
                int ff=graph[front_][i];
                if(!visited[ff])
                {
                    qu.push(ff);
                    visited[ff]=1;
                    level[ff]=level[front_]+1;
                }
            }
        }
        for(int i=1; i<a; i++)printf("%d\n",level[i]);
    }
    return 0;
}
