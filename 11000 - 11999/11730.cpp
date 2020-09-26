#include<bits/stdc++.h>
using namespace std;
bool status [ 1100 ];
bool visited [ 1100 ];
int t,n,m,a,b,c,cases;
int level [ 1100 ];
vector < int > prime;
vector < int > graph [ 1100 ], flag [ 1100 ];
void seive();
void make_flag();
int bfs( int source, int target );
int main()
{
    seive();
    make_flag();
    while( scanf("%d%d",&n,&m)==2 && ( n || m ) )
    {
        int sq = sqrt( n+1 );
        for ( int i = 0; i <= 1002; i++ )
        {
            level [ i ] = -1;
            graph [ i ].clear();
            visited [ i ] = 0;
        }
        int ans = bfs( n, m );
        printf("Case %d: %d\n",++cases,ans);
    }
    return 0;
}
void seive()
{
    int l = 1100;
    int sq = sqrt(l+1 );
    status [ 0 ] = status [ 1 ] = 1;
    for ( int i = 4; i <= l; i+= 2 )
    {
        status [ i ] = 1;
    }
    prime.push_back( 2 );
    int o_o = 0;
    for ( int i = 3; i <= sq; i+=2 )
    {
        if ( !status [ i ] )
        {
            o_o = i;
            prime.push_back( i );
            for ( int j = i*i ; j <= l; j+= ( i+i ) )
            {
                status [ j ] = 1;
            }
        }
    }
    for ( int i = o_o+2; i <= l; i+=2 )
    {
        if ( !status [ i ] )prime.push_back( i );
    }
}
void make_flag()
{
    for ( int i = 1 ; i <= 1002; i++ )
    {
        if ( status [ i ] )
        {
            for ( int j  = 0 ; j <= 200 ; j++ )
            {
                if ( prime [ j ] >= i )break;
                if ( prime [ j ] < i && i % prime [ j ] == 0 )
                {
                    flag [ i ].push_back ( prime [ j ] );
                }
            }
        }
    }
}
int bfs( int source, int target )
{
    if ( source == target )return 0;
    if ( source > target )return -1;
    visited [ source ] = 1;
    level [ source ] = 0;
    queue < int > qu;
    if ( !status [ source ] )return -1;
    qu.push( source );
    while ( !qu.empty() )
    {
        int front_ = qu.front();
        qu.pop();
        int sz = flag[ front_ ].size();
        for ( int i = 0; i != sz; i++ )
        {
            int o_o = flag [ front_ ] [ i ] + front_;
            if ( !visited [ o_o ] && o_o <= target )
            {
                if ( o_o == target )return level [ front_ ]+1;
                level [ o_o ] = level [ front_ ]+1;
                qu.push( o_o );
                visited [ o_o ] = 1;
            }
        }
    }
    return -1;
}
