///*** One Last Try ***///
#include<bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
//#define ll long long int
#define inf ( int )( 1e9 )
#define mxs (int)( 1e6 + 10 )
#define md  int mid = ( l + r )>>1;
#define mod (ll)(1e9)+7
//int dx[]={+1,0,+0,-1};///Four Directions
//int dy[]={+0,-1,+1,+0};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
int t, n, m, j, ans, k,a, b, c, d, e,f ,sum , i,sz,cases,mx , source , target;
int cost [ 110 ] [ 110 ] , rev_cost [ 110 ] [ 110 ] , edges [ 110 ] [ 110 ] , parent [ 2 ][ 110 ] , mi [ 110 ] ;
vector < int > graph [ 110 ] , rev [ 110 ];
bool visited [ 110 ];
queue < pair < int , int > > qu;
void brainfuck();
void clear_();
void make_graph();
void max_flow();
bool augmented_path();
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
    while( cin>>n && n )
    {
        clear_();
        cin>>source>>target>>m;
        for ( i = 1 ; i <= m ; i++ )
        {
            cin>>a>>b>>c;
            cost [ a ] [ b ] += c;
            cost [ b ] [ a ] += c;
        }
        make_graph();
        max_flow();
        cout<<"Network "<<++cases<<"\nThe bandwidth is "<<ans<<".\n\n";
    }
}
void clear_()
{
    memset( edges , 0 , sizeof edges );
    memset( cost , 0 , sizeof cost );
    memset( rev_cost , 0 , sizeof rev_cost );
    for ( i = 0 ; i <= n ; i++ )
    {
        graph [ i ].clear();
        rev [ i ].clear();
    }
}
void make_graph()
{
    for ( i = 1 ; i <= n ; i++ )
        for ( j = 1; j <= n ; j++ )
            if ( cost [ i ] [ j ] )
            {
                graph [ i ].push_back( j );
                rev [ j ].push_back( i );
            }
}
void max_flow()
{
    ans = 0;
    while( augmented_path() )continue;
    for ( i = 1 ; i <= n ; i++ )
    {
        ans += rev_cost [ i ] [ source ];
    }
}
bool augmented_path()
{
    while( !qu.empty() )qu.pop();
    memset( visited , 0 , sizeof visited );
    memset( parent , -1 , sizeof parent );
    parent [ 1 ][ source ] = source;
    visited[ source ] = 1;
    qu.push( { source , inf } );
    while( !qu.empty() )
    {
        a = qu.front().first;
        if ( a == target )break;
        c = qu.front().second;
        qu.pop();
        sz = graph [ a ].size();
        for ( i = 0 ; i < sz ; i++ )
        {
            b = graph [ a ] [ i ];
            if ( !visited [ b ] && cost [ a ] [ b ] )
            {
                parent [ 1 ] [ b ] = a;
                visited [ b ] = 1;
                parent [ 0 ] [ b ] = 1;
                mi [ b ] = min( c , cost [ a ] [ b ] );
                qu.push( { b , min( c , cost [ a ] [ b ] ) } );
            }
        }
        sz = rev [ a ].size();
        for ( i = 0 ; i < sz; i++ )
        {
            b = rev [ a ] [ i ];
            if ( !visited [ b ] && rev_cost [ a ] [ b ] )
            {
                mi [ b ]= min( c , rev_cost [ a ] [ b ] );
                qu.push( { b , min( c , rev_cost [ a ] [ b ] ) } );
                visited [ b ] = 1;
                parent [ 1 ] [ b ] = a;
                parent [ 0 ] [ b ] = 2;
            }
        }
    }
    if ( !visited [ target ] )return 0;
    c = mi [ target ];
    for ( i = target ; ; i = parent [ 1 ] [ i ] )
    {
        a = parent [ 1 ] [ i ];
        if ( parent [ 0 ] [ i ] == 1 )
        {
            ///Main Graph
            cost [ a ] [ i ] -= c;
            cost [ i ] [ a ] -= c;
            rev_cost [ i ] [ a ] += c;
        }
        else
        {
            ///Reversed Graph
            cost [ a ] [ i ] += c;
            cost [ i ] [ a ] += c;
            rev_cost [ a ] [ i ] -= c;
        }
        if ( parent [ 1 ] [ i ] == source )break;
    }
    return 1;
}
