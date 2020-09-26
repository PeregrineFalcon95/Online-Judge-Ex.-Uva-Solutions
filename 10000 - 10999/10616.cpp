#include<bits/stdc++.h>
using namespace std;
int n , m , a , b , c , d , st , cases , i ,q;
int ar [ 201 ] , in [ 201 ] , dp [ 201 /* IDX */] [ 50 /* SUM */ ] [ 20/* NUM*/ ];
int choose( int idx , int sum , int num );
int main()
{
    while ( scanf("%d%d",&n,&q) == 2 && n )
    {
        for ( i = 1; i <= n; i++ )scanf("%d",&in [ i ] );
        printf("SET %d:\n",++cases);
        st = 0;
        while ( q-- )
        {
            scanf("%d%d",&d,&m);
            for ( i = 1; i <= n; i++ )ar [ i ] = ( in [ i ] + d )% d;
            memset( dp , -1, sizeof dp );
            printf("QUERY %d: %d\n",++st,choose( 1 , 0 , 0 ) );
        }
    }
    return 0;
}
int choose( int idx , int sum , int num )
{
    if ( num == m || idx >= n )
    {

        if ( num == m && !( sum % d ) )return 1;
        if ( n == idx && num == m - 1 && ( sum + ar [ idx ] ) % d == 0 )return 1;
        return 0;
    }
    if ( dp [ idx ] [ sum ] [ num ] != -1 )return dp [ idx ] [ sum ] [ num ];
    int x = 0, y = 0;
    x = choose( idx + 1 , ( sum + ar [ idx ] ) % d , num + 1 );
    y = choose( idx + 1 , sum , num );
    return ( dp [ idx ] [ sum ] [ num ] = ( x + y ) );
}
