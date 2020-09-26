#include<bits/stdc++.h>
using namespace std;
vector < int > graph [ 100+5 ];
char color [ 100+5 ];
int source;
void dfs( int n );
void fastscan(int &number)
{
    bool negative = false;
    register int c;
    number = 0;
    c = getchar();
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
}
int main()
{
    int n;
    ios_base::sync_with_stdio(false);
    while ( scanf("%d",&n)==1 && n  )
    {
        getchar();
        for ( int i = 1; i <= n; i++ )graph [ i ].clear();
        for ( int i = 1; i <= n; i++ )color [ i ] = 'w';
        int a;
        while ( 1 )
        {
            fastscan( a );
            if( !a )break;
            int b;
            while ( 1)
            {
                fastscan(b );
                if ( !b )break;
                graph [ a ].push_back ( b );
                //a = b;
            }
        }
        fastscan(a);
        for ( int i = 1; i <= a; i++ )
        {
            int b;
            fastscan(b);
            for ( int i = 1; i <= n; i++ )color [ i ] = 'w';
            int ans = 0;
            source = b;
            dfs ( b );
            if ( source == b )color [ b ] = 'w';
            vector < int > v;
            for ( int i = 1; i <= n; i++ )
            {
                if ( color [ i ] == 'w')
                {
                    ans++;
                    v.push_back(i);
                }
            }
            printf("%d",ans);
            for ( int i = 0; i != ans; i++)
            {
                printf(" %d",v[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
void dfs( int n )
{
    color [ n ] = 'g';
    int sz = graph [ n ].size();
    for ( int i = 0; i != sz; i++ )
    {
        int o_o = graph [ n ] [ i ];
        if ( o_o == source )source = -1;
        if ( color [ o_o ] =='w' )
        {
            dfs ( o_o );
        }
    }
    color [ n ] ='b';
    return;
}
