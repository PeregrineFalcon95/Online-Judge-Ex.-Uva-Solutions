#include<bits/stdc++.h>
using namespace std;
int source_row,source_col,row,col;
string grid[28];
int dx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int dy[]={-1,+1,+0,+0,+1,+1,-1,-1};
bool check( int i , int j ) { return !(i < 0 || j < 0 || i > row || j > col || grid [ i ] [ j ] == '0' ); }
int bfs();
int main()
{
    int n,m;
    scanf("%d",&n);
    m = n-1;
    getchar();
    getchar();
    while ( n-- )
    {
        if( m != n )printf("\n");
        int num = -1;
        while( getline(cin,grid[ ++num ]) )
        {
            if ( !grid[ num ].size() )break;
        }
        row = num-1;
        col = grid[0].size() -1 ;
        int ans = 0;
        for ( int i = 0; i <= row; i++ )
        {
            for ( int  j = 0; j <= col; j++ )
            {
                if ( grid [ i ] [ j ] == '1' )
                {
                    source_row = i;
                    source_col = j;
                    int o_o = bfs();
                    if ( o_o > ans )ans = o_o;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
int bfs()
{
    queue < pair < int, int > > qu;
    qu.push( pair < int, int > ( source_row, source_col ) );
    int ans = 1;
    grid[ source_row ] [ source_col ] = '0';
    while ( !qu.empty() )
    {
        int front_row = qu.front().first;
        int front_col = qu.front().second;
        qu.pop();
        for ( int i = 0; i != 8; i++ )
        {
            int rr = dx [ i ] + front_row;
            int cc = dy [ i ] + front_col;
            if ( check( rr , cc ) )
            {
                ans++;
                grid[ rr ] [ cc ] = '0';
                qu.push( pair < int, int > ( rr, cc ) );
            }
        }
    }
    return ans;
}
