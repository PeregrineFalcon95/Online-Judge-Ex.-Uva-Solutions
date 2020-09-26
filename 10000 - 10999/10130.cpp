#include<bits/stdc++.h>
using namespace std;
int a , b , c , d , e , g , n , t , i , j , ans ,z ;
int price [ 1010 ] , weight [ 1010 ] , ar [ 110 ] , cal [ 32 ] , dp [ 1010 ] [ 110 ] ;
int finder ( int pro , int wei );
int main()
{
    scanf("%d",&t);
    while ( t-- )
    {
        memset( cal , -1 , sizeof cal );
        ans = 0;
        scanf("%d",&n);
        for ( i = 1; i <= n; i++ )scanf("%d%d",&price [ i ] , &weight [ i ] );
        scanf("%d",&g);
        for ( i = 1; i <= g; i++ )
        {
            scanf("%d",&ar [ i ] );
            z = ar [ i ];
            if ( cal [ z ] != -1 )
            {
                ans += cal [ z ];
            }
            else
            {
                memset ( dp , -1 , sizeof dp );
                ans += ( cal [ z ] = finder( 1, 0 )  );
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
int finder ( int pro , int wei )
{
    if ( pro > n  )return 0;
    if ( dp[ pro ] [ wei ] != -1 )return dp [ pro ] [ wei ];
    int x = 0;
    int y = 0;
    if ( weight [ pro ] + wei <= z )
    {
        x = price [ pro ] + finder ( pro + 1 , weight [ pro ] + wei );
    }
    y = finder( pro + 1 , wei );
    return ( dp [ pro ] [ wei ] = max ( x , y ) );
}
