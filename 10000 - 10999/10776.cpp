#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>pbds;
//#pragma comment(linker, "/stack:200000000")
#define mod 998244353
#define ll long long int
#define inf ( ll  )( 1e9 + 10 )
#define mxs (int)( 1e6 + 10 )
//#define md  int mid = ( l + r )>>1;
//int dx[]={+1,-1,+0,+0};///Four Directions
//int dy[]={+0,+0,+1,-1};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
int n , m ;
int ar [ mxs ] , ar2 [ mxs ];
string s , s2 , s3;
vector < char > v;
bool visited [ 40 ];
void brainfuck();
void backtrack( int idx , int num );
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    brainfuck();
    return 0;
}
void brainfuck()
{
    while( cin>>s>>m )
    {
        memset( visited, 0 , sizeof visited );
        sort( s.begin() , s.end() );
        n = s.size();
        backtrack( 0 , 0 );
    }
}
void backtrack( int idx , int num )
{
    if ( num == m )
    {
        ///Printing
        for ( int i = 0 ; i < m; i++ )cout<<v [ i ];
        cout<<"\n";
        return;
    }
    if ( idx == n )return;
    for ( int i = idx ; i < n; i++ )
    {
        if ( visited [ i ] )continue;
        visited [ i ] = 1;
        v.push_back( s [ i ] );
        backtrack( i + 1 , num + 1 );
        v.pop_back();
        visited [ i ] = 0;
        while( i + 1 < n && s [ i ] == s [ i + 1 ] )i++;
    }
}
