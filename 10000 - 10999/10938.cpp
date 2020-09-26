#include<bits/stdc++.h>
using namespace std;
#define mxs 5010
vector < int > graph [ mxs ] , graph2 [ mxs ];
vector < int > v;
bool visited [ mxs ];
int level [ mxs ] ,sparse [ mxs ] [ 18 ] , parent [ mxs ];
int i , j , n , m , a , b , c , p , q , mi , mx , e ;
void dfs( int source );
void make_sparse();
int lca();
void dfs2( int source );
int main()
{
    //freopen("output.txt","w",stdout);
    while ( scanf("%d",&n) == 1 && n )
    {
        memset( sparse , -1, sizeof sparse );
        for ( i = 0; i <= n; i++ )
        {
            graph [ i ].clear();
            graph2 [ i ].clear();
            visited [ i ] = 0;
        }
        for ( i = 1; i < n; i++ )
        {
            scanf("%d%d",&a,&b);
            graph [ a ].push_back ( b );
            graph [ b ].push_back ( a );
        }
        level [ 1 ] = 0;
        parent [ 1 ] = -1;
        dfs ( 1 );
        scanf("%d",&c);
        make_sparse();
        while ( c-- )
        {
            scanf("%d%d",&p,&q);
            if ( p == q )
            {
                printf("The fleas meet at %d.\n",p);
                continue;
            }
            a = lca();
            v.clear();
            dfs2( mx );
            a = level [ mi ] - level [ a ];
            b = a + v.size() - 1;
            if ( b&1 )
            {
                b /= 2;
                a = v [ b ];
                b = v [ b + 1 ];
                printf("The fleas jump forever between %d and %d.\n",min(a,b),max(a,b));
            }
            else
            {
                b /= 2;
                printf("The fleas meet at %d.\n",v [ b ] );
            }
        }
    }
    return 0;
}
void dfs( int source )
{
    visited [ source ] = 1;
    int sz = graph [ source ].size();
    for ( int l = 0; l != sz; l++ )
    {
        int xx = graph [ source ] [ l ];
        if ( !visited [ xx ] )
        {
            graph2 [ xx ].push_back ( source );
            level [ xx ] = level [ source ] + 1;
            parent [ xx ] = source;
            dfs ( xx );
        }
    }
}
void make_sparse()
{
    for ( i = 1; i <= n; i++ )sparse [ i ] [ 0 ] = parent [ i ];
    for ( j = 1; ( 1<<j ) <= n ; j++ )
        for ( i = 1; i <= n; i++ )
            if ( sparse [ i ] [ j - 1 ] != -1 )sparse [ i ] [ j ] = sparse [ sparse [ i ] [ j - 1 ] ] [ j - 1 ];
}
int lca()
{
    int log = 1;
    if ( level [ p ] < level [ q ] )swap( p , q );
    while ( 1<< ( log + 1 ) <= level [ p ] )log++;
    mx = p;
    mi = q;
    for ( i = log; i >= 0; i-- )
        if ( sparse [ p ] [ i ] != -1 && level [ p ] - ( 1<<i ) >= level [ q ] )p = sparse [ p ] [ i ];
    if ( p == q )return p;
    for ( i = log; i >= 0; i-- )
        if ( sparse [ p ] [ i ] != -1 && sparse [ p ] [ i ] != sparse [ q ] [ i ] )p = sparse [ p ] [ i ],q = sparse [ q ] [ i ];
    return sparse [ p ] [ 0 ];
}
void dfs2( int source )
{
    v.push_back( source );
    if ( graph2 [ source ].back() != a )dfs2( graph2 [ source ].back() );
    else v.push_back( graph2 [ source ].back() );
}
