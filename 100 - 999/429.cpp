#include<bits/stdc++.h>
using namespace std;
vector < string > input_string;
int level[220];
bool visited[220];
vector < int > graph[210];
map < string, int >compress_map;
queue < pair <string, string > > input_query;
void compress();
int bfs(int so, int tar);
void graph_setup(string source, string target);
int main()
{
    int n,m=0;
    while(scanf("%d",&n)==1)
    {
        cin.ignore();
        m=0;
        while(n--)
        {
            if(m)printf("\n");
            m++;
            input_string.clear();
            compress_map.clear();
            string s;
            while(cin>>s)
            {
                if(s=="*")break;
                int sz=s.size();
                input_string.push_back(s);
            }
            compress();
            cin.ignore();
            while(getline(cin,s))
            {
                if(s.empty())break;
                stringstream ss(s);
                string token;
                string source,target;
                int a=0;
                while(ss>>token)
                {
                    if(a==2)break;
                    else if(!a)
                    {
                        a=1;
                        source=token;
                    }
                    else if(a==1)
                    {
                        a=2;
                        target=token;
                    }
                }
                input_query.push(pair < string, string > (source,target));
            }
            while(!input_query.empty())
            {
                for(int j=0; j<210; j++)graph[j].clear();
                string source=input_query.front().first;
                string target=input_query.front().second;
                input_query.pop();
                memset(level, 0, sizeof level);
                memset(visited, 0, sizeof visited);
                graph_setup(source,target);
            }
        }
    }
    return 0;
}
void compress()
{
    int sz=input_string.size();
    int mithila_mojumder=0;
    for(int i=0; i!=sz; i++)
    {
        compress_map[input_string[i]]=mithila_mojumder++;
    }
}
void graph_setup(string source, string target)
{
    int sz=source.size();
    int ssz=input_string.size();
    for(int i=0; i<ssz; i++)
    {
        int siz=input_string[i].size();
        if(sz==siz)
        {
            for(int j=0; j<ssz; j++)
            {
                if(i==j)continue;
                int tz=input_string[j].size();
                if(sz==tz)
                {
                    string che=input_string[j];
                    string che2=input_string[i];
                    int dif=0;
                    for(int l=0; l!=sz; l++)
                    {
                        if(che[l]!=che2[l])dif++;
                    }
                    if(dif==1)
                    {
                        int a=compress_map[che2];
                        int b=compress_map[che];
                        graph[a].push_back(b);
                    }
                }
            }
        }
    }
    int a=compress_map[source];
    int b=compress_map[target];
    int ans=bfs(a,b);
    cout<<source<<" "<<target<<" "<<ans<<endl;
}
int bfs(int so, int tar)
{
    queue < int > qu;
    qu.push(so);
    visited[so]=1;
    while(!qu.empty())
    {
        int front_=qu.front();
        qu.pop();
        int sz=graph[front_].size();
        for(int i=0; i!=sz; i++)
        {
            int mithila=graph[front_][i];
            if(!visited[mithila])
            {
                qu.push(mithila);
                level[mithila]=level[front_]+1;
                visited[mithila]=1;
                if(mithila==tar)return level[mithila];
            }
        }
    }
}
