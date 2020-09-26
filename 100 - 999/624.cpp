#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n , m , a , b , ans;
ll ar [ 22 ];
ll dp [ 22 ] [ 10000 ];
ll dpp ( ll i , ll j );
void printer( ll i , ll j );
int main()
{
    while ( scanf("%lld",&n) == 1 )
    {
        memset( dp , -1 , sizeof dp );
        scanf("%lld",&m);
        for ( int i = 1 ; i <= m; i++ )scanf("%lld",&ar [ i ] );
        ans = dpp( 1 , 0 );
        printer( 1 , 0 );
        printf("sum:%lld\n",ans);
    }
    return 0;
}
ll dpp ( ll i , ll j )
{
    if ( i > m )return j;
    if ( dp [ i ] [ j ] != -1 )return dp [ i ] [ j ];
    ll x = 0 , y = 0;
    if ( j + ar [ i ] <= n )
    {
        x = dpp ( i + 1 , j + ar [ i ] );
    }
    else x = j;
    y = dpp ( i + 1 , j );
    return ( dp [ i ] [ j ] = max( x , y ) );
}
void printer( ll i , ll j )
{
    if ( i > m )
    {
        return;
    }
    ll x = 0 , y = 0;
    if ( dp [ i + 1 ] [ j ] > dp [ i + 1 ] [ j + ar [ i ] ] )
    {
        printer( i + 1 , j );
    }
    else
    {
        if ( j + ar [ i ] > n )return;
        printf("%lld ",ar [ i ] );
        printer ( i + 1 , j + ar [ i ] );
    }
}


