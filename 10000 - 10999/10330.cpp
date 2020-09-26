#include<bits/stdc++.h>
using namespace std;
#define inf (int)(1e9+7)
int cost [ 210 ] [ 210 ] , rev_cost [ 210 ] [ 210 ] ;
int parent [ 2 ] [ 220 ] , mi [ 220 ] , ar [ 220 ] ;
bool visited [ 220 ];
int t , cases , n , m , a , b , c , d , e , f , g , h , i , j , ans , sz;
vector < int > graph [ 210 ] , rev [ 210 ];
vector < int > sources , targets;
queue < pair < int , int > > qu;
void brainfuck();
void clear_();
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
    while( cin>>n )
    {
        clear_();
        for ( i = 1; i <= n ; i++ )
        {
            cin>>c;
            a = i + i - 1;///Incoming node
            b = i + i; ///Outgoing node
            graph [ a ].push_back( b );
            rev [ b ].push_back( a );
            cost [ a ] [ b ] = c;
        }
        cin>>m;
        for ( i = 1 ; i <= m; i++ )
        {
            cin>>a>>b>>c;
            d = a + a;///Outgoing node
            e = b + b - 1;///Incoming node
            graph [ d ].push_back( e );
            rev [ e ].push_back( d );
            cost [ d ] [ e ] = c;
        }
        cin>>e>>f;
        m = n + n + 1;
        for ( i = 1 ; i <= e ; i++ )
        {
            cin>>c;
            a = c + c - 1;
            graph [ 0 ].push_back( a );///Incoming edges with super source
            cost [ 0 ] [ a ] = inf;
            rev [ a ].push_back( 0 );
        }
        for ( i = 1 ; i <= f; i++ )
        {
            cin>>c;
            a = c + c;
            graph [ a ].push_back( m );
            cost [ a ] [ m ] = inf;
            rev [ m ].push_back( a );
        }
        ans = 0;
        max_flow();
        cout<<ans<<"\n";
    }
}
void clear_()
{
    ///Clearing previous data
    memset( cost , 0 , sizeof cost );
    memset( rev_cost , 0 , sizeof rev_cost );
    m = n + n + 2;
    for ( i = 0 ; i <= m; i++ )
    {
        graph [ i ].clear();
        rev [ i ].clear();
    }
}
void max_flow()
{
    while( augmented_path() )
    {
        c = mi [ m ];
        for ( i = m; ; i = parent [ 1 ] [ i ] )
        {
            a = parent [ 1 ] [ i ];
            if ( parent [ 0 ] [ i ] == 1 )
            {
                cost [ a ] [ i ] -= c;
                cost [ i ] [ a ] -= c;
                rev_cost [ i ] [ a ] += c;
            }
            else
            {
                rev_cost [ a ] [ i ] -= c;
                cost [ i ] [ a ] += c;
                cost [ a ] [ i ] += c;
            }
            if ( parent [ 1 ] [ i ] == 0 )break;
        }
    }
    ans = 0;
    for ( i = 1; i <= m; i++ )
    {
          ans += rev_cost [ i ] [ 0 ];
    }
}
bool augmented_path()
{
    memset( visited , 0 , sizeof visited );
    while( !qu.empty() )qu.pop();
    qu.push( { 0 , inf } );
    visited [ 0 ] = 1;
    while( !qu.empty() )
    {
        a = qu.front().first;
        c = qu.front().second;
        qu.pop();
        sz = graph [ a ].size();
        for ( i = 0 ; i < sz; i++ )
        {
            b = graph [ a ] [ i ];
            if ( !visited [ b ] && cost [ a ] [ b ])
            {
                visited [ b ] = 1;
                parent [ 1 ] [ b ] = a;
                parent [ 0 ] [ b ] = 1;///Main graph
                qu.push( { b , min( c , cost [ a ] [ b ] ) } );
                mi [ b ] = min( c , cost [ a ] [ b ] );
                if ( b == m )return 1;
            }
        }
        sz = rev [ a ].size();
        for ( i = 0 ; i < sz; i++ )
        {
            b = rev [ a ] [ i ];
            if ( !visited [ b ] && rev_cost [ a ] [ b ] )
            {
                visited [ b ] = 1;
                parent [ 0 ] [ b ] = 2;///Traversing Reversed graph
                parent [ 1 ] [ b ] = a;
                qu.push( { b , min( c , rev_cost [ a ] [ b ] ) } );
                if ( b == m )return 1;
            }
        }
    }
    return 0;
}
