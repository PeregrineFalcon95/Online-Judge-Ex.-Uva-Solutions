#include<bits/stdc++.h>
using namespace std;
map < string, vector < string > > graph;
int warehouse_num,route_num,query_num;
int bfs(string source, string target);
int main()
{
    int n,t=0;
    scanf("%d",&n);
    while(n--)
    {
        if(t)printf("\n");
        graph.clear();
        scanf("%d %d %d",&warehouse_num, &route_num, &query_num );
        for(int i=0; i<warehouse_num; i++)
        {
            string s;
            cin>>s;
            graph[s].clear();
        }
        cin.ignore();
        for(int i = 0; i < route_num; i++)
        {
            string s;
            getline(cin,s);
            stringstream ss(s);
            string token;
            string a,b;
            int mithila=0;
            while(ss>>token)
            {
                if(mithila == 2)break;
                else if(!mithila)
                {
                    mithila = 1;
                    a=token;
                }
                else if(mithila == 1)
                {
                    mithila=2;
                    b=token;
                }
            }
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        if(!query_num && !t)printf("SHIPPING ROUTES OUTPUT\n\n");
        if(!query_num){printf("DATA SET  %d\n\n",++t);continue;}
        for(int i = 0; i < query_num; i++)
        {
            if(!i && !t)printf("SHIPPING ROUTES OUTPUT\n\n");
            if(!i)printf("DATA SET  %d\n\n",++t);
            string s;
            getline(cin,s);
            int sz=0;
            string source, target;
            stringstream ss(s);
            string token="";
            int mithila=0;
            while(ss >> token)
            {
                if(mithila == 3)break;
                else if(!mithila)
                {
                    for(int i = 0; i != token.size(); i++)
                    {
                        sz*=10;
                        sz+=(token[i]-'0');
                    }
                    mithila=1;
                }
                else if(mithila == 1)
                {
                    source = token;
                    mithila =2;
                }
                else if(mithila == 2)
                {
                    target = token;
                    mithila =3;
                }
            }
            int ans = bfs(source, target);
            if(!ans)printf("NO SHIPMENT POSSIBLE\n");
            else printf("$%d\n",sz*ans*100);
        }
    }
    printf("\nEND OF OUTPUT\n");
    return 0;
}
int bfs(string source, string target)
{
    queue < string > qu;
    qu.push(source);
    map < string , int > visited;
    map < string, int > level;
    level[source]=0;
    visited[source]=1;
    while(!qu.empty())
    {
        string _front=qu.front();
        qu.pop();
        int siz=graph[_front].size();
        for(int i = 0; i < siz; i++)
        {
            string mithila = graph[_front][i];
            if(visited.find(mithila)==visited.end())
            {
                qu.push(mithila);
                level[mithila]=level[_front]+1;
                visited[mithila]=1;
                if(mithila == target)
                {
                    return level[mithila];
                }
            }
        }
    }
    return 0;
}
