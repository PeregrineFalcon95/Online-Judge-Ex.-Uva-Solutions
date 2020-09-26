#include<bits/stdc++.h>
using namespace std;
int n , m , a , b , c , mx , i , sz , ans , j;
vector < int > graph [ 101 ];
bool visited [ 101 ] ;
int marker [ 101 ];
queue < int > qu;
void bfs ( );
int main()
{
    while ( scanf("%d",&n) == 1 && n )
    {
        for ( i = 1; i <= n; i++ )
        {
            graph [ i ].clear();
            marker [ i ] = 0;
        }
        for ( i = 1; i <= n; i++ )
        {
            scanf("%d",&a);
            while ( a-- )
            {
                scanf("%d",&b);
                graph [ i ].push_back ( b );
            }
        }
        ans = 1;
        mx = 0;
        for ( i = 1; i <= n; i++ )
        {
            memset( visited , 0 , sizeof visited );
            bfs();
        }
        printf("%d\n",ans);
    }
    return 0;
}
void bfs ( )
{
    qu.push ( i );
    visited [ i ] = 1;
    while ( !qu.empty() )
    {
        a = qu.front();
        qu.pop();
        sz = graph [ a ].size();
        for ( j = 0; j != sz ; j++ )
        {
            b = graph [ a ] [ j ];
            if ( !visited [ b ] )
            {
                qu.push( b );
                marker [ i ]++;
                visited [ b ] = 1;
            }
        }
    }
    if ( marker [ i ] > mx )
    {
        mx = marker [ i ];
        ans = i;
    }
}
