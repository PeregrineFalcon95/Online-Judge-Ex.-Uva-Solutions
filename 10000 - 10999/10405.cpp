#include<bits/stdc++.h>
using namespace std;
string s , s2;
bool visited [ 1010 ] [ 1010 ];
int dp [ 1010 ] [ 1010 ];
int counter( int i , int j );
int main()
{
    while ( getline(cin,s) )
    {
        getline(cin,s2);
        memset(visited , 0 , sizeof visited );
        memset(dp , 0 , sizeof dp );
        printf("%d\n",counter( 0 , 0 ) );
    }
    return 0;
}
int counter( int i , int j )
{
    if ( s [ i ] == '\0' || s2 [ j ] == '\0' )return 0;
    if ( visited [ i ] [ j ] )return dp [ i ] [ j ];
    int ans = 0;
    if ( s [ i ] == s2 [ j ] )ans = 1 + counter( i + 1 , j + 1 );
    else
    {
        int a = counter( i + 1 , j );
        int b = counter ( i , j + 1 );
        ans = max( a , b );
    }
    dp [ i ] [ j ] = ans;
    visited [ i ] [ j ] = 1;
    return dp [ i ] [ j ];
}
