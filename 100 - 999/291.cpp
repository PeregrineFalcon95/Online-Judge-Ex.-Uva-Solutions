#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>pbds;
//#pragma comment(linker, "/stack:200000000")
#define mod 998244353
#define ll long long int
#define inf ( ll  )( 1e9 + 10 )
#define mxs (int)( 1e6 + 10 )
//#define md  int mid = ( l + r )>>1;
//int dx[]={+1,-1,+0,+0};///Four Directions
//int dy[]={+0,+0,+1,-1};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
int n , m , cases;
int ar [ mxs ] , ar2 [ mxs ];
string s , s2 , s3;
vector < int > graph [ 30 ];
bool visited [ 40 ] , status [ 40 ];
bool matrix [ 10 ] [ 10 ];
vector < int > v;
void brainfuck();
void backtrack( int idx , int taken );
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(NULL);
    //cin.tie(NULL);
    //cout.tie(NULL);
    brainfuck();
    return 0;
}
void brainfuck()
{
    graph[ 1 ].push_back( 2 );
    graph[ 2 ].push_back( 1 );
    graph[ 1 ].push_back( 5 );
    graph[ 5 ].push_back( 1 );
    graph[ 2 ].push_back( 3 );
    graph[ 3 ].push_back( 2 );
    graph[ 2 ].push_back( 5 );
    graph[ 5 ].push_back( 2 );
    graph[ 1 ].push_back( 3 );
    graph[ 3 ].push_back( 1 );
    graph[ 5 ].push_back( 4 );
    graph[ 4 ].push_back( 5 );
    graph[ 3 ].push_back( 4 );
    graph[ 4 ].push_back( 3 );
    graph[ 5 ].push_back( 3 );
    graph[ 3 ].push_back( 5 );
    for ( int i = 1 ; i <= 5; i++ )sort( graph [ i ].begin() , graph [ i ].end() );

    matrix[ 1 ] [ 2 ] = 1 ;
    matrix[ 2 ] [ 1 ] = 1;
    matrix[ 1 ] [ 5 ] = 1;
    matrix[ 5 ] [ 1 ] = 1;
    matrix[ 2 ] [ 3 ] = 1;
    matrix[ 3 ] [ 2 ] = 1;
    matrix[ 2 ] [ 5 ] = 1;
    matrix[ 5 ] [ 2 ] = 1;
    matrix[ 1 ] [ 3 ] = 1;
    matrix[ 3 ] [ 1 ] = 1;
    matrix[ 5 ] [ 4 ] = 1;
    matrix[ 4 ] [ 5 ] = 1;
    matrix[ 3 ] [ 4 ] = 1;
    matrix[ 4 ] [ 3 ] = 1;
    matrix[ 5 ] [ 3 ] = 1;
    matrix[ 3 ] [ 5 ] = 1;

    v.push_back( 1 );
    backtrack( 1 , 1 );
}
void backtrack( int idx , int taken )
{
    if ( taken == 9 )
    {
        for ( int i = 0 ; i < 9 ; i++ )
        {
            printf("%d",v [ i ] );
        }
        putchar( 10 );
        return;
    }

    int sz = graph [ idx ].size();
    for ( int i = 0 ; i < sz; i++ )
    {
        int b = graph [ idx ] [ i ];
        if ( matrix [ idx ] [ b ] )
        {
            matrix [ idx ] [ b ] = 0;
            matrix [ b ] [ idx ] = 0;
            v.push_back( b );
            backtrack( b , taken + 1 );
            v.pop_back();
            matrix [ idx ] [ b ] = 1;
            matrix [ b ] [ idx ] = 1;
        }
    }
}

