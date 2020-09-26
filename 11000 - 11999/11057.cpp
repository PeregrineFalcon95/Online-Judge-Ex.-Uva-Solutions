#include<bits/stdc++.h>
using namespace std;
int ar [ 10010 ];
int i , n , m , a , b , c , ans , lo , hi , mid;
int main()
{
    while ( scanf("%d",&n) == 1 )
    {
        for ( i = 1; i <= n; i++ )scanf("%d",&ar [ i ] );
        scanf("%d",&m);
        a = b = -1 ;
        sort ( ar + 1 , ar + n + 1 );
        for ( i = 1; i < n; i++ )
        {
            c = m - ar [ i ];
            hi = n;
            lo = i;
            while ( lo <= hi )
            {
                mid = ( hi + lo ) / 2;
                if ( ar [ mid ] == c )break;
                else if ( ar [ mid ] > c )hi = mid - 1;
                else lo = mid + 1;
            }
            if ( ar [ mid ] == c  )
            {
                if ( a == -1 || abs ( c - ar [ i ] ) < abs ( a - b ) )a = ar [ i ], b = c;
            }
        }
        printf("Peter should buy books whose prices are %d and %d.\n",a,b);
        putchar(10);
    }
    return 0;
}
