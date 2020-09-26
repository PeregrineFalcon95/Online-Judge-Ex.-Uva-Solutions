#include<bits/stdc++.h>
using namespace std;
#define inf ( int ) 1e9+10
#define pii pair < int , int >
#define mxs 1005
int cost [ mxs ] , parent [ mxs ];
bool visited [ mxs ];
priority_queue < pii > pq;
vector < pii > graph [ mxs ];
deque < int > ans;
map < pii , int > mp;
map < pii , int >::iterator it;
pii x , y;
int n , m , a , b , c , d , e , f , t , i , j , sz;
void mst();
int main()
{
    while ( scanf("%d%d",&n,&m) == 2 && n || m )
    {
        mp.clear();
        for ( i = 0; i <= n ; i++ )
        {
            cost [ i ] = inf;
            visited [ i ] = 0;
            graph [ i ].clear();
        }
        for ( i = 1; i <= m; i++ )
        {
            scanf("%d%d%d",&a,&b,&c);
            graph [ a ].push_back ( { b , c } );
            graph [ b ].push_back ( { a , c } );
            x = { a , b };
            y = { b , a };
            mp [ x ] = mp [ y ] = c;
        }
        for ( j = 0; j < n; j++ )if( !visited [ j ] )mst();
        for ( it = mp.begin() ; it != mp.end(); it++ )
        {
            if ( it->second != -1 )
            {
                ans.push_back ( it->second );
                x = { it->first.second, it->first.first };
                mp [ x ] = -1;
            }
        }
        if ( !ans.size() )printf("forest\n");
        else
        {
            sort(ans.begin(),ans.end());
            printf("%d",ans.front());
            ans.pop_front();
            while( !ans.empty() )
            {
                printf(" %d",ans.front());
                ans.pop_front();
            }
            putchar(10);
        }
    }
    return 0;
}
void mst()
{
    cost [ j ] = 0;
    pq.push( { 0 , j } );
    while ( !pq.empty() )
    {
        a  = pq.top().second;
        pq.pop();
        if ( visited [ a ] )continue;
        visited [ a ] = 1;
        sz = graph [ a ].size();
        for ( i = 0; i != sz; i++ )
        {
            b = graph [ a ] [ i ].first;
            c = graph [ a ] [ i ].second;
            if ( !visited [ b ] && cost [ b ] > c )
            {
                cost [ b ] = c;
                pq.push( { -c , b } );
                parent [ b ] = a;
            }
        }
    }
    for ( i = 1 ; i < n; i++ )
    {
        a = parent [ i ];
        x = { a , i };
        mp [ x ] = -1;
        x = { i , a };
        mp [ x ] = -1;
    }
}
