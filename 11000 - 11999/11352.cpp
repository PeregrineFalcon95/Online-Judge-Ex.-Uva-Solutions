#include<bits/stdc++.h>
using namespace std;
char grid [ 105 ] [ 105 ];
int row,col,source_row,source_col;
int horse_dx[]={-2,-2,-1,1,-1,1,2,2};
int horse_dy[]={1,-1,-2,-2,2,2,-1,1};
int dx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int dy[]={-1,+1,+0,+0,+1,+1,-1,-1};
bool check( int i , int j ){ return !( i < 0 || j < 0 || i >= row || j >= col || grid [ i ] [ j ] == 'Z' || grid[ i ][ j ] == '!'); }
bool horse_check( int i, int j ){ return !( i < 0 || j < 0 || i >= row || j >= col || grid [ i ][ j ] == 'A' || grid [ i ] [ j ] == 'B' || grid[ i ][ j ] == '!' || grid[ i ] [ j ] =='Z'); }
int bfs();
int main()
{
    int t;
    scanf("%d",&t);
    while ( t-- )
    {
        scanf("%d%d",&row,&col);
        getchar();
        for ( int i = 0; i != row; i++ )scanf("%s",&grid[i]);
        for ( int i = 0; i != row; i++ )
        {
            for ( int j = 0; j != col; j++ )
            {
                if ( grid[ i ] [ j ] == 'Z' )
                {
                    for ( int l = 0; l != 8; l++ )
                    {
                        int rr = horse_dx [ l ] + i;
                        int cc = horse_dy [ l ] + j;
                        if ( horse_check( rr , cc ) )
                        {
                            grid [ rr ] [ cc ] = '!';
                        }
                    }
                }
                else if ( grid [ i ] [ j ] == 'A' )
                {
                    source_row = i;
                    source_col = j;
                }
            }
        }
        int ans = 0;
        ans = bfs();
        if ( !ans )printf("King Peter, you can't go now!\n");
        else printf("Minimal possible length of a trip is %d\n",ans);
    }
    return 0;
}
int bfs()
{
    int ans = 0;
    queue < pair < int, int > > qu;
    qu.push( pair < int, int > (source_row,source_col) );
    grid [ source_row ][ source_col ] = 'Z';
    int level [ row +1 ] [ col+1 ];
    memset(level, 0 , sizeof level );
    while ( !qu.empty() )
    {
        int front_row = qu.front().first;
        int front_col = qu.front().second;
        qu.pop();
        int o_o = 0;
        for ( int i = 0; i != 8; i++ )
        {
            int rr = dx [ i ]+front_row;
            int cc = dy [ i ]+front_col;
            if ( check(rr,cc) )
            {
                qu.push( pair < int, int > ( rr, cc ));
                level [ rr ] [ cc ] = level [ front_row ][ front_col ] + 1;
                if ( grid [ rr ] [ cc ] == 'B' )
                {
                    o_o = 1;
                    ans = level  [ rr ] [ cc ];
                    break;
                }
                grid [rr ] [ cc ] = 'Z';
            }
        }
        if ( o_o )break;
    }
    return ans;
}
