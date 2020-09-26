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
int t, n, m, j, ans, k,a, b, c, d, e,f ,sum , i,sz,cases,mx;
string s, s2, s3, s4;
int dp [ 100007 ];
//vector < int > v ;
//int ar [ mxs ] , ar2 [ mxs ] , ar3 [ mxs ] , parent [ mxs ];
void brainfuck();
int rec( int idx );
int main()
{
    //ios_base::sync_with_stdio(NULL);
    //cin.tie(NULL);
    //cout.tie(NULL);
    brainfuck();
    return 0;
}
void brainfuck()
{
    memset( dp , -1, sizeof dp );
    dp [ 0 ] = 1;
    dp [ 1 ] = 1;
    while( scanf( "%d",&n ) == 1 )
    {
        a = rec(n);
        while( a % 10 == 0 )a /= 10;
        a = a % 10;
        printf("%5d -> %d\n",n,a);
    }
}
int rec( int idx )
{
    if ( dp [ idx ] != -1 )return dp [ idx ];
    int lol = rec( idx -1 );
    lol *= idx;
    while( lol % 10 == 0 )lol /= 10;
    return ( dp [ idx ] = (lol %= 100000) );
}

