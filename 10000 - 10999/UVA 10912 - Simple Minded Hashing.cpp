///Notice, letters have to be in strictly increasing order, so, leangth will be always less then 27

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
int n , m, t, ans, cases ;
string s , s2;
int dp [ 30 ] [ 30 ] [ 900 ];
int rec( int idx , int pre , int sum )
{
    if ( idx > n )
    {
        if ( !sum )return 1;
        return 0;
    }
    int &pp = dp [ idx ] [ pre ] [ sum ];
    if ( pp != -1 )return pp;
    pp = 0;
    for ( int i = pre + 1; i <= 26; i++ )
        pp += rec( idx + 1 , i , sum - i );
    return pp;
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
    while( cin>>n>>m && n )
    {
        ans = 0;
        if ( n > 26 )ans = 0;
        else
        {
            memset( dp , -1, sizeof dp );
            ans = rec( 1 , 0 , m );
        }
        cout<<"Case "<<++cases<<": "<<ans<<"\n";
    }
}
