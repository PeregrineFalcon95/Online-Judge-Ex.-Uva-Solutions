#include<bits/stdc++.h>
using namespace std;
int n , m , t , a , b , c , k , l;
int ar [ 11 ] [ 101 ] , dp [ 11 ] [ 101 ] [ 2001 ];
int judge ( int idx , int hours , int sum );
int main()
{
    scanf("%d",&t);
    while ( t-- )
    {
        scanf("%d%d",&n,&m);
        memset(dp , 0, sizeof dp );
        for ( k = 1; k <= n; k++ )
            for ( l = 1; l <= m; l++ )scanf("%d",&ar [ k ] [ l ] );
        a = judge( 1 , 0 , 0 );
        if ( a == -1 )
        {
            printf("Peter, you shouldn't have played billiard that much.\n");
            continue;
        }
        double x = ((double)a / n);
        printf("Maximal possible average mark - %.2f.\n",(x+1e-12) );
    }
    return 0;
}
int judge ( int idx , int hours , int sum )
{
    if ( idx > n )return sum;
    if ( dp [ idx ] [ hours ] [ sum ] )return dp [ idx ] [ hours ] [ sum ];
    int mx = -1;
    for ( int i = 1; i <= m; i++ )if ( ar [ idx ] [ i ] >= 5 && ( hours + i ) <= m ) mx = max( mx , judge ( idx + 1 , hours + i , sum + ar [ idx ] [ i ] ) );
    return ( dp [ idx ] [ hours ] [ sum ] = mx );
}
