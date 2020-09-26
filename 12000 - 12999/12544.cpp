///*** One Last Try ***///
#include<bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#define ll long long int
#define inf ( int )( 1e9 + 1e9 )
#define mxs (int)( 1e6 + 10 )
#define md  int mid = ( l + r )>>1;
#define mod 10000000000007//(ll)(1e9)+7
//int dx[]={+1,0,+0,-1};///Four Directions
//int dy[]={+0,-1,+1,+0};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
int t, n, m, j,a, b, c, d, e,f, i,ans,cases , pos , num , root;
string s, s2, s3, s4;
int visited [ 510 ] , level [ 510 ] , parent [ 510 ];
queue < int > qu;
vector < int > graph [ mxs ];
void brainfuck();
int finder( int node );
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
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
        for ( i = 0 ; i <= n; i++ )
        {
            graph [ i ].clear();
        }
        while( m-- )
        {
            cin>>a>>b;
            graph [ a ].push_back( b );
            graph [ b ].push_back( a );
        }
        ans = inf;
        for ( i = 0; i < n; i++ )
        {
            ans = min( ans , finder( i ) );
        }
        cout<<"Case "<<++cases<<": ";
        if ( ans == inf )cout<<"impossible\n";
        else cout<<ans<<"\n";
    }
}
int finder( int node )
{
    int lol = inf;
    while( !qu.empty() )qu.pop();
    memset( visited , 0 , sizeof visited );
    memset( parent , -1, sizeof parent );
    level [ node ] = 0;
    qu.push( node );
    visited [ node ] = 1;
    while( !qu.empty() )
    {
        a = qu.front();
        qu.pop();
        int sz = graph [ a ].size();
        for ( j = 0 ; j < sz; j++ )
        {
            b = graph [ a ] [ j ];
            if ( !visited [ b ] )
            {
                parent [ b ] = a;
                qu.push( b );
                level [ b ] = level [ a ] + 1;
                visited [ b ] = 1;
            }
            else if ( parent [ a ] != b )
            {
                lol = min( lol , level [ a ] + level [ b ] + 1 );
                //return ( level [ a ] + level [ b ] + 1);
            }
        }
    }
    return lol;
}
