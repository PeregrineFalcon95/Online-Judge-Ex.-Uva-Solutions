#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,edges,cases=0;
    while(scanf("%d",&edges)==1&&edges!=0)
    {
        map<int,vector<int>>graph;
        set<int>nodes;
        set<int>::iterator it=nodes.begin();
        for(int i=0; i<edges; i++)
        {
            scanf("%d%d",&a,&b);
            graph[a].push_back(b);
            graph[b].push_back(a);
            nodes.insert(it,a);
            nodes.insert(it,b);
        }
        int number_of_nodes=nodes.size();
        c=0;
        vector<int>query[2];
        while(scanf("%d%d",&a,&b)==2&&(a!=0||b!=0))
        {
            c++;
            query[0].push_back(a);
            query[1].push_back(b);
        }
        int size_query=query[0].size();
        for(int i=0; i<c; i++)
        {
            map<int,int>distance;
            queue<int>qu;
            int y=1;
            qu.push(query[0][i]);
            distance[query[0][i]]=0;
            while(!qu.empty())
            {
                int front_=qu.front();
                qu.pop();
                int sz=graph[front_].size();
                for(int j=0; j<sz; j++)
                {
                    int next_distance=distance[front_]+1;
                    if(next_distance>query[1][i])break;
                    else if(distance.find(graph[front_][j])==distance.end())
                    {
                        y++;
                        distance[graph[front_][j]]=next_distance;
                        qu.push(graph[front_][j]);
                    }
                }
            }
            int ans=number_of_nodes-y;
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",++cases,ans,query[0][i],query[1][i]);
        }
    }
    return 0;
}
