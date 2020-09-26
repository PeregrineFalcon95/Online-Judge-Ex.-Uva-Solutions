#include<bits/stdc++.h>
using namespace std;
int matrix [ 102 ] [ 102 ] , ar [ 102 ];
int n , m , a , b , c , ans , x , i , j , k ;
void finder();
int main()
{
    while ( scanf("%d%d",&n,&m) == 2 && ( n || m ) )
    {
        for ( i =1 ; i <= n; i++ )
            for ( j = 1; j <= m; j++ )scanf("%d",&matrix [ i ] [ j ] );
        finder();
        printf("%d\n",ans);
    }
    return 0;
}
void finder()
{
    ans = 0;
    for ( i = 1; i <= m; i++ )
    {
        memset ( ar , 0 , sizeof ar );
        for ( j = i; j <= m; j++ )
        {
            for ( k = 1; k <= n; k++ )if ( matrix [ k ] [ j ] == 0 )ar [ k ]++;
            a = j - i + 1;
            b = 1;
            for ( k = 1; k <= n; k++ )
            {
                if ( ar [ k ] != a )b = k + 1;
                else ans = max ( ans , ( k - b + 1 ) * a );
            }
        }
    }
}
