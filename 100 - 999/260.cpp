#include<bits/stdc++.h>
using namespace std;
int source_row,source_col,target,n,cases;
int dx [ ] = {-1,-1,0,0,1,1};
int dy [ ] = {0,-1,-1,1,0,1};
char grid [ 202 ] [ 202 ];
bool visited [ 202 ] [ 202 ];
int level [ 202 ] [ 202 ];
int bfs_white();
int bfs_black();
bool check_black(int i, int j){return !(i < 0 || j < 0 || i >= n || j >= n || grid [ i ] [ j ] =='w' || visited [ i ] [ j ]);}
bool check_white(int i, int j){return !(i < 0 || j < 0 || i >= n || j >= n || grid [ i ] [ j ] =='b' || visited [ i ] [ j ]);}
int main()
{
    while(scanf("%d",&n)==1 && n )
    {
        ///cout<<"xxx"<<endl;
        for ( int i = 0; i != n; i++ )scanf("%s",&grid[ i ]);
        int white = INT_MAX, black = INT_MAX;
        ///Working on the black
        for ( int i = 0; i != n; i++ )
        {
            if ( grid [ 0 ] [ i ] == 'b' )
            {
                //cout<<"xxx"<<endl;
                source_row =  0;
                source_col = i;
                target = n-1;
                int o_o = bfs_black();
                if ( o_o < black )black = o_o;
            }
        }
        ///Working on the white
        for ( int i = 0; i != n; i++ )
        {
            if ( grid [ i ] [ 0 ] == 'w' )
            {
                source_row =  i;
                source_col = 0;
                target = n-1;
                int o_o = bfs_white();
                if ( o_o < white )white = o_o;
            }
        }
        if ( black > white )printf("%d W\n",++cases);
        else if ( black < white )printf("%d B\n",++cases);
    }
    return 0;
}
int bfs_black()
{
    queue < pair < int, int > > qu;
    qu.push( pair < int, int > (source_row, source_col) );
    memset(visited, 0 , sizeof visited);
    memset(level, 0, sizeof level);
    visited [ source_row ] [ source_col ] = 1;
    while ( !qu.empty() )
    {
        int front_row = qu.front().first;
        int front_col = qu.front().second;
        qu.pop();
        int w_w = 0;
        for ( int i = 0; i != 6; i++ )
        {
            int row = front_row + dx [ i ];
            int col = front_col + dy [ i ];
            if ( check_black( row , col ) )
            {
                visited [ row ] [ col ] = 1;
                level [ row ] [ col ] = level [ front_row ] [ front_col ]+1;
                qu.push( pair < int, int > (row, col) );
                if ( target == row ) return level [ row ] [ col ];
            }
        }
    }
    return 99999;
}

int bfs_white()
{
    queue < pair < int, int > > qu;
    qu.push( pair < int, int > (source_row, source_col) );
    memset(visited, 0 , sizeof visited);
    memset(level, 0, sizeof level);
    visited [ source_row ] [ source_col ] = 1;
    while ( !qu.empty() )
    {
        int front_row = qu.front().first;
        int front_col = qu.front().second;
        qu.pop();
        int w_w = 0;
        for ( int i = 0; i != 6; i++ )
        {
            int row = front_row + dx [ i ];
            int col = front_col + dy [ i ];
            if ( check_white( row , col ) )
            {
                visited [ row ] [ col ] = 1;
                level [ row ] [ col ] = level [ front_row ] [ front_col ]+1;
                qu.push( pair < int, int > (row, col) );
                if ( target == col ) return level [ row ] [ col ];
            }
        }
    }
    return 99999;
}
