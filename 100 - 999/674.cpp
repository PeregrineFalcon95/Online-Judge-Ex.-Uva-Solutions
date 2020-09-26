#include<bits/stdc++.h>
using namespace std;
int ar [] = {0 , 1 , 5 , 10 , 25 , 50 };
int dp [ 7 ] [ 7491 ] , ans [ 7492 ];
int n , m ;
int coin( int i , int j );
void pre ();
int main()
{
    pre();
    while ( scanf("%d",&n) == 1 )
    {
        printf("%d\n",ans [ n ] );
    }
    return 0;
}
void pre ()
{
    memset( dp , -1, sizeof dp );
    for ( int i = 0; i <= 7489; i++ )
    {
        ans [ i ] = coin( 1 , i );
    }
}
int coin( int i , int j )
{
    if ( i >= 6 )
    {
        if ( !j )return 1;
        return 0;
    }
    if ( dp[ i ] [ j ] != -1 )return dp [ i ] [ j ];
    int ret1 = 0, ret2 = 0;
    if ( j - ar [ i ] >= 0 )ret1 = coin( i , j - ar[ i ] );
    ret2 = coin( i + 1 , j );
    return ( dp [ i ] [ j ] = ret1 + ret2 );
}

///Another solution , not optimal



















#include<bits/stdc++.h>
using namespace std;
int ar [ ] = { 0 , 50 , 25 , 10 , 5 , 1 };
int ans [ 7495 ], dp [ 7 ] [ 7496 ] ;
int n , m , total;
void pre ();
int coin( int i , int amount );
int main()
{
    pre();
    while ( scanf("%d",&n) == 1 )
    {
        printf("%d\n",ans [ n ] );
    }
    return 0;
}
void pre()
{
    for ( int i = 0; i <= 7491 ; i++ )
    {
        memset(dp , -1, sizeof dp );
        dp [ 0 ] [ 0 ] = 1;
        total = i;
        ans [ i ] = coin( 1 , 0 );
    }
}
int coin( int i , int amount )
{
    if ( i >= 6 )
    {
        if ( amount == total )return 1;
        else return 0;
    }
    if ( dp [ i ] [ amount ] != -1 )return dp [ i ] [ amount ];
    int ret1 = 0 , ret2 = 0;
    if ( amount + ar [ i ] <= total )ret1 = coin( i , amount + ar [ i ] );
    ret2 = coin( i + 1 , amount );
    return ( dp [ i ] [ amount ] = ret1 + ret2 );
}
