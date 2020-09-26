///*** One Last Try ***///
#include<bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
//#define ll long long int
#define inf ( int )( 1e9 + 1e9 )
#define mxs (int)( 1e6 + 10 )
#define md  int mid = ( l + r )>>1;
#define mod (ll)(1e9)+7
int dx[]={+1,0,+0,-1};///Four Directions
int dy[]={+0,-1,+1,+0};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
int t, n, m, j, ans, k,a, b, c, d, e,f ,sum , i,sz,cases,mx , source , target , mi;
string s , s2 , s3 , s4 , s5;
bool grid [ 110 ] [ 110 ] , visited [ 110 ] [ 110 ] ;
int level [ 110 ] [ 110 ];
int dp [ 110 ] [ 110 ] [ 110 ];
queue < pair < int , int > > qu;
void brainfuck();
bool checker( int x , int y )
{
    return !( x > n || y > m || !x || !y || grid [ x ] [ y ] || visited [ x ] [ y ] );
}
void fuck()
{
    stringstream ss( s );
    e = 0;
    while( ss >> s2 )
    {
        if ( !e )
        {
            a = 0;
            e = 1;
            for ( j = 0 ; j < s2.size(); j++ )
            {
                a *= 10;
                a += s2 [ j ] - '0';
            }
        }
        else
        {
            b = 0;
            for ( j = 0 ; j < s2.size(); j++ )
            {
                b *= 10;
                b += s2 [ j ] - '0';
            }
            grid [ a ] [ b ] = 1;
        }
    }
}
int call( int row , int col , int mo )
{
    if ( row == n && col == m )return 1;
    if ( dp [ row ] [ col ] [ mo ] != -1 )return dp [ row ] [ col ] [ mo ];
    int aa = 0;
    for ( int ii = 0 ; ii < 4; ii++ )
    {
        int bb = dx [ ii ] + row;
        int cc = dy [ ii ] + col;
        if ( checker( bb , cc ) && mo + 1 <= mi )
        {
            aa += call( bb , cc , mo + 1 );
        }
    }
    return ( dp [ row ] [ col ] [ mo ] = aa );
}
int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    brainfuck();
    return 0;
}
void brainfuck()
{
    cin>>t;
    f = t -1;
    while( t-- )
    {
        cin>>n>>m;
        cin.ignore();
        memset( grid , 0 , sizeof grid );
        for ( i = 1 ; i <= n; i++ )
        {
            getline( cin , s );
            fuck();
        }
        if ( f != t )cout<<"\n";
        memset( visited , 0 , sizeof visited );
        memset( dp , -1 , sizeof dp );
        if ( grid [ 1 ] [ 1 ] )
        {
            cout<<"0\n";
            continue;
        }
        qu.push( { 1 , 1 } );
        visited [ 1 ] [ 1 ] = 1;
        level [ 1 ] [ 1 ] = 0;
        while( !qu.empty() )
        {
            a = qu.front().first;
            b = qu.front().second;
            qu.pop();
            for ( i = 0 ; i < 4; i++ )
            {
                c = dx [ i ] + a;
                d = dy [ i ] + b;
                if ( checker( c , d ) )
                {
                    qu.push( { c , d  } );
                    visited [ c ] [ d ] = 1;
                    level [ c ] [ d ] = level [ a ] [ b ] + 1;
                }
            }
        }
        if ( !visited [ n ] [ m ] )cout<<"0\n";
        else
        {
            memset( visited , 0 , sizeof visited );
            mi = level [ n ] [ m ];
            cout<<call( 1 , 1 , 0 )<<"\n";
        }
    }
}
