#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        vector < int >graph[n+2];
        cin.ignore();
        for(int lol = 0; lol != n; lol++)
        {
            string s;
            getline(cin,s);
            int sz=s.size();
            char temp[10];
            int a=0,ff=0,router=0;
            for(int i = 0; i != sz; i++ )
            {
                if(s[i] == '-' )
                {
                    temp[a] = 0;
                    a = 0;
                    router = atoi(temp);
                    temp[0] = 0;
                    continue;
                }
                else if( s[i] == ',')
                {
                    temp[a] = 0;
                    a = 0;
                    ff = atoi(temp);
                    graph[router].push_back(ff);
                    continue;
                }
                else
                {
                    temp[a++] = s[i];
                }
            }
            if(a)
            {
                temp[a] = 0;
                ff = atoi(temp);
                a=0;
                graph[router].push_back(ff);
            }
        }
        printf("-----\n");
        int query_num,source,target;
        scanf("%d",&query_num);
        while(query_num--)
        {
            scanf("%d%d",&source,&target);
            bool visited[n+2];
            memset(visited, 0, sizeof visited);
            map < int, int > parent;
            queue < int > qu;
            qu.push(source);
            visited[source] = 1;
            while(!qu.empty())
            {
                int front_ = qu.front();
                qu.pop();
                int sz = graph[front_].size();
                for(int i = 0; i != sz; i++ )
                {
                    int ff = graph[front_][i];
                    if(!visited[ff])
                    {
                        visited[ff] = 1;
                        qu.push(ff);
                        parent[ff] = front_;
                        if( front_ == target)break;
                    }
                }
            }
            if(!visited[target])
            {
                printf("connection impossible\n");
                continue;
            }
            vector < int > ans;
            int pre = target;
            ans.push_back(pre);
            while(1)
            {
                if(pre == source)break;
                ans.push_back( parent[pre] );
                pre = parent[pre];
            }
            reverse( ans.begin(), ans.end());
            int a=0;
            for(auto it:ans)
            {
                if(a)printf(" ");
                a++;
                printf("%d",it);
            }
            printf("\n");
        }
    }
    return 0;
}
