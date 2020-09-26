#include<bits/stdc++.h>
using namespace std;
int t,n,m,cases,a,b,source,target;
vector < int > graph [ 110 ];
bool visited [ 110 ];
int level [ 110 ] [ 2 ];
void bfs( int source );
void bfs_2( int source );
int main()
{
    scanf("%d",&t);
    while ( t-- )
    {
        scanf("%d%d",&n,&m);
        for ( int i = 0; i<= n; i++ )
        {
            visited [ i ] = 0;
            graph [ i ].clear();
            level [ i ] [ 0 ] = level [ i ] [ 1 ] = 0;
        }
        for ( int i = 0; i != m; i++ )
        {
            scanf("%d%d",&a,&b);
            graph [ a ].push_back ( b );
            graph [ b ].push_back ( a );
        }
        scanf("%d%d",&source,&target);
        bfs( source );
        int mx = 0;
        memset( visited , 0 , sizeof visited );
        bfs_2 ( target );
        for ( int i = 0; i != n; i++ )
        {
            mx = max( mx , ( level [ i ] [ 0 ] + level [ i ] [ 1 ] ) );
        }
        printf("Case %d: %d\n",++cases,mx);
    }
    return 0;
}
void bfs( int source )
{
    level [ source ] [ 0 ] = 0;
    visited [ source ] = 1;
    queue < int > qu;
    qu.push( source );
    while ( !qu.empty() )
    {
        //cout<<"  vvv "<<endl;
        int front_ = qu.front();
        qu.pop();
        int sz = graph [ front_ ].size();
        for ( int i = 0; i != sz; i++ )
        {
            int o_o = graph [ front_ ] [ i ];
            if ( !visited [ o_o ] )
            {
                qu.push( o_o );
                visited [ o_o ] = 1;
                level [ o_o ] [ 0 ] = level [ front_ ] [ 0 ] + 1;
            }
        }
    }
}
void bfs_2( int source )
{
    level [ source ] [ 1 ]= 0;
    visited [ source ] = 1;
    queue < int > qu;
    qu.push( source );
    while ( !qu.empty() )
    {
        int front_ = qu.front();
        qu.pop();
        int sz = graph [ front_ ].size();
        for ( int i = 0; i != sz; i++ )
        {
            int o_o = graph [ front_ ] [ i ];
            if ( !visited [ o_o ] )
            {
                qu.push( o_o );
                visited [ o_o ] = 1;
                level [ o_o ] [ 1 ]= level [ front_ ] [ 1 ] + 1;
            }
        }
    }
}

