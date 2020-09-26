#include<bits/stdc++.h>
using namespace std;
#define inf 999999999999999.00
double ar [ 2 ] [ 105 ] , cost [ 105 ];
double x , y , ans ;
int t , ll , a , b , c , n , i , j ;
bool visited [ 105 ];
vector < pair < int , double > > graph [ 105 ];
priority_queue < pair < double , int > > pq;
int main()
{
    scanf("%d",&t);
    ll = t - 1;
    while ( t-- )
    {
        if ( t != ll )putchar(10);
        scanf("%d",&n);
        for ( i = 0; i <= 102; i++ )
        {
            cost [ i ] = inf;
            graph [ i ].clear();
            visited [ i ] = 0;
        }
        for ( i = 1; i <= n; i++ )scanf("%lf %lf",&ar[ 0 ] [ i ] ,&ar [ 1 ] [ i ] );
        for ( i = 1; i <= n; i++ )
        {
            for ( j = 1; j <= n; j++ )
            {
                if ( i == j )continue;
                x = ar [ 0 ] [ i ] - ar [ 0 ] [ j ];
                x *= x;
                y = ar [ 1 ] [ i ] - ar [ 1 ] [ j ];
                y *= y;
                x = sqrt( (x+y) );
                graph [ i ].push_back ( { j , x } );
                graph [ j ].push_back ( { i , x } );
            }
        }
        ans = 0;
        pq.push( { 0.00 , 1 } );
        cost [ 1 ] = 0.00;
        while ( !pq.empty() )
        {
            a = pq.top().second;
            pq.pop();
            if ( visited [ a ] )continue;
            visited [ a ] = 1;
            c = graph [ a ].size();
            for ( i = 0; i != c; i++ )
            {
                b = graph [ a ] [ i ].first;
                x = graph [ a ] [ i ].second;
                if ( !visited [ b ] && cost [ b ] > x )
                {
                    cost [ b ] = x;
                    pq.push( { -x , b } );
                }
            }
        }
        for ( i = 1; i <= n; i++ )ans += cost [ i ];
        printf("%.2f\n",ans);
    }
    return 0;
}
