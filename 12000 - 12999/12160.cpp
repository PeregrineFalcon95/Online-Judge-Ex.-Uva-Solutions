///*** One Last Try ***///
#include<bits/stdc++.h>
using namespace std;
#define inf ( int )( 1e9 )
#define mxs (int)( 1e6 + 10 )
#define ll long long int
#define md  int mid = ( l + r )>>1;
//int dx[]={+1,-1,+0,+0};///Four Directions
//int dy[]={+0,+0,+1,-1};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
int t, n, m, i, j, ans, k, a, b, c, d, e, row, col,sz,f ;
string s, s2, s3, s4;
int ar [ mxs ], ar2 [ mxs ];
bool visited [ 10005 ];
queue < int > qu;
void brainfuck();
int bfs( int source , int target );
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
    while( cin>>a>>b>>e && e  )
    {
        for ( i = 1 ; i <= e; i++ )cin>>ar [ i ];
        a = bfs( a , b );
        if ( a == -1 )cout<<"Case "<<++f<<": Permanently Locked\n";
        else cout<<"Case "<<++f<<": "<<a<<"\n";
    }
}
int bfs( int source , int target )
{
    memset( visited , 0 , sizeof visited );
    while( !qu.empty() )qu.pop();
    visited [ source ] = 1;
    qu.push( source );
    ar2 [ source ] = 0;
    c = 0;
    while( !qu.empty() )
    {
        c++;
        a = qu.front();
        qu.pop();
        for ( i = 1 ; i <= e; i++ )
        {
            b = a + ar [ i ];
            b %= 10000;
            if ( !visited [ b ] )
            {
                visited [ b ] = 1;
                ar2 [ b ] = ar2 [ a ] + 1;
                if ( b == target )return ar2 [ b ];
                qu.push( b );
            }
        }
    }
    return -1;
}

