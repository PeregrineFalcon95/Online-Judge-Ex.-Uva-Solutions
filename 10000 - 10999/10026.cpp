#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,t,day;
    scanf("%d",&t);
    for ( int k = 0; k != t; k++ )
    {
        if ( k )printf("\n");
        scanf("%d",&n);
        double ar [ n+2 ] [ 2 ];
        vector < pair < double, double > > ans;
        for ( int i = 1; i <= n; i++)
        {
            scanf("%lf%lf",&ar [ i ] [ 0 ], &ar [ i ] [ 1 ] );
            double pp = ( ar [ i ] [ 0 ] / ar [ i ] [ 1 ] );
            ans.push_back( pair < double, double > ( pp, i ) );
        }
        sort(ans.begin(),ans.end());
        int sz = ans.size();
        for ( int i = 0; i != sz; i++ )
        {
            if ( i  )putchar(32);
            printf("%.0f",ans[ i ].second);
        }
        putchar(10);
    }
    return 0;
}
