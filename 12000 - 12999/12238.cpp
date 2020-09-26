#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mxs 100010
vector < pair < int , int > > graph [ mxs ];
deque < ll > an;
int n , m , a , b , c , e , i , j , p , q , lo , sz;
ll ans;
int level [ mxs ];
ll sparse [ 2 ] [ mxs ] [ 20 ];
queue < int > qu;
void bfs();
ll lca ();
int main()
{
    //freopen ("input.txt" , "r", stdin );
    //freopen("output.txt","w",stdout);
    while ( scanf("%d",&n ) == 1 && n )
    {
        memset( sparse , -1, sizeof sparse );
        for ( i = 0; i <= n; i++ )graph [ i ].clear();
        for ( i = 1; i < n; i++ )
        {
            scanf("%d%d",&a,&b);
            graph [ a ].push_back ( pair < ll , ll > ( i , b ) );
            graph [ i ].push_back ( pair < ll , ll > ( a , b ) );
        }
        bfs();
        scanf("%d",&e);
        while ( e-- )
        {
            scanf("%d%d",&p,&q);
            ans = lca();
            an.push_back( ans );
        }
        i = 0;
        while ( an.size() )
        {
            if ( i )putchar( 32 );
            i = 1;
            printf("%lld",an.front());
            an.pop_front();
        }
        putchar(10);
    }
    return 0;
}
void bfs()
{
    level [ 0 ] = 0;
    qu.push( 0 );
    sparse [ 0 ] [ 0 ] [ 0 ] = -1;
    sparse [ 1 ] [ 0 ] [ 0 ] = 0;
    while ( !qu.empty() )
    {
        a = qu.front();
        qu.pop();
        sz = graph [ a ].size();
        for ( i = 0; i != sz; i++ )
        {
            b = graph [ a ] [ i ].first;
            c = graph [ a ] [ i ].second;
            if ( sparse [ 0 ] [ b ] [ 0 ] == -1 && b )
            {
                sparse [ 0 ] [ b ] [ 0 ] = a;
                sparse [ 1 ] [ b ] [ 0 ] = c;
                level [ b ] = level [ a ] + 1;
                qu.push( b );
            }
        }
    }
    for ( j = 1; (1<<j) <= n; j++ )
        for ( i = 0; i < n; i++ )
            if ( sparse [ 0 ] [ i ] [ j - 1 ] != -1 )
            {
                sparse [ 0 ] [ i ] [ j ] = sparse [ 0 ] [ sparse [ 0 ] [ i ] [ j - 1 ] ] [ j - 1 ];
                sparse [ 1 ] [ i ] [ j ] = sparse [ 1 ] [ i ] [ j - 1 ] + sparse [ 1 ] [ sparse [ 0 ] [ i ] [ j - 1 ] ] [ j - 1 ];
            }
}
ll lca ()
{
    if ( level [ p ] < level [ q ] )swap( p , q );
    lo = 1;
    while ( ( 1 << (lo + 1 ) ) <= level [ p ] )lo++;
    ans = 0;
    for ( i = lo; i >= 0; i-- )
        if ( sparse [ 0 ] [ p ] [ i ] != -1 && ( level [ p ] - (1<<i) ) >= level [ q ] )
        {
            ans += sparse [ 1 ] [ p ] [ i ];
            p = sparse [ 0 ] [ p ] [ i ];
        }
    if ( p == q )return ans;
    for ( i = lo; i >= 0; i-- )
        if ( sparse [ 0 ] [ p ] [ i ] != sparse [ 0 ] [ q ] [ i ] && sparse [ 0 ] [ p ] [ i ] != -1 )
        {
            ans += sparse [ 1 ] [ p ] [ i ];
            ans += sparse [ 1 ] [ q ] [ i ];
            p = sparse [ 0 ] [ p ] [ i ];
            q = sparse [ 0 ] [ q ] [ i ];
        }
    ans += sparse [ 1 ] [ p ] [ 0 ];
    ans += sparse [ 1 ] [ q ] [ 0 ];
    return ans;
}

