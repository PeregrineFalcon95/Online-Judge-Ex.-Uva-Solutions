#include<bits/stdc++.h>
using namespace std;
int n, cases;
char grid[ 30 ] [ 30 ];
bool visited[ 30 ] [ 30 ];
int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};
int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};
bool check(int i, int j ){return !(i < 0 || j < 0 || i >= n || j >= n || grid[ i ] [ j ] !='1' || visited [ i ] [ j ] );}
void bfs(int i, int j);
int main()
{
    while(scanf("%d",&n) == 1 )
    {
        for ( int i = 0; i != n; i++ )scanf("%s",&grid [ i ]);
        memset(visited, 0, sizeof visited);
        int ans = 0;
        for ( int i = 0; i != n; i++ )
        {
            for ( int j = 0; j != n; j++ )
            {
                if ( grid [ i ] [ j ] == '1' && !visited [ i ] [ j ] )
                {
                    ans++;
                    bfs(i,j);
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n",++cases,ans);
    }
    return 0;
}
void bfs(int i, int j)
{
    queue < pair < int, int > > qu;
    qu.push( pair < int, int > (i,j) );
    visited [ i ] [ j ] = 1;
    while( !qu.empty() )
    {
        int front_row = qu.front().first;
        int front_col = qu.front().second;
        qu.pop();
        for ( int l = 0; l != 8; l++ )
        {
            int row = dx [ l ]+front_row;
            int col = dy [ l ]+front_col;
            if ( check( row, col ) )
            {
                qu.push( pair < int, int > ( row, col ));
                visited [ row ] [ col ]  = 1;
            }
        }
    }
}
