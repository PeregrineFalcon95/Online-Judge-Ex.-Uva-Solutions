///** One Last Try ***///
#include<bits/stdc++.h>
using namespace std;
#define mxs (int)( 1e6 + 10 )
int ans, t, n, m, i, j , k, a, b, c, d, e,f, sz, q,mx,le,re,cases;
vector < int > graph [ mxs ] , rev [ mxs ] , extra [ mxs ];
bool visited [ mxs ];
int cost [ mxs ] , ar [ mxs ] , com [ mxs ];
stack < int > st , stk;
void dfs( int source );
void dfs2( int source );
void dfs3( int source );
int longest_path( int source );
void brainfuck();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    brainfuck();
    return 0;
}
void brainfuck()
{
    cin>>t;
    while( t-- )
    {
        cin>>n>>m;
        for ( i = 1 ; i <= n; i++ )
        {
            graph [ i ].clear();
            rev [ i ].clear();
            visited [ i ] = 0;
            extra [ i ].clear();
        }
        for ( i = 1 ; i <= m; i++ )
        {
            cin>>a>>b;
            graph [ a ].push_back( b );
            rev [ b ].push_back( a );
        }
        for ( i = 1 ; i <= n; i++ )
            if( !visited [ i ] )dfs( i );

        for ( i = 1 ; i <= n; i++ )visited [ i ] = 0;

        b = 0;
        while( !st.empty() )
        {
            a = st.top();
            st.pop();
            if ( !visited [ a ] )
            {
                c = 0;
                dfs2( a );
                ar [ ++b ] = c;
            }
        }
        for ( i = 1 ; i <= n; i++ )
        {
            visited [ i ] = 0;
            sz = graph [ i ].size();
            for ( j = 0 ; j < sz; j++ )
                if ( com [ i ] != com [ graph [ i ] [ j ] ]  )
                extra [ com [ i ] ].push_back( com [ graph [ i ] [ j ] ] );
        }
        n = b;
        for ( i = 1 ; i <= n; i++ )
        {
            if ( !visited [ i ] )
            {
                dfs3( i );
            }
        }
        ans = 0;
        for ( i = 1 ; i <= n; i++ )
        {
            stk = st;
            ans = max( ans , longest_path( i ) );
        }
        while( !st.empty() )st.pop();
        while( !stk.empty() )stk.pop();
        cout<<ans<<"\n";
    }
}
void dfs( int source )
{
    visited [ source ] = 1;
    int szz = graph [ source ].size();
    for ( int ii = 0 ; ii < szz; ii++ )
    {
        int bb = graph [ source ] [ ii ];
        if ( !visited [ bb ] )dfs( bb );
    }
    st.push( source );
}
void dfs2( int source )
{
    com [ source ] = b + 1;
    c++;
    visited [ source ] = 1;
    int szz = rev [ source ].size();
    for ( int ii = 0 ; ii < szz; ii++ )
    {
        int bb = rev [ source ] [ ii ];
        if ( !visited [ bb ] )dfs2( bb );
    }
}
void dfs3( int source )
{
    visited [ source ] = 1;
    int szz = extra [ source ].size();
    for ( int ii = 0 ; ii < szz; ii++ )
    {
        int bb = extra [ source ] [ ii ];
        if ( !visited [ bb ] )dfs3( bb );
    }
    st.push( source );
}
int longest_path( int source )
{
    int lol = 1;
    for ( j = 1 ; j <= n; j++ )cost [ j ] = 0;
    cost [ source ] = ar [ source ];
    lol = cost [ source ];
    while( !stk.empty() )
    {
        a = stk.top();
        stk.pop();
        sz = extra [ a ].size();
        for ( j = 0; j < sz; j++ )
        {
            b = extra [ a ] [ j ];
            if ( cost [ a ] && cost [ b ] < cost [ a ] + ar [ b ] )
            {
                cost [ b ] = cost [ a ] + ar [ b ];
                lol = max( lol , cost [ b ] );
            }
        }
    }
    return lol;
}
