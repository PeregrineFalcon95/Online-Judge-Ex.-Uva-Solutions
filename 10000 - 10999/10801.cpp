#include<bits/stdc++.h>
using namespace std;
#define inf 99999999
#define pii pair < int , int >
string s,token;
int n,m,a,b,c,d,e,f,t,target;
int time_ [ 6 ], cost [ 510 ], ar [ 6 ], markerr [ 510 ];
int floors [ 6 ] [ 110 ];
map < int, int > marker;
vector < pii > graph [ 510 ];
void make_graph();
int djk( int source );
int main()
{
    while( scanf("%d%d",&n,&target) == 2 )
    {
        for ( int i = 0; i <= 502 ; i ++ )
        {
            markerr [ i ] = inf;
            graph [ i ].clear();
        }
        for ( int i = 1; i <= n; i++ )
        {
            scanf("%d",&time_ [ i ] );
        }
        getchar();
        for( int i = 1; i <= n; i++ )
        {
            getline(cin,s);
            stringstream ss ( s );
            b = 0;
            while( ss >> token )
            {
                a = 0;
                b++;
                int sz = token.size();
                for ( int j = 0; j != sz; j++ )
                {
                    a*= 10;
                    a+= token [ j ] - '0';
                }
                floors [ i ] [ b ] = a;
            }
            ar [ i ] = b;
        }
        make_graph();
        int mi = inf;
        if( !markerr [ 0 ] )mi = min(mi , djk( 0 ) );
        if( !markerr [ 100 ] )mi = min( mi , djk( 100) );
        if( !markerr [ 200 ] )mi = min( mi , djk( 200 ) );
        if( !markerr [ 300 ] )mi = min( mi , djk( 300 ) );
        if( !markerr [ 400 ] )mi = min( mi , djk( 400 ) );
        int ans = mi;
        if( ans == inf )printf("IMPOSSIBLE\n");
        else printf("%d\n",ans);
    }
    return 0;
}
void make_graph()
{
    marker.clear();
    for ( int i = 1; i <= n; i++ )
    {
        a = ar [ i ];
        if( !floors [ i ] [ 1 ] )markerr [ (i-1) * 100 ] = 0;
        for ( int j = 2; j <= a; j++ )
        {
            b = ( floors [ i ] [ j ] + ( ( i-1 ) * 100 ) );
            c = ( floors [ i ] [ j-1 ] + ( ( i-1 ) * 100 ) );
            marker [ b ] = 1;
            marker [ c ] = 1;
            d = time_ [ i ];
            e = abs(b-c)*d;
            graph [ b ].push_back( pii ( c, e ) );
            graph [ c ].push_back( pii ( b, e ) );
        }
    }
    map < int, int > ::iterator it = marker.begin();
    map < int,int > ::iterator it2;
    for( ; it != marker.end(); it++ )
    {
        for( it2 = marker.begin(); it2 != marker.end(); it2++ )
        {
            a = abs( it->first - it2->first );
            if( a == 100 || a == 200 || a == 300 || a == 400 )
            {
                graph [ it->first ].push_back( pii ( it2->first, 60 ) );
                graph [ it2->first ].push_back( pii ( it->first, 60 ) );
            }
        }
    }
}
int djk( int source )
{
    priority_queue < pii > pq;
    pq.push( pii ( 0 , source ) );
    for( int i = 0; i <= 502; i++ )cost [ i ] = inf;
    cost [ source ] = 0;
    while( !pq.empty() )
    {
        int front_ = pq.top().second;
        pq.pop();
        int sz = graph [ front_ ].size();
        for( int i = 0; i != sz; i++ )
        {
            int node = graph [ front_ ] [ i ].first;
            int cos = graph [ front_ ] [ i ].second;
            int o_o = cost [ front_ ] + cos;
            if( cost [ node ] > o_o )
            {
                pq.push( pii ( -o_o, node ) );
                cost [ node ] = o_o;
            }
        }
    }
    int mi = inf;
    for( int i = 1; i <= n; i++ )
    {
        a = ( ( i-1 ) * 100 ) + target;
        mi = min( cost [ a ], mi );
    }
    return mi;
}
