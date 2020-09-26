#include<bits/stdc++.h>
using namespace std;
int n,m,t,a,b,c,cases;
bool visited [ 110 ];
int dis [ 110 ], parent [ 110 ];
vector < pair < int, int > > graph [ 110 ];
int main()
{
    while ( scanf("%d%d",&n,&m)==2 && ( n || m ) )
    {
        for ( int i = 0; i <= n; i++ )
        {
            graph [ i ].clear();
            visited [ i ] = dis [ i ] = 0;
        }
        for ( int i = 0; i != m; i++ )
        {
            scanf("%d%d%d",&a,&b,&c);
            graph [ a ].push_back ( pair < int , int > ( b , c ) );
            graph [ b ].push_back ( pair < int , int > ( a , c ) );
        }
        scanf("%d%d%d",&a,&b,&c);
        priority_queue < pair < int, int > > pq;
        pq.push( pair < int, int > (  0, a ) );
        while ( !pq.empty() )
        {
            int v = pq.top().second;
            pq.pop();
            if ( visited [ v ] )continue;
            visited [ v ] = 1;
            int sz = graph [ v ].size();
            for ( int i = 0 ; i != sz; i++ )
            {
                int o_o = graph [ v ] [ i ].first;
                int w_w = graph [ v ] [ i ].second;
                pq.push( pair < int, int > ( w_w, o_o ) );
                if ( !visited [ o_o ] && dis [ o_o ] < w_w )
                {
                    dis [ o_o ] = w_w;
                    parent [ o_o ] = v;
                }
            }
        }
        int o_o = b;
        int mi = INT_MAX;
        while ( 1)
        {
            mi = min( dis [ o_o ], mi );
            if ( parent [ o_o ] == a )break;
            o_o = parent [ o_o ];
        }
        int ans = 0;
        a = ( c / (mi-1) );
        if ( a*(mi-1) == c )ans = a;
        else ans = a+1;
        printf("Scenario #%d\nMinimum Number of Trips = %d\n\n",++cases,ans);
    }
    return 0;
}
