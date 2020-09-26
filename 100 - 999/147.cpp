#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll dp [ 13 ] [ 30010 ] , ans [ 30010 ];
ll ar [ ] = {0 , 5 , 10 , 20 , 50 , 100 , 200 , 500 , 1000 , 2000 , 5000 , 10000 };
ll n, m;
double e,f;
void pre ( );
ll coin( ll i , ll amount );
int main()
{
    pre();
    while ( scanf("%lf",&e ) == 1 && e != 0.00 )
    {
        f = (e + 0.001) * 100.00;
        n =  (ll) f;
        printf("%6.2f%17lld\n",e,ans [ n ] );
    }
    return 0;
}
void pre ( )
{
    memset(dp , -1, sizeof dp );
    dp [ 0 ] [ 0 ] = 1;
    for ( ll i = 0; i <= 30000; i++ )ans [ i ] = coin( 1 , i );
}
ll coin( ll i , ll amount )
{
    if ( i > 11 )
    {
        if ( !amount )return 1;
        else return 0;
    }
    if ( dp [ i ] [ amount ] != -1 )return dp [ i ] [ amount ];
    ll a = 0, b = 0;
    if ( amount - ar [ i ] >= 0 )
    {
        a = coin( i , amount - ar [ i ] );
    }
    b = coin( i + 1 , amount );
    return ( dp [ i ] [ amount ] = a + b );
}
