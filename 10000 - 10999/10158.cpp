
///Every node have two identity. i and i+n+1. i will be connected with friends, and i+n+1 will be connected with enimies.

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
int parent [ mxs ] ;
int find_parent( int node );
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
    cin>>n;
    for ( int i = 1 ; i <= n + n + 1; i++ )parent [ i ] = i ;
    int a , b , c;
    while( cin>>a>>b>>c )
    {
        if ( !a )break;
        if ( a == 1 )
        {
            ///Make friend
            if ( find_parent( b ) == find_parent( c + 1 + n ) )
            {
                cout<<"-1\n";
                continue;
            }
            parent [ find_parent( b ) ] = find_parent( c );
            parent [ find_parent( b + n + 1 ) ] = find_parent( c + n + 1 );
        }
        else if ( a == 2 )
        {
            ///Make enemy
            if ( find_parent( b ) == find_parent( c ) )
            {
                cout<<"-1\n";
                continue;
            }
            parent [ find_parent( b ) ] = find_parent( c + n + 1 );
            parent [ find_parent( b + n + 1 ) ] = find_parent( c  );
        }
        else if ( a == 3 )
        {
            ///Is friend?
            if ( find_parent( b ) == find_parent( c  )  )cout<<"1\n";
            else cout<<"0\n";
        }
        else
        {
            ///Is enemy?
            if ( find_parent( b ) == find_parent( c + 1 + n ) )cout<<"1\n";
            else cout<<"0\n";
        }
    }
}
int find_parent( int node )
{
    if ( parent [ node ] == node )return node;
    return ( parent [ node ] = find_parent( parent [ node ] ) );
}
