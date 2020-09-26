#include<bits/stdc++.h>
using namespace std;
#define mxs 1000010
int one [ mxs ] , zero [ mxs ];
string s;
int n , m , i , j , a , b , q , x , y , cases;
int main()
{
    while ( getline(cin,s) )
    {
        if ( !s.size() )break;
        if ( s [ 0 ] == '1' )one [ 0 ] = 1 , zero [ 0 ] = 0;
        else one [ 0 ] = 0 , zero [ 0 ] = 1;
        a = s.size();
        for ( i = 1; i != a; i++ )
        {
            one [ i ] = one [ i - 1 ];
            zero [ i ] = zero [ i - 1 ];
            if ( s [ i ] == '1' )one [ i ]++;
            else zero [ i ]++;
        }
        scanf("%d",&q);
        printf("Case %d:\n",++cases);
        while ( q-- )
        {
            scanf("%d%d",&a,&b);
            x = min ( a , b );
            y = max ( a , b );
            if (( ( zero [ x ] == zero [ y ] && one [ x ] != one [ y ] ) || ( one [ x ] == one [ y ] && zero [ x ] != zero [ y ] ) ) && s [ x ] == s [ y ] )printf("Yes\n");
            else if ( x == y )printf("Yes\n");
            else printf("No\n");
        }
        getchar();
    }
    return 0;
}
