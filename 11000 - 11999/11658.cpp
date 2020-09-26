#include<bits/stdc++.h>
using namespace std;
double in [ 101 ] ;
int dp [ 101 ] [ 10001 ] , ar [ 101 ];
int n , m , a , b , c , bro , i, ans;
int select ( int idx , int have );
int main()
{
    //freopen ("output.txt","w",stdout);
    while ( scanf("%d%d",&n,&m) == 2 && ( n || m ) )
    {
        memset(dp , -1, sizeof dp );
        for ( i = 1; i <= n; i++ )scanf("%lf",&in [ i ] );
        a = 0;
        bro = ( int ) ( ( in [ m ] *100.00 ) + 0.001 );
        for ( i = 1; i <= n; i++ )
        {
            if ( i != m )
            {
                b = ( int )( ( in [ i ] * 100.00 ) + 0.001 );
                ar [ ++a ] = b;
            }
        }
        ans = select( 1 , bro );
        double o_o = ( double )( ( 100.00 *in [ m ] ) / ( double )( ans / 100.00 ) );
        printf("%.2f\n",o_o);
    }
    return 0;
}
int select ( int idx , int have )
{
    if ( idx > a )
    {
        if ( have > 5000 )return have;
        return INT_MAX;
    }
    if ( dp [ idx ] [ have ] != -1 )return dp [ idx ] [ have ];
    int x , y , z;
    z = x = y = INT_MAX;
    if ( have > 5000 )z = have;
    x = select ( idx + 1 , have + ar [ idx ] );
    y = select ( idx + 1 , have );
    if ( y > 5000 && x > 5000 )x = min( x , y );
    else if ( y > 5000 )x = y;
    x = min( x , z );
    if ( z > 5000 )x = min( z , x );
    if ( x < 5000)x = INT_MAX;
    return ( dp [ idx ] [ have ] = x );
}

