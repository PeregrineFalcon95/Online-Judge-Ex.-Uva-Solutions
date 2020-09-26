#include<bits/stdc++.h>
using namespace std;
#define mx 50100
#define inf 99999999
int n, m, t, sum;
int ar [ 110 ];
int dp [ 103 ] [ mx ];
int dpp ( int i, int j );
int main()
{
    scanf("%d",&t);
    while ( t-- )
    {
        scanf("%d",&n);
        sum = 0;
        for ( int i = 1 ; i <= n; i++ )
        {
            scanf("%d",&ar [ i ] );
            sum += ar [ i ];
        }
        for ( int i = 0 ; i <= n+1; i++ )
            for ( int j = 0; j <= sum+1 ; j++ )dp [ i ] [ j ] = inf;
        printf("%d\n",dpp( 1, 0 ) );
        //cout<<"lol "<<sum<<endl;
    }
    return 0;
}
int dpp ( int i, int j )
{
    if ( i > n )return abs( (sum - j) - j );
    if ( dp [ i ] [ j ] != inf )return dp [ i ] [ j ];
    int x = abs( (sum - j) - j );
    int y = inf;
    if ( j + ar [ i ]  <= sum )y = dpp( i + 1, j + ar [ i ] );
    int z = dpp( i + 1, j );
    //cout<<x<<" "<<y<<" "<<z<<" lol "<<i<<" "<<j<<endl;
    x = min(x, y );
    return ( dp [ i ] [ j ] = min(x,  z ) );
}


