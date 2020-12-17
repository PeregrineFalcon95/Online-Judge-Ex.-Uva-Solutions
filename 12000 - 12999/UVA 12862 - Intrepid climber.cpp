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
#define inf ( int  )( 1e9 + 10 )
#define mxs (int)(1e6+100)
#define CHECK_BIT(var,pos) ((var) & (1LL<<(pos)))
//#define md  int mid = ( l + r )>>1;
//int dx[]={+1,-1,+0,+0};///Four Directions
//int dy[]={+0,+0,+1,-1};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
//int dx[]={-2,-2,-1,1,-1,1,2,2};///Knight moves
//int dy[]={1,-1,-2,-2,2,2,-1,1};///Knight moves
int n , m, t, ans, cases ;
string s , s2;
int dp [ 100010 ] [ 2 ];
bool ar [ 100010 ] , childer [ 100010 ];
bool visited [ 100010 ] , vis [ 100010 ];
vector < pair < int , int > > graph [ 100010 ];
void dfs ( int node , bool status )
{
    if ( status )visited [ node ] = true;
    else vis [ node ] = true;

    bool haveFriend = false;
    if ( ar [ node ] )haveFriend = true;
    int sz = graph [ node ].size();
    int child , sum = 0;

    for ( int i = 0 ; i < sz; i++ )
    {
        child = graph [ node ] [ i ].first;
        if ( !vis [ child ]  )dfs( child , 0 );
        if ( childer [ child ] )
        {
            haveFriend = true;
            sum += dp [ child ] [ 0 ] + graph [ node ] [ i ].second;
        }
    }
    dp [ node ] [ 0 ] = sum;
    childer [ node ] = haveFriend;
    if ( status == false || haveFriend == false )return;

    dp [ node ] [ 1 ] = sum;
    for ( int i = 0 ; i < sz; i++ )
    {
        child = graph [ node ] [ i ].first;
        if ( !visited [ child ] )dfs( child , 1 );
        if ( childer [ child ] )
            dp [ node ] [ 1 ] = min( dp [ node ] [ 1 ] , sum - dp [ child ] [ 0 ] - graph [ node ] [ i ].second + dp [ child ] [ 1 ] );
    }
}
void brainfuck();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    fast
    //cin>>t;
    t = 1;
    //scanf("%d",&t);
    while( t-- )brainfuck();
    return 0;
}
void brainfuck()
{
    while( cin>>n>>m )
    {
        for ( int i = 0 ; i <= n; i++ )
        {
            graph [ i ].clear();
            ar [ i ] = false;
            visited [ i ] = false;
            childer [ i ] = false;
            vis [ i ] = false;
        }

        int a , b , c;
        for ( int i = 1 ; i < n; i++ )
        {
            cin>>a>>b>>c;
            graph [ a ].push_back( { b , c } );
        }
        for ( int i = 1 ; i <= m; i++ )
        {
            cin>>a;
            ar [ a ] = true;
        }

        dfs( 1 , 0 );
        dfs( 1 , 1 );
        cout<<min( dp [ 1 ] [ 0 ] , dp [ 1 ] [ 1 ] )<<"\n";
    }
}


/// https://codeforces.com/gym/101628/problem/f
/// https://codeforces.com/contest/144/problem/D
/// https://codeforces.com/gym/102006/problem/K
/// https://codeforces.com/contest/1397/problem/D
/// https://codeforces.com/contest/59/problem/D
/// https://codeforces.com/contests/page/13
