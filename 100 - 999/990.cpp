#include<bits/stdc++.h>
using namespace std;
int dp  [ 2 ] [ 33 ] [ 10010 ], ar [ 2 ] [ 33 ];
int n, m, a, b, c, t, w ,pp;
vector < int > ans;
int dpp ( int i, int j );
void searching_machine( int i, int j );
int main()
{
    while ( scanf("%d%d",&t,&w) == 2 )
    {
        if ( pp )putchar( 10 );
        pp++;
        ans.clear();
        memset(dp, -1, sizeof dp );
        scanf("%d",&n);
        for ( int i = 1 ; i <= n; i++ )
        {
            scanf("%d%d",&ar [ 0 ] [ i ],&ar [ 1 ] [ i ] );
            ar [ 0 ] [ i ] *= ( 3 * w );
        }
        printf("%d\n",dpp ( 1, 0 ) );
        searching_machine( 1, 0 );
        sort(ans.begin(),ans.end());
        printf("%d\n",ans.size());
        for ( int i = 0; i != ans.size(); i++ )
            printf("%d %d\n",ar [ 0 ] [ ans [ i ] ] / (3*w),ar [ 1 ] [ ans [ i ] ] );
    }
    return 0;
}
int dpp ( int i, int j )
{
    if ( i > n )return 0;
    if ( dp [ 0 ] [ i ] [ j ] != -1 )return dp [ 0 ] [ i ] [ j ];
    int x = 0, y = 0;
    if ( j + ar [ 0 ] [ i ] <= t )x = ar [ 1 ] [ i ] + dpp ( i + 1, j + ar [ 0 ] [ i ] );
    y = dpp ( i + 1, j ) ;
    if ( x > y )dp [ 1 ] [ i ]  [ j ] = 1;
    else dp [ 1 ] [ i ] [ j ] = 0;
    return ( dp [ 0 ] [ i ] [ j ] = max( x, y ) );
}
void searching_machine( int i, int j )
{
    if ( i > n )return;
    if ( dp [ 1 ] [ i ] [ j ] == 1 )
    {
        ans.push_back( i );
        searching_machine( i + 1, j + ar [ 0 ] [ i ] );
    }
    else searching_machine( i + 1, j );
}
