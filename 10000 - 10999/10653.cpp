#include<bits/stdc++.h>
using namespace std;
int source_row,source_col,row,col,target_row,target_col;
bool visited[1005][1005];
int grid[1005][1005];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
void bfs();
bool check(int i, int j){return !(i<0 || j<0 || i==row || j==col || grid[i][j]==-1 || visited[i][j]==1);}
int main()
{
    while(scanf("%d%d",&row,&col)==2 && (row!=0 || col!=0))
    {
        int n;
        scanf("%d",&n);
        memset(grid, 0, sizeof grid);
        for(int i=0; i<n; i++)
        {
            int y;
            scanf("%d",&y);
            int m;
            scanf("%d",&m);
            for(int j=0; j<m; j++)
            {
                int x;
                scanf("%d",&x);
                grid[y][x]=-1;
            }
        }
        scanf("%d%d%d%d",&source_row,&source_col,&target_row,&target_col);
        bfs();
    }
    return 0;
}
void bfs()
{
    queue < pair < int, int > > qu;
    memset(visited, 0, sizeof visited);
    qu.push(pair < int, int > (source_row,source_col));
    visited[source_row][source_col]=1;
    int level[row+1][col+1];
    memset(level, 0, sizeof level);
    while(!qu.empty())
    {
        int front_r=qu.front().first;
        int front_c=qu.front().second;
        qu.pop();
        for(int i=0; i<4; i++)
        {
            int a=dx[i]+front_r;
            int b=dy[i]+front_c;
            if(check(a,b))
            {
                visited[a][b]=1;
                qu.push(pair < int, int > (a,b));
                level[a][b]=level[front_r][front_c]+1;
                if(a==target_row && b==target_col){printf("%d\n",level[a][b]);return;}
            }
        }
    }
}
