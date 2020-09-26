#include<bits/stdc++.h>
using namespace std;
int b,c,n,m;
int ar [ 100000 +2 ] , a [ 100000+2 ] , marker [ 100000 +2 ];
int main()
{

    while(scanf("%d%d",&n,&m) == 2 )
    {
        memset( marker , -1 , sizeof marker );
        scanf("%d",&a [ 0 ]);
        ar [ 0 ] = a [ 0 ];
        int o_o = 0;
        int ans = INT_MAX;
        for ( int i = 1; i != n; i++ )
        {
            scanf("%d",&a [ i ]);
            ar [ i ] = a [ i ] + ar [ i-1 ];
            if ( ar [ i ] >= m )
            {
                int ll = o_o;
                while( 1 )
                {
                    if ( ( ar [ i ] - ar [ ll + 1 ] ) >= m )ll++;
                    else break;
                }
                marker [ i ] = ll;
                ans = min ( i-ll , ans );
                o_o =ll;
            }
        }
        if( ans == INT_MAX )ans = 0;
        printf("%d\n",ans);
    }
    return 0;
}
