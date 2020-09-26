#include<bits/stdc++.h>
using namespace std;
#define inf 1000001000
#define mx 50010
#define pii pair < int , int >
int n , t , m , a , b , c , d , i , j , cases , sz, l ;
int parent [ 2 ] [ mx ] , level [ mx ] , mst [ 2 ] [ mx ] , sparse [ 2 ] [ mx ] [ 20 ] , cost [ mx ];
bool visited [ mx ];
vector < pii > graph [ mx ];
priority_queue < pii > pq;
queue < int > qu;
void bfs( int source );
void mst_( int source );
void make_sparse();
int query( int p , int q );
int main()
{
    //freopen("output.txt","w",stdout);
    while ( scanf("%d%d",&n,&m)== 2)
    {
        getchar();
        memset(sparse , -1 , sizeof sparse );
        for ( i = 0; i <= n; i++ )
        {
            graph [ i ].clear();
            visited [ i ] = 0;
            mst [ 0 ] [ i ] = cost [ i ] = inf;
        }
        while ( m-- )
        {
            scanf("%d%d%d",&a,&b,&c);
            graph [ a ].push_back ( pii ( b , c ) );
            graph [ b ].push_back ( pii ( a , c ) );
        }
        mst_( 1 );
        for ( i = 0; i <= n; i++ )graph [ i ].clear();
        for ( i = 2; i <= n; i++ )
        {
            graph [ i ].push_back ( pii ( mst [ 1 ] [ i ] , mst [ 0 ] [ i ] ) );
            graph [ mst [ 1 ] [ i ] ].push_back ( pii ( i , mst [ 0 ] [ i ] ) );
        }
        bfs( 1 );
        make_sparse();
        if ( t )putchar( 10 );
        t++;
        scanf("%d",&l);
        while ( l-- )
        {
            scanf("%d%d",&a,&b);
            printf("%d\n" , query( a , b ));
        }
    }
    return 0;
}
void mst_( int source )
{
    pq.push( pii ( 0 , source ) );
    mst [ 0 ] [ source ] = 0 ;
    mst [ 1 ] [ source ] = source ;
    //cost [ source ] = 0;
    while ( !pq.empty() )
    {
        a = pq.top().second;
        pq.pop();
        if ( visited [ a ] )continue;
        visited [ a ] = 1;
        sz = graph [ a ].size();
        for ( i = 0; i != sz; i++ )
        {
            b = graph [ a ] [ i ].first;
            c = graph [ a ] [ i ].second;
            if ( !visited [ b ] && mst [ 0 ] [ b ] > c )
            {
                pq.push( pii ( -c , b ) );
                mst [ 0 ] [ b ] = c;
                mst [ 1 ] [ b ] = a;
            }
        }
    }
}
void bfs( int source )
{
    memset( visited , 0 , sizeof visited );
    qu.push( source );
    visited [ source ] = 1;
    parent [ 0 ] [ source ] = -1;
    parent [ 1 ] [ source ] = 0;
    level [ source ] = 0;
    while ( !qu.empty() )
    {
        a = qu.front();
        qu.pop();
        sz = graph [ a ].size();
        for ( i = 0; i != sz; i++ )
        {
            b = graph [ a ] [ i ].first;
            c = graph [ a ] [ i ].second;
            if ( !visited [ b ] )
            {
                qu.push( b );
                parent [ 0 ] [ b ] = a;
                parent [ 1 ] [ b ] = c;
                level [ b ] = level [ a ] + 1;
                visited [ b ] = 1;
            }
        }
    }
}
void make_sparse()
{
    for ( i = 1; i <= n; i++ )
        sparse [ 0 ] [ i ] [ 0 ] = parent [ 0 ] [ i ] , sparse [ 1 ] [ i ] [ 0 ] = parent [ 1 ] [ i ];
    for ( i = 1; ( 1<<i ) < n ; i++ )
        for ( j = 1; j <= n; j++ )
        {
            if ( sparse [ 0 ] [ j ] [ i - 1 ] == -1 )continue;
            sparse [ 0 ] [ j ] [ i ] = sparse [ 0 ] [ sparse [ 0 ] [ j ] [ i - 1 ] ] [ i - 1 ];
            sparse [ 1 ] [ j ] [ i ] = max( sparse [ 1 ] [ j ] [ i - 1 ] , sparse [ 1 ] [ sparse [ 0 ] [ j ] [ i - 1 ] ] [ i - 1 ] );
        }
}
int query( int p , int q )
{
    ///* Sparse 1 = maximum value *///
    ///* Sparse 0 = parent *///
    int ans = 0;
    int log = 1;
    if ( level [ p ] < level [ q ] )swap( p , q );
    while ( ( 1 << ( log + 1 ) ) < n  )log++;
    for ( i = log; i >= 0; i-- )
    {
        if ( sparse [ 0 ] [ p ] [ i ] != -1 && level [ p ] - ( 1 << i ) >= level [ q ] )
        {
            ans = max( ans , sparse [ 1 ] [ p ] [ i ] );
            p = sparse [ 0 ] [ p ] [ i ];
        }
    }
    if ( p == q )return ans;
    for ( i = log; i >= 0; i-- )
    {
        if ( sparse [ 0 ] [ p ] [ i ] != -1 && sparse [ 0 ] [ p ] [ i ] != sparse [ 0 ] [ q ] [ i ] )
        {
            ans = max ( ans , sparse [ 1 ] [ p ] [ i ] );
            ans = max ( ans , sparse [ 1 ] [ q ] [ i ] );
            p = sparse [ 0 ] [ p ] [ i ];
            q = sparse [ 0 ] [ q ] [ i ];
        }
    }
    ans = max ( sparse [ 1 ] [ p ] [ 0 ] , ans );
    ans = max ( sparse [ 1 ] [ q ] [ 0 ] , ans );
    return ans;
}
