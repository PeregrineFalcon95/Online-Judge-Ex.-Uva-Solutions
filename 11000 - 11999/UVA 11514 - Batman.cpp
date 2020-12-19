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
int dp [ 1010 ] [ 1010 ] ;
bool weakness [ 1010 ] [ 1010 ];
int power [ 1010 ] , calory [ 1010 ] , defense [ 1010 ];
map < string , int > mp;
int rec ( int idx , int idx2 )
{
    if ( idx2 > m )return 0;
    if ( idx > n )return inf;
    int &p = dp [ idx ] [ idx2 ];
    if ( p != -1 )return p;
    p = inf;
    if ( weakness [ idx2 ] [ idx ] && defense [ idx2 ] <= power [ idx ] )p = rec( idx + 1 , idx2 + 1 ) + calory [ idx ];
    p = min( p , rec( idx + 1 , idx2 ) );
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
    while( cin>>n>>m>>cases && ( n || m || cases ) )
    {
        for ( int i = 0 ; i <= n; i++ )
            for ( int j = 0 ; j <= m; j++ )dp [ i ] [ j ] = -1;
        for ( int i = 0 ; i <= m; i++ )
            for ( int j = 0 ; j <= n; j++ )weakness [ i ] [ j ] = false;

        mp.clear();
        int marker = 0;
        for ( int i = 1 ; i <= n; i++ )
        {
            cin>>s>>power [ i ]>>calory [ i ];
            mp [ s ] = i;
        }
        for ( int i = 1 ; i <= m; i++ )
        {
            cin>>s>>defense [ i ]>>s2;
            ans = s2.size();
            s = "";
            for ( int j = 0 ; j < ans; j++ )
            {
                if ( s2 [ j ] == ',' || j == ans - 1 )
                {
                    if ( j == ans - 1 )s += s2 [ j ];
                    weakness [ i ] [ mp [ s ] ] = true;
                    s = "";
                }
                else s += s2 [ j ];
            }
        }
        if ( cases >= rec( 1 , 1  ) )cout<<"Yes\n";
        else cout<<"No\n";
    }
}
