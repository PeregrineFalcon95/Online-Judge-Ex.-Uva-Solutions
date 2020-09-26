#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define inf (1e8+9)
#define mxs 1002
int n , a , b, c, t , cases , i , j , sz , state , road , rail ;
int parent [ mxs ];
bool visited [ mxs ];
double x , y , z , roads , rails , m;
double ar [ 2 ] [ mxs ] , cost [ mxs ];
int marker [ mxs ];
vector < pair < int , double > > graph [ mxs ];
priority_queue < pair < double , int > > pq;
vector < int > v;
void clear_();
void make_state_graph ();
void make_state_mst();
void make_country_graph();
void make_country_mst();
void mst();
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    scanf("%d",&t);
    while ( t-- )
    {
        scanf("%d%lf",&n,&m);
        clear_();
        for ( i = 1; i <= n; i++ )scanf("%lf%lf",&ar [ 0 ] [ i ],&ar [ 1 ] [ i ] );//cin>>ar [ 0 ] [ i ]>>ar [ 1 ] [ i ];
        make_state_graph ();
        make_state_mst();
        state = a;
        make_country_graph();
        make_country_mst();
        a = ( int )roads;
        b = ( int )( roads + 0.500 );
        if ( ( double )a - roads < ( ( double )b - roads ) )road = a;
        else road = b;
        a = ( int )rails;
        b = ( int )( rails + 0.500 );
        if ( ( double )a - rails < ( ( double )b - rails ) )rail = a;
        else rail = b;
        printf("Case #%d: %d %.f %.f\n",++cases,state,roads,rails);
    }
    return 0;
}
void clear_()
{
    for ( i = 0; i <= n; i++ )
    {
        cost [ i ] = inf;
        graph [ i ].clear();
        visited [ i ] = 0;
    }
}
void make_state_graph ()
{
    for ( i = 1; i <= n; i++ )
        for ( j = 1; j <= n; j++ )
        {
            if ( i == j )continue;
            x = ar [ 0 ] [ i ] - ar [ 0 ] [ j ];
            x *= x;
            y = ar [ 1 ] [ i ] - ar [ 1 ] [ j ];
            y *= y;
            z = sqrt( x + y  );
            if ( z > m )continue;
            graph [ i ].push_back ( { j , z } );
            graph [ j ].push_back ( { i , z } );
        }
}
void make_state_mst()
{
    roads = 0.00;
    a = 0;
    for ( i = 1; i <= n; i++ )
    {
        if ( !visited [ i ] )a++,mst();
    }
}
void mst()
{
    pq.push( { 0.00 , i } );
    cost [ i ] = 0.00;
    while ( !pq.empty() )
    {
        b = pq.top().second;
        pq.pop();
        if ( visited [ b ] )continue;
        marker [ b ] = a;
        visited[ b ] = 1;
        v.push_back( b );
        sz = graph [ b ].size();
        for ( j = 0; j != sz; j++ )
        {
            c = graph [ b ] [ j ].first;
            x = graph [ b ] [ j ].second;
            if ( !visited [ c ] && cost [ c ] > x )
            {
                cost [ c ] = x;
                pq.push( { -x , c } );
            }
        }
    }
    while( !v.empty() )
    {
        roads += cost [ v.back() ];
        v.pop_back();
    }
}
void make_country_graph()
{
    clear_();
    for ( i = 1; i <= n; i++ )
        for ( j = 1 ; j <= n; j++ )
        {
            if ( i == j )continue;
            x = ar [ 0 ] [ i ] - ar [ 0 ] [ j ];
            x *= x;
            y = ar [ 1 ] [ i ] - ar [ 1 ] [ j ];
            y *= y;
            z = sqrt( x + y  );
            a = marker [ i ];
            b = marker [ j ];
            graph [ a ].push_back ( { b , z } );
            graph [ b ].push_back ( { a , z } );
        }
}
void make_country_mst()
{
    pq.push( { 0.00 , 1 } );
    cost [ 1 ] = 0.00;
    while ( !pq.empty() )
    {
        a = pq.top().second;
        pq.pop();
        if ( visited [ a ] )continue;
        visited [ a ] = 1;
        v.push_back( a );
        sz = graph [ a ].size();
        for ( i = 0; i != sz; i++ )
        {
            b = graph [ a ] [ i ].first;
            x = graph [ a ] [ i ].second;
            if ( !visited [ b ] && cost [ b ] > x )
            {
                cost [ b ] = x;
                pq.push( { -x , b } );
            }
        }
    }
    rails = 0.00;
    while ( !v.empty() )
    {
        rails += cost [ v.back() ];
        v.pop_back();
    }
}
