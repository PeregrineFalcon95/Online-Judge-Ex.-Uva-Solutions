///*** One Last Try ***///
#include<bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#define ll long long int
#define inf ( int )( 1e9 + 7 )
#define mxs (int)( 1e6 + 10 )
#define md  int mid = ( l + r )>>1;
#define mod (ll)(1e9)+7
//int dx[]={+1,0,+0,-1};///Four Directions
//int dy[]={+0,-1,+1,+0};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
int t, n, m, j, ans, k,a, b, c, d, e,f ,sum , i,sz,cases,mx , source , target;
string s, s2, s3, s4;
vector < int > graph [ 120 ] , rev [ 120 ];
int cost [ 120 ] [ 120 ] , rev_cost [ 120 ] [ 120 ] , parent [ 2 ] [ 120 ] , mi [ 120 ];
bool visited [ 120 ];
queue < pair < int , int > > qu;
//vector < int > v ;
//int ar [ mxs ] , ar2 [ mxs ] , ar3 [ mxs ] , parent [ mxs ];
void brainfuck();
void clear_();
void max_flow();
bool augmenting_path();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(NULL);
    //cin.tie(NULL);
    //cout.tie(NULL);
    brainfuck();
    return 0;
}
void brainfuck()
{
    while( scanf("%d%d",&n,&m) == 2 &&  n )
    {
        clear_();
        target = n + n;
        source = 1;
        graph [ 1 ].push_back( 2 );
        rev [ 2 ].push_back( 1 );
        cost [ 1 ] [ 2 ] = inf;
        rev_cost [ 2 ] [ 1 ] = 0;
        graph [ n + n - 1 ].push_back( n + n );
        rev [ n + n ].push_back( n + n - 1 );
        cost [ n + n - 1 ] [ n + n ] = inf;
        rev_cost [ n + n ] [ n + n - 1 ] = 0;
        for ( i = 2 ; i < n; i++ )
        {
            scanf("%d%d",&b,&a);
            graph [ b + b - 1 ].push_back( b + b );
            rev [ b + b ].push_back( b + b - 1 );
            cost [ b + b - 1 ] [ b + b  ] = a;
            rev_cost [ b + b  ] [ b + b - 1 ] = 0;
        }
        for ( i = 1 ; i <= m; i++ )
        {
            scanf("%d%d%d",&a,&b,&c);
            graph [ a + a ].push_back( b + b - 1 );
            rev [ b + b - 1 ].push_back( a + a );
            cost [ a + a  ] [ b + b - 1 ] = c;
            rev_cost [ b + b - 1 ] [ a + a ] = 0;

            graph [ b + b ].push_back( a + a - 1 );
            rev [ a + a - 1 ].push_back( b + b );
            cost [ b + b ] [ a + a - 1 ] = c;
            rev_cost [ a + a - 1 ] [ b + b  ] = 0;
        }
        ans = 0;
        max_flow();
        printf("%d\n",ans);
    }
}
void clear_()
{
    memset( cost , 0 , sizeof cost );
    memset( rev_cost , 0 , sizeof rev_cost );
    for ( i = 0 ; i <= 101; i++ )
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
                ///Main graph
                cost [ i ] [ a ] -= c;
                cost [ a ] [ i ] -= c;
                rev_cost [ i ] [ a ] += c;
            }
            else
            {
                ///Reversed Graph
                rev_cost [ a ] [ i ] -= c;
                cost [ a ] [ i ] += c;
                cost [ i ] [ a ] += c;
            }
            if ( parent [ 1 ] [ i ] == source )break;
        }
    }
    ans = rev_cost [ 2 ] [ 1 ];
}
bool augmenting_path()
{
    memset( visited , 0 , sizeof visited );
    while( !qu.empty() )qu.pop();
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
            if ( !visited [ b ] &&  cost [ a ] [ b ] )
            {
                qu.push( { b , min( c , cost [ a ] [ b ] ) } );
                mi [ b ] = min( c , cost [ a ] [ b ] );
                visited [ b ] = 1;
                parent [ 0 ] [ b ] = 1;
                parent [ 1 ] [ b ] = a;
                if ( b == target )return 1;
            }
        }
        sz = rev [ a ].size();
        for ( i = 0 ; i < sz; i++ )
        {
            b = rev [ a ] [ i ];
            if ( !visited [ b ] &&  rev_cost [ a ] [ b ] )
            {
                qu.push( { b , min( c , rev_cost [ a ] [ b ] ) } );
                mi [ b ] = min( c , rev_cost [ a ] [ b ] );
                visited [ b ] = 1;
                parent [ 0 ] [ b ] = 1;
                parent [ 1 ] [ b ] = a;
                if ( b == target )return 1;
            }
        }
    }
    return 0;
}
