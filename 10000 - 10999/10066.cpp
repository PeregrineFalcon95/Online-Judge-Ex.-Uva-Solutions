#include<bits/stdc++.h>
using namespace std;
int t , n , m , a , b , c;
int dp [ 110 ] [ 110 ] ;
bool visited [ 110 ] [ 110 ];
int ar [ 110 ] , ar2 [ 110 ];
int lcs( int i , int j );
int main()
{
    while ( scanf("%d%d",&n,&m) == 2 && ( n || m ) )
    {
        memset(dp, 0 , sizeof dp);
        memset( visited , 0 , sizeof visited );
        for ( int i = 1; i <= n; i++ )scanf("%d",&ar [ i ] );
        for ( int i = 1; i <= m; i++ )scanf("%d",&ar2 [ i ] );
        printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",++t,lcs(1,1));
    }
    return 0;
}
int lcs( int i , int j )
{
    if ( i > n || j > m )return 0;
    if ( visited [ i ] [ j ] )return dp [ i ] [ j ];
    int ans = 0;
    if ( ar [ i ] == ar2 [ j ] )ans  = 1 + lcs( i + 1 , j + 1 );
    else
    {
        ans = lcs( i + 1, j );
        int val = lcs ( i , j+ 1 );
        ans = max( ans , val );
    }
    visited [ i ] [ j ] = 1;
    return ( dp [ i ] [ j ] = ans );
}
