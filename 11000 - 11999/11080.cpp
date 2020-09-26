#include<bits/stdc++.h>
using namespace std;
vector < int > graph [ 250 ];
int n , m , t , a , b , c , d , sz , x , y , ans;
bool visited [ 250 ];
int color [ 250 ];
map < int , int > mp;
map < int , int > ::iterator it;
int bfs ( int source );
int main()
{
    scanf("%d",&t);
    while ( t-- )
    {
        scanf("%d%d",&n,&m);
        for ( int i = 0; i <= n; i++ )
        {
            visited [ i ] = 0;
            color [ i ] = -1;
            graph [ i ].clear();
        }
        for ( int i = 0; i != m; i++ )
        {
            scanf("%d%d",&a,&b);
            graph [ a ].push_back ( b );
            graph [ b ].push_back ( a );
        }
        y = ans = 0;
        for ( int i = 0; i != n; i++ )
        {
            if ( !visited [ i ] )
            {
                x = bfs( i );
                if ( x == -1 )
                {
                    printf("-1\n");
                    y = 1;
                    break;
                }
                else
                    ans += x;
            }
        }
        if ( !y )
            printf("%d\n",ans);
    }
    return 0;
}
int bfs ( int source )
{
    mp.clear();
    queue < int > qu;
    qu.push( source );
    visited [ source ] = 1;
    color [ source ] = 1;
    mp [ 1 ]++;
    while ( !qu.empty() )
    {
        a = qu.front();
        qu.pop();
        sz = graph [ a ].size();
        for ( int i = 0; i != sz; i++ )
        {
            b = graph [ a ] [ i ];
            if ( visited [ b ] && color [ a ] == color [ b ] )return -1;
            else if ( !visited [ b ] )
            {
                if ( color [ a ] == 1 )color [ b ] = 0;
                else color [ b ] = 1;
                mp [ color [ b ] ]++;
                qu.push( b );
                visited [ b ] = 1;
            }
        }
    }
    a = INT_MAX;
    for ( it = mp.begin(); it != mp.end(); it++ )a = min ( a , it->second );
    return a;
}
