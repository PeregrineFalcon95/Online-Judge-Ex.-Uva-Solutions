#include<bits/stdc++.h>
using namespace std;
int t,cases,n,source_row,source_col,row,col;
char grid [ 110 ] [ 110 ];
int dx [] = {+1,-1,+0,+0};
int dy [] = {+0,+0,+1,-1};
bool check( int i, int j ){ return !( i < 0 || j < 0 || i >= n || j >= n || grid [ i ] [ j ] =='.' ); }
int flood();
int main()
{
    scanf("%d",&t);
    while ( t-- )
    {
        scanf("%d",&n);
        for ( int i = 0; i != n; i++ )scanf("%s",&grid[ i ]);
        int ans = 0;
        for ( int i = 0; i != n; i++ )
        {
            for ( int j = 0; j != n; j++ )
            {
                if ( grid [ i ] [ j ] == 'x' )
                {
                    source_row = i;
                    source_col = j;
                    ans += flood();
                }
            }
        }
        printf("Case %d: %d\n",++cases,ans);
    }
    return 0;
}
int flood()
{
    queue < pair < int, int > > qu;
    qu.push( pair < int, int > ( source_row , source_col ));
    grid [ source_row ] [ source_col ]= '.';
    while ( !qu.empty() )
    {
        int front_row = qu.front().first;
        int front_col = qu.front().second;
        qu.pop();
        for ( int i = 0 ; i != 4; i++ )
        {
            int rr = front_row + dx [ i ];
            int cc = front_col + dy [ i ];
            if ( check ( rr, cc ) )
            {
                qu.push ( pair < int, int > (rr,cc) );
                grid [ rr ] [ cc ] = '.';
            }
        }
    }
    return 1;
}
