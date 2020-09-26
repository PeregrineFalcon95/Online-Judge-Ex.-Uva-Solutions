#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,c,d,source,target,cases;
map < string , int > mp;
string s,s2;
vector < pair < int, int > > graph [ 205 ];
int dis [ 205 ], parent [ 205 ];
bool visited [ 205 ];
int MST();
int main()
{
    while ( scanf("%d%d",&n,&m) == 2 && ( n || m ) )
    {
        d = 0;
        for ( int i = 0; i <= n; i++ )
        {
            parent [ i ] = -1;
            visited [ i ] = 0;
            dis [ i ] = 0;
            graph [ i ].clear();
        }
        for ( int i = 0; i != m; i++ )
        {
            cin>>s>>s2;
            if ( mp .find( s ) != mp.end() )
            {
                b = mp [ s ];
            }
            else
            {
                mp [ s ] = ++d;
                b = d;
            }
            if ( mp.find ( s2 ) != mp.end() )
            {
                c = mp [ s2 ];
            }
            else
            {
                mp [ s2 ] = ++d;
                c = d;
            }
            scanf("%d",&a);
            graph [ b ].push_back ( pair < int ,int > ( c, a ) );
            graph [ c ].push_back ( pair < int, int > ( b, a ) );
        }
        cin>>s>>s2;
        if ( mp.find( s ) != mp.end() )
        {
            source = mp [ s ];
        }
        else
        {
            mp [ s ] = ++d;
            source = d;
        }

        if ( mp.find( s2 ) != mp.end() )
        {
            target = mp [ s2 ];
        }
        else
        {
            mp [ s2 ] = ++d;
            target = d;
        }
        int ans = MST();
        printf("Scenario #%d\n",++cases);
        printf("%d tons\n",ans);
        putchar(10);
    }
    return 0;
}
int MST()
{
    dis [ source ] = INT_MAX;
    int node = source;
    while ( !visited [ node ] )
    {
        visited [ node ] = 1;
        int sz = graph [ node ].size();
        for ( int i = 0; i != sz; i++ )
        {
            int o_o = graph [ node ] [ i ].first;
            int w_w = graph [ node ] [ i ].second;
            if ( !visited [ o_o ] && dis [ o_o ] < w_w )
            {
                dis [ o_o ] = w_w;
                parent [ o_o ] = node;
            }
        }
        node = 1;
        int dist = 0;
        for ( int i = 1; i <=n; i++ )
        {
            if ( !visited [ i ] && dist < dis [ i ] )
            {
                node = i;
                dist = dis [ i ];
            }
        }
    }
    int ans = INT_MAX;
    while ( 1 )
    {
        ans = min( ans, dis [ target ] );
        target = parent [ target ];
        if ( target == source )return ans;
    }
}
