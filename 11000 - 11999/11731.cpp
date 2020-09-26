#include<bits/stdc++.h>
using namespace std;
int n,o_o,marker,m;
vector < int > graph [ 30 ], graph_rev [ 30 ];
vector < int > ans [ 30 ];
char visited [ 30 ];
stack < int > stk;
void dfs( int source );
void dfs_2 ( int source );
int main()
{
    while ( scanf("%d",&n) == 1 && n )
    {
        if ( m )putchar(10);
        m++;
        getchar();
        marker = 0;
        for ( int i = 0; i <= 27; i++ )
        {
            ans [ i ].clear();
            graph [ i ].clear();
            graph_rev [ i ].clear();
            visited [ i ] = '!';
        }
        string s;
        for ( int i = 0; i != n; i++ )
        {
            getline(cin, s );
            stringstream ss ( s );
            string g;
            o_o = 0;
            int a = s [ 10 ]-64;
            visited [ a ] = 'w';
            while ( ss >> g )
            {
                char ch = g  [ 0 ];
                if ( o_o == 5 )break;
                o_o++;
                graph [ ch-64 ].push_back ( a );
                graph_rev [ a ].push_back ( ch-64 );
                visited [ ch-64 ] = 'w';
            }
        }
        for ( int i = 0; i <= 26; i++ )
        {
            if ( visited [ i ] == 'w' )
            {
                dfs(i);
            }
        }
        for ( int i = 0; i <= 27; i++ )
        {
            if ( visited [ i ] == 'g' )visited [ i ] = 'w';
        }
        while ( !stk.empty() )
        {
            int w_w = stk.top();
            stk.pop();
            if ( visited [ w_w ] == 'w' )
            {
                marker++;
                dfs_2( w_w );
            }
        }
        map < int, vector < int > > lol;
        for ( int i = 0; i <= marker; i++ )
        {
            int sz = ans [ i ].size();
            sort( ans [ i ].begin(), ans [ i ].end());
            for ( int j = 0; j != sz ; j++ )
            {
                lol [ ans [ i ] [ 0 ] ].push_back ( ans [ i ] [ j ] );
            }
        }
        map < int, vector < int > > ::iterator it = lol.begin();
        for ( it = lol.begin(); it != lol.end(); it++ )
        {
            int sz = it->second.size();
            for ( int j = 0; j != sz ; j++ )
            {
                if(j)putchar(32);
                printf("%c",it->second [ j ]+64 );
            }
            putchar(10);
        }
    }
    return 0;
}
void dfs( int source )
{
    visited [ source ] = 'g';
    int sz = graph [ source ].size();
    for ( int i = 0; i != sz; i++ )
    {
        int kk = graph [ source ] [ i ];
        if ( visited [ kk ] ==  'w' )dfs( kk );
    }
    stk.push( source );
}
void dfs_2( int source )
{
    ans [ marker ].push_back ( source );
    visited [ source ] = 'g';
    int sz = graph_rev [ source ].size();
    for ( int i = 0; i != sz; i++ )
    {
        int h_h = graph_rev [ source ] [ i ];
        if ( visited [ h_h ] == 'w' )dfs_2( h_h);
    }
}
