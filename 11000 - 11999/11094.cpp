#include<bits/stdc++.h>
using namespace std;
int row,col,source_row,source_col;
char chh;
char grid [ 25 ] [ 25 ];
int dx[]={+1,-1,+0,+0};
int dy[]={+0,+0,+1,-1};
bool check ( int i, int j ) { return !( i < 0 || j < 0 || i >= row || j >= col || grid [ i ] [ j ] != chh ); }
int bfs();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while ( scanf("%d%d",&row,&col) == 2 )
    {
        getchar();
        for ( int i = 0; i != row; i++ )scanf("%s",&grid[ i ]);
        scanf("%d%d",&source_row,&source_col);
        chh = grid [ source_row ] [ source_col ];
        int w_w = bfs();
        w_w = 0;
        for ( int i = 0; i != row; i++ )
        {
            for ( int j = 0; j != col ; j++ )
            {
                if ( grid [ i ] [ j ] == chh )
                {
                    source_row = i;
                    source_col = j;
                    int o_o = bfs();
                    if ( o_o > w_w )w_w = o_o;
                }
            }
        }
        printf("%d\n",w_w);
    }
    return 0;
}
int bfs()
{
    queue < pair < int, int >  > qu;
    grid [ source_row ] [ source_col ] = '!';
    qu.push( pair < int, int > ( source_row, source_col) );
    int ans = 1;
    while ( !qu.empty() )
    {
        int front_row = qu.front().first;
        int front_col = qu.front().second;
        qu.pop();
        for ( int i = 0; i != 4; i++ )
        {
            int rr = dx [ i ] + front_row;
            int cc = dy [ i ] + front_col;
            if ( (rr == front_row && cc >= col) || ( rr == front_row && cc < 0 ) )
            {
                if ( cc < 0 ) cc = col-1;
                else cc = 0;
                if ( grid [ rr ] [ cc ] == chh )
                {
                    ans++;
                    grid[ rr ] [ cc ] = '!';
                    qu.push ( pair < int, int > (rr,cc));
                }
            }
            else if ( check( rr, cc ) )
            {
                ans++;
                qu.push( pair < int, int > (rr,cc) );
                grid [ rr ] [ cc ] = '!';
            }
        }
    }
    return ans;
}
