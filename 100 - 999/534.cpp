#include<bits/stdc++.h>
using namespace std;
#define inf 999999999999.00
double cost [ 205 ] , marker [ 2 ] [ 205 ];
vector < pair < int , double > > graph [ 205 ];
bool visited [ 205 ];
int parent [ 205 ];
int t , i , j , cases , n , m , a , b , c , sz;
double x , y , z , w , ans;
priority_queue < pair < double , int > > pq;
void clear_();
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    while ( scanf("%d",&n) == 1 && n )
    {
        clear_();
        for ( i = 1; i <= n; i++ )scanf("%lf%lf",&marker [ 0 ] [ i ], &marker [ 1 ] [ i ] );
        for ( i = 1; i <= n; i++ )
            for ( j = 1; j <= n; j++ )
            {
                if ( i == j )continue;
                x = marker [ 0 ] [ i ] - marker [ 0 ] [ j ];
                x *= x;
                y = marker [ 1 ] [ i ] - marker [ 1 ] [ j ];
                y *= y;
                x += y;
                x = sqrt ( x );
                graph [ i ].push_back ( { j , x } );
                graph [ j ].push_back ( { i , x } );
            }
        cost [ 1 ] = 0.00;
        pq.push( { 0.00 , 1 } );
        parent [ 1 ] = 1;
        while ( !pq.empty() )
        {
            a = pq.top().second;
            pq.pop();
            if ( visited [ a ] )continue;
            visited [ a ] = 1;
            sz = graph [ a ].size();
            for ( i = 0; i != sz; i++ )
            {
                b = graph [ a ] [ i ].first;
                x = graph [ a ] [ i ].second;
                if ( !visited [ b ] && cost [ b ] > x )
                {
                    pq.push( { -x , b } );
                    cost [ b ] = x;
                    parent [ b ] = a;
                }
            }
        }
        ans = 0.00;
        a = 2;
        b = 1;
        while ( 1 )
        {
            ans = max( ans, cost [ a ] );
            a = parent [ a ];
            if ( b == a )break;
        }
        printf("Scenario #%d\nFrog Distance = %.3f\n\n",++cases,ans);
    }
    return 0;
}
void clear_()
{
    for ( i = 0; i <= 202 ; i++ )
    {
        graph [ i ].clear();
        visited [ i ] = 0;
        cost [ i ] = inf;
    }
}
