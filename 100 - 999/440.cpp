#include<bits/stdc++.h>
using namespace std;
int n , m , a , b , c , i , j , k , l , x;
int ans [ 155 ];
void pre();
int main()
{
    pre();
    while ( scanf("%d",&n) == 1 && n )
    {
        printf("%d\n",ans [ n ] );
    }
    return 0;
}
void pre()
{
    for ( i = 3; i <= 150; i++ )
    {
        x = 0;
        for ( j = 2; ; j++ )
        {
            l = i - 1;
            a = 0;
            for ( k = 2; k <= l; k++ )
            {
                a = ( a + j ) % k;
            }
            if ( a == 0 )
            {
                ans  [ i ] = j;
                break;
            }
        }
    }
}
