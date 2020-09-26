#include<bits/stdc++.h>
using namespace std;
#define pii pair < int , int >
#define inf 999999999
int n , m , t , cases , x , y , a , b , c , e , d , i , j , mx , index_ , mx2 , marker;
int matrix [ 510 ] [ 510 ];
vector < pii > graph [ 510 ];
priority_queue < pii > pq;
int timer [ 510 ];
void djk ();
int main()
{
    while ( scanf("%d%d",&n,&m) == 2 && ( n || m ) )
    {
        memset ( matrix , -1 , sizeof matrix );
        for ( i = 0; i <= n; i++ ){graph [ i ].clear();timer [ i ] = inf; }
        for ( i = 0; i != m; i++ )
        {
            scanf("%d%d%d",&a,&b,&c);
            matrix [ a ] [ b ] = c;
            matrix [ b ] [ a ] = c;
            graph [ a ].push_back( pii ( b , c ) );
            graph [ b ].push_back( pii ( a , c ) );
        }
        djk();
        mx = 0;
        for ( i = 1 ; i <= n; i++ )
        {
            if ( timer [ i ] != inf && mx < timer [ i ] )
            {
                mx = timer [ i ];
                index_ = i;
            }
        }
        a = b = -1;
        mx2 = 0;
        marker = 0;
        int xxx;
        for ( i = 0; i <= n; i++ )
        {
            for ( j = 0; j <= n; j++ )
            {
                if ( matrix [ i ] [ j ] != -1 && timer [ i ] != inf && timer [ j ] != inf )
                {
                    e = matrix [ i ] [ j ];
                    matrix [ i ] [ j ] = matrix [ j ] [ i ] = -1;
                    x = abs ( timer [ i ] - timer [ j ] );
                    e -= x;
                    if ( e&1 )c = 1;
                    else c = 0;
                    e /= 2;
                    e += max ( timer [ i ] ,timer [ j ] );
                    if ( mx2 <= e )
                    {
                        if ( !c && mx2 == e )continue;
                        if ( c )marker = 1;
                        else marker = 0;
                        mx2 = e;
                        a = i;
                        b = j;
                    }
                }
            }
        }
        printf("System #%d\n",++cases);
        if ( !mx && !mx2 )printf("The last domino falls after 0.0 seconds, at key domino 1.\n",mx,index_);
        else if ( marker && mx2 >= mx )printf("The last domino falls after %d.5 seconds, between key dominoes %d and %d.\n",mx2,a,b);
        else if ( !marker && mx2 > mx )printf("The last domino falls after %d.0 seconds, between key dominoes %d and %d.\n",mx2,a,b);
        else printf("The last domino falls after %d.0 seconds, at key domino %d.\n",mx,index_);
        putchar(10);
    }
    return 0;
}
void djk ()
{
    //mx = 0;
    while(!pq.empty() )pq.pop();
    pq.push( pii ( 0 , 1 ) );
    timer [ 1 ] = 0;
    while ( !pq.empty() )
    {
        a = pq.top().second;
        pq.pop();
        c = graph [ a ].size();
        for ( i = 0; i != c; i++ )
        {
            x = graph [ a ] [ i ].first;
            y =  graph [ a ] [ i ].second;
            if ( timer [ x ] > timer [ a ] + y )
            {
                timer [ x ] = timer [ a ] + y;
                pq.push( pii ( - ( timer [ x ] ) , x ) );
            }
        }
    }
}
