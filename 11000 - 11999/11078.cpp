#include<bits/stdc++.h>
using namespace std;
int n , m , a , b , c , mi , ans , t ;
int ar [ 1000000 ];
int main()
{
    scanf("%d",&t);
    while ( t-- )
    {
        scanf("%d",&n);
        for ( int i = 1 ;i <= n; i++)scanf("%d",&ar [ i ] );
        ans = INT_MIN;
        mi = ar [ n ];
        for ( int i = n - 1 ; i >= 1; i-- )
        {
            ans = max( ans , ar [ i ] - mi );
            mi = min ( mi , ar [ i ] );
        }
        printf("%d\n",ans);
    }
    return 0;
}

