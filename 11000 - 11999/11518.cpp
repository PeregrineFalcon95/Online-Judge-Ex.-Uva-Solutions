#include<bits/stdc++.h>
using namespace std;
vector < int > graph [ 10000 +5 ];
char color [ 10000 +5 ];
void dfs ( int n );
int main()
{
    int t;
    scanf("%d",&t);
    while ( t-- )
    {
        int n,m,l;
        scanf("%d%d%d",&n,&m,&l);
        for ( int i = 1; i <= n; i++ )graph [ i ].clear();
        for ( int i = 1; i <= n; i++ )color [ i ] = 'w';
        for ( int i = 1; i <= m; i++ )
        {
            int a,b;
            scanf("%d%d",&a,&b);
            graph [ a ].push_back ( b );
        }
        int a;
        for ( int i = 0; i != l; i++ )
        {
            scanf("%d",&a);
            if ( color [ a ] =='w' )
            {
                dfs ( a );
            }
        }
        int ans = 0;
        for ( int i = 1; i <= n; i++ )
        {
            if ( color [ i ] =='w' )ans++;
        }
        printf("%d\n",n-ans);
    }
    return 0;
}
void dfs ( int n )
{
    color [ n ] = 'g';
    int sz = graph [ n ].size();
    for ( int i = 0; i != sz; i++ )
    {
        int o_o = graph [ n ] [ i ];
        if ( color [ o_o ] == 'w' )
        {
            dfs( o_o );
        }
    }
    color [ n ] == 'b';
    return;
}
