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
int n, m, t, ans, cases;
string s , s2;
int parent [ mxs ], dis [ mxs ];
void brainfuck();
pair < int , int > find_parent( int node )
{
    if ( parent [ node ] == node )return { node , 0 };
    pair < int , int > x = find_parent( parent [ node ] );
    dis [ node ] += x.second;
    x.second = dis [ node ];
    parent [ node ] = x.first;
    return x;
}
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
    int a , b;
    cin>>n;
    for ( int i = 1 ; i <= n; i++ )
    {
        dis [ i ] = 0;
        parent [ i ] = i;
    }
    while( cin>>s )
    {
        //cerr<<s<<endl;
        if ( s == "O" )return;
        if ( s == "I" )
        {
            cin>>a>>b;
            ///Connect
            pair < int , int > x , y ;
            //y = find_parent( a );
            //a = y.first;
            x = find_parent( b );
            parent [ a ] = parent [ x.first ];
            dis [ a ] = abs(b - a) % 1000 + dis [ b ];
        }
        else
        {
            cin>>m;
            ///Query
            pair < int , int > x = find_parent( m );
            cout<<x.second<<"\n";
        }
    }
}
