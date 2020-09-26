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
int dp [ 1007 ] [ 1007 ];
//vector < int > v ;
//int ar [ mxs ] , ar2 [ mxs ] , ar3 [ mxs ] , parent [ mxs ];
void brainfuck();
int rec( int le , int re );
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
    cin.ignore();
    while( t-- )
    {
        memset( dp , -1 , sizeof dp );
        getline( cin , s );
        if ( !s.size() )
        {
            cout<<"0\n";
            continue;
        }
        n = s.size() - 1;
        cout<<rec( 0 , n )<<"\n";
    }
}
int rec( int le , int re  )
{
    if ( le == re )return 1;
    if ( s [ le ] == s [ re ] && le + 1 == re  )return 2;
    if ( le + 1 == re )return 1;
    if ( dp [ le ] [ re ] != -1 )return dp [ le ] [ re ];
    int aa = 0;
    if ( s [ le ] == s [ re ] )aa = rec( le + 1 , re - 1 ) + 2;
    else aa = max( rec( le  , re - 1 ) , rec( le + 1, re  ) );
    return ( dp [ le ] [ re ] = aa );
}
