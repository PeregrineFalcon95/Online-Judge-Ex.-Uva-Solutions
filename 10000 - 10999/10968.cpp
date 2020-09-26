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
int t, n, m, j,a, b, c, d, e,f, i,ans,cases ;
string s, s2, s3, s4;
int degree [ 1010 ] , visited [ 1010 ] , level [ 1010 ];
vector < int > graph [ 1010 ];
queue < int > qu;
void brainfuck();
int bfs( );
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
    while( cin>>n>>m && n )
    {
        for ( i = 0; i <= n; i++ )
        {
            visited [ i ] = 0;
            graph [ i ].clear();
        }
        while( m-- )
        {
            cin>>a>>b;
            graph [ a ].push_back( b );
            graph [ b ].push_back( a );
        }
        a = b = -1;
        for ( i = 1 ; i <= n; i++ )
        {

            degree [ i ] = graph [ i ].size();
            if ( degree [ i ] < 2 )
            {
                cout<<"Poor Koorosh\n";
                a = -2;
                break;
            }
            if ( degree [ i ]&1 && a == -1 )
            {
                a = i;
            }
            else if ( degree [ i ]&1 && b == -1 )
            {
                b = i;
            }
        }
        if ( a == -2 )continue;
        c = bfs();
        if ( c == -1 )cout<<"Poor Koorosh\n";
        else cout<<c<<"\n";
    }
}
int bfs( )
{
    if ( a == -1 || b == -1  )return 0;
    memset( level , -1, sizeof level );
    while( !qu.empty() )qu.pop();
    qu.push( a );
    visited [ a ] = 1;
    level [ a ] = 0;
    while( !qu.empty() )
    {
        a = qu.front();
        qu.pop();
        int sz = graph [ a ].size();
        for ( i = 0 ; i < sz; i++ )
        {
            d = graph [ a ] [ i ];
            if ( !visited [ d ] && degree [ d ] > 2 )
            {
                visited [ d ] = 1;
                qu.push( d );
                level [ d ] = level [ a ] + 1;
                if ( d == b )return level [ d ];
            }
        }
    }
    return -1;
}
