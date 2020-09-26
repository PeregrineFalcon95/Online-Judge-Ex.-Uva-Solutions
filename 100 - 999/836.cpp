#include<bits/stdc++.h>
using namespace std;
char matrix [ 30 ] [ 30 ];
string s;
int ar [ 30 ] , ar2 [ 30 ];
int n , m , t , a , b,  c , x , ans , sum , i ,j , k , l;
void finder();
int main()
{
    scanf("%d",&t);
    x = t - 1;
    //getchar();
    getchar();
    getchar();
    while ( t-- )
    {
        //getchar();
        //getchar();
        if ( x != t )putchar ( 10 );
        n = 0;
        while ( getline( cin,s ) )
        {
            if ( !s.size() )break;
            n++;
            m = s.size();
            for ( i = 1; i <= m; i++ )matrix [ n ] [ i ] = s [ i - 1 ];
        }
        finder();
        printf("%d\n",ans);
    }
    return 0;
}
void finder()
{
    ans = 0;
    for ( i = 1; i <= m; i++ )
    {
        memset ( ar , 0 , sizeof ar );
        for ( j = i; j <= m; j++ )
        {
            for ( k = 1; k <= n; k++ )if ( matrix [ k ] [ j ] == '1' )ar [ k ]++;
            a = j - i + 1;
            l = 1;
            for ( k = 1; k <= n; k++ )
            {
                if ( ar [ k ] != a )l = k + 1;
                else
                {
                    ans = max ( ans , ( k - l + 1 ) * a );
                }
            }
        }
    }
}
