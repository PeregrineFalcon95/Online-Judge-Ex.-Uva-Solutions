#include<bits/stdc++.h>
using namespace std;
map < int , string > mp , mp2 ;
map < int , string >::iterator it;
int n , m , a, b , c;
string s , s2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mp2 [ 1 ] = "Happy"; mp2 [ 2 ] = "birthday"; mp2 [ 3 ] = "to"; mp2 [ 4 ] = "you"; mp2 [ 5 ] = "Happy";
    mp2 [ 6 ] = "birthday"; mp2 [ 7 ] = "to";mp2 [ 8 ] = "you";mp2 [ 9 ] = "Happy";mp2 [ 10 ] = "birthday";mp2 [ 11 ] = "to";
    mp2 [ 12 ] = "Rujia";mp2 [ 13 ] = "Happy";mp2 [ 14 ] = "birthday";mp2 [ 15 ] = "to";mp2 [ 16 ] = "you";
    cin>>n;
    a = 1;
    for ( int i = 1; i <= n; i++ )
    {
        cin>>s;
        mp [ i ] = s;
    }
    b = 1;
    if ( n%16 )a = ( n / 16 ) + 1;
    while ( a-- )
    {
        for ( it = mp2.begin(); it != mp2.end(); it++ )
        {
             cout<<mp [ b ]<<": "<<it->second<<"\n";
             if ( b == n )b = 1;
             else b++;
        }
    }
    return 0;
}
