#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll dp [ 70 ] [ 70 ] [ 2 ];
bool marker [ 70 ];
ll n , m , a , b , c;
ll ans ( ll idx , ll pre , ll lol );
int main()
{
    while ( scanf("%lld%lld",&n,&m) == 2 )
    {
        if ( n < 0 )break;
        memset ( marker , 0 , sizeof marker );
        marker [ 0 ] = 1;
        memset ( dp , -1, sizeof dp );
        printf("%lld\n",ans( 1 , 0 , 1 ) );
    }
    return 0;
}
ll ans ( ll idx , ll pre , ll lol )
{
    if ( idx > n )
    {
        if ( pre == m )return 1;
        return 0;
    }
    if ( dp [ idx ] [ pre ] [ lol ]!= -1 )return dp [ idx ] [ pre ] [ lol ];
    ll x , y;

    marker [ idx ] = 1;
    if ( marker [ idx - 1 ] || idx == 1 )x = ans ( idx + 1 , pre + 1 , 1 );
    else x = ans ( idx + 1 , pre , 1 );
    marker [ idx ] = 0;

    y = ans ( idx + 1 , pre , 0 );

    return ( dp [ idx ] [ pre ] [ lol ]= ( x + y ) );
}
