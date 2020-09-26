#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    vector < pair < ll , ll > > graph [ 100009 ];
    ll a,b,c,n,m;
    bool visited [ 100009 ];
    while ( scanf("%lld%lld",&n,&m) == 2 && ( n || m ) )
    {
        int sum = 0,o_o = 0;
        priority_queue < pair < ll , ll > > pq;
        for ( int i = 0; i <= n; i++ )
        {
            graph [ i ].clear();
            visited [ i ] = 0;
        }
        for ( int i = 0; i != m; i++ )
        {
            scanf("%lld%lld%lld",&a,&b,&c);
            graph [ a ].push_back ( pair < ll , ll > ( b , c ) );
            graph [ b ].push_back ( pair < ll , ll > ( a , c ) );
            sum+=c;
        }
        pq.push( pair < ll , ll > ( 0 , 0) );
        o_o = 0;
        while ( !pq.empty() )
        {
            ll front_weight = -pq.top().first;
            ll front_node = pq.top().second;
            pq.pop();
            if( visited [ front_node ] )continue;
            visited [ front_node ] = 1;
            o_o += front_weight;
            int sz = graph [ front_node ].size();
            for ( int i = 0; i != sz; i++ )
            {
                ll w_w = graph [ front_node ] [ i ].first;
                ll i_i = graph [ front_node ] [ i ].second;
                if ( !visited [ w_w ] )
                {
                    pq.push( pair < ll , ll > ( -i_i , w_w ) );
                }
            }
        }
        printf("%ld\n",(sum-o_o));
    }
    return 0;
}
