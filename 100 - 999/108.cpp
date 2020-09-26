#include<bits/stdc++.h>
using namespace std;
int matrix [ 102 ] [ 102 ];
int ar [ 102 ];
int sum , l , r , mx , a , b , c , cur , i , j , k , n ;
void cp();
int main ()
{
    mx = INT_MIN;
    scanf("%d",&n);
    for ( i = 1; i <= n; i++ )
        for ( j = 1; j <= n; j++ )scanf("%d",&matrix [ i ] [ j ] );
    for ( i = 1; i <= n; i++ )
    {
        memset ( ar , 0 , sizeof ar );
        for ( j = i; j <= n; j++ )
        {
            for ( k = 1; k <= n; k++ )ar [ k ] += matrix [ k ] [ j ];
            cp();
        }
    }
    printf("%d\n",mx);
    return 0;
}
void cp()
{
    sum = 0;
    for ( k = 1; k <= n; k++ )
    {
        sum += ar [ k ];
        mx =  max ( sum , mx );
        if ( sum < 0 )sum = 0;
    }
}
