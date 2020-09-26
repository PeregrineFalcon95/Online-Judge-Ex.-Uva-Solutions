#include<bits/stdc++.h>
using namespace std;
int visited [ 300 ];
vector < int > graph [ 300 ];
int t , n , m , a , b , c , d , e , lol , j , i , ans , sz;
char color [ 300 ];
map < char , int > mp;
map < char , int >::iterator it;
int bfs ( int source );
int main()
{
    scanf("%d",&t);
    while ( t-- )
    {
        scanf("%d",&n);
        for ( i = 0; i <= 200; i++ )
        {
            visited [ i ]  = 0;
            color [ i ] = 'l';
            graph [ i ].clear();
        }
        for ( i = 1; i <= n; i++ )
        {
            scanf("%d",&e);
            for ( j = 1; j <= e; j++ )
            {
                scanf("%d",&a);
                if ( a > n )continue;
                graph [ i ].push_back ( a );
                graph [ a ].push_back ( i );
            }
        }
        ans = 0;
        for ( i = 1; i <= n; i++ )
        {
            if ( !visited [ i ] )
            {
                //cout<<i<<"  lol\n";
                ans += bfs( i );
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
int bfs ( int source )
{
    int x  = 0;
    mp.clear();
    queue < int > qu;
    qu.push( source );
    visited [ source ] = 1;
    color [ source ] = 'w';
    mp [ color [ source ] ] ++;
    while ( !qu.empty() )
    {
        a = qu.front();
        qu.pop();
        sz = graph [ a ].size();
        for ( j = 0; j != sz; j++ )
        {
            b = graph [ a ] [ j ];
            if ( visited [ b ] && color [ b ] == color [ a ] )x = 1;
            else if ( !visited [ b ] )
            {
                qu.push( b );
                visited [ b ] = 1;
                if ( color [ a ] == 'w' )color [ b ] = 'r';
                else color [ b ] = 'w';
                if( b <= n )mp [ color [ b ] ] ++;
            }
        }
    }
    if ( x )return 0;
    a = 0;
    for ( it = mp.begin(); it != mp.end(); it++ )a = max ( a , it->second );
    //cout<<a<<"  lol  "<<source<<endl;
    return a;
}
