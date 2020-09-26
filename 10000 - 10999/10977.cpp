///*** One Last Try ***///
#include<bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#define ll long long int
#define inf ( int )( 1e9 + 1e9 )
#define mxs (int)( 1e6 + 10 )
#define md  int mid = ( l + r )>>1;
#define mod 10000000000007//(ll)(1e9)+7
int dx[]={+1,0,+0,-1};///Four Directions
int dy[]={+0,-1,+1,+0};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
int t, n, m, j,a, b, c, d, e,f, i,ans,cases, pos, num, root;
string s, s2, s3, s4;
queue < pair < int , int > > quu;
bool visited [ 210 ] [ 210 ];
bool grid [ 210 ] [ 210 ];
int level [ 210 ] [ 210 ];
void brainfuck();
void blocker( int x , int y );
void bfs( );
bool check( int x , int y )
{
    return !( x <= 0 || y <= 0 || x > n || y > m || grid [ x ] [ y ] || visited [ x ] [ y ]  );
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    brainfuck();
    return 0;
}
void brainfuck()
{
    while( cin>>n>>m && n || m )
    {
        memset( grid , 0 , sizeof grid );
        memset( visited, 0 , sizeof visited );
        cin>>e;
        while( e-- )
        {
            cin>>a>>b;
            grid [ a ] [ b ] = 1;
        }
        cin>>e;
        while ( e-- )
        {
            cin>>a>>b>>c;
            blocker( a , b );
        }

        if( !grid [ 1 ] [ 1 ] )bfs( );

        if ( !visited [ n ] [ m ]  )cout<<"Impossible.\n";
        else cout<<level [ n ] [ m ]<<"\n";
    }
}
void blocker( int x , int y )
{
    for ( i = 1 ; i <= n; i++ )
    {
        for ( j = 1 ; j <= m; j++ )
        {
            if(  ( ( x - i ) * ( x - i ) ) + ( ( y - j ) * ( y - j ) ) <= c * c )grid [ i ] [ j ] = 1;
        }
    }
}
void bfs()
{
    quu.push( { 1 , 1  } );
    visited [ 1 ] [ 1 ] = 1;
    level [ 1 ] [ 1 ] = 0;
    while( !quu.empty() )
    {
        a = quu.front().first;
        b = quu.front().second;
        quu.pop();
        for ( i = 0 ; i < 4; i++ )
        {
            c = a + dx [ i ];
            d = b + dy [ i ];
            if ( check( c , d  ) )
            {
                level [ c ] [ d ] = level [ a ] [ b ] + 1;
                quu.push( { c , d } );
                visited [ c ] [ d ] = 1;
            }
        }
    }
}
