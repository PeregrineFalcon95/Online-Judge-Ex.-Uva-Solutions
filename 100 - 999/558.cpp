/*#include<bits/stdc++.h>
using namespace std;
#define mx 1002
#define inf 99999999
int n,m,t,a,b,c;
vector < pair < int, int > > graph [ mx ];
int dis [ mx ];
int Ford( int source );
int main()
{
    scanf("%d",&t);
    while ( t-- )
    {
        scanf("%d%d",&n,&m);
        for ( int i = 0; i <= n; i++ )
        {
            dis [ i ] = inf;
            graph [ i ].clear();
        }
        for ( int i = 0; i != m; i++ )
        {
            scanf("%d%d%d",&a,&b,&c);
            graph [ a ].push_back ( pair < int , int > ( b , c ) );
        }
        int ans = Ford( 0 );
        if ( ans )printf("possible\n");
        else printf("not possible\n");
    }
    return 0;
}
int Ford( int source )
{
    dis [ source ] = 0;
    for ( int i = 0; i != n-1; i++ )
    {
        bool lol = 0;
        for ( int j = 0; j != n; j++ )
        {
            int sz = graph [ j ].size();
            for ( int k = 0; k != sz; k++ )
            {
                int o_o = graph [ j ] [ k ].first;
                int w_w = graph [ j ] [ k ].second;
                //dis [ o_o ] = min( dis [ o_o ] , ( w_w + dis [ j ] ) );
                if ( dis [ o_o ] > ( w_w + dis [ j ] ) )
                {
                    lol = 1;
                    dis [ o_o ] = ( w_w + dis [ j ] );
                }
            }
        }
        if ( !lol )break;
    }
    for ( int i = 0; i != n; i++ )
    {
        int sz = graph [ i ].size();
        for ( int j = 0; j != sz; j++ )
        {
            int o_o = graph [ i ] [ j ].first;
            int w_w = graph [ i ] [ j ].second;
            if ( dis [ o_o ] > ( w_w + dis [ i ] ) )
            {
                return 1;
            }
        }
    }
    return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;
#define mx 1002
#define inf 99999999
int n,m,t,a,b,c;
vector < pair < int , pair < int , int > > > graph;
int dis [ mx ];
int Ford( int source );
int main()
{
    scanf("%d",&t);
    while ( t-- )
    {
        graph.clear();
        scanf("%d%d",&n,&m);
        for ( int i = 0; i <= n; i++ )
        {
            dis [ i ] = inf;
        }
        for ( int i = 0; i != m; i++ )
        {
            scanf("%d%d%d",&a,&b,&c);
            graph.push_back( make_pair( a , make_pair( b , c ) ) );
        }
        int ans = Ford( 0 );
        if ( ans )printf("possible\n");
        else printf("not possible\n");
    }
    return 0;
}
int Ford( int source )
{
    dis [ source ] = 0;
    for ( int i = 0; i != n-1; i++ )
    {
        bool lol = 0;
        for ( int j = 0; j != m; j++ )
        {
            int sou = graph [ j ].first;
            int tar = graph [ j ].second.first;
            int we = graph [ j ].second.second;
            if ( dis [ tar ] > ( we + dis [ sou ] ) )
            {
                lol = 1;
                dis [ tar ] = ( we + dis [ sou ] );
            }
        }
        if ( !lol )break;
    }
    for ( int i = 0; i != m; i++ )
    {
        int sou = graph [ i ].first;
        int tar = graph [ i ].second.first;
        int we = graph [ i ].second.second;
        if ( dis [ tar ] > ( we + dis [ sou ] ) )
        {
            return 1;
        }
    }
    return 0;
}
