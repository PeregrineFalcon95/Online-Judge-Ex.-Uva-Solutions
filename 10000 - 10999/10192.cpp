#include<bits/stdc++.h>
using namespace std;
string a , b;
int t , c , d;
int dp [ 110 ] [ 110 ];
bool visited [ 110 ] [ 110 ];
int lcs ( int i , int j );
int main()
{
    while ( getline(cin , a ) )
    {
        memset(visited , 0 , sizeof visited );
        memset( dp , 0 , sizeof dp );
        if ( a == "#" )break;
        getline(cin,b);
        printf("Case #%d: you can visit at most %d cities.\n",++t,lcs( 0 , 0 ));
    }
    return 0;
}
int lcs ( int i , int j )
{
    if ( a [ i ] == '\0' || b [ j ] == '\0' )return 0;
    if ( visited [ i ] [ j ] )return dp [ i ] [ j ];
    int ans = 0;
    if ( a [ i ] == b [ j ] )ans = 1 + lcs ( i + 1 , j + 1 );
    else
    {
        ans = lcs ( i + 1 , j );
        int val = lcs ( i , j + 1 );
        ans = max( ans , val );
    }
    visited [ i ] [ j ] = 1;
    return ( dp [ i ] [ j ] = ans );
}
