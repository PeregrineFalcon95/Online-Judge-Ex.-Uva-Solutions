#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define mxs 1002
int dp [ mxs ] [ 2 ], parent [ mxs ];
int m , a , b , c, d , e , n , ans ;
vector < int > graph [ mxs ];
int dfs( int source , int status );
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while ( cin>>n && n )
    {
        for ( int i = 0; i <= n; i++ )
        {
            parent [ i ]  = -1;
            graph [ i ].clear();
            dp [ i ] [ 0 ] = dp [ i ] [ 1 ] = -1;
        }
        for ( int i = 1; i <= n; i++ )
        {
            cin>>m;
            while ( m-- )
            {
                cin>>a;
                graph [ i ].push_back ( a );
            }
        }
        ans = min( dfs( 1 , 0 ) , dfs( 1 , 1 ) );
        if ( !ans )ans = 1;
        cout<<ans<<endl;
    }
    return 0;
}
int dfs( int source , int status )
{
    if ( dp [ source ] [ status ] != -1 )return dp [ source ] [ status ];
    int sz = graph [ source ].size();
    int sum = 0;
    for ( int i = 0; i != sz; i++ )
    {
        int x = graph [ source ] [ i ];
        if ( parent [ source ] == x )continue;
        parent [ x ] = source;
        if ( !status )sum += dfs( x , 1 );
        else sum += min( dfs( x , 0 ) , dfs( x , 1 ) );
    }
    return ( dp [ source ] [ status ] = sum + status );
}
