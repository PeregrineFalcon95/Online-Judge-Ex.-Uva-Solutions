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
int ans, t, n, m, i, j , k, a, b, c, d, e,f, sz, q,mx,le,re,cases;
int source , target;
vector < int > graph [ mxs ] , rev [ mxs ];
stack < int > st;
bool visited [ mxs ];
int ar [ mxs ];
map < string , int > mp;
string s, s2, s3, s4, s5, s6;
void brainfuck();
void dfs( int source );
void dfs2( int source );
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
            visited [ i ] = 0;
            graph [ i ].clear();
        }
        for ( i = 1; i <= m; i++ )
        {
            cin>>a>>b;
            graph [ a ].push_back( b );
        }
        for ( i = 0 ; i <= n; i++ )
        {
            if ( !visited [ i ] )
            {
                dfs( i );
            }
        }
        ans = 0;
        for ( i = 0 ; i <= n; i++ )visited [ i ] = 0;
        while( !st.empty() )
        {
            a = st.top();
            st.pop();
            if ( !visited [ a ] )
            {
                dfs2( a );
                if ( a )ans++;
            }
        }
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
        if ( !visited [ bb ] )
        {
            dfs( bb );
        }
    }
    st.push( source );
}
void dfs2( int source )
{
    visited [ source ] = 1;
    int szz = graph [ source ].size();
    for ( int ii = 0 ; ii < szz; ii++ )
    {
        int bb = graph [ source ] [ ii ];
        if ( !visited [ bb ] )
        {
            dfs2( bb );
        }
    }
}
