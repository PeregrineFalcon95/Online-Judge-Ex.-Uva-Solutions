#include<bits/stdc++.h>
using namespace std;
vector < int > graph [ 500 ];
int  v , n , m , a , b , c , d;
bool visited [ 500 ] ;
char color [ 500 ];
bool bfs ( int source );
int main()
{
    while ( scanf("%d",&n) == 1 && n )
    {
        for ( int i = 0; i <= n; i++ )
        {
            color [ i ] = 't';
            visited [ i ] = 0;
            graph [ i ].clear();
        }
        while ( scanf("%d%d",&a,&b) == 2 && a && b )
        {
            graph [ a ].push_back ( b );
            graph [ b ].push_back ( a );
        }
        b = 0;
        for ( int i = 1 ; i <= n; i++ )
        {
            if ( !visited [ i ] )
            {
                a = bfs( i );
                if ( a )
                {
                    printf("NO\n");
                    b = 1;
                    break;
                }
            }
        }
        if(!b)printf("YES\n");
    }
    return 0;
}
bool bfs ( int source )
{
    queue < int > qu;
    qu.push( source );
    visited [ source ] = 1;
    color [ source ] = 'w';
    while ( !qu.empty() )
    {
        a = qu.front();
        qu.pop();
        c = graph [ a ].size();
        for ( int i = 0; i != c; i++ )
        {
            d = graph [ a ] [ i ];
            if ( visited [ d ] && color [ d ] == color [ a ] )return 1;
            else if ( !visited[ d ] )
            {
                if ( color [ a ] == 'w' )color [ d ] = 'r';
                else color [ d ] = 'w';
                qu.push( d );
                visited [ d ] = 1;
            }
        }
    }
    return 0;
}
