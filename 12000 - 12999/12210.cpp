#include<bits/stdc++.h>
using namespace std;
int n , m , a , b , c , ans , mi , cases , i , j ;
int marker [ 65 ] , marker2 [ 65 ];
int main()
{
    while ( scanf("%d%d",&n,&m) == 2 && ( n || m ) )
    {
        memset ( marker , 0 , sizeof marker );
        memset ( marker2 , 0 , sizeof marker2 );
        for ( i = 1; i <= n; i++ )
        {
            scanf("%d",&a);
            marker [ a ]++;
        }
        for ( i = 1; i <= m; i++ )
        {
            scanf("%d",&a);
            marker2 [ a ]++;
        }
        a = 0;
        for ( i = 60; i >= 2; i-- )
        {
            while ( marker [ i ] )
            {
                mi = INT_MAX;
                for ( j =  2; j <= 60; j++ )
                {
                    if ( marker2 [ j ] && abs( i - j ) < mi )
                    {
                        mi = abs(i-j);
                        b = j;
                    }
                }
                if ( mi == INT_MAX ){a = 1;break;}
                marker2 [ b ]--;
                marker [ i ]--;
            }
            if ( a )break;
        }
        a = ans = 0;
        for ( i = 2; i <= 60; i++ )
        {
            if ( marker [ i ] && !a )a = i;
            ans += marker [ i ];
        }
        printf("Case %d: %d",++cases,ans);
        if ( ans )printf(" %d",a);
        putchar(10);
    }
    return 0;
}
