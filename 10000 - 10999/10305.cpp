#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a,b,c,d;
    while(scanf("%d%d",&n,&m)==2&&(n!=0||m!=0))
    {
        vector < int > Graph[n+1],value,sorted;
        value.assign(n+1,-1);
        for(int i=0; i<m; i++)
        {
            scanf("%d%d",&a,&b);
            Graph[a].push_back(b);
            if(value[b]==-1)value[b]=1;
            else value[b]++;
            if(value[a]==-1)value[a]=0;
        }
        int visited[n+1];
        //memset(visited, 0, sizeof visited);
        for(int i=0; i<=n; i++)visited[i]=0;
        for(int i=0; i<=n; i++){if(value[i]==-1)value[i]=0;}
        b=0;
        for(int i=1; i<=n; i++)
        {
            if(value[i]==0&&visited[i]==0)
            {
                int ara[]={i};
                vector < int > ::iterator it = sorted.begin();
                sorted.insert(it+b++,ara,ara+1);
                visited[i]=1;
                queue < int > qu;
                qu.push(i);
                while(!qu.empty())
                {
                    a=qu.front();
                    qu.pop();
                    c=Graph[a].size();
                    for(int j=0; j<c; j++)
                    {
                        d=Graph[a][j];
                        value[d]--;
                        if(value[d]==0){sorted.push_back(d);visited[d]=1;qu.push(d);}
                    }
                }
            }
        }
        for(vector < int > :: iterator it= sorted.begin(); it!= sorted.end(); it ++){if(it!=sorted.begin())printf(" ");printf("%d",*it);}
        printf("\n");
    }
    return 0;
}

