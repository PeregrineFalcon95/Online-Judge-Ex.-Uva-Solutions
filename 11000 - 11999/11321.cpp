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
#define mod ( ll  ) ( 1e9 + 7 )  //( 1e9 + 7 )
#define ll long long int
#define inf ( ll  )( 1e9 + 10 )
#define mxs (int)(1e6+10)//( 1e6 + 10 )
#define CHECK_BIT(var,pos) ((var) & (1LL<<(pos)))
//#define md  int mid = ( l + r )>>1;
//int dx[]={+1,-1,+0,+0};///Four Directions
//int dy[]={+0,+0,+1,-1};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
//int dx[]={-2,-2,-1,1,-1,1,2,2};///Knight moves
//int dy[]={1,-1,-2,-2,2,2,-1,1};///Knight moves
int n, m, t, ans , cases;
string s , s2;
int ar [ mxs ];
bool cmp( int a , int b )
{
    ///Returning based on mod value
    if (a % m != b % m)
        return a % m < b % m;

    ///Now comparing between same mod values
    ///even odd check
    if ( a&1 && b % 2 == 0 )return true;
    if ( b&1 && a % 2 == 0 )return false;

    ///checking for greater odd
    if ( a&1 && b&1 )return a > b;

    ///checking for lesser even
    return a < b;
}
void brainfuck();
int main()
{
    //freopen("tour.in","r",stdin);
    //freopen("output.txt","w",stdout);
    fast
    //cin>>t;
    t = 1;
    while( t-- )brainfuck();
    return 0;
}
void brainfuck()
{
    while( cin>>n>>m )
    {
        cout<<n<<" "<<m<<'\n';

        if ( !n && !m )return;

        for ( int i = 1 ; i <= n; i++ )cin>>ar [ i ];

        sort( ar + 1 , ar + n + 1 , cmp );

        for ( int i = 1 ; i <= n; i++ )cout<<ar [ i ]<<'\n';
    }
}
