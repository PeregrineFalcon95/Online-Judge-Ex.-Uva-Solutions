#include<bits/stdc++.h>
using namespace std;
#define inf 999999
#define pii pair < int , int >
int t , n , m , a , b , c , price , i;
int dp [ 102 ] [ 20010 ], marker [ 102 ] [ 20010 ];
pii ans;
vector < int > v;
pii coin ( int idx , int amount );
int main()
{
    scanf("%d",&t);
    while ( t-- )
    {
        memset ( dp , -1, sizeof dp );
        v.clear();
        scanf("%d",&price);
        scanf("%d",&n);
        for ( i = 0; i != n; i++ )
        {
            scanf("%d",&a);
            v.push_back( a );
        }
        sort( v.begin() , v.end() );
        ans = coin( 0 , 0 );
        printf("%d %d\n",ans.first,ans.second);
    }
    return 0;
}
pii coin ( int idx , int amount )
{
    if ( idx == n || amount >= price )
    {
        pii o_o;
        if ( amount >= price )
        {
            o_o.first = amount;
            o_o.second = 0;
            return o_o;
        }
        o_o.first = inf;
        o_o.second = inf;
        return o_o;
    }
    if ( dp [ idx ] [ amount ] != -1 )
    {
        pii o_o;
        o_o.first = dp [ idx ] [ amount ];
        o_o.second = marker [ idx ] [ amount ];
        return o_o;
    }
    pii x , y;
    x = coin( idx + 1 , amount + v [ idx ] );
    dp [ idx ] [ amount ] = x.first ;
    marker [ idx ] [ amount ] = x.second + 1;
    y = coin( idx + 1 , amount );
    if ( y.first < dp [ idx ] [ amount ] )
    {
        dp [ idx ] [ amount ] = y.first;
        marker [ idx ] [ amount ] = y.second;
    }
    else if ( y.first == dp [ idx ] [ amount ] && marker [ idx ] [ amount ] > y.second )marker [ idx ] [ amount ] = y.second;
    y.first = dp [ idx ] [ amount ];
    y.second = marker [ idx ] [ amount ];
    return y;
}
