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
int n , m, t, ans, cases , total ;
string s , s2;
pair < int , int > dp [ 10100 ];
pair < int , int > rec( int rem ) ///First is beer time, second total number
{
    if ( dp [ rem ].first != -1 )return dp[ rem ];
    pair < int , int > x = { rem , 0 };
    if ( rem - n >= 0 )
    {
        x = rec( rem - n );
        x.second++;
    }
    if ( rem - m >= 0 )
    {
        if ( rec( rem - m  ).first < x.first )
        {
            x = rec( rem - m );
            x.second++;
        }
        else if ( rec( rem - m ).first == x.first && rec( rem - m ).second >= x.second )
        {
            x = rec( rem - m );
            x.second++;
        }
    }
    return dp [ rem ] = x;
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
    while( cin>>n>>m>>total )
    {
        for ( int i = 0 ; i <= total; i++ )dp [ i ].first = -1;
        pair < int , int > p = rec( total );
        cout<<p.second;
        if ( p.first )cout<<" "<<p.first;
        cout<<'\n';
    }
}

