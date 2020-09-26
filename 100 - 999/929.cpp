#include<bits/stdc++.h>
using namespace std;
int row,col,t;
int grid [ 1002 ][ 1002 ];
int marker [ 1002 ] [ 1002 ];
int dx[]={+1,-1,+0,+0};
int dy[]={+0,+0,+1,-1};
bool check(int i, int j ){ return !( i < 0 || j < 0 || i >= row || j >= col ); }
int dijk();
void fastscan(int &number)
{
    register int c;

    number = 0;
    c = getchar();
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
}
int main()
{
    ios_base::sync_with_stdio(false);
    fastscan(t);
    while ( t-- )
    {
        fastscan(row);
        fastscan(col);
        for ( int i = 0; i != row; i++ )
        {
            for ( int j = 0; j != col; j++ )
            {
                fastscan(grid[i][j]);
            }
        }
        int ans = 0;
        ans = dijk();
        printf("%d\n",ans);
    }
    return 0;
}
int dijk()
{
    priority_queue < pair < int ,pair < int, int > > > pq;
    pq.push( make_pair ( -grid [ 0 ][ 0 ] , make_pair ( 0,0) ) );
    memset(marker, -1, sizeof marker );
    marker [ 0 ] [ 0 ] = grid[ 0 ] [ 0 ];
    while ( !pq.empty() )
    {
        int front_value = pq.top().first;
        int front_row = pq.top().second.first;
        int front_col = pq.top().second.second;
        front_value *= -1;
        pq.pop();
        for ( int i = 0; i != 4; i++ )
        {
            int rr = dx [ i ] + front_row;
            int cc = dy [ i ] + front_col;
            if ( check( rr,cc ) )
            {
                int value = grid [ rr ] [ cc ];
                int o_o = front_value + value;
                if ( marker [ rr ] [ cc ] == -1 )
                {
                    marker [ rr ] [ cc ] = o_o;
                    pq.push( make_pair ( -o_o, make_pair (rr,cc ) ) );
                }
                else if ( marker [ rr ] [ cc ] > o_o )
                {
                    marker [ rr ] [ cc ] = o_o;
                    pq.push( make_pair ( -o_o, make_pair (rr,cc ) ) );
                }
            }
        }
    }
    return marker [ row-1 ] [ col-1 ];
}
