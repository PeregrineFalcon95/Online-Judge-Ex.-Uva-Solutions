#include<bits/stdc++.h>
using namespace std;
char grid [ 200 ] [ 200 ];
int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};
int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};
bool visited [ 105 ] [ 105 ];
int source_row,source_col,limit_row,limit_col;
bool check( int i, int j )
{
    return !( i < 0 || j < 0 || i > limit_row || j > limit_col || visited [ i ] [ j ] || grid [ i ] [ j ] =='L');
}
int bfs();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n,m;
    scanf("%d",&n);
    m = n-1;
    getchar();
    while ( n-- )
    {
        if ( m != n ){printf("\n");}
        int num = 0;
        while( scanf(" %[^\n]",&grid[num])!= EOF )
        {
            int marker = 0;
            if(grid [ num ] [ 0 ] != 'L' && grid [ num ] [ 0 ] != 'W' )
            {
                getchar();
                limit_row = num-1;
                limit_col = strlen(grid[num-1])-1;
                string s = grid [ num ];
                stringstream ss(s);
                string token;
                source_row = source_col = 0;
                int o_o = 0;
                while(ss>>token)
                {
                    int sz = token.size();
                    for ( int i = 0; i != sz; i++ )
                    {
                        if ( !o_o )
                        {
                            source_row*=10;
                            source_row+=(token[i]-'0');
                        }
                        else
                        {
                            source_col*=10;
                            source_col+=(token[i]-'0');
                        }
                    }
                    o_o = 1;
                }
                memset(visited, 0, sizeof visited);
                int ans = 0;
                ans = bfs();
                printf("%d\n",ans);
                while(getline(cin,s))
                {
                    if(!s.size())
                    {
                        marker = 1;
                        break;
                    }
                    stringstream ss(s);
                    string token;
                    source_row = source_col = 0;
                    int o_o = 0;
                    while(ss>>token)
                    {
                        int sz = token.size();
                        for ( int i = 0; i != sz; i++ )
                        {
                            if ( !o_o )
                            {
                                source_row*=10;
                                source_row+=(token[i]-'0');
                            }
                            else
                            {
                                source_col*=10;
                                source_col+=(token[i]-'0');
                            }
                        }
                        o_o = 1;
                    }
                    memset(visited, 0, sizeof visited);
                    int ans = 0;
                    ans = bfs();
                    printf("%d\n",ans);
                }
            }
            num++;
            if ( marker )break;
        }
    }
    return 0;
}
int bfs()
{
    queue < pair < int, int > > qu;
    qu.push( pair < int, int > (source_row-1,source_col-1));
    visited [ source_row -1 ][ source_col -1 ] = 1;
    int w_w = 0;
    while( !qu.empty() )
    {
        int front_row = qu.front().first;
        int front_col = qu.front().second;
        qu.pop();
        w_w++;
        for ( int i = 0; i != 8; i++ )
        {
            int row = dx [ i ] + front_row;
            int col = dy [ i ] + front_col;
            if ( check( row,col ) )
            {
                visited [ row ] [ col ] = 1;
                qu.push( pair < int, int > ( row, col ));
            }
        }
    }
    return w_w;
}
