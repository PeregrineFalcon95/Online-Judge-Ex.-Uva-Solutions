#include<bits/stdc++.h>
using namespace std;
int n,m,q,cases,a,b,c,source,target;;
vector < pair < int, int > > graph [ 110 ],graph_2 [ 110 ];
int visited [ 110 ];
int father [ 110 ], dis [ 110 ];
int mst( int source );
int bfs( int marker );
int main()
{
    while ( scanf("%d%d%d",&n,&m,&q ) == 3 && ( n || m || q) )
    {
        for ( int i = 0; i <= n; i++ )
        {
            graph_2 [ i ].clear();
            graph [ i ].clear();
            visited [ i ] = 0;
            father [ i ] = 0;
            dis [ i ] = INT_MAX;
        }
        for ( int i = 0; i != m; i++ )
        {
            scanf("%d%d%d",&a,&b,&c);
            graph [ a ].push_back ( pair < int, int > ( b, c ) );
            graph [ b ].push_back ( pair < int, int > ( a, c ) );
        }
        for ( int i = 1; i <= n; i++ )
        {
            if ( !visited [ i ] )
            {
                mst( i );
            }
        }
        for ( int i = 2; i <= n; i++ )
        {
            graph_2 [ i ].push_back ( pair < int, int > ( father [ i ] , dis [ i ] ) );
            graph_2 [ father [ i ] ].push_back( pair < int, int > ( i , dis [ i ] ) );
        }
        if( cases )putchar(10);
        printf("Case #%d\n",++cases);
        memset( visited , 0 , sizeof visited );
        for ( int i = 1; i <= q ; i++ )
        {
            scanf("%d%d",&source,&target);
            int ans = bfs( i );
            if ( ans )printf("%d\n",ans);
            else printf("no path\n");
        }
    }
    return 0;
}
int mst( int source )
{
    father [ source ] = source ;
    dis [ source ] = 0;
    while ( !visited [ source ] )
    {
        visited [ source ] = 1;
        int sz = graph [ source ].size();
        for ( int i = 0; i != sz ; i++ )
        {
            int o_o = graph [ source ] [ i ].first;
            int w_w = graph [ source ] [ i ].second;
            if ( !visited [ o_o ] && dis [ o_o ] > w_w )
            {
                dis [ o_o ] = w_w;
                father [ o_o ] = source;
            }
        }
        int i_i = INT_MAX;
        for ( int i = 1; i <= n; i++ )
        {
            if ( !visited [ i ] && dis [ i ] < i_i )
            {
                i_i = dis [ i ];
                source = i;
            }
        }
    }
}

int bfs(int marker )
{
    queue < int > qu;
    qu.push( source );
    visited [ source ] = marker;
    int ans = 0;
    int parent [ n+2 ] [ 2 ];
    parent [ source ] [ 0 ] = source;
    parent [ source ] [ 1 ] = 0;
    while ( !qu.empty() )
    {
        int front_node = qu.front();
        qu.pop();
        int  sz = graph_2 [ front_node ].size();
        for ( int i = 0; i != sz ; i ++ )
        {
            int pp = graph_2 [ front_node ] [ i ].first;
            int hh = graph_2 [ front_node ] [ i ].second;
            if ( visited [ pp ] != marker )
            {
                parent [ pp ] [ 0 ] = front_node;
                parent [ pp ] [ 1 ] = hh;
                visited [ pp ] = marker;
                if ( pp == target )
                {
                    while(!qu.empty())qu.pop();
                    break;
                }
                qu.push( pp );
            }
        }
    }
    if ( visited [ target ] != marker )return 0;
    ans = 0;
    while ( 1 )
    {
        ans = max( ans , parent [ target ] [ 1 ] );
        if ( parent [ target ] [ 0 ] == source )break;
        target = parent [ target ] [ 0 ];
    }
    return ans;
}
