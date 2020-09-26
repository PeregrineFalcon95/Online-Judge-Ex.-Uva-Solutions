///** One Last Try ***///
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define inf ( ll )(1000000000000000)//( 1e9 + 10 )
#define mxs (int)( 1e6 + 10 )
#define ll long long int
//#define md  int mid = ( l + r )>>1;
//int dx[]={+1,-1,+0,+0};///Four Directions
//int dy[]={+0,+0,+1,-1};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
int t, n, m, i, j, ans, k, a, b, c, d, e,f, sz, q,mx,l,h,cases,pos;
string s, s2, s3, s4, s5, s6;
int ar [ mxs ] , tree [ mxs ] , node_sz [ mxs ];
void brainfuck();
vector < int > graph [ mxs ];
vector < int > v;
bool visited [ 100007 ];
queue < int > qu;
int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    brainfuck();
    return 0;
}
void brainfuck()
{
    while( cin>>n>>m && n )
    {
        //memset( visited , 0 , sizeof visited );
        for ( i = 1 ; i <= m; i++ )
        {
            cin>>c;
            for ( j = 1 ; j <= c; j++ )
            {
                cin>>ar [ j ];
                if ( j != 1 )
                {
                    graph [ ar [ j ] ].push_back( ar [ j - 1 ] );
                    graph [ ar [ j - 1 ] ].push_back( ar [ j ] );
                }
            }
        }
        qu.push( 0 );
        visited [ 0 ] = 1;
        ans = 0;
        while( !qu.empty() )
        {
            ans++;
            a = qu.front();
            qu.pop();
            sz = graph [ a ].size();
            for ( i = 0 ; i < sz; i++ )
            {
                b = graph [ a ] [ i ];
                if ( !visited [ b ] )
                {
                    visited [ b ] = 1;
                    qu.push( b );
                }
            }
        }
        cout<<ans<<"\n";
        for ( i = 0 ; i <= n; i++ )
        {
            graph [ i ].clear();
            visited [ i ] = 0;
        }
    }
}
