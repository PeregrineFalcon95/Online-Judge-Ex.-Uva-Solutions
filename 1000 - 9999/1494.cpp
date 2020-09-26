#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define mxs 1010
#define inf 9999999999999.00
double loc [ 2 ] [ mxs ] , cost [ mxs ];
double value [ 25 ] [ mxs ];
int population [ mxs ] , parent [ mxs ] , sparse [ mxs ] [ 22 ] , level [ mxs ];
vector < pair < int , double > > graph [ mxs ];
int p , q , a , b , n , t , m , c , k , log_;
bool visited [ mxs ];
priority_queue < pair < double , int > > pq;
double x , y , z , w , ans , sum;
map < pair < int , int > , double > mp;
pair < int , int > pop;
void make_graph();
void mst();
void clear_();
void dfs( int source );
void make_sparse();
void solution_finder();
double lca();
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    scanf("%d",&t);
    while ( t-- )
    {
        clear_();
        scanf("%d",&n);
        for ( int i = 1; i <= n; i++ )scanf("%lf%lf %d",&loc [ 0 ] [ i ] , &loc [ 1 ] [ i ], &population [ i ] );
        make_graph();
        mst();
        level [ 1 ] = 0;
        parent [ 1 ] = -1;
        cost [ 1 ] = 0.00;
        dfs( 1 );
        make_sparse();
        solution_finder();
        printf("%.2f\n",ans);
    }
    return 0;
}
void clear_()
{
    memset( sparse , -1, sizeof sparse );
    for ( int i = 0; i <= 1002; i++ )
    {
        visited [ i ] = 0;
        graph [ i ].clear();
        cost [ i ] = inf;
    }
}
void make_graph()
{
    for ( int i = 1; i <= n; i++ )
    {
        for ( int j = 1; j <= n; j++ )
        {
            if ( i == j )continue;
            x = loc [ 0 ] [ i ] - loc [ 0 ] [ j ];
            x *= x;
            y = loc [ 1 ] [ j ] - loc [ 1 ] [ i ];
            y *= y;
            x += y;
            x = (double)sqrt( x );
            graph [ i ].push_back ( { j , x } );
            graph [ j ].push_back ( { i , x } );
        }
    }
}
void mst()
{
    parent [ 1 ] = -1;
    pq.push( { 0.00 , 1 } );
    cost [ 1 ] = 0.00;
    while ( !pq.empty() )
    {
        a = pq.top().second;
        pq.pop();
        if ( visited [ a ] )continue;
        visited [ a ] = 1;
        int sz = graph [ a ].size();
        for ( int i = 0; i != sz; i++ )
        {
            b = graph [ a ] [ i ].first;
            x = graph [ a ] [ i ].second;
            if ( !visited [ b ] && cost [ b ] > x )
            {
                pq.push( { -x , b } );
                cost [ b ] = x;
                parent [ b ] = a;
            }
        }
    }
    for ( int i = 0; i <= n; i++ )
    {
        graph [ i ].clear();
        visited [ i ] = 0;
    }
    sum = 0.00;
    for ( int i = 2; i <= n; i++ )
    {
        a = parent [ i ];
        sum += cost [ i ];
        graph [ a ].push_back ( { i , cost [ i ] } );
        graph [ i ].push_back ( { a , cost [ i ] } );
        parent [ i ] = -1;
    }
}
void dfs( int source )
{
    visited [ source ] = 1;
    int sz = graph [ source ].size();
    for ( int i = 0; i != sz; i++ )
    {
        int lol = graph [ source ] [ i ].first;
        if ( !visited [ lol ] )
        {
            parent [ lol ] = source;
            level [ lol ] = level [ source ] + 1;
            cost [ lol ] = graph [ source ] [ i ].second;
            dfs( lol );
        }
    }
}
void make_sparse()
{
    value [ 0 ] [ 1 ] = 0.00;
    for ( int i = 2; i <= n; i++ )sparse [ 0 ] [ i ] = parent [ i ],value [ 0 ] [ i ] = cost [ i ];
    for ( int j = 1; ( 1<<j ) <= n ; j++ )
        for ( int i = 2 ; i <= n; i++ )
            if ( sparse [ j - 1 ] [ i ] != -1 )
            {
                sparse [ j ] [ i ] = sparse [ j - 1 ] [ sparse [ j - 1 ] [ i ] ];
                value [ j ] [ i ] = max ( value [ j - 1 ] [ i ] , value [ j - 1 ] [ sparse [ j - 1 ] [ i ] ] );
            }
}
void solution_finder()
{
    ans = 0.00;
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= n; j++ )
        {
            if ( i == j )continue;
            p = i , q = j;
            w = lca();
            x = ( double )( population [ i ] + population [ j ] );
            ans = max ( ans , ( double )( x / ( sum - w ) ) );
        }
}
double lca()
{
    if ( level [ p ] < level [ q ] )swap( p , q );
    log_ = 1;
    while ( level [ p ] >= ( 1<< ( log_ + 1 ) ) )log_++;
    w = 0.00;

    for ( int i = log_; i >= 0; i-- )
        if ( sparse [ i ] [ p ] != -1 && ( level [ p ] - ( 1<<i ) ) >= level [ q ] )
        {
            w = max ( w , value [ i ] [ p ] );
            p = sparse [ i ] [ p ];
        }


    if ( p == q )return w;

    for ( int i = log_; i >= 0; i-- )
        if ( sparse [ i ] [ p ] != -1 && sparse [ i ] [ p ] != sparse [ i ] [ q ] )
        {
            w = max ( w , value [ i ] [ p ] );
            w = max ( w , value [ i ] [ q ] );
            p = sparse [ i ] [ p ];
            q = sparse [ i ] [ q ];
        }

    w = max ( w , value [ 0 ] [ p ] );
    w = max ( w , value [ 0 ] [ q ] );
    return w;
}

