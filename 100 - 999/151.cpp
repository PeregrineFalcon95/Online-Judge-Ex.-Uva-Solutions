#include<bits/stdc++.h>
using namespace std;
int ans [ 110 ] , ar [ 110 ];
int a , b , c , i , j ,k;
void pre ();
int main()
{
    pre();
    while ( scanf("%d",&a) == 1 && a )printf("%d\n",ans [ a ] );
    return 0;
}
void pre ()
{
    for ( i = 0; i <= 110; i++ )ar [ i ] = i + 2;
    for ( i = 13; i <= 99; i++ )
    {
        for ( k = 1; ; k ++ )
        {
            b = 0;
            for ( j = 1 ; j <= (i - 1); j++ )
            {
                b = ( ( b + k  ) % j );
            }
            if ( b == 11 )
            {
                ans [ i ] = k;
                break;
            }
        }
    }
}
