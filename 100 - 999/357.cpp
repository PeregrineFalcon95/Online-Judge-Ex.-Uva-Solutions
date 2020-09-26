#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll ar [ ] = { 0 , 1 , 5 , 10 , 25 , 50 };
ll dp [ 6 ] [ 30010 ] , ans [ 30010 ];
ll coin( ll i , ll j );
ll n;
void pre();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    pre();
    while ( scanf("%lld",&n) == 1 )
    {
        if (ans [ n ] > 1 ) printf("There are %lld ways to produce %lld cents change.\n",ans [ n ] , n );
        else printf("There is only %lld way to produce %lld cents change.\n",ans [ n ] , n );
    }
    return 0;
}
ll coin( ll i , ll j )
{
    if ( i >= 6 )
    {
        if ( !j )return 1;
        else return 0;
    }
    if ( dp [ i ] [ j ] != -1 )return dp [ i ] [ j ];
    ll ret1 = 0 , ret2 = 0;
    if ( j - ar [ i ] >= 0 )
    {
        ret1 = coin( i , j - ar [ i ] );
    }
    ret2 = coin( i + 1 , j );
    return ( dp [ i ] [ j ] = ret1 + ret2  );
}
void pre()
{
    memset(dp , -1, sizeof dp );
    dp [ 0 ] [ 0 ] = 1;
    for ( ll i = 0; i != 30001; i++ )
    {
        ans [ i ] = coin( 1 , i );
    }
}

