#include<bits/stdc++.h>
using namespace std;
#define mxs 200010
int marker [ mxs ] , parent [ mxs ];
map < string , int > mp;
char a [ 22 ] , b [ 22 ];
int n , m , t , ans , x , y , o_o , e , f , i;
int dsu( int lol );
int main()
{
    scanf("%d",&t);
    while ( t-- )
    {
        o_o = 0;
        mp.clear();
        scanf("%d",&n);
        for ( i = 1; i <= 200000; i++ )
        {
            marker [ i ] = 0;
            parent [ i ] = i;
        }
        while ( n-- )
        {
            scanf("%s %s",&a,&b);
            if ( mp.find( a ) != mp.end() )x = mp [ a ];
            else
            {
                mp [ a ] = ++o_o;
                x = o_o;
                marker [ x ] = 1;
            }
            if ( mp.find( b ) != mp.end() )y = mp [ b ];
            else
            {
                mp [ b ] = ++o_o;
                y = o_o;
                marker [ y ] = 1;
            }
            ans = 0;
            e = dsu ( x );
            f = dsu ( y );
            if ( e != f )
            {
                marker [ e ] += marker [ f ];
                marker [ f ] = 0;
                parent [ f ] = e;
            }
            ans = marker [ e ];
            printf("%d\n",ans);
        }
    }
    return 0;
}
int dsu( int lol )
{
    if ( parent [ lol ] == lol )return lol;
    return ( parent [ lol ] = dsu ( parent [ lol ] ) ) ;
}
