#include<bits/stdc++.h>
using namespace std;
#define inf 99999999
int t,n,m,a,b,c,x,y,z,ans,in;
int level [ 502 ] [ 502 ];
int level_2 [ 502 ], level_3 [ 502 ];
bool visited [ 502 ];
vector < pair < int ,int > > vv;
vector < int > v;
vector < pair < int, int > > graph [ 505 ];
void djk( int source );
void calculation();
void djk_2( int source );
int main()
{
    scanf("%d",&t);
    z = t-1;
    while( t-- )
    {
        ans = inf;
        vv.clear();
        v.clear();
        if( z!= t )putchar( 10 );
        scanf("%d%d",&a,&n);
        for( int i = 0; i <= n; i++ )
        {
            for ( int j = 0; j <= n; j++ )level [ i ] [ j ] = inf;
            visited [ i ] = 0;
            level_2 [ i ] = inf;
            graph [ i ].clear();
        }
        for ( int i = 0; i != a; i++ )
        {
            scanf("%d",&b);
            v.push_back( b );
        }
        string s;
        getchar();
        while( getline(cin,s) )
        {
            a = b = c = 0;
            if( !s.size() || s.empty() )break;
            stringstream ss ( s );
            string token;
            while( ss >> token )
            {
                int sz = token.size();
                x = 0;
                for ( int i = 0; i != sz; i++ )
                {
                    x*= 10;
                    x+= token [ i ] - '0';
                }
                if( !a )a = x;
                else if ( !b ) b = x;
                else if ( !c ) c = x;
            }
            graph [ a ].push_back( pair < int, int > ( b, c ) );
            graph [ b ].push_back( pair < int, int > ( a, c ) );
        }
        while( !v.empty() )
        {
            b = v.back();
            v.pop_back();
            visited [ b ] = 1;
            djk( b );
        }
        calculation();
        for ( int i = 1; i <= n; i++ )
        {
            if( !visited [ i ] )
            {
                visited [ i ] = 1;
                djk_2( i );
            }
        }
        sort(vv.begin(),vv.end());
        int szz = vv.size();
        int o_o = vv [ 0 ].second;
        printf("%d\n",o_o);
    }
    return 0;
}
void djk( int source )
{
    priority_queue < pair < int, int > > pq;
    pq.push( pair < int, int > ( 0, source ) );
    level [ source ] [ source ] = 0;
    while( !pq.empty() )
    {
        int front_ = pq.top().second;
        pq.pop();
        int sz = graph [ front_ ].size();
        for ( int i = 0; i != sz; i++ )
        {
            a = graph [ front_ ] [ i ].first;
            b = graph [ front_ ] [ i ].second;
            c = level [ source ] [ front_ ] + b;
            if( level [ source ] [ a ] > c )
            {
                level [ source ] [ a ] = c;
                pq.push( pair < int, int > ( -c, a ) );
            }
        }
    }
}
void calculation()
{
    for ( int i = 1; i <= n; i++ )
    {
        if ( visited [ i ] )
        {
            int mx = -1;
            for ( int j = 1; j <= n; j++ )
            {
                level_2 [ j ] = min(level [ i ] [ j ], level_2 [ j ] );
                mx = max( mx, level [ i ] [ j ] );
            }
            if(mx == -1 )continue;
            if( mx <= ans )
            {
                ans = mx;
                in = i;
                vv.push_back( pair < int ,int > ( ans , in ) );
            }
        }
    }
}
void djk_2( int source )
{
    for ( int i = 1; i <= n; i++ )level_3 [ i ] = inf;
    priority_queue < pair < int, int > > pq;
    pq.push( pair < int, int > ( 0, source ) );
    level_3 [ source ] = 0;
    while( !pq.empty() )
    {
        int front_ = pq.top().second;
        pq.pop();
        int sz = graph [ front_ ].size();
        for ( int i = 0; i != sz; i++ )
        {
            a = graph [ front_ ] [ i ].first;
            b = graph [ front_ ] [ i ].second;
            c = level_3 [ front_ ] + b;
            if( level_3 [ a ] > c )
            {
                level_3 [ a ] = c;
                pq.push( pair < int, int > ( -c, a ) );
            }
        }
    }
    int mx = -1;
    int lol = 0;
    for ( int i = 1; i <= n; i++ )
    {
        if( level_2 [ i ] > level_3 [ i ] )
        {
            mx = max( mx, level_3 [ i ] );
        }
        else mx = max(mx , level_2 [ i ] );
    }
    if( mx == -1 )return;
    if( mx <= ans )
    {
        ans = mx;
        in = source;
        vv.push_back( pair < int ,int > ( ans , in ) );
    }
}
