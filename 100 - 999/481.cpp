#include<bits/stdc++.h>
using namespace std;
#define mxs 100100
#define inf 1999999999
int n , m , a , b , c , hi , lo , mid , in , mx , i;
vector < int > ans;
int ar [ mxs ] , dir [ mxs ] , dp [ mxs ];
int main()
{
    //freopen("output.txt","w",stdout);
    while ( scanf("%d",&ar [ ++n ] ) == 1 );
    n--;
    mx = 0;
    dir [ 0 ] = -inf;
    for ( i = 1; i <= n; i++ )dir [ i ] = inf;
    for ( i = 1; i <= n; i++ )
    {
        lo = 0;
        hi = n;
        while ( lo <= hi )
        {
            mid = ( hi + lo ) / 2;
            if ( dir [ mid ] >= ar [ i ] )hi = mid - 1;
            else lo = mid + 1;
        }
        dir [ lo ] = ar [ i ];
        dp [ i ] = lo;
        mx = max ( dp [ i ] , mx );
    }
    printf("%d\n-\n",mx );
    for ( i = n; i >= 1; i-- )if ( dp [ i ] == mx )mx--,ans.push_back( ar [ i ] );
    while ( !ans.empty() )printf("%d\n",ans.back()),ans.pop_back();
    return 0;
}
