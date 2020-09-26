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
int ans, t, n, m, i, j , k, a, b, c, d, e,f, sz, q,mx,le,re,cases,pos;
string s, s2, s3, s4, s5, s6;
int ar [ mxs ] ;
int status [ mxs ];
queue < int > qu;
bool visited [ mxs ];
vector < int > lol [ mxs ];
map < int , vector < int > > mp;
map < int , vector < int > >::iterator it;
vector < int > prime;
vector < int > graph [ mxs ];
void brainfuck();
void seive();
void clear_();
void bfs( int source );
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(NULL);
    //cin.tie(NULL);
    //cout.tie(NULL);
    brainfuck();
    return 0;
}
void brainfuck()
{
    seive();
    scanf("%d",&t);
    e = sqrt( 1000002 );
    while( t-- )
    {
        clear_();
        scanf("%d",&n);
        for ( i = 1 ; i <= n; i++ )
        {
            scanf("%d",&a);
            if( a > 1 )mp [ a ].push_back( i );
            b = sqrt( a + 1 ) + 5;
            c = lol [ a ].size();
            for ( j = 0; j < c ; j++ )
                mp [ lol [ a ] [ j ] ].push_back( i );

        }
        for (  it = mp.begin(); it != mp.end(); it++ )
        {
            a = it->second.size();
            for ( i = 1; i < a; i++ )
            {
                graph [ it->second [ i ] ].push_back( it->second [ i - 1 ] );
                graph [ it->second [ i - 1 ] ].push_back( it->second [ i ] );
            }
        }
        ans = 0;
        for ( i = 1 ; i <= n ; i++ )
        {
            if ( !visited [ i ] )
            {
                ans++;
                bfs( i );
            }
        }
        printf("Case %d: %d\n",++cases,ans);
    }
}
void seive()
{
    a = sqrt( 1000002 );
    for ( i  = 1 ; i <= 1000000; i++ )status [ i ] = i;

    for ( i= 4 ; i <= 1000000; i+= 2 )status [ i ] = 2;
    for ( i = 3; i <= a; i += 2 )
    {
        if ( status [ i ] == i )
        {
            prime.push_back( i );
            for ( j = i + i; j <= 1000000; j += i )status [ j ]= i;
        }
    }
    vector<int> ret;
    for ( i = 1 ; i <= 1000000 ; i++ )
    {
        ret.clear();
        int xx = i ;
        while (xx != 1)
        {
            ret.push_back(status[xx]);
            xx = xx / status[xx];
        }
        lol [ i ] = ret;

    }
}
void clear_()
{
    mp.clear();
    for ( i = 1 ; i <= 1000000; i++ )
    {
        visited [ i ] = 0;
        graph [ i ].clear();
    }
}
void bfs( int source )
{
    qu.push( source );
    visited [ source ] = 1;
    while( !qu.empty() )
    {
        a = qu.front();
        qu.pop();
        sz = graph [ a ].size();
        for ( j = 0 ; j < sz; j++ )
        {
            b = graph [ a ] [ j ];
            if ( !visited [ b ] )
            {
                qu.push( b );
                visited [ b ] = 1;
            }
        }
    }
}
