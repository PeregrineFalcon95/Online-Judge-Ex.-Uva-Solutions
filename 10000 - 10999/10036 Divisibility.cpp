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
int ar [ mxs ];
int dp [ 10005 ] [ 105 ];
string s , s2;
bool rec( int idx , int sum )
{
    if ( idx > n )
    {
        if ( sum % k == 0 )return 1;
        else return 0;
    }
    if ( dp [ idx ] [ sum ] != -1 )return dp [ idx ] [ sum ];

    return dp [ idx ] [ sum ] = max( rec( idx + 1 , abs( ( sum + ar [ idx ] ) % k ) ) , rec ( idx + 1 , abs( ( sum - ar [ idx ] ) % k ) ) );
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
    cin>>n>>k;
    for ( int i = 0; i <= n + 1; i++ )
        for ( int j = 0; j <= k + 1 ; j++ )dp [ i ] [ j ] = -1;
    for ( int i = 1 ; i <= n; i++ )
    {
        cin>>ar [ i ];
        ar[ i ] %= k;
    }
    if ( rec( 2 , abs( ar [1 ] ) ) )cout<<"Divisible\n";
    else cout<<"Not divisible\n";
}


