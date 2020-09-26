#include<bits/stdc++.h>
using namespace std;
#define MOD 2000000011
#define ll long long int
ll dp [ 110 ];
ll n , m , a , b, cases;
ll rec( ll x , ll y );
int main()
{
    dp [ 1 ] = dp [ 2 ] = 1;
    for ( ll i = 3; i <= 100; i++ )dp [ i ] = rec ( i , i - 2 ) % MOD;
    scanf("%lld",&n);
    while ( n-- )
    {
        scanf("%lld",&a);
        printf("Case #%lld: %lld\n",++cases,dp [ a ] );
    }
    return 0;
}
ll rec( ll x , ll y )
{
    if ( y == 1 )return x;
    ll lol = rec ( x , y / 2 ) % MOD;
    if ( y&1 )return ( ( x * ( ( lol * lol )%MOD ) ) % MOD );
    else return ( ( lol * lol ) % MOD );
}
