#include<bits/stdc++.h>
using namespace std;
int n , m , a , b , i;
int lim [ 1010 ] , weight [ 1010 ] , dp [ 1010 ] [ 6010 ];
int choose( int node , int limit  );
int main()
{
     //freopen ("input.txt" , "r", stdin );
    //freopen ("output.txt","w",stdout);
    while ( scanf("%d",&n) == 1 && n )
    {
        memset( dp , -1, sizeof dp );
        for ( i = 1; i <= n; i++ )scanf("%d%d",&weight [ i ] , &lim [ i ] );
        printf("%d\n",choose( 1 , 6000 ) );
    }
    return 0;
}
int choose( int node , int limit )
{
    if ( node == n )
    {
        if ( weight [ node ] <= limit )return 1;
        return 0;
    }
    if ( dp[ node ] [ limit ] != -1 )return dp [ node ] [ limit ];
    int x = 0 , y = 0;
    if( limit - weight [ node ] >= 0 )x = choose ( node + 1 , min( ( limit - weight [ node ] ) , lim [ node ] ) )+1;
    y = choose ( node + 1 , limit );
    return ( dp [ node ] [ limit ] = max( x , y ) );
}
