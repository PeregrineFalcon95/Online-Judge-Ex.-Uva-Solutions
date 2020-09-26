///*** One Last Try ***///
#include<bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#define ll long long int
#define inf ( int )( 1e9 + 1e9 )
#define mxs (int)( 1e6 + 10 )
#define md  int mid = ( l + r )>>1;
#define mod (ll)(1e9)+7
//int dx[]={+1,0,+0,-1};///Four Directions
//int dy[]={+0,-1,+1,+0};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
ll t, n, m, j, ans, k,a, b, c, d, e,f ,sum , i,sz,cases ;
string s, s2, s3, s4;
ll ar [ mxs ] , ar2 [ mxs ] , ar3 [ mxs ] ;
ll dp [ 100007 ];
void brainfuck();
ll increasing( ll idx )
{
    ll mx = 0;
    if ( dp [ idx ] != -1 )return dp [ idx ];
    for ( ll ii = idx + 1 ; ii <= n; ii++ )
        if ( ar [ ii ] > ar [ idx ] )mx = max( mx , increasing( ii ) );
    return ( dp [ idx ] = mx + ar2 [ idx ] );
}
ll decreasing( ll idx )
{
    ll mx = 0;
    if ( dp [ idx ] != -1 )return dp [ idx ];
    for ( ll ii = idx + 1 ; ii <= n; ii++ )
        if ( ar [ ii ] < ar [ idx ] )mx = max( mx , decreasing( ii ) );
    return ( dp [ idx ] = mx + ar2 [ idx ] );
}
int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    brainfuck();
    return 0;
}
void brainfuck()
{
    cin>>t;
    while( t-- )
    {
        cin>>n;
        for ( i = 1 ; i <= n; i++ )cin>>ar [ i ];
        for ( i = 1 ; i <= n; i++ )cin>>ar2 [ i ];
        a = b = 0;
        memset( dp , -1 , sizeof dp );
        for ( i = 1 ; i <= n; i++ )a = max( a , increasing( i ) );

        memset( dp , -1, sizeof dp );
        for ( i = 1 ; i <= n; i++ )b = max( b , decreasing( i ) );

        if ( a >= b )cout<<"Case "<<++cases<<". Increasing ("<<a<<"). Decreasing ("<<b<<").\n";
        else cout<<"Case "<<++cases<<". Decreasing ("<<b<<"). Increasing ("<<a<<").\n";
    }
}
