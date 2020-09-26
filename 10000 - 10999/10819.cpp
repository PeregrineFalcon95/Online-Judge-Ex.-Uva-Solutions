#include<bits/stdc++.h>
using namespace std;
#define pii pair < int , int >
int dp [ 103 ] [ 11000 ];
vector < pair < int , int > > v;
int n , m , a , b , c;
int dpp ( int i, int j, int limit);
int main()
{
    //freopen ("input.txt" , "r", stdin );
    //freopen ("output.txt","w",stdout);
    while ( scanf("%d%d",&m,&n) == 2 )
    {
        memset( dp , -1, sizeof dp );
        v.clear();
        v.push_back(pii ( -1 , -1 ) );
        for ( int i = 1 ; i <= n; i++ )
        {
            scanf("%d%d",&a,&b);
            v.push_back( pii ( a , b  ) );
        }
        sort(v.begin(),v.end() );
        printf("%d\n",dpp ( 1 , 0 , m  ) );
    }
    return 0;
}
int dpp ( int i, int j, int limit )
{
    if ( i > n )
    {
        return 0;
    }
    if ( dp [ i ] [ j ] != -1 )
    {
        return dp [ i ] [ j ];
    }
    int x = 0 , y = 0 , z = 0;
    if ( j <= 2000 && ( v [ i ].first + j > 2000  ) )z = 200;
    if ( ( v [ i ].first + j ) <= ( limit + z ) )
    {
        x = v [ i ].second + dpp ( i + 1, j + v [ i ].first, limit +  z );
    }
    y = dpp ( i + 1, j, limit);
    return ( dp [ i ] [ j ] = max( x , y ) );
}




//Data set weak, that's why it give ac verdict.
#include<bits/stdc++.h>
using namespace std;
int dp [ 102 ] [ 10300 ];
int n , m , a , b , c;
int ar [ 2 ] [ 110 ];
int dpp ( int i, int j, int limit);
int main()
{
    while ( scanf("%d%d",&m,&n) == 2 )
    {
        memset( dp , -1, sizeof dp );
        for ( int i = 1 ; i <= n; i++ )
        {
            scanf("%d%d",&ar [ 0 ] [ i ],&ar [ 1 ] [ i ] );
        }
        printf("%d\n",dpp ( 1 , 0 , m  ) );
    }
    return 0;
}
int dpp ( int i, int j, int limit )
{
    if ( i > n )return 0;
    if ( dp [ i ] [ j ] != -1 )return dp [ i ] [ j ];
    int x = 0 , y = 0 , z = 0;
    if ( j <= 2000 && ( ar [ 0 ] [ i ] + j > 2000  ) )z = 200;
    if ( ( ar [ 0 ] [ i ] + j ) <= ( limit + z ) )
    {
        x = ar [ 1 ] [ i ] + dpp ( i + 1, j + ar [ 0 ] [ i ], limit +  z );
    }
    y = dpp ( i + 1, j, limit);
    return ( dp [ i ] [ j ] = max( x , y ) );
}
