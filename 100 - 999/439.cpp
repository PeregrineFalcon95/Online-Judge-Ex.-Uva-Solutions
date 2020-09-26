#include<bits/stdc++.h>
using namespace std;
int dx[]={-2,-2,-1,1,-1,1,2,2};
int dy[]={1,-1,-2,-2,2,2,-1,1};
int source_row,source_col,target_row,target_col;
int grid[9][9];
bool visited[9][9];
int moves[9][9];
bool check(int i, int j){return !(i<0 || j<0 || i > 7 || j > 7);}
int bfs();
int main()
{
    string in;
    while(getline(cin,in))
    {
        source_row=in[1]-'1';
        source_col=in[0]-49-'0';
        target_row=in[4]-'1';
        target_col=in[3]-49-'0';
        memset(grid, 0, sizeof grid);
        int ans=bfs();
        printf("To get from %c%c to %c%c takes %d knight moves.\n",in[0],in[1],in[3],in[4],ans);
    }
    return 0;
}
int bfs()
{
    queue < pair < int, int > >qu;
    memset(visited, 0, sizeof visited);
    memset(moves, 0, sizeof moves);
    qu.push(pair <int, int > (source_row, source_col));
    visited[source_row][source_col]=1;
    moves[source_row][source_col]=0;
    while(!qu.empty())
    {
        int front_row=qu.front().first;
        int front_col=qu.front().second;
        qu.pop();
        for(int i=0; i<8; i++)
        {
            int a=front_row+dx[i];
            int b=front_col+dy[i];
            if(check(a,b))
            {
                if(!visited[a][b])
                {
                    qu.push(pair < int, int > (a,b) );
                    visited[a][b] = 1;
                    moves[a][b] = moves[front_row][front_col]+1;
                }
            }
        }
    }
    return moves[target_row][target_col];
}
