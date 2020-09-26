#include<bits/stdc++.h>
using namespace std;
#define inf 999999
int a,b,c,n,m,o_o,cases;
bool visited [ 102 ];
int matrix [ 102 ] [ 102 ];
void warshall( int source );
int main()
{
    while ( 1 )
    {
        memset ( visited , 0 , sizeof visited );
        for ( int i = 1; i <= 100; i++ )
        {
            for ( int j = 1; j <= 100; j++ )
            {
                if ( i != j )matrix [ i ] [ j ] = inf;
                else matrix [ i ] [ j ] = 0;
            }
        }
        o_o = 0;
        while( scanf("%d%d",&a,&b) == 2 && ( a || b ) )
        {
            o_o = 1;
            visited [ a ] = visited [ b ] = 1;
            matrix [ a ] [ b ] = 1;
        }
        if ( !o_o )break;
        for ( int i = 1; i <= 100; i++ )
        {
            if ( visited [ i ] )
            {
                warshall( i );
                break;
            }
        }
        double ans = 0.00;
        double i_i = 0;
        for ( int i = 1 ; i <= 100; i++ )
        {
            for ( int j = 1; j <= 100; j++ )
            {
                if ( matrix [ i ] [ j ] && matrix [ i ] [ j ] < inf ){ans+=matrix [ i ] [ j ];i_i++;}
            }
        }
        printf("Case %d: average length between pages = %.3f clicks\n",++cases,ans/i_i);
    }
    return 0;
}
void warshall( int source )
{
     for ( int i = 1; i <= 100 ; i++ )
     {
         if ( visited [ i ] )
         {
             for ( int j = 1; j <= 100; j++ )
             {
                 if ( visited [ j ] )
                 {
                     for ( int k = 1; k <= 100; k++ )
                     {
                         if ( visited [ k ] )
                         {
                             matrix [ j ] [ k ] = min( ( matrix [ j ] [ i ]+ matrix [ i ] [ k ] ) , matrix [ j ] [ k ] );
                         }
                     }
                 }
             }
         }
     }
}
