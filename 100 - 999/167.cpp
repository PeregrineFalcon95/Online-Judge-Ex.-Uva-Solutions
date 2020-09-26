#include<bits/stdc++.h>
using namespace std;
int k , a , b;
int ar [ 10 ] [ 10 ];
bool dig1 [ 20 ] , dig2 [ 20 ] , col [ 10 ];
int ans ( int idx , int sum );
int main()
{
    scanf("%d",&k);
    while ( k-- )
    {
        memset( dig1 , 0 , sizeof dig1 );
        memset( dig2 , 0 , sizeof dig2 );
        memset( col , 0 , sizeof col );
        for ( int i = 1; i <= 8; i++ )
            for ( int j = 1; j <= 8; j++ )scanf("%d",&ar [ i ] [ j ] );
        printf("%5d\n",ans( 1 , 0 ) );
    }
    return 0;
}
int ans ( int idx , int sum )
{
    if ( idx == 9 )return sum;
    int o_o = 0;
    for ( int i = 1; i <= 8; i++ )
    {
        if ( col [ i ] || dig1 [ i + idx ] || dig2 [ 8 + idx - i ] )continue;
        col [ i ] = dig1 [ i + idx ] = dig2 [ 8 + idx - i ] = 1;
        o_o = max ( o_o , ans ( idx + 1 , sum + ar [ idx ] [ i ] ) );
        col [ i ] = dig1 [ i + idx ] = dig2 [ 8 + idx - i ] = 0;
    }
    return o_o;
}
