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
int t, n, m, j, ans, k,a, b, c, d, e,f ,sum , i,sz,cases,mx , source , target;
string s , s2 , s3 , s4 , s5;
int ar [ 1107 ] , parent [ 2 ] [ 1107 ] , mi [ 1107 ] , com [ 2 ] [ 100 ];
vector < int > graph [ 1107 ] , rev [ 1107 ];
int rev_cost [ 1107 ] [ 1107 ] , cost [ 1107 ] [ 1107 ];
bool visited [ 1107 ];
vector < int > lol;
queue < pair < int , int > > qu;
void brainfuck();
void make_graph();
void solution();
void clear_();
bool max_flow();
bool augmenting_path();
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
    source = 0;
    target = 1100;
    a = 1001;
    for ( i = 1 ; i <= 20; i++ )
    {
        com [ 0 ] [ i ] = a++; ///In
        com [ 1 ] [ i ] = a++; ///Out
    }
    while( cin>>n>>m )
    {
        clear_();
        sum = 0;
        for ( i = 1 ; i <= n ; i++ )
        {
            cin>>ar [ i ];
            sum += ar [ i ];
            cost [ com [ 1 ] [ i ] ] [ 1100 ] = ar [ i ];
            cost [ com [ 0 ] [ i ] ] [ com [ 1 ] [ i ] ] = ar [ i ];
        }
        for ( i = 1 ; i <= m; i++ )
        {
            cin>>c;
            graph [ 0 ].push_back( i );
            rev [ i ].push_back( 0 );
            cost [ 0 ] [ i ] = 1;
            for ( j = 1 ; j <= c; j++ )
            {
                cin>>a;
                graph [ i ].push_back( com [ 0 ] [ a ] );
                rev [ com [ 0 ] [ a ] ].push_back( i );
                cost [ i ] [ com [ 0 ] [ a ] ] = 1;
            }
        }
        if( max_flow() )
        {
            cout<<"1\n";
            for ( i = 1 ; i <= n; i++ )
            {
                lol.clear();
                a = com [ 0 ] [ i ];
                for ( j = 1 ; j <= m; j++ )
                {
                    if ( rev_cost [ a ] [ j ] )
                    {
                        lol.push_back( j );
                    }
                }
                cout<<lol.back();
                lol.pop_back();
                while( !lol.empty() )
                {
                    cout<<" "<<lol.back();
                    lol.pop_back();
                }
                cout<<"\n";
            }
        }
        else cout<<"0\n";
    }
}
void clear_()
{
    memset( rev_cost , 0 , sizeof rev_cost );
    memset( cost , 0 , sizeof cost );
    for ( i = 0; i <= 1100; i++ )
    {
        graph [ i ].clear();
        rev [ i ].clear();
    }
    for ( i = 1 ; i <= 20; i++ )
    {
        graph [ com [ 1 ] [ i ] ].push_back( target );
        rev [ target ].push_back( com [ 1 ] [ i ] );

        graph [ com [ 0 ] [ i ] ].push_back( com [ 1 ] [ i ] );
        rev [ com [ 1 ] [ i ] ].push_back( com [ 0 ] [ i ] );
    }
}
bool max_flow()
{
    while( augmenting_path() )
    {
        c= mi [ target ];
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
    for ( i = 1 ; i <= m; i++ )
    {
        ans += rev_cost [ i ] [ source ];
    }
    if ( ans == sum )return 1;
    return 0;
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
