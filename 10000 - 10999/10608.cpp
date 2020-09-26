#include<bits/stdc++.h>
using namespace std;
int t,num,pa,a,b,source;
vector < int > graph[ 30005 ];
bool visited [ 30005 ];
void fastscan( int &n )
{
    register int c;
    c = getchar();
    n = 0;
    for (; c>47 && c <58 ; c=getchar())n=n*10+c-48;
}
int bfs();
int main()
{
    ios_base::sync_with_stdio(false);
    fastscan(t);
    while ( t-- )
    {
        fastscan(num);
        fastscan(pa);
        for ( int i = 0; i <= num; i++ )visited[ i ] = 0;
        for ( int i = 0; i <= num; i++ )graph [ i ].clear();
        for ( int i = 0; i != pa; i++ )
        {
            fastscan( a );
            fastscan( b );
            graph [ a ].push_back( b );
            graph [ b ].push_back( a );
        }
        int o_o ,ans = 0;
        for ( int i = 0; i <=num ; i++ )
        {
            if ( !visited [ i ] )
            {
                source = i;
                o_o = bfs();
                ans = max(o_o,ans);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
int bfs()
{
    queue < int > qu;
    qu.push( source );
    visited[ source ] = 1;
    int mx = 1;
    while ( !qu.empty() )
    {
        int front_ = qu.front();
        qu.pop();
        int sz = graph [ front_ ].size();
        for ( int i = 0; i != sz ; i++ )
        {
            int o_o = graph [ front_ ] [ i ];
            if ( !visited [ o_o ] )
            {
                 mx++;
                 qu.push( o_o );
                 visited [ o_o ] = 1;
            }
        }
    }
    return mx;
}
