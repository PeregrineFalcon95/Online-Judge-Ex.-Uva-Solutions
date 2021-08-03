#include<bits/stdc++.h>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>pbds;
//#pragma comment(linker, "/stack:200000000")
#define fast ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
#define ll long long int
#define mod ( ll  ) ( 1e9 + 7 )  //( 1e9 + 7 )
#define inf ( ll  )( 1e9 + 10 )
#define mxs (int)(1e6+100)
#define CHECK_BIT(var,pos) ((var) & (1LL<<(pos)))
//#define md  int mid = ( l + r )>>1;
//int dx[]={+1,-1,+0,+0};///Four Directions
//int dy[]={+0,+0,+1,-1};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
//int dx[]={-2,-2,-1,1,-1,1,2,2};///Knight moves
//int dy[]={1,-1,-2,-2,2,2,-1,1};///Knight moves
int n , m, t, ans, cases , k;
int grid [ 15 ] [ 1100 ] , dp [ 15 ] [ 1100 ] ;
string s , s2;
int rec( int row , int col )
{
    if ( col > m )
    {
        if ( row == n )return 0;
        return inf;
    }
    if ( dp [ row ] [ col ] != -1 )return dp [ row ] [ col ];

    int mi = inf;
    if ( col == 1 )mi = rec( row - 1 , col + 1 ) + grid [ row ] [ col ] + 60;
    else if ( col == m )mi = min( mi , rec( row + 1 , col + 1 ) + grid [ row ] [ col ] ) + 20;
    else
    {
        if ( row != 1 )mi = min( mi , rec( row - 1 , col + 1 ) + grid [ row ] [ col ] + 60 );
        mi = min( mi , rec( row , col + 1 ) + grid [ row ] [ col ] + 30 );
        if ( row + 1 != n )mi = min( mi , rec ( row + 1 , col + 1 ) + grid [ row ] [ col ] + 20 );
    }
    return dp [ row ] [ col ] = mi ;
}
void brainfuck();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    fast
    cin>>t;
    //t = 1;
    //scanf("%d",&t);
    while( t-- )brainfuck();
    return 0;
}
void brainfuck()
{
    memset( dp , -1 , sizeof dp );
    cin>>m;
    m /= 100;
    n = 10;
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1 ; j <= m; j++ )
        {
            cin>>grid [ i ] [ j ];
            grid [ i ] [ j ]*= -1;
        }

    cout<<rec( n , 1 )<<"\n\n";
}
