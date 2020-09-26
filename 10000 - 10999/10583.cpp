#include<bits/stdc++.h>
using namespace std;
int ar [ 50010 ];
int find_rep( int a );
void make_friend( int a , int b );
int main()
{
    int n , m ,a , b , cases = 0;
    while(scanf("%d%d",&n,&m) == 2 && ( n || m ) )
    {
        set < int > ans;
        for ( int i = 0; i <= n; i++ )ar [ i ] = i;
        for ( int i = 1; i <= m; i++ )
        {
            scanf("%d%d",&a,&b);
            make_friend( a , b );
        }
        for ( int i = 1; i <= n; i++ )
        {
            a = find_rep( i );
        }
        for ( int i = 1; i <= n; i++ )
        {
            ans.insert(ar [ i ] );
        }
        printf("Case %d: %d\n",++cases,ans.size());
    }
    return 0;
}
int find_rep( int a )
{
    if ( ar [ a ] == a )return a;
    return ( ar [ a ] = find_rep( ar [ a ] ) );
}
void make_friend( int a , int b )
{
    int u = find_rep( a );
    int v = find_rep( b );
    if ( u != v )
    {
        ar [ u ] = v;
    }
}
