#include<bits/stdc++.h>
using namespace std;
#define inf 999999
int t , n , m , a , b , c , j;
vector < int > v [ 22 ];
int dp [ 21 ] [ 21 ] [ 202 ];
int select ( int idx , int num , int amount );
int main()
{
    scanf("%d",&t);
    while ( t-- )
    {
        memset( dp , -1, sizeof dp );
        scanf("%d%d",&m,&n);
        for ( int i = 0; i < n; i++ )
        {
            v [ i ].clear();
            scanf("%d",&a);
            for ( j = 1; j <= a; j++ )
            {
                scanf("%d",&b);
                v [ i ].push_back ( b );
            }
        }
        a = select ( 0 , 0 , 0 );
        if ( a <= 0 )printf("no solution\n");
        else printf("%d\n",a);
    }
    return 0;
}
int select ( int idx , int num , int amount )
{
    if ( idx >= n )return amount;
    if ( dp [ idx ] [ num ] [ amount ] != -1 )return dp [ idx ] [ num ] [ amount ];
    int x = 0, y ;
    int sz = v [ idx ].size();
    for ( int i = 0; i != sz; i++ )
    {
        y = v [ idx ] [ i ];
        if ( y + amount <= m )x = max ( x , select ( idx + 1 , num + 1 , amount + y ) );
    }
    return ( dp [ idx ] [ num ] [ amount ] = x );
}
