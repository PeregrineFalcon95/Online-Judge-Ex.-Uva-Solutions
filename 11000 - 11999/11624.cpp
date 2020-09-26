#include<bits/stdc++.h>
using namespace std;
int t,row,col,source_row,source_col,j_row,j_col;
int dx[]={+1,-1,+0,+0};
int dy[]={+0,+0,+1,-1};
char grid [ 1010 ] [ 1010 ];
int level [ 1005 ] [ 1005 ];
bool fire_check( int i, int j ){ return !( i < 0 || j < 0 || i >= row || j >= col || grid [ i ] [ j ] == '#' ); }
void fire_bfs();
int survival_bfs();
int main()
{
    scanf("%d",&t);
    while ( t-- )
    {
        memset( level, -1 , sizeof level);
        scanf("%d%d",&row,&col);
        for ( int i = 0 ; i != row; i++ )scanf("%s",&grid[ i ]);
        for ( int i = 0; i != row; i++ )
        {
            for ( int j = 0; j != col ; j++ )
            {
                if ( level [ i ] [ j ] == -1 && grid [ i ] [ j ] =='F' )
                {
                    source_row = i;
                    source_col = j;
                    fire_bfs();
                }
                else if ( grid [ i ] [ j ] == 'J' )
                {
                    j_row = i;
                    j_col = j;
                }
            }
        }
        int ans = 0;
        ans = survival_bfs();
        if ( !ans )printf("IMPOSSIBLE\n");
        else printf("%d\n",ans);
    }
    return 0;
}
int survival_bfs()
{
    if ( j_row == 0 || j_col == 0 || j_row == row-1 || j_col == col-1 )
    {
        return 1 ;
    }
    queue < pair < int, int > > qu;
    qu.push ( pair < int, int > (j_row, j_col) );
    grid [ j_row ] [ j_col ] = '#';
    int level_j [ row+2 ] [ col+2 ];
    memset( level_j, 0, sizeof level_j);
    level_j [ j_row ] [ j_col ] = 1;
    while ( !qu.empty() )
    {
        int front_row = qu.front().first;
        int front_col = qu.front().second;
        qu.pop();
        for ( int i = 0; i != 4; i++ )
        {
            int rr = dx [ i ] + front_row;
            int cc = dy [ i ] + front_col;
            if ( grid [ rr ][ cc ] == '.' && (level [ rr ] [ cc ] > level_j [ front_row ] [ front_col ]+1 || level [ rr ] [ cc ] == -1 )&& rr >=0 && cc >= 0 && rr < row && cc < col)
            {
                qu.push( pair < int, int > ( rr,cc ) );
                grid [ rr ] [ cc ] = '#';
                if ( rr == 0 || cc == 0 || rr == row-1 || cc == col-1 )
                {
                    return level_j [ front_row ] [ front_col ] +1 ;
                }
                level_j [ rr ] [ cc ] = level_j [ front_row ] [ front_col ] +1;
            }
        }
    }
    return 0;
}
void fire_bfs()
{
    queue < pair < int, int > > qu;
    qu.push ( pair < int, int > ( source_row, source_col ) );
    level [ source_row ] [ source_col ] = 1;
    while ( !qu.empty() )
    {
        int front_row = qu.front().first;
        int front_col = qu.front().second;
        qu.pop();
        for ( int i = 0; i != 4; i++ )
        {
            int rr = dx [ i ] + front_row;
            int cc = dy [ i ] + front_col;
            if ( fire_check(rr, cc ) )
            {
                if ( level [ rr ] [ cc ] == -1 || ( level [ rr ] [ cc ] != -1 && level [ rr ] [ cc ] > level [ front_row ] [ front_col ]+1 ) )
                {
                    qu.push( pair < int, int > ( rr, cc ) );
                    if ( grid [ rr ] [ cc ] == 'F' )level [ rr ] [ cc ] = 1;
                    else level [ rr ] [ cc ] = level [ front_row ] [ front_col ] + 1;
                }
            }
        }
    }
}
