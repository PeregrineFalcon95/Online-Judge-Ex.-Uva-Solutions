#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,c,marker;
void fastscan(int &number)
{
    register int c;
    number = 0;
    c = getchar();
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
}
vector < int > graph [ 2200 ],graph_2 [ 2200 ];
char color [ 2200 ];
int stk [ 2200 ];
void dfs( int source );
void dfs_2( int source );
int main()
{
    while ( 1 )
    {
        fastscan( n );
        fastscan( m );
        if ( !n && !m )break;
        for ( int i = 0; i <= n; i++ )
        {
            graph [ i ].clear();
            graph_2 [ i ].clear();
            color [ i ] ='w';
        }
        marker = 0;
        for ( int i = 0; i != m; i++ )
        {
            fastscan( a );
            fastscan( b );
            fastscan( c );
            if ( c ==1 )
            {
                graph [ a ].push_back ( b );
                graph_2 [ b ].push_back ( a );
            }
            else if ( c == 2 )
            {
                graph [ a ].push_back ( b );
                graph [ b ].push_back ( a );
                graph_2 [ a ].push_back ( b );
                graph_2 [ b ].push_back ( a );
            }
        }
        dfs( 1 );
        int o_o = 0;
        for ( int i = 1; i <=n ; i++ )
        {
            if ( color [ i ] == 'w' )
            {
                printf("0\n");
                o_o = 1;
                break;
            }
        }
        if ( o_o )continue;
        for ( int i = 0; i <= n; i++ )color [ i ] = 'w';
        dfs_2 ( stk [ marker-1 ] );
        for ( int i = 1 ; i <= n; i++ )
        {
            if ( color [ i ] == 'w' )
            {
                o_o = 1;
                printf("0\n");
                break;
            }
        }
        if ( o_o )continue;
        printf("1\n");
    }
    return 0;
}
void dfs( int source )
{
    color [ source ] = 'g';
    int sz = graph [ source ].size();
    for ( int i = 0; i != sz; i++ )
    {
        int o_o = graph [ source ][ i ];
        if ( color [ o_o ] == 'w' )dfs( o_o );
    }
    stk [ marker++ ] = source ;
}
void dfs_2( int source )
{
    color [ source ] = 'g';
    int sz = graph_2 [ source ].size();
    for ( int i = 0; i != sz; i++ )
    {
        int o_o = graph_2 [ source ] [ i ];
        if ( color [ o_o ] == 'w' )
        {
            dfs_2( o_o );
        }
    }
}

