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
int a,b,cases,t,n,m,tim,ans;
vector < int > graph [ 10005 ];
stack < int > st;
bool visited [ 10005 ];
void dfs( int source );
void dfs2( int source );
int main()
{
    fastscan( t );
    while ( t-- )
    {
        while(1){fastscan( n );if(n)break;}
        fastscan( m );
        while ( !st.empty() )st.pop();
        for ( int i = 0; i <= n+1 ; i++ )
        {
            graph [ i ].clear();
            visited [ i ] = 0;
        }
        tim = 0;
        for ( int i = 0; i != m; i++ )
        {
            fastscan( a );
            fastscan( b );
            graph [ a ].push_back( b );
        }
        for ( int i = 1; i <= n; i++ )
        {
            if( !visited[ i ] )
            {
                dfs( i );
            }
        }
        memset(visited, 0, sizeof visited );
        ans = 0;
        while( ! st.empty() )
        {
            int w_w = st.top();
            st.pop();
            if ( !visited [ w_w ] )
            {
                ans++;
                dfs2( w_w );
            }
        }
        printf("Case %d: %d\n",++cases,ans);
    }
    return 0;
}
void dfs( int source )
{
    visited [ source ] = 1;
    int sz = graph [ source ].size();
    for ( int i = 0; i != sz; i++ )
    {
        int o_o = graph [ source ] [ i ];
        if ( !visited [ o_o ] )dfs( o_o );
    }
    st.push(source);
}

void dfs2( int source )
{
    visited [ source ] = 1;
    int sz = graph[ source ].size();
    for ( int i = 0; i != sz; i++ )
    {
        int o_o = graph[ source ][ i ];
        if ( !visited [ o_o ] )
        {
            dfs2( o_o );
        }
    }
}
