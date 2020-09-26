#include<bits/stdc++.h>
using namespace std;
#define mxs 20010
#define pii pair < int , int >
vector < pii > graph [ mxs ];
int sparse [ mxs ] [ 19 ] , level [ mxs ] , value [ mxs ] [ 19 ] , cost [ mxs ] , parent [ mxs ];
bool visited [ mxs ];
int n , m , a , b , c , d , e , p , q , ans , i , j;
priority_queue < pii > pq;
void mst ();
void dfs( int source );
int lca();
int main()
{
    while(scanf("%d%d%d",&n,&m,&e) == 3 )
    {
        for ( i = 0 ; i <= n; i++ )
        {
            graph [ i ].clear();
            cost [ i ] = visited [ i ] = 0;
        }
        while ( m-- )
        {
            scanf("%d%d%d",&a,&b,&c);
            graph [ a ].push_back ( pii ( b, c ) );
            graph [ b ].push_back ( pii ( a, c ) );
        }
        memset( sparse, -1, sizeof sparse );
        mst();
        while ( e-- )
        {
            scanf("%d%d",&p,&q);
            printf("%d\n",lca() );
        }
    }
    return 0;
}
void mst ()
{
    pq.push( pii ( 0 , 1 ) );
    while ( !pq.empty() )
    {
        a = pq.top().second;
        pq.pop();
        if ( visited [ a ] )continue;
        visited [ a ] = 1;
        while ( !graph [ a ].empty() )
        {
            b = graph [ a ].back().first;
            c = graph [ a ].back().second;
            graph [ a ].pop_back();
            if ( !visited [ b ] && cost [ b ] <= c )
            {
                cost [ b ] = c;
                parent [ b ] = a;
                pq.push( pii ( c , b ) );
            }
        }
    }
    for ( i = 1; i <= n; i++ )
    {
        graph [ i ].push_back ( pii ( parent [ i ] , cost [ i ] ) );
        graph [ parent [ i ] ].push_back ( pii ( i , cost [ i ] ) );
    }
    sparse [ 1 ] [ 0 ] = -2;
    dfs( 1 );
    for ( j = 1; ( 1 << j ) <= n; j++ )
        for ( i = 1; i <= n; i++ )
            if ( sparse [ i ] [ j - 1 ] != -1 )
            {
                sparse [ i ] [ j ] = sparse [ sparse [ i ] [ j - 1 ] ] [ j - 1 ];
                value [ i ] [ j ] = min( value [ i ] [ j - 1 ], value [ sparse [ i ] [ j - 1 ] ] [ j - 1 ] );
            }
}
void dfs( int source )
{
    while ( !graph [ source ].empty() )
    {
        b = graph [ source ].back().first;
        c = graph [ source ].back().second;
        graph [ source ].pop_back();
        if ( sparse [ b ] [ 0 ] == -1 )
        {
            sparse [ b ] [ 0 ] = source ;
            value [ b ] [ 0 ] = c;
            level [ b ] = level [ source ] + 1;
            dfs( b );
        }
    }
}
int lca()
{
    int log = 1;
    if ( level [ p ] < level [ q ] )swap( p , q );
    while ( ( 1<< ( log + 1 ) ) <= level [ p ] )log++;
    ans = 999999999;
    for ( i = log ; i >= 0; i-- )
        if ( sparse [ p ] [ i ] != -1 && level [ p ] - ( 1 << i ) >= level [ q ] )
        {
            ans = min ( ans , value [ p ] [ i ] );
            p = sparse [ p ] [ i ];
        }
    if ( p == q )return ans;
    for ( i = log ; i >= 0; i-- )
        if ( sparse [ p ] [ i ] != -1 && sparse [ p ] [ i ] != sparse [ q ] [ i ] )
        {
            ans = min ( value [ p ] [ i ], ans );
            ans = min ( value [ q ] [ i ], ans );
            p = sparse [ p ] [ i ];
            q = sparse [ q ] [ i ];
        }
    ans = min ( ans , value [ p ] [ 0 ] );
    ans = min ( ans , value [ q ] [ 0 ] );
    return ans;
}
