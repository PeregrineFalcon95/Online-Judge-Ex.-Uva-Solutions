///** One Last Try ***///
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define inf ( int )( 1e9 + 10 )
#define mxs (int)( 1e6 + 10 )
#define ll long long int
//#define md  int mid = ( l + r )>>1;
//int dx[]={+1,-1,+0,+0};///Four Directions
//int dy[]={+0,+0,+1,-1};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
ll ans, t, n, m, i, j , k, a, b, c, d, e,f, sz, q,mx,le,re,cases;
ll source , target;
vector < ll > graph [ mxs ] , rev [ mxs ];
stack < ll > st;
bool visited [ mxs ];
ll ar [ mxs ];
ll mat [ 5001 ] [ 5001 ];
string s, s2, s3, s4, s5, s6;
void brainfuck();
void dfs( ll source );
void dfs2( ll source );
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
    while( cin>>n>>m )
    {
        for ( i = 0 ; i <= n; i++ )
        {
            rev [ i ].clear();
            visited [ i ] = 0;
            graph [ i ].clear();
            for ( j = 0 ; j <= n; j++ )mat [ i ] [ j ] = 0;
        }
        for ( i = 1; i <= m; i++ )
        {
            cin>>a>>b;
            mat [ a ] [ b ] = 1;
        }
        for ( i = 1 ; i <= n; i++ )
        {
            for ( j = 1 ; j <= n; j++ )
            {
                if ( i != j && !mat [ i ] [ j ] )
                {
                    graph [ i ].push_back( j );
                    rev [ j ].push_back( i );
                }
            }
        }
        cin>>e;
        for ( i = 1 ; i <= n; i++ )
        {
            if ( !visited [ i ] )
            {
                dfs( i );
            }
        }
        ans = b = 0;
        for ( i = 0 ; i <= n; i++ )visited [ i ] = 0;
        while( !st.empty() )
        {
            a = st.top();
            st.pop();
            if ( !visited [ a ] )
            {
                dfs2( a );
                b++;
            }
        }
        ans = b * e;
        cout<<ans<<"\n";
    }
}
void dfs( ll source )
{
    visited [ source ] = 1;
    ll szz = graph [ source ].size();
    for ( ll ii = 0 ; ii < szz; ii++ )
    {
        ll bb = graph [ source ] [ ii ];
        if ( !visited [ bb ] )
        {
            dfs( bb );
        }
    }
    st.push( source );
}
void dfs2( ll source )
{
    visited [ source ] = 1;
    ll szz = rev [ source ].size();
    for ( ll ii = 0 ; ii < szz; ii++ )
    {
        ll bb = rev [ source ] [ ii ];
        if ( !visited [ bb ] )
        {
            dfs2( bb );
        }
    }
}
