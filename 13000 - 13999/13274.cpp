#include<bits/stdc++.h>
using namespace std;
void fastscan(int &number)
{
    register int c;
    number = 0;
    c = getchar_unlocked();
    for (; (c>47 && c<58); c=getchar_unlocked())
        number = number *10 + c - 48;
}
vector < int > graph [ 1000+5 ];
char status [ 1000+5 ];
int k;
int dfs ( int n );
int main()
{
    int t,cases = 0;
    fastscan(t);
    while ( t-- )
    {
        int edges,a,b;
        for ( int i = 0; i != 1002; i++ )graph [ i ].clear();
        memset ( status, 'w', sizeof status );
        while(1){fastscan(edges);if(edges)break;}
        fastscan(k);
        for ( int i = 1; i != edges; i++ )
        {
            fastscan(a);
            fastscan(b);
            graph [ a ].push_back ( b );
            graph [ b ].push_back( a );
        }
        a = 0;
        a =  dfs( 1 );
        printf("Case %d: %d\n",++cases,a);
    }
    return 0;
}
int dfs ( int n )
{
    status [ n ] = 'g';
    int sz = graph [ n ].size();
    int flag = 0 , o_o_o = 0;
    vector < int > xxx;
    int mark = 0;
    for ( int i = 0; i != sz; i++ )
    {
        int o_o = graph [ n ] [ i ];
        if ( status [ o_o ] == 'w' )
        {
            flag++;
            xxx.push_back( dfs( o_o ) );
        }
    }
    status [ n ] = 'b';
    if ( flag < k )return 1;
    sort ( xxx.begin(), xxx.end(), greater<int>() );
    o_o_o = 0;
    for ( int i = 0; i != k; i++ )o_o_o+=xxx[i];
    return o_o_o+1;
}
