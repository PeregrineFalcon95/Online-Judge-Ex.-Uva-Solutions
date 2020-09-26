#include<bits/stdc++.h>
using namespace std;
///***Size 21
#define ll long long int
int ar [ ] = { 0 , 1 , 8 , 27 , 64 , 125 , 216 , 343 , 512 , 729 , 1000 , 1331 , 1728 , 2197 , 2744 , 3375 , 4096 , 4913 , 5832 , 6859 , 8000 , 9261 };
ll dp [ 30 ] [ 10002 ];
int n , m , a , b , c;
ll coin( int idx , int rem );
int main()
{
    //freopen ("output.txt","w",stdout);
    memset(dp , -1, sizeof dp );
    while ( scanf("%d",&n) == 1 )
    {
        printf("%lld\n",coin( 1 , n ) );
    }
    return 0;
}
ll coin( int idx , int rem )
{
    if ( rem <= 0 || idx > 21 )
    {
        if ( !rem )return 1;
        return 0;
    }
    if ( dp [ idx ] [ rem ] != -1 )return dp [ idx ] [ rem ];
    ll x = 0 , y = 0;
    if ( rem - ar [ idx ] >= 0 )x = coin( idx , rem - ar [ idx  ] );
    y = coin( idx + 1 , rem );
    return ( dp [ idx ] [ rem ] = x + y );
}
