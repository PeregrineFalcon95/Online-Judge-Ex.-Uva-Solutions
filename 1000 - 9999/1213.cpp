#include<bits/stdc++.h>
using namespace std;
int n , m , a , b , c , i , j , k;
int ar [ 200 ] , dp [ 190 ] [ 1200 ] [ 15 ];
bool status [ 1122 ];
void seive();
int solution( int idx , int sum , int num );
int main()
{
    //freopen ("output.txt","w",stdout);
    seive();
    while ( scanf("%d%d",&n,&k) == 2 && ( n && k ) )
    {
        memset( dp, -1, sizeof dp );
        printf("%d\n",solution( 1 , 0 , 0 ) );
    }
    return 0;
}
void seive()
{
    n = 1121;
    a = sqrt(n);
    status [ 0 ] = status [ 1 ] = 1;
    for ( i = 4; i <= n; i+= 2 )status [ i ] = 1;
    for ( i = 3; i <= a; i +=2 )
        if ( !status [ i ] )
            for ( j = i + i; j <= n; j+= i )status [ j ] = 1;
    a = 0;
    for ( i = 1; i <= n; i++ )if (!status [ i  ] )ar [ ++a ] = i;
}
int solution( int idx , int sum , int num )
{
    if ( ar [ idx ] > n || idx >= 187 || sum >= n || num >= k)
    {
        if ( sum == n && num == k )return 1;
        if ( ar [ idx ] + sum == n && num + 1 == k )return 1;
        return 0;
    }
    if ( dp [ idx ] [ sum ] [ num ] != -1 )return dp [ idx ] [ sum ] [ num ];
    int x = 0 , y = 0;
    x = solution( idx + 1 , sum + ar [ idx ] , num + 1 );
    y = solution( idx + 1 , sum , num );
    return ( dp [ idx ] [ sum ] [ num ] = ( x + y ) );
}

