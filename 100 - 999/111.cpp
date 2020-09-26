#include<bits/stdc++.h>
using namespace std;
int dp [ 22 ] [ 22 ] , ar [ 22 ] , st [ 22 ];
bool visited [ 22 ] [ 22 ];
vector < int > v , temp;
string s , s2;
int n , m , a , b , c;
int lcs ( int i , int j );
int main()
{
    while ( getline(cin,s ) )
    {
        stringstream ss ( s );
        while ( ss >> s2 )
        {
            sscanf(s2.c_str(),"%d",&a);
            v.push_back( a );
        }
        if ( v.size() == 1 )
        {
            n = v.back();
            c = 1;
        }
        else if ( c )
        {
            for ( int i = 0; i != v.size(); i++ )
            {
                ar [ v [ i ] ] = i + 1;
            }
            c = 0;
        }
        else
        {
            memset( dp , 0 , sizeof dp );
            memset( visited , 0 , sizeof visited );
            for ( int i = 0; i != v.size(); i++ )
            {
                st [ v [ i ] ] = i + 1;
            }
            printf("%d\n",lcs( 1 , 1 ) );
        }
        v.clear();
    }
    return 0;
}
int lcs ( int i , int j )
{
    if ( i > n || j > n )return 0;
    if ( visited [ i ] [ j ] )return dp [ i ] [ j ];
    int ans = 0;
    if ( ar [ i ] == st [ j ] )ans = 1 + lcs ( i + 1 , j + 1 );
    else
    {
        ans = lcs ( i + 1 , j );
        int val  = lcs ( i , j + 1 );
        ans = max( ans , val );
    }
    visited [ i ] [ j ] = 1;
    return ( dp [ i ] [ j ] = ans );
}
