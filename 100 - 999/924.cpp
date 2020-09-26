#include<bits/stdc++.h>
using namespace std;
vector < int > graph[2505];
void bfs(int source, int e);
int main()
{
    int e;
    scanf("%d",&e);
    for(int l=0; l<e; l++)
    {
        int n,a,b;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a);
            graph[l].push_back(a);
        }
    }
    int q;
    scanf("%d",&q);
    for(int i=0; i<q; i++)
    {
        int source;
        scanf("%d",&source);
        bfs(source,e);
    }
    return 0;
}
void bfs(int source, int e)
{
    bool visited[e+1];
    memset(visited, 0, sizeof visited);
    int level[e+1];
    memset(level, 0, sizeof level);
    int bomb_size[e+1];
    memset(bomb_size, 0, sizeof bomb_size);
    queue < int > qu;
    qu.push(source);
    visited[source]=1;
    int mx=0,in=0;
    while(!qu.empty())
    {
        int front_=qu.front();
        qu.pop();
        int sz=graph[front_].size();
        for(int i=0; i!=sz; i++)
        {
            int mithila = graph[front_][i];
            if(!visited[mithila])
            {
                visited[mithila]=1;
                level[mithila]=level[front_]+1;
                bomb_size[level[mithila]]++;
                if(bomb_size[level[mithila]]>mx)
                {
                    mx=bomb_size[level[mithila]];
                    in=level[mithila];
                }
                qu.push(mithila);
            }
        }
    }
    if(!mx)printf("0\n");
    else printf("%d %d\n",mx,in);
    return;
}
