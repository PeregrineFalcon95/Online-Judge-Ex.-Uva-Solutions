#include<bits/stdc++.h>
using namespace std;
#define mx 100005
bool visited [ mx ];
int dis [ mx ], lo [ mx ],parent [ mx ];
int n,a,b,c,ans,time_,kk,o_o;
char ch,ch2,ch3;
string s;
vector < int > graph [ mx ];
vector < pair < int, int > >bridges;
vector < int > temp;
void art( int source );
int main()
{
    while ( scanf("%d",&n) == 1 )
    {
        time_ = kk = 0;
        bridges.clear();
        for ( int i = 0; i <= n; i++ )
        {
            visited [ i ] = dis [ i ] = 0;
            parent [ i ] = -1;
            lo [ i ] = INT_MAX;
            graph [ i ].clear();
        }
        for ( int i = 0; i != n; i++ )
        {
            scanf("%d%c%c%d%c",&a,&ch,&ch,&b,&ch);
            for ( int j = 0; j != b; j++ )
            {
                scanf("%d",&c);
                long long int e = a*10+c;
                long long int f = c*10+a;
                graph [ a ].push_back ( c );
                graph [ c ].push_back ( a );
            }
        }
        ans = 0;
        for ( int i = 0; i != n; i++ )
        {
            if ( !visited [ i ] )
            {
                o_o = i;
                kk = 0;
                art( i );
            }
        }
        sort(bridges.begin(),bridges.end());
        int sz = bridges.size();
        printf("%d critical links\n",sz);
        for ( int i = 0; i != sz; i++ )
        {
            printf("%d - %d\n",bridges[ i ].first,bridges [ i ].second);
        }
        printf("\n");
    }
    return 0;
}
void art( int source )
{
    time_++;
    lo [ source ] = dis [ source ] = time_;
    visited [ source ] = 1;
    int sz = graph [ source ].size();
    for ( int i = 0; i != sz ; i++ )
    {
        int vv = graph [ source ] [ i ];
        if ( parent [ source ] == vv )continue;
        if ( visited [ vv ] )
        {
            lo [ source ] = min( lo [ source ], dis [ vv ] );
        }
        else if ( !visited [ vv ] )
        {
            parent [ vv ] = source;
            art ( vv );
            lo [ source ] = min( lo [ vv ], lo [ source ] );
            if ( dis [ source ] < lo [ vv ] /*&& source != o_o*/ )
            {
                int pp = min( vv, source );
                int xx = max( vv, source );
                bridges.push_back ( pair < int, int > ( pp, xx ) );
            }
        }
    }
}
