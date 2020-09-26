#include<bits/stdc++.h>
using namespace std;
#define inf 9999999
int matrix [ 100+2 ] [ 100+2 ];
int t,a,n,c,d;
int warshall( int source );
int main()
{
    scanf("%d",&t);
    for ( int i = 0; i != t; i++ )
    {
        for ( int j = 0; j != t; j++ )
        {
            if ( j != i )matrix [ i ] [ j ] = inf;
            else matrix [ i ] [ j ] = 0;
        }
    }
    getchar();
    for ( int i = 1; i != t; i++ )
    {
        string s,s2;
        getline(cin,s );
        stringstream ss ( s );
        int o_o = 0;
        while ( ss >> s2 )
        {
            if ( s2 [ 0 ] == 'x')
            {
                o_o++;
                continue;
            }
            a = 0;
            for ( int j = 0; j != s2.size(); j++ )
            {
                a*= 10;
                a+= s2 [ j ]-'0';
            }
            matrix [ i ] [ o_o ] = a;
            matrix [ o_o ] [ i ] = a;
            o_o++;
        }
    }
    int ans = warshall( 0 );
    printf("%d\n",ans);
    return 0;
}
int warshall( int source )
{
    for ( int k = 0; k != t; k++ )
    {
        for ( int i = 0; i != t; i++ )
        {
            for ( int j = 0; j != t; j++ )
            {
                matrix [ i ] [ j ] = min(matrix [ i ] [ j ], ( matrix [ i ] [ k ] + matrix [ k ] [ j ] ) );
            }
        }
    }
    int ans = 0;
    for ( int i = 0; i != 1; i++ )
    {
        for ( int j = 0; j != t; j++ )
        {
            if ( matrix [ i ] [ j ] != inf )ans = max( ans, matrix [ i ] [ j ] );
        }
    }
    return ans;
}
