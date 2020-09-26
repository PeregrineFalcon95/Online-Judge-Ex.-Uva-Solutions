///** One Last Try ***///
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define inf ( int  )( 1e9 + 10 )
#define mxs (int)( 1e6 + 10 )
//#define md  int mid = ( l + r )>>1;
int dx[]={+1,-1,+0,+0};///Four Directions
int dy[]={+0,+0,+1,-1};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
int ans, t, n, m, i, j , k, a, b, c, d, e,f, sz, q,cases , sum;
string s , s2 , s3 , s4;
int ar [ mxs ] ;
int dis [ mxs ];
int grid [ 110 ] [ 110 ];
vector < pair < int , int > > graph [ mxs ];
bool visited [ mxs ];
stack < int > stk;
void clear_();
void brainfuck();
bool checker( int x , int y )
{
    return !( x <= 0 || y <= 0 || x > n || y > m );
}
void dfs( int source );
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
        cin>>s>>n>>m;
        for ( i = 1 ; i <= n; i++ )
            for ( j = 1 ; j <= m; j++ )cin>>grid [ i ] [ j ];
        clear_();
        for ( i = 1 ; i <= n; i++ )
        {
            for ( j = 1; j <= m ; j++ )
            {
                dis [ m * ( i  - 1  ) + j  ] = 1;
                for ( k = 0 ; k < 4; k++ )
                {
                    a = dx [ k ] + i;
                    b = dy [ k ] + j;
                    if ( checker( a , b ) && grid [ a ] [ b ] < grid [ i ] [ j ] )
                    {
                        graph [ m * ( i - 1 ) + j ].push_back( { m * ( a - 1 ) + b , 1 } );
                    }
                }
            }
        }
        n = n * m;
        ans = 0;
        for ( i = 1 ; i <= n; i++ )if ( !visited [ i ] )dfs ( i );
        while( !stk.empty() )
        {
            a = stk.top();
            stk.pop();
            int sz = graph [ a ].size();
            for ( i = 0 ; i < sz; i++ )
            {
                b = graph [ a ] [ i ].first;
                c = graph [ a ] [ i ].second;
                if ( dis [ b ] < dis [ a ] + c )
                {
                    dis [ b ] = dis [ a ] + c;
                    ans = max( dis [ b ] , ans  );
                }
            }
        }
        cout<<s<<": "<<ans<<"\n";
    }
}
void dfs( int source )
{
    visited [ source ] = 1;
    int sz = graph [ source ].size();
    for ( int ii = 0 ; ii < sz; ii++ )
    {
        int bb = graph [ source ] [ ii ].first;
        if ( !visited [ bb ] )dfs( bb );
    }
    stk.push( source );
}
void clear_()
{
    a = n * m;
    for ( i = 0 ; i <= a; i++ )
    {
        graph [ i ].clear();
        dis [ i ] = 0;
        visited [ i ] = 0;
    }
}
