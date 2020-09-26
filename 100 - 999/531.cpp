#include<bits/stdc++.h>
using namespace std;
vector < string > v , v2 , ans;
string s , s2 ;
int t , a , b , c;
int dp [ 110 ] [ 100 ] , visited [ 110 ] [ 100 ];
int lcs ( int i , int j );
void printer ( int i , int j );
int main()
{
    while ( getline(cin,s) )
    {
        if ( s == "#" )
        {
            while ( getline ( cin , s2 ) )
            {
                if ( s2 == "#" )break;
                stringstream ss ( s2 );
                while ( ss >> s )v2.push_back( s );
            }
            a = v.size();
            b = v2.size();
            c = lcs( 0 , 0 );
            printer ( 0 , 0 );
            putchar(10);
            memset( dp , 0 , sizeof dp );
            memset( visited , 0 , sizeof visited );
            ans.clear();
            v.clear();
            v2.clear();
        }
        stringstream ss ( s );
        while ( ss >> s2 )v.push_back( s2 );
    }
    return 0;
}
int lcs ( int i , int j )
{
    if ( i >= a || j >= b )return 0;
    if ( visited [ i ] [ j ] )return dp [ i ]  [ j ];
    int as = 0;
    if ( v [ i ] == v2 [ j ] )as = 1 + lcs ( i + 1 , j + 1 );
    else
    {
        int o_o = lcs ( i + 1 , j );
        as = lcs ( i , j + 1 );
        as = max ( as , o_o );
    }
    visited [ i ] [ j ] = 1;
    return ( dp [ i ] [ j ] = as );
}
void printer ( int i, int j )
{
    if ( i >= a || j >= b )
    {
        for ( int i = 0; i != ans.size(); i++ )
        {
            if ( i )putchar( 32 );
            cout<<ans [ i ];
        }
        return;
    }
    if ( v [ i ] == v2 [ j ] )
    {
        ans.push_back( v [ i ] );
        printer ( i + 1 , j + 1 );
    }
    else
    {
        if ( dp [ i ] [ j + 1 ] > dp [ i + 1 ] [ j ] )printer( i , j + 1 );
        else printer ( i + 1 , j );
    }
}
