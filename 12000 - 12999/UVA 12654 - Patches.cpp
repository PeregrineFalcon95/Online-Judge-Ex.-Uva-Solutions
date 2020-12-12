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
int t1 , t2 , lastOne;
int ar [ mxs ];
int dp [ 3010 ];
int rec ( int idx )
{
    if ( idx > lastOne )return 0;
    int &p = dp [ idx ];
    if ( p != -1 )return p;

    int id = idx;
    for ( int i = idx + 1; i <= lastOne; i++ )
        if ( ar [ i ] - ar [ idx ] <= t1 )id = i;
    p = rec( id + 1 ) + t1;

    id = idx;
    for ( int i = idx + 1; i <= lastOne; i++ )
        if ( ar [ i ] - ar [ idx ] <= t2 )id = i;
    p = min( p , rec( id + 1 ) + t2 );

    return p;
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
    while( cin>>n>>m>>t1>>t2 )
    {
        lastOne = n + n;
        for ( int i = 0 ; i <= lastOne; i++ )dp [ i ] = -1;
        for ( int i = 1; i <= n; i++ )cin>>ar [ i ];

        for ( int i = n + 1 ; i <= n + n; i++ )ar [ i ] = ar [ i - n ] + m;
        ans = inf;
        for ( int i = 1 ; i <= n; i++ )
        {
            lastOne = i + n - 1;
            for ( int j = i; j <= lastOne; j++ )dp [ j ] = -1;
            ans = min( ans , rec( i ) );
        }
        cout<<ans<<"\n";
    }
}
