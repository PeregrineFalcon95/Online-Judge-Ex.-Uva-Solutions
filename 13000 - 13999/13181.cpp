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
int n, m, t, ans , k;
int ar [ mxs ] ;
bool visited [ mxs ];
string s , s2;
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
    while( cin>>s )
    {
        n = s.size();
        ans = 0;
        vector < int > graph [ n + 2 ];
        for ( int i = 1 ; i < n; i++ )
        {
            graph [ i ].push_back( i - 1 );
            graph [ i - 1 ].push_back( i );
            visited  [ i ] = 0;
        }
        queue < int > qu;
        visited [ 0 ] = 0;
        for ( int i = 0 ; i < n; i++ )
        {
            if ( s [ i ] == 'X' )
            {
                qu.push( i );
                visited [ i ] = 1;
                ar [ i ] = -1;
            }
        }
        int a , b;
        while( !qu.empty() )
        {
            a = qu.front();
            qu.pop();
            int sz = graph [ a ].size();
            for ( int i = 0 ; i < sz; i++ )
            {
                b = graph [ a ] [ i ];
                if ( !visited [ b ] )
                {
                    qu.push( b );
                    visited [ b ] = 1;
                    ar [ b ] = ar [ a ] + 1;
                }
            }
        }
        for ( int i = 0 ; i < n; i++ )
        {
            ans = max( ans , ar [ i ] );
        }
        cout<<ans<<"\n";
    }
}
