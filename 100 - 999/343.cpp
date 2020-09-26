#include<bits/stdc++.h>
using namespace std;
#define ll long long int
string x,y;
ll sz, n, m, d, e, f;
double a, b, c , x_base , y_base;
char ch,ch2;
map < ll , ll > x_mp , y_mp;
void make_base();
void x_bases();
void y_bases();
void compare();
int main()
{
    while( cin>> x >> y )
    {
        //cout<<x<<" "<<y<<endl;
        x_mp.clear();
        y_mp.clear();
        make_base();
        x_bases();
        y_bases();
        compare();
        if ( e == 9999 )cout<<x<<" is not equal to "<<y<<" in any base 2..36\n";
        else cout<<x<<" (base "<<e<<") = "<<y<<" (base "<<f<<")\n";
    }
    return 0;
}

///Determining the min bases///
void make_base()
{
    sz = x.size();
    ch = '0';
    for ( int i = 0; i != sz; i++ )
    {
        if ( ch < x [ i ] )ch = x [ i ];
    }
    if ( ch >= '0' && ch <= '9' )
    {
        x_base = ch - '0' + 1;
    }
    else x_base = ch - 'A' + 11;
    sz = y.size();
    ch = '0';
    for ( int i = 0; i != sz; i++ )
    {
        if ( ch < y [ i ] )ch = y [ i ];
    }
    if ( ch >= '0' && ch <= '9' )
    {
        y_base = ch - '0' + 1;
    }
    else y_base = ch - 'A' + 11;
    if( y_base == 1 )y_base = 2;
    if ( x_base == 1 )x_base = 2;
    //cout<<x_base<<" lol "<<y_base<<endl;
}
///Making all possible bases
void x_bases()
{
    sz = x.size();
    for ( double i = x_base ; i <= 36; i++ )
    {
        a = 0.00;
        d = 0;
        for ( ll j = sz-1; j >= 0; j-- )
        {
            if ( x [ j ] >= '0' && x [ j ] <= '9' )
            {
                d += ( ( x [ j ] - '0' ) * pow( i , a++ )  );
            }
            else
            {
                d += ( ( x [ j ] - 'A' + 10 ) * pow ( i , a++ ) );
            }
        }
        ll g = i;
        //cout<<i<<" lol "<<d<<endl;
        x_mp [ g ] = d;
    }
}
void y_bases()
{
    sz = y.size();
    for ( double i = y_base ; i <= 36; i++ )
    {
        a = 0.00;
        d = 0;
        for ( ll j = sz-1; j >= 0; j-- )
        {
            if ( y [ j ] >= '0' && y [ j ] <= '9' )
            {
                d += ( ( y [ j ] - '0' ) * pow( i , a++ )  );
            }
            else
            {
                d += ( ( y [ j ] - 'A' + 10 ) * pow ( i , a++ ) );
            }
        }
        ll g = i;
        //cout<<i<<" o_o "<<d<<endl;
        y_mp [ g ] = d;
    }
}
///Comparing for the minimum bases
void compare()
{
    e = f = 9999;
    for ( map < ll , ll > ::iterator it = x_mp.begin(); it != x_mp.end(); it++ )
    {
        for ( map < ll , ll >::iterator it2 = y_mp.begin(); it2 != y_mp.end(); it2++ )
        {
            if ( it->second == it2->second )
            {
                e = it->first;
                f = it2->first;
                break;
            }
        }
        if ( e != 9999 )break;
    }
    //cout<<e<<" yyy "<<f<<endl;
}
