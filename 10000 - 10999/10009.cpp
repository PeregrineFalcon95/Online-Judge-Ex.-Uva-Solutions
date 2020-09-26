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
        int edge_num,query_num;
        scanf("%d %d",&edge_num,&query_num);
        cin.ignore();
        map < string, vector < string > >graph;
        map < string, int > visited;
        for(int i = 0; i < edge_num; i++)
        {
            string s;
            getline(cin,s);
            stringstream ss(s);
            string token,a,b;
            int jerry = 0;
            while(ss >> token)
            {
                if(jerry == 2)break;
                else if(!jerry)
                {
                    a=token;
                    jerry=1;
                }
                else if(jerry)
                {
                    b=token;
                    jerry=2;
                }
            }
            graph[a].push_back(b);
            graph[b].push_back(a);
            visited[a] = 0;
            visited[b] = 0;
        }
        for(int i = 0; i < query_num; i++)
        {
            for(map < string, int > ::iterator it = visited.begin(); it != visited.end(); it++)
            {
                it->second = 0;
            }
            string s;
            string token,source,target;
            getline(cin,s);
            stringstream ss(s);
            int wizer=0;
            while(ss >> token)
            {
                if(wizer == 2)break;
                else if(!wizer)
                {
                    wizer=1;
                    source = token;
                }
                else if(wizer)
                {
                    wizer = 2;
                    target = token;
                }
            }
            queue < string > qu;
            qu.push(source);
            visited[source] =1;
            map < string, string > parent;
            while(!qu.empty())
            {
                string front_=qu.front();
                qu.pop();
                int sz=graph[front_].size();
                for(int k = 0; k < sz; k++)
                {
                    string temp=graph[front_][k];
                    if(visited[temp] == 0)
                    {
                        visited[temp] = 1;
                        qu.push(temp);
                        parent[temp] = front_;
                        if(target == temp)break;
                    }
                }
            }
            vector < char > ans;
            string temp = target;
            ans.push_back(target[0]);
            while(1)
            {
                string c=parent[temp];
                ans.push_back(c[0]);
                if(c == source){break;}
                temp = c;
            }
            reverse ( ans.begin(), ans.end());
            for(auto it:ans)printf("%c",it);
            printf("\n");
        }
    }
    return 0;
}
