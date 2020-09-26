#include<bits/stdc++.h>
using namespace std;
void fastscan(int &number)
{
    register int c;
    number = 0;
    c = getchar();
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
}
int i,t,n,m,a,b,o_o,time_,ans,aaa;
vector < int > graph [ 100006 ];
bool color [ 100006 ];
int stk [ 100006 ];
void dfs( int source );
void dfs_2 ( int source );
int main()
{
    fastscan(t);
    while ( t-- )
    {
        time_ = 0;
        while(1){fastscan( n );if(n)break;}
        fastscan( m );
        for ( i = 1; i <= n; i++ )
        {
            graph [ i ].clear();
            color [ i ] = 0;
        }
        for ( i = 0; i != m; i++ )
        {
            fastscan( a );
            fastscan( b );
            graph [ a ].push_back ( b );
        }
        for ( i = 1; i <= n; i++ )
        {
            if ( !color [ i ] )dfs( i );
        }
        for ( i = 1; i <= n; i++)color [ i ] = 0;
        ans = 0;
        for ( i = time_ ; i > 0; i-- )
        {
            if ( !color [ stk [ i ] ] )
            {
                ans++;
                dfs_2( stk [ i ] );
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
void dfs( int source )
{
    color [ source ] = 1;
    int sz = graph [ source ].size();
    for (int j = 0; j < sz; j++ )
    {
        o_o = graph [ source ] [ j ];
        if ( !color [ o_o ] )dfs( o_o );
    }
    stk [ ++time_ ] = source;
}
void dfs_2 ( int source )
{
    color [ source ] = 1;
    int sz = graph [ source ].size();
    for (int j = 0; j < sz; j++ )
    {
        o_o = graph [ source ] [ j ];
        if ( !color [ o_o ] )dfs_2( o_o );
    }
}



















#include<bits/stdc++.h>
using namespace std;
vector < int > Graph[100000];
char color[100001];
int stop_watch,num,sum;
deque < int > sorted;
void top_sort(int source);
void dfs(int source);
int main()
{
    int nodes,edges,t,a,b;
    cin>>t;
    while(t--)
    {
        num=stop_watch=0;
        sorted.clear();
        scanf("%d%d",&nodes,&edges);
        memset(color, 'w', nodes+2);
        map < int, int > mp;
        for(int i=1; i<=nodes; i++){Graph[i].clear();mp[i]=0;}
        for(int i=0; i<edges; i++){scanf("%d%d",&a,&b);Graph[a].push_back(b);mp[a]=1;}
        for(int i=1; i<=nodes; i++){if(mp[i]==1&&color[i]=='w')top_sort(i);}
        for(int i=1; i<=nodes; i++){if(mp[i]==0&&color[i]=='w')sorted.push_back(i);}
        memset(color, 'w', nodes+2);
        for(deque < int > ::iterator it=sorted.begin(); it!=sorted.end(); it++){int a=*it;if(color[a]=='w'){dfs(a);num++;}}
        sum=0;
        for(int i=1; i<=nodes; i++){if(color[i]=='w')sum++;}
        printf("%d\n",sum+num);
    }
    return 0;
}

void top_sort(int source)
{
    color[source]='g';
    stop_watch++;
    int sz=Graph[source].size();
    for(int i=0; i!=sz; i++){if(color[Graph[source][i]]=='w')top_sort(Graph[source][i]);}
    stop_watch++;
    sorted.push_front(source);
    color[source]='b';
}

void dfs(int source)
{
    color[source]='g';
    int sz=Graph[source].size();
    for(int i=0; i!=sz; i++){if(color[Graph[source][i]]=='w')dfs(Graph[source][i]);}
    color[source]='b';
}

