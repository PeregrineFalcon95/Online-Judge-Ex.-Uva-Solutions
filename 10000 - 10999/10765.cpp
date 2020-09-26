#include<bits/stdc++.h>
using namespace std;
#define mx 10009
int n,m,a,b,kk,time_;
vector < int > graph [ mx ];
bool visited [ mx ];
int dis [ mx ], lo [ mx ], parent [ mx ], count_ [ mx ];
void art ( int source );
int main()
{
    while ( scanf("%d%d",&n,&m) == 2 && ( n || m ) )
    {
        time_ = kk = 0;
        for ( int i = 0; i <= n; i++ )
        {
            parent [ i ] = -1;
            visited [ i ] = 0;
            count_ [ i ] = 1;
            graph [ i ].clear();
        }
        while ( scanf("%d%d",&a,&b) == 2 && ( a != -1 || b != -1 ) )
        {
            graph [ a ].push_back ( b );
            graph [ b ].push_back ( a );
        }
        art ( 0 );
        if ( kk > 1 )count_ [ 0 ] += kk-1;
        map < int , vector < int > > mp;
        for ( int i = 0; i != n; i++ )
        {
            mp [ count_ [ i ] ].push_back ( i );
        }
        map < int , vector < int > > ::iterator it = mp.begin();
        for ( it = mp.begin(); it != mp.end(); it++ )
        {
            a = it->first;
            sort( mp [ a ].begin(), mp [ a ].end() );
        }
        vector < pair < int , int > > ans;
        it = mp.end();
        if ( mp.size() )it--;
        while ( 1 )
        {
            int sz = it->second.size() ;
            a = it->first;
            for ( int i = 0; i != sz; i++ )
            {
                if ( ans.size() == m )break;
                ans.push_back ( pair < int , int > ( mp [ a ] [ i ] , a ) );
            }
            if ( ans.size() == m )break;
            if ( it == mp.begin() )break;
            it--;
        }
        int sz = ans.size();
        for ( int i = 0; i != sz; i++ )
        {
            printf("%d %d\n",ans [ i ].first, ans [ i ].second);
        }
        printf("\n");
    }
    return 0;
}
void art ( int source )
{
    time_++;
    visited [ source ] = 1;
    lo [ source ] = dis [ source ] = time_;
    int sz = graph [ source ].size();
    for ( int i = 0; i != sz; i++ )
    {
        int o_o = graph [ source ] [ i ];
        if ( parent [ source ] == o_o )continue;
        if ( visited [ o_o ] )
        {
            lo [ source ] = min( lo [ source ], dis[ o_o ] );
            continue;
        }
        parent [ o_o ] = source;
        art ( o_o );
        lo [ source ] = min( lo [ source ], lo [ o_o ] );
        if ( dis [ source ] <= lo [ o_o ] && source )count_ [ source ]++;
        if ( !source )kk++;
    }
}
