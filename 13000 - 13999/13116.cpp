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
int t, n, m, j,a, b, c, d, e,f, i,ans,cases, pos, num, root;
string s, s2, s3, s4;
int source_d , source_r , source_c , target_d , target_r, target_c , k, dim;
char grid [ 110 ] [ 110 ] [ 110 ];
int level [ 110 ] [ 110 ] [ 110 ];
struct data{
    int row , col , dim;
};
queue < data > qu;
void brainfuck();
void bfs();
bool checker ( int x , int y , int z)
{
    return !( z < 0 || x < 0 || y < 0 || z == dim || x == n || y == m || grid [ z ] [ x ] [ y ] == '#' || level [ z ] [ x ] [ y ] != -1 );
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
    while( cin>>n>>m>>dim && n || m || dim )
    {
        memset( level , -1 , sizeof level );
        for ( i = 0 ; i < dim; i++ )
            for ( j = 0 ; j < n; j++ )cin>>grid [ i ] [ j ];

        for ( i = 0 ; i < dim; i++ )
        {
            for ( j = 0 ; j < n; j++ )
            {
                for ( k = 0 ; k < m; k++ )
                {
                    if ( grid [ i ] [ j ] [ k ] == 'S' )
                    {
                        source_d = i , source_r = j , source_c = k;
                    }
                    else if ( grid [ i ] [ j ] [ k ] == 'E' )
                    {
                        target_d = i , target_r = j , target_c = k;
                    }
                }
            }
        }
        bfs();

        if ( level [ target_d ] [ target_r ] [ target_c ] != -1 )cout<<level [ target_d ] [ target_r ] [ target_c ]<<"\n";
        else cout<<"-1\n";
    }
}
void bfs()
{
    data lol;
    lol.dim = source_d;
    lol.row = source_r;
    lol.col = source_c;
    level [ source_d ] [ source_r ] [ source_c ] = 0;
    qu.push( lol );
    while( !qu.empty() )
    {
        lol = qu.front();
        a = lol.row;
        b = lol.col;
        c = lol.dim;
        qu.pop();
        for ( i = 0 ; i < 4; i++ )
        {
            e = a + dx [ i ];
            f = b + dy [ i ];
            if ( checker( e , f , c ) )
            {
                level [ c ] [ e ] [ f ] = level [ c ] [ a ] [ b ] + 1;
                lol.dim = c;
                lol.row = e;
                lol.col = f;
                qu.push( lol );
            }
        }
        if ( grid [ c ] [ a ] [ b ] == '-' )
        {
            ///Elevator
            if ( c - 1 >= 0 && grid [ c - 1 ] [ a ] [ b ] == '-' && level [ c - 1  ] [ a ] [ b ] == -1 )
            {
                lol.dim = c - 1;
                lol.row = a;
                lol.col = b;
                qu.push( lol );
                level [ c - 1 ] [ a ] [ b ] = level [ c ] [ a ] [ b ] + 1;
            }
            if ( c + 1 < dim && grid [ c + 1 ] [ a ] [ b ] == '-' && level [ c + 1 ] [ a ] [ b ] == -1 )
            {
                lol.dim = c + 1;
                lol.row = a;
                lol.col = b;
                qu.push( lol );
                level [ c + 1 ] [ a ] [ b ] = level [ c ] [ a ] [ b ] + 1;
            }
        }
    }
}
