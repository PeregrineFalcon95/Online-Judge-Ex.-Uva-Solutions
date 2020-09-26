///*** One Last Try ***///
#include<bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
//#define ll long long int
#define inf ( int )( 1e9 + 7 )
#define mxs (int)( 1e6 + 10 )
#define md  int mid = ( l + r )>>1;
#define mod (ll)(1e9)+7
//int dx[]={+1,0,+0,-1};///Four Directions
//int dy[]={+0,-1,+1,+0};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
int t, n, m, j, ans, k,a, b, c, d, e,f ,sum , i,sz,cases,mx , target;
string s, s2, s3, s4;
queue < pair < int , int > > qu;
int mi [ 1020 ];
map < string , int > mp;
bool visited [ 1020 ];
int parent [ 2 ] [ 1020 ];
int cost [ 1010 ] [ 1010 ] , rev_cost [ 1010 ] [ 1010 ];
vector < int > graph [1010 ] , rev [ 1010 ];
void make_graph();
void clear_();
void max_flow();
bool augmenting_path();
void brainfuck();
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
        cin>>n>>m;
        n /= 6;
        clear_();
        make_graph();
        for ( i = 1; i <= m; i++ )
        {
            cin>>s>>s2;
            a = mp [ s ];
            b = mp [ s2 ];
            graph [ i ].push_back( a + a - 1 );
            rev [ a + a - 1 ].push_back( i );
            cost [ i ] [ a + a - 1 ] = 1;

            graph [ i ].push_back( b + b - 1 );
            rev [ b + b - 1 ].push_back( i );
            cost [ i ] [ b + b - 1 ] = 1;
        }
        max_flow();
        if ( ans >= m )cout<<"YES\n";
        else cout<<"NO\n";
    }
}
void clear_()
{
    mp.clear();
    memset( cost , 0 , sizeof cost );
    memset( rev_cost , 0 , sizeof rev_cost );
    for ( i = 0 ; i <= 202; i++ )
    {
        graph[ i ].clear();
        rev [ i ].clear();
    }
}
void max_flow()
{
    while( augmenting_path() )
    {
        ///Computing data
        c = mi [ target ];
        for ( i = target; ; i = parent [ 1 ] [ i ] )
        {
            a = parent [ 1 ] [ i ];
            if ( parent [ 0 ] [ i ] == 1 )
            {
                cost [ a ] [ i ] -= c;
                rev_cost [ i ] [ a ] += c;
            }
            else
            {
                rev_cost [ a ] [ i ] -= c;
                cost [ i ] [ a ] += c;
            }
            if ( parent [ 1 ] [ i ] == 0 )break;
        }
    }
    ans = 0;
    for ( i = 1; i < target; i++ )
    {
          ans += rev_cost [ i ] [ 0 ];
    }
}
bool augmenting_path()
{
    while( !qu.empty() )qu.pop();
    memset( visited , 0 , sizeof visited );
    visited [ 0 ] = 1;
    qu.push( { 0 , inf } );
    while( !qu.empty() )
    {
        a = qu.front().first;
        c = qu.front().second;
        qu.pop();
        sz = graph [ a ].size();
        for ( i = 0 ; i < sz; i++ )
        {
            b = graph [ a ] [ i ];
            if ( !visited [ b ] && cost [ a ] [ b ] )
            {
                visited [ b ] = 1;
                parent [ 0 ] [ b ] = 1;
                parent [ 1 ] [ b ] = a;
                qu.push( { b , min( c , cost [ a ] [ b ] ) } );
                mi [ b ] = min( c , cost [ a ] [ b ] );
                if ( b == target )return 1;
            }
        }
        sz = rev [ a ].size();
        for ( i = 0 ; i < sz; i++ )
        {
            b = rev [ a ] [ i ];
            if ( !visited [ b ] && rev_cost [ a ] [ b ] )
            {
                visited [ b ] = 1;
                parent [ 0 ] [ b ] = 2;
                parent [ 1 ] [ b ] = a;
                qu.push( { b , min( c , rev_cost [ a ] [ b ] ) } );
                mi [ b ] = min( c , rev_cost [ a ] [ b ] );
                if ( b == target )return 1;
            }
        }
    }
    return 0;
}
void make_graph()
{
    mp [ "XXL" ] = 60;
    mp [ "XL" ] = 61;
    mp [ "L" ] = 62;
    mp [ "M" ] = 63;
    mp [ "S" ] = 64;
    mp [ "XS" ] = 65;
    target = 200;
    for ( i = 1; i <= m; i++ )
    {
        graph [ 0 ].push_back( i );
        rev [ i ].push_back( 0 );
        cost [ 0 ] [ i ] = 1;
    }
    for ( i = 60; i <= 65; i++ )
    {
        graph [ i + i - 1 ].push_back( i + i );
        rev [ i + i ].push_back( i + i - 1 );
        cost [ i + i - 1 ] [ i + i ] = n;

        graph [ i + i ].push_back( target );
        rev [ target ].push_back( i + i );
        cost [ i + i ] [ target ] = inf;
    }
}



