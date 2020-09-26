#include<bits/stdc++.h>
using namespace std;
int dp [ 100000 ] , ar [ 100000 ];
int n , m , a , b , c , ans , cases;
void solve();
int lis ( int u );
int main()
{
    while ( scanf("%d",&ar [ ++n ] ) == 1 )
    {
        if ( n == 1 && ar [ n ] == -1 )break;
        if ( ar [ n ] == -1 )solve();
    }
    return 0;
}
void solve()
{
    memset( dp , -1 ,sizeof dp );
    n--;
    ans = 0;
    for ( int i  = 1; i <= n; i++ )ans = max ( lis ( i ) + 1 , ans );
    if ( cases )putchar(10);
    printf("Test #%d:\n",++cases);
    printf("  maximum possible interceptions: %d\n",ans);
    n = 0;
}
int lis ( int u )
{
    int x = 0;
    if ( dp [ u ] != -1 )return dp [ u ];
    for ( int i = u + 1; i <= n; i++ )
    {
        if ( ar [ i ] <= ar [ u ] )
        {
            x = max ( lis ( i ) + 1 , x );
        }
    }
    return x;
}
