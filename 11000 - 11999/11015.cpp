#include<bits/stdc++.h>
using namespace std;
#define inf 99999999
int n,m,a,b,c,cases;
string s;
map < string , int  > name;
map < int , string > num;
int matrix [ 24 ] [ 24 ];
int cost [ 24 ];
void warshall ( int source );
int main()
{
    while ( scanf("%d%d",&n,&m) == 2 && ( n || m ) )
    {
        for ( int i = 1; i <= n; i++ )
        {
            for ( int j = 1; j <= n; j++ )
            {
                if ( i != j )matrix [ i ] [ j ] = inf;
                else matrix [ i ] [ j ] = 0;
            }
        }
        ///memset(cost , 0 , sizeof cost );
        name.clear();
        num.clear();
        for ( int i = 1; i <= n; i++ )
        {
            cin>>s;
            name [ s ] = i;
            num [ i ] = s;
        }
        for ( int i = 0; i != m; i++ )
        {
            scanf("%d%d%d",&a,&b,&c);
            matrix [ a ] [ b ] = matrix [ b ] [ a ] = c;
        }
        warshall( 1 );
        int o_o = inf , index = 0;
        for ( int i = 1; i <= n; i++ )
        {
            int sum = 0;
            for ( int j = 1; j <= n; j++ )
            {
                if ( matrix [ i ] [ j ] && matrix [ i ] [ j ] < inf )sum+=matrix [ i ] [ j ];
            }
            if ( o_o > sum )
            {
                o_o = sum;
                index = i;
            }
        }
        s = num [ index ];
        printf("Case #%d :",++cases);
        cout<<" "<<s;
        putchar( 10 );
    }
    return 0;
}
void warshall ( int source )
{
    for ( int  k = 1; k <= n; k++ )
    {
        for ( int i = 1; i <= n; i++ )
        {
            for ( int j = 1; j <= n; j++ )
            {
                matrix [ i ] [ j ] = min( matrix [ i ] [ j ] , ( matrix [ i ] [ k ] + matrix [ k ] [ j ] ) );
            }
        }
    }
}
