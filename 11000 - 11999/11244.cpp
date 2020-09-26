#include<bits/stdc++.h>
using namespace std;
int source_row,source_col,n,m;
int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};
int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};
char grid [ 110 ] [ 110 ];
bool check ( int i, int j ){return !( i < 0 || j < 0 || i >= n || j >= m || grid [ i ] [ j ] == '.' );}
int bfs();
int main()
{
    while (scanf("%d%d",&n,&m) == 2 && ( n || m ) )
    {
        for ( int i = 0; i != n; i++ )
        {
            scanf("%s",&grid [ i ]);
        }
        int ans = 0;
        for ( int i = 0; i != n; i++ )
        {
            for ( int j = 0; j != m; j++ )
            {
                if ( grid [ i ] [ j ] == '*' )
                {
                    source_row = i;
                    source_col = j;
                    ans += bfs();
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
int bfs()
{
    int a = 1;
    queue < pair < int, int > > qu;
    qu.push( pair < int, int > ( source_row, source_col ) );
    grid [ source_row ] [ source_col ] = '.';
    while ( !qu.empty() )
    {
        int front_row = qu.front().first;
        int front_col = qu.front().second;
        qu.pop();
        for ( int i = 0; i != 8; i++ )
        {
            int rr = front_row + dx [ i ];
            int cc = front_col + dy [ i ];
            if ( check ( rr, cc ) )
            {
                a++;
                grid [ rr ] [ cc ] ='.';
                qu.push ( pair < int, int > ( rr, cc  ) );
            }
        }
    }
    if ( a > 1 )a = 0;
    return a;
}
