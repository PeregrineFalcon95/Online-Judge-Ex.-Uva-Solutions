#include<bits/stdc++.h>
using namespace std;
int row,col,num,source_row,source_col;
char grid [ 105 ] [ 105 ];
char dir[10000*6];
bool visited [ 105 ] [ 105 ];
char pos;
int bfs();
int main()
{
    while( scanf("%d%d%d",&row,&col,&num)==3 && (row || col || num) )
    {
        pos = '!';
        for ( int i = 0; i != row; i++ )
        {
            scanf("%s",&grid[i]);
            if(pos == '!' )
            {
                for ( int j = 0; j != col; j++ )
                {
                    if ( grid [ i ] [ j ] == 'N' ||grid [ i ] [ j ] =='S' || grid [ i ][ j ] == 'L' || grid [ i ] [ j ] == 'O' )
                    {
                        pos = grid [ i ] [ j ];
                        source_row = i;
                        source_col = j;
                    }
                }
            }
        }
        scanf("%s",&dir);
        int ans=0;
        ans = bfs();
        printf("%d\n",ans);
    }
    return 0;
}
int bfs()
{
    queue < pair < int, int > > qu;
    qu.push( pair < int, int > ( source_row, source_col  ) );
    memset(visited, 0,sizeof visited );
    visited [ source_row ] [ source_col ] = 1;
    int marker = 0;
    int ans = 0;
    while ( !qu.empty() )
    {
        int front_row = qu.front().first;
        int front_col = qu.front().second;
        qu.pop();
        int rr,cc;
        if ( pos == 'N' )
        {
            if ( dir[ marker ] == 'D' )
            {
                rr = front_row ;
                cc = front_col ;
                pos = 'L';
                qu.push( pair < int, int > ( rr,cc ) );
            }
            else if ( dir [ marker ] == 'E' )
            {
                rr = front_row ;
                cc = front_col ;
                pos = 'O';
                qu.push( pair < int, int > ( rr,cc ) );
            }
            else if ( dir [ marker ] == 'F')
            {
                rr = front_row + (-1);
                cc = front_col ;
                if( rr < 0 )rr = front_row;
                else if( grid [ rr ] [ cc ] == '#' )rr = front_row;
                if ( !visited [ rr ] [ cc ] && grid [ rr ] [ cc ] == '*' )
                {
                    ans++;
                }
                visited [ rr ] [ cc ] = 1;
                qu.push( pair < int, int > ( rr,cc ) );
            }
        }
        else if ( pos == 'S' )
        {
            if ( dir[ marker ] == 'D' )
            {
                rr = front_row ;
                cc = front_col ;
                pos = 'O';
                qu.push( pair < int, int > ( rr,cc ) );
            }
            else if ( dir [ marker ] == 'E' )
            {
                rr = front_row ;
                cc = front_col ;
                pos = 'L';
                qu.push( pair < int, int > ( rr,cc ) );
            }
            else if ( dir [ marker ] == 'F')
            {
                rr = front_row + 1;
                cc = front_col ;
                if ( rr >= row )rr = front_row;
                else if ( grid [ rr ] [ cc ] == '#')rr = front_row;
                if ( !visited [ rr ] [ cc ] && grid [ rr ] [ cc ] == '*' )
                {
                    ans++;
                }
                visited [ rr ] [ cc ] = 1;
                qu.push( pair < int, int > ( rr,cc ) );
            }
        }
        else if ( pos == 'L')
        {
            if ( dir[ marker ] == 'D' )
            {
                rr = front_row  ;
                cc = front_col  ;
                pos = 'S';
                qu.push( pair < int, int > ( rr,cc ) );
            }
            else if ( dir [ marker ] == 'E' )
            {
                rr = front_row ;
                cc = front_col ;
                pos = 'N';
                qu.push( pair < int, int > ( rr,cc ) );
            }
            else if ( dir [ marker ] == 'F')
            {
                rr = front_row ;
                cc = front_col + 1;
                if ( cc >= col )cc = front_col;
                else if ( grid [ rr ] [ cc ] == '#' )cc =front_col;
                if ( !visited [ rr ] [ cc ] && grid [ rr ] [ cc ] == '*' )
                {
                    ans++;
                }
                visited [ rr ] [ cc ] = 1;
                qu.push( pair < int, int > ( rr,cc ) );
            }
        }
        else if ( pos == 'O' )
        {
            if ( dir[ marker ] == 'D' )
            {
                rr = front_row ;
                cc = front_col ;
                pos = 'N';
                qu.push( pair < int, int > ( rr,cc ) );
            }
            else if ( dir [ marker ] == 'E' )
            {
                rr = front_row ;
                cc = front_col ;
                pos = 'S';
                qu.push( pair < int, int > ( rr,cc ) );
            }
            else if ( dir [ marker ] == 'F')
            {
                rr = front_row ;
                cc = front_col -1;
                if ( cc < 0 )cc=front_col;
                else if (  grid [ rr ] [ cc ] =='#')cc = front_col;
                if ( !visited [ rr ] [ cc ] && grid [ rr ] [ cc ] == '*' )
                {
                    ans++;
                }
                visited [ rr ] [ cc ] = 1;
                qu.push( pair < int, int > ( rr,cc ) );
            }
        }
        if ( marker >= num-1 )break;
        marker++;
    }
    return ans;
}
