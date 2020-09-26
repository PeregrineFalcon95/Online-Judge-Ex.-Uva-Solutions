//#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define inf (1e8+9)
#define mxs 2002
map < string , int > mp;
vector < pair < int , int > > graph [ mxs ];
priority_queue < pair < int , int > > pq;
vector < int > v;
int cost [ mxs ];
bool visited [ mxs ];
char s [ 10 ] , s2 [ 10 ];
int n , m , a , b, c , t , cases , x , y , e , i , j , ans , sz ;
void mst();
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    scanf("%d",&t);
    e = t - 1;
    while ( t-- )
    {
        if ( t != e )putchar( 10 );
        scanf("%d%d",&n,&m);
        x = 0;
        mp.clear();
        for ( i = 0; i <= n; i++ )
        {
            graph[ i ].clear();
            visited [ i ] = 0;
            cost [ i ] = inf;
        }
        while ( m-- )
        {
            scanf("%s %s %d",&s,&s2,&c);
            if ( mp.find( s ) == mp.end() )
            {
                mp [ s ] = ++x;
                a = x;
            }
            else a = mp [ s ];
            if ( mp.find( s2 ) == mp.end() )
            {
                mp [ s2 ] = ++x;
                b = x;
            }
            else b = mp [ s2 ];
            graph[ a ].push_back ( { b , c } );
            graph[ b ].push_back ( { a , c } );
        }
        ans = 0;
        for ( i = 1; i <= x; i++ )if ( !visited [ i ] )mst();
        printf("%d\n",ans);
    }
    return 0;
}
void mst()
{
    cost [ i ] = 0;
    pq.push( { 0 , i } );
    while ( !pq.empty() )
    {
        a = pq.top().second;
        pq.pop();
        if ( visited [ a ] )continue;
        visited [ a ] = 1;
        ans += cost [ a ];
        sz = graph [ a ].size();
        for ( j = 0; j != sz; j++ )
        {
            b = graph [ a ] [ j ].first;
            c = graph [ a ] [ j ].second;
            if ( !visited [ b ] && cost [ b ] > c )
            {
                cost [ b ] = c;
                pq.push( { -c, b } );
            }
        }
    }
}
