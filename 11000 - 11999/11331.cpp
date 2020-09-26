#include<bits/stdc++.h>
using namespace std;
vector < int > graph [ 2005 ];
int t , n , m , a , b , c , cow , bull , red , blue , e , f , i , j , g;
int parent [ 2005 ] , color [ 2 ] [ 2002 ] , dp [ 2002 ] [ 1002 ];
bool co [ 2002 ];
queue < int > qu;
bool o_o;
bool bfs ();
int coin ( int idx , int cow_h , int bull_h  );
int main()
{
    scanf("%d",&t);
    while ( t-- )
    {
        memset(parent , -1, sizeof parent );
        o_o = 0;
        scanf("%d%d%d",&bull,&cow,&n);
        a = bull + cow;
        for ( i = 0; i <= a; i++ )graph [ i ].clear();
        for ( i = 1; i <= n; i++ )
        {
            scanf("%d%d",&a,&b);
            graph [ a ].push_back ( b );
            graph [ b ].push_back ( a );
        }
        a = bull + cow;
        c = 0;
        for ( i = 1; i <= a; i++ )
        {
            if ( parent [ i ] == -1 )
            {
                if( bfs() )
                {
                    o_o = 1;
                    printf("no\n");
                    break;
                }
            }
        }
        if ( o_o )continue;
        memset( dp , -1, sizeof dp );
        if ( coin ( 1 , cow , bull ) == 0 )printf("no\n");
        else printf("yes\n");
    }
    return 0;
}
bool bfs ()
{
    while( !qu.empty())qu.pop();
    c++;
    co [ i ] = 1;
    parent [ i ] = i;
    color [ 0 ] [ c ] = color [ 1 ] [ c ] = 0;
    color [ 1 ] [ c ] = 1;
    qu.push( i );
    while ( !qu.empty() )
    {
        b = qu.front();
        qu.pop();
        g = graph [ b ].size();
        for ( j = 0; j != g; j++ )
        {
            e = graph [ b ] [ j ];
            if ( parent [ b ] == e )continue;
            if ( parent [ e ] == -1 )
            {
                if ( co [ b ] )co [ e ] = 0,color [ 0 ] [ c ]++;
                else co [ e ] = 1,color [ 1 ] [ c ]++;
                qu.push( e );
                parent [ e ] = b;
            }
            else if ( co [ b ] == co [ e ] )return 1;
        }
    }
    return 0;
}
int coin ( int idx , int cow_h , int bull_h )
{
    if ( idx > c || ( !cow_h && !bull_h ) )
    {
        if ( !cow_h && !bull_h )return 1;
        return 0;
    }
    if ( dp [ idx ] [ cow_h ] != -1 )return dp [ idx ] [ cow_h ];
    int x = 0 , y = 0;
    x = coin( idx + 1 , cow_h - color [ 0 ] [ idx ] , bull_h - color [ 1 ] [ idx ] );
    y = coin( idx + 1 , cow_h - color [ 1 ] [ idx ] , bull_h - color [ 0 ] [ idx ] );
    return ( dp [ idx ] [ cow_h ] = max ( x , y ) );
}
