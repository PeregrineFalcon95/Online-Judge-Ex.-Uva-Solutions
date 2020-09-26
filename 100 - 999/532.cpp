#include<bits/stdc++.h>
using namespace std;
int row,col,dim,source_row,source_col,source_dim,target_row,target_col,target_dim;
char grid[ 32 ] [ 32 ] [ 32 ];
int dx[]= {+1,-1,+0,+0,+0,+0};
int dy[]= {+0,+0,+1,-1,+0,+0};
int di[]= {+0,+0,+0,+0,+1,-1};
bool check(int k, int i , int j ){ return !( i < 0 || j < 0 || k < 0 || i >= row || j >= col || k >= dim || grid [ k ] [ i ] [ j ] == '#' );}
int bfs();
int main()
{
    while ( scanf("%d%d%d",&dim,&row,&col )==3 && ( row ||  col || dim ) )
    {
        for ( int i = 0; i != dim; i++ )
        {
            for ( int j = 0; j != row; j++ )
            {
                scanf("%s",&grid [ i ] [ j ]);
            }
            getchar();
        }
        for ( int i = 0; i != dim; i++ )
        {
            for ( int j = 0; j != row; j++ )
            {
                for ( int k = 0 ; k != col; k++ )
                {
                    if ( grid [ i ] [ j ] [ k ] == 'S' )
                    {
                        source_dim = i;
                        source_row = j;
                        source_col = k;
                        break;
                    }
                }
            }
        }
        int ans = 0;
        ans = bfs();
        if ( !ans )printf("Trapped!\n");
        else printf("Escaped in %d minute(s).\n",ans);
    }
    return 0;
}
int bfs()
{
    int ans = 0;
    queue < pair < int, pair < int, int > > > qu;
    qu.push( make_pair( source_dim,make_pair( source_row, source_col ) ) );
    grid [ source_dim ] [ source_row ] [ source_col ] = '#';
    int level [ dim+1 ] [ row+1 ] [ col+1 ];
    memset(level , 0 ,sizeof level );
    while ( !qu.empty() )
    {
        int front_dim = qu.front().first;
        int front_row = qu.front().second.first;
        int front_col = qu.front().second.second;
        qu.pop();
        int o_o = 0;
        for ( int i = 0; i != 6; i++ )
        {
            int dd = front_dim + di [ i ];
            int rr = front_row + dx [ i ];
            int cc = front_col + dy [ i ];
            if ( check( dd, rr, cc ) )
            {
                qu.push( make_pair( dd, make_pair( rr, cc ) ) );
                level [ dd ] [ rr ] [ cc ] = level [ front_dim ] [ front_row ] [ front_col ]+1;
                if( grid [ dd ] [ rr ] [ cc ] == 'E' )
                {
                    o_o  = 1;
                    ans = level [ dd ] [ rr ] [ cc ];
                    break;
                }
                grid [ dd ] [ rr ] [ cc ] = '#';
            }
        }
        if ( o_o )break;
    }
    return ans;
}
