#include<bits/stdc++.h>
using namespace std;
#define inf 999999999
int t , n , m , value , a , b , c , i;
int ar [ 2 ] [ 41 ] , dp [ 41 ] [ 301 ] [ 301 ];
int coin ( int idx , int left , int right );
int main()
{
    scanf("%d",&t);
    while ( t-- )
    {
        memset( dp , -1, sizeof dp );
        scanf("%d%d",&n,&m);
        for ( i = 1; i <= n; i++ )scanf("%d%d",&ar [ 0 ] [ i ] , &ar [ 1 ] [ i ] );
        a = coin ( 1 , 0 , 0 );
        if ( 0 >= a || a >= inf )printf("not possible\n");
        else printf("%d\n",a);
    }
    return 0;
}
int coin ( int idx , int left , int right )
{
    if ( dp [ idx ] [ left ] [ right ] != -1  )return dp [ idx ] [ left ] [ right ];
    int x = inf, y = inf , z , w;
    z = left + ar [ 0 ] [ idx ];
    w = right + ar [ 1 ] [ idx ];
    z = ( z * z ) + ( w * w );
    w = sqrt ( z );
    if ( w <= m )
    {
        if ( ( w * w ) == z && w == m )x = 1;
        else x = coin ( idx , left + ar [ 0 ] [ idx ] , right + ar [ 1 ] [ idx ] ) + 1;
    }
    if ( idx + 1 <= n )
    {
        y = coin ( idx + 1 , left , right );
    }
    else
    {
        z = sqrt ( left * left + right * right );
        if ( z * z == ( left * left + right * right ) && z == m )y = 1;
    }
    return ( dp [ idx ] [ left ] [ right ] = min ( x , y ) );
}
