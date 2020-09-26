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
int ar [ mxs ] ;
string s , s2;
void brainfuck();
int main()
{
    //freopen("tour.in","r",stdin);
    //freopen("output.txt","w",stdout);
    fast
    cin>>t;
    //t = 1;
    while( t-- )brainfuck();
    return 0;
}
void brainfuck()
{
    cin>>s;
    n = s.size();
    s2 = "";

    ///Initializing the temporary string with spaces
    for ( int i = 0 ; i < n; i++ )s2 += " ";

    ///Filling the rules
    for ( int i = 0 ; i < n; i++ )
    {
        if ( s [ i ] == 'B' )
        {
            s2 [ i ] = '!';
            if ( i - 1 >= 0 )s2 [ i - 1 ] = '!';
            if ( i - 2 >= 0 )s2 [ i - 2 ] = '!';
        }
        else if ( s [ i ] == 'S' )
        {
            s2 [ i ] = '!';
            if ( i - 1 >= 0 )s2 [ i - 1 ] = '!';
            if ( i + 1 < n )s2 [ i + 1 ] = '!';
        }
        else if ( s [ i ] == 'D' )
        {
            s2 [ i ] = '!';
        }
    }
    ans = 0;

    ///Calculating the possible answers
    for ( int i = 0 ; i < n; i++ )
        if ( s2 [ i ] == ' ' )ans++;

    cout<<"Case "<<++cases<<": "<<ans<<'\n';
}

