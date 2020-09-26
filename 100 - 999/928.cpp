///*** One Last Try ***///
#include<bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#define ll long long int
#define inf ( int )( 1e9 + 1e9 )
#define mxs (int)( 1e6 + 10 )
#define md  int mid = ( l + r )>>1;
#define mod (int)(1e9)+7
int dx[]={+1,0,+0,-1};///Four Directions
int dy[]={+0,-1,+1,+0};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
int source, t, n, m, j,a, b, c, d, e,f, i,ans,cases, pos, num, root, k;
string s, s2, s3, s4;
int source_r , source_c , target_r , target_c;
struct data
{
    int row , col , state;
};
queue < data > qu;
int ar [ mxs ];
int dp [ 310 ] [ 310 ] [ 5 ];
char grid [ 310 ] [ 310 ];
void brainfuck();
bool checker( int x , int y )
{
    return !( x < 0 || y < 0 || x >= n || y >= m || grid [ x ] [ y ] == '#' );
}
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
        for ( i = 0 ; i <= 301; i++ )
            for ( j = 0 ; j <= 301; j++ )
                for ( k = 0 ; k <= 4; k++ )
                    dp [ i ] [ j ] [ k ] = inf;

        for ( i = 0 ; i < n; i++ )cin>>grid [ i ];
        for ( i = 0 ; i < n; i++ )
        {
            for ( j = 0 ; j < m; j++ )
            {
                if ( grid [ i ] [ j ] == 'S' )
                {
                    source_r = i;
                    source_c = j;
                }
                else if ( grid [ i ] [ j ] == 'E' )
                {
                    target_r = i;
                    target_c = j;
                }
            }
        }
        data lol;
        lol.row = source_r;
        lol.col = source_c;
        lol.state = 0;
        qu.push( lol );
        dp [ source_r ] [ source_c ] [ 0 ] = 0;
        while( !qu.empty() )
        {
            lol = qu.front();
            a = lol.row;
            b = lol.col;
            c = lol.state;
            qu.pop();
            for ( i = 0 ; i < 4; i++ )
            {
                e = a;
                f = b;
                for ( j = 0 ; j < c + 1; j++ )
                {
                    e += dx [ i ];
                    f += dy [ i ];
                    if ( checker( e , f ) == 0 )break;
                }
                if ( c == 2 )k = 0;
                    else k = c + 1;
                if ( checker( e , f ) && dp [ e ] [ f ] [ k ] > dp [ a ] [ b ] [ c ] + 1 )
                {

                    dp [ e ] [ f ] [ k ] = dp [ a ] [ b ] [ c ] + 1;
                    lol.row = e;
                    lol.col = f;
                    lol.state = k;
                    qu.push( lol );
                }
            }
        }
        ans = inf;
        for ( i = 0 ; i <= 3; i++ )
        {
            if ( dp [ target_r ] [ target_c ] [ i ] != inf )
            {
                ans = min( dp [ target_r ] [ target_c ] [ i ] , ans );
            }
        }
        if ( ans == inf )cout<<"NO\n";
        else cout<<ans<<"\n";
    }
}
