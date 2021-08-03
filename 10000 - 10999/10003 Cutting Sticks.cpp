/// Hint: Complete search with memorization.
/// First we have the whole stick, no matter what position we choose to cut, it will cost the whole length.
/// But how we will know what position will bring optimal answer? Try cutting each position.
/// for every position, if we cut in ith position, there will be two sticks, one from left to i, another will be from i to right.
/// check what will be the best answer for this two segment.
/// So? For every i, which will bring the best result, we will cut in this position.
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
int n , m, t, ans, cases;
string s , s2;
int ar [ 60 ];
int dp [ 60 ] [ 60 ];
int rec ( int le , int re );
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
    int len;
    while( cin>>len && len )
    {
        memset( dp , -1, sizeof dp );
        cin>>n;
        for ( int i = 1 ; i <= n; i++ )cin>>ar [ i ];
        ar [ n + 1 ] = len;

        ans = rec( 0 , n + 1 );
        cout<<"The minimum cutting is "<<ans<<".\n";
    }
}
int rec ( int le , int re )
{
    if ( dp [ le ] [ re ] != -1 )return dp [ le ] [ re ];
    if ( le + 1 == re )return dp [ le ] [ re ] = 0;

    int optimal = inf;
    for ( int i = le + 1 ; i < re; i++ )
    {
        optimal = min( optimal , rec( le , i ) + rec( i , re ) + ar [ re ] - ar [ le ] );
    }
    return dp [ le ] [ re ] = optimal;
}

