#include<bits/stdc++.h>
using namespace std;
int t, n, m, a, b, c, x, y, cases, i, j , z;
vector < int > graph [ 110 ];
vector < int > dominatores;
bool grid [ 105 ] [ 105 ];
bool visited [ 105 ];
queue < int > qu;
queue < int > quu;
bool cheaker( int target );
void bfs ( int target );
int main()
{
    scanf("%d",&t);
    while ( t-- )
    {
        memset(grid , 0 , sizeof grid );
        scanf("%d",&n);
        for ( i =0; i < n; i++ )graph [ i ].clear();
        for ( i = 0; i != n; i++ )
        {
            grid [ 0 ] [ i ] = 1;
            for ( j = 0; j != n; j++ )
            {
                scanf("%d",&a);
                if ( a )
                    graph [ i ].push_back ( j );
            }
        }
        for ( i = 1; i < n; i++ )
        {
            bfs ( i );
        }
        printf("Case %d:\n",++cases);
        for ( i = 0; i != n; i++ )
        {
            if ( !i){putchar('+');
            a = n + n - 1;
            for ( j = 0; j != a; j++ )putchar('-');
            putchar('+');
            putchar(10);}
            for ( j = 0; j != n; j++ )
            {
                if ( grid [ i ] [ j ] )printf("|Y");
                else printf("|N");
            }
            printf("|\n");
            putchar('+');
            a = n + n - 1;
            for ( j = 0; j != a; j++ )putchar('-');
            putchar('+');
            putchar(10);
        }
    }
    return 0;
}
void bfs ( int target )
{
    if ( !cheaker( target ) )
    {
        grid [ 0 ] [ target ] = 0;
        return;
    }
    dominatores.clear();
    for ( j = 1; j < n; j++ )
    {
        if ( j == target )
        {
            dominatores.push_back ( j );
            continue;
        }
        memset( visited , 0 , sizeof visited );
        visited [ j ] = visited [ 0 ] = 1;
        while(!qu.empty())qu.pop();
        qu.push( 0 );
        y = 0;
        while ( !qu.empty() )
        {
            a = qu.front();
            qu.pop();
            b = graph [ a ].size();
            for ( z = 0; z != b; z++ )
            {
                x = graph [ a ] [ z ];
                if ( !visited [ x ] )
                {
                    qu.push( x );
                    visited [ x ] = 1;
                    if ( x == target )
                    {
                        y = 1;
                        break;
                    }
                }
            }
            if ( y )break;
        }
        if ( y )continue;
        else dominatores.push_back ( j );
    }
    while ( !dominatores.empty() )
    {
        a = dominatores.back();
        dominatores.pop_back();
        grid [ a ] [ target ] = 1;
    }
}
bool cheaker( int target )
{
    while ( !quu.empty() )quu.pop();
    memset(visited , 0 , sizeof visited );
    quu.push( 0 );
    visited [ 0 ] = 1;
    while ( !quu.empty() )
    {
        a = quu.front();
        b = graph [ a ].size();
        quu.pop();
        for ( j = 0; j != b; j++ )
        {
            c = graph [ a ] [ j ];
            if ( !visited [ c ] )
            {
                quu.push( c );
                visited [ c ] = 1;
                if ( c == target )return 1;
            }
        }
    }
    if ( visited [ target ] )return 1;
    return 0;
}
