#include<bits/stdc++.h>
using namespace std;
#define inf 99999999
#define mx 110
#define pii pair < int , int >
int t,a,b,c,ans,num,exit_,timer,e,f;
int cost [ mx ];
vector < pii > graph [ mx ];
int djk( int source );
int main()
{
    scanf("%d",&t);
    f = t-1;
    while( t-- )
    {
        if ( f != t )putchar( 10 );
        scanf("%d%d%d%d",&num,&exit_,&timer,&e);
        for ( int i = 0; i <= num; i++ )
        {
            graph [ i ].clear();
            cost [ i ] = inf;
        }
        for ( int i = 0; i != e; i++ )
        {
            scanf("%d%d%d",&a,&b,&c);
            graph [ a ].push_back( pii ( b, c ) );
        }
        ans = 0;
        for ( int i = 1; i <= num; i++ )
        {
            if( djk( i ) ) ans++;
            for ( int j = 1; j <=num ; j++)cost [ j ] = inf;
        }
        printf("%d\n",ans);
    }
    return 0;
}
int djk( int source )
{
    priority_queue < pii > pq;
    pq.push( pii ( 0, source ) );
    cost [ source ] = 0;
    while( !pq.empty() )
    {
        int front_ = pq.top().second;
        pq.pop();
        int sz = graph [ front_ ].size();
        for ( int i = 0; i != sz; i++ )
        {
            int o_o = graph [ front_ ] [ i ].first;
            int lol = graph [ front_ ] [ i ].second;
            if ( cost [ o_o ] > cost [ front_ ] + lol )
            {
                cost [ o_o ] = cost [ front_ ] + lol;
                pq.push( pii ( -cost [ o_o ], o_o ) );
            }
        }
    }
    if ( cost [ exit_ ] <= timer ) return 1;
    return 0;
}
