#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,cases = 0;
    while( scanf("%d",&n) == 1 && n )
    {
        int ar [ n +1 ];
        for ( int i = 0; i != n; i++ )scanf("%d",&ar[i]);
        int m;
        scanf("%d",&m);
        int q;
        printf("Case %d:\n",++cases);
        for ( int i = 0 ; i != m; i++ )
        {
             scanf("%d",&q);
             int ans[1][2];
             ans [ 1 ] [ 0 ] = 0;
             ans [ 1 ] [ 1 ] = INT_MAX;
             for ( int j = 0; j !=n; j ++ )
             {
                 for ( int k = 0; k != n; k++ )
                 {
                     if( k == j )continue;
                     int a,b;
                     a = abs( q - ( ar [ j ] + ar [ k ] ) );
                     b = abs( ( ar [ j ] + ar [ k ] ) - q );
                     a =min(a,b);
                     if ( a < ans [ 1 ] [ 1 ])
                     {
                         ans [ 1 ] [ 0 ] = ( ar [ j ] + ar [ k ] );
                         ans [ 1 ] [ 1 ] = a;
                     }
                 }
             }
             printf("Closest sum to %d is %d.\n",q,ans [ 1 ] [ 0 ]);
        }
    }
    return 0;
}
