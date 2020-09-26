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
ll t, n, m, j, ans, k,a, b, c, d, e,f ,sum , i,sz,cases,mx;
string s, s2, s3, s4;
//vector < int > v ;
//vector < int > graph [ mxs ];
//int ar [ mxs ] , ar2 [ mxs ] , ar3 [ mxs ] , parent [ mxs ];
bool grid [ 110 ] [ 110 ];
ll dp [ 110 ] [ 110 ];
void brainfuck();
ll be_the_best( ll x , ll y );
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
    while( cin>>m>>n && ( n || m  ) )
    {
        memset( grid , 0 , sizeof grid );
        memset( dp , -1 , sizeof dp );
        cin>>e;
        while( e-- )
        {
            cin>>b>>a;
            a = n - a;
            grid [ a ] [ b ] = 1;
        }
        ans = be_the_best( n , 0 );
        if ( !ans )cout<<"There is no path.\n";
        else if ( ans == 1 )cout<<"There is one path from Little Red Riding Hood's house to her grandmother's house.\n";
        else cout<<"There are "<<ans<<" paths from Little Red Riding Hood's house to her grandmother's house.\n";
    }
}
ll be_the_best( ll x , ll y )
{
    if ( grid [ x ] [ y ] )return 0;
    if ( !x && y ==  m )return 1;
    if ( dp [ x ] [ y ] != -1 )return dp [ x ] [ y ];
    ll aa = 0 , xx , yy;
    xx = x - 1 , yy = y;
    if ( xx >= 0 && yy <= m )aa = be_the_best( xx , yy );
    xx = x , yy = y + 1;
    if ( xx >= 0 && yy <= m )aa += be_the_best( xx , yy );
    return ( dp [ x ] [ y ] = aa );
}
