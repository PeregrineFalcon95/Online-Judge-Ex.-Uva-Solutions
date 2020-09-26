///*** One Last Try ***///
#include<bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
//#define ll long long int
#define inf ( int )( 1e9 + 1e9 )
#define mxs (int)( 1e6 + 10 )
#define md  int mid = ( l + r )>>1;
#define mod (ll)(1e9)+7
//int dx[]={+1,0,+0,-1};///Four Directions
//int dy[]={+0,-1,+1,+0};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
int t, n, m, j, ans, k,a, b, c, d, e,f ,sum , i,sz,cases,mx , source , target ;
string s, s2, s3, s4;
vector < int > graph [ 605 ] , rev [ 605 ];
bool visited [ 606 ];
//int level [ mxs ];
int cost [ 606 ] [ 606 ] , rev_cost [ 606 ] [ 606 ] , parent [ 2 ] [ 606 ] , mi [ 606 ];
//int ar [ mxs ] , ar2 [ mxs ] , ar3 [ mxs ] , parent [ mxs ];
queue < pair < int , int > > qu;
void brainfuck();
void clear_();
void max_flow();
bool augmenting_path();
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
    source = 0;
    target = 600;
    cin>>t;
    while( t-- )
    {
        clear_();
        cin>>n>>a>>b>>m;
        for ( i = 1 ; i <= n; i++ )
        {
            graph [ 0 ].push_back( i );
            rev [ i ].push_back( 0 );
            cost [ 0 ] [ i ] = 1;
        }
        c = n + 1; d = c + a - 1;
        for ( i = c ; i <= d; i++ )
        {
            graph [ i ].push_back( 600 );
            rev [ 600 ].push_back( i );
            cost [ i ] [ 600 ] = b;
        }
        while( m-- )
        {
            cin>>a>>b;
            graph [ a ].push_back( n + b );
            cost [ a ] [ n + b ] = 1;
            rev [ n + b ].push_back( a );
        }
        max_flow();
        cout<<ans<<"\n";
    }
}
void clear_()
{
    memset( cost , 0 , sizeof cost );
    memset( rev_cost , 0 , sizeof rev_cost );
    for ( i = 0 ; i <= 600; i++ )
    {
        graph [ i ].clear();
        rev [ i ].clear();
    }
}
void max_flow()
{
    while( augmenting_path() )
    {
        c = mi [ target ];
        for ( i = target ; ; i = parent [ 1 ] [ i ] )
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
            if ( parent [ 1 ] [ i ] == source )break;
        }
    }
    ans = 0;
    for ( i = 1 ; i <= n; i++ )
    {
        ans += rev_cost [ i ] [ source ];
    }
}
bool augmenting_path()
{
    while( !qu.empty() )qu.pop();
    memset( visited , 0 , sizeof visited );
    qu.push( { source , inf } );
    visited [ source ] = 1;
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
                qu.push( { b , min( c , cost [ a ] [ b ] ) } );
                parent [ 0 ] [ b ] = 1;
                parent [ 1 ] [ b ] = a;
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
                qu.push( { b , min( c , rev_cost [ a ] [ b ] ) } );
                parent [ 0 ] [ b ] = 2;
                parent [ 1 ] [ b ] = a;
                mi [ b ] = min( c , rev_cost [ a ] [ b ] );
                if ( b == target )return 1;
            }
        }
    }
    return 0;
}
