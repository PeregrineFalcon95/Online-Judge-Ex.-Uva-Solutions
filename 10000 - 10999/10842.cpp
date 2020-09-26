#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define inf (1e8+9)
#define mxs 102
#define pii pair < int , int >
vector < pii > graph [ mxs ];
priority_queue < pii > pq;
int n , m , a , b, c , t , cases , ans , i , j , sz;
bool visited [ mxs ];
int cost [ mxs ];
void mst();
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    scanf("%d",&t);
    while ( t-- )
    {
        scanf("%d%d",&n,&m);
        for ( i = 0; i <= n; i++ )
        {
            visited [ i ] = cost [ i ]  = 0;
            graph[ i ].clear();
        }
        while ( m-- )
        {
            scanf("%d%d%d",&a,&b,&c);
            graph[ a ].push_back ( { b , c } );
            graph[ b ].push_back ( { a , c } );
        }
        mst();
        printf("Case #%d: %d\n",++cases,ans);
    }
    return 0;
}
void mst()
{
    pq.push( { 0 , 0 } );
    cost [ 0 ] = 0;
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
            c = graph [ a ] [ i ].second;
            if ( !visited [ b ] && cost [ b ] < c )
            {
                pq.push( { c , b } );
                cost [ b ] = c;
            }
        }
    }
    ans = INT_MAX;
    for ( i = 1; i < n; i++ )ans = min( ans, cost [ i ] );
}
