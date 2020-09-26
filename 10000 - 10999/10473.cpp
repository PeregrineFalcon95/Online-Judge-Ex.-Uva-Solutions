#include<bits/stdc++.h>
using namespace std;
string s,s2;
double a,b,c;
long long int d,e,f;
void convert();
int main()
{
    while( cin >> s )
    {
        if ( s [ 0 ] == '-' )break;
        convert();
        if( s [ 0 ] == '0' && s [ 1 ] == 'x' )printf("%.0f\n",a);
        else cout<<"0x"<<s2<<"\n";
    }
    return 0;
}
void convert()
{
    s2 = "";
    a = b = 0.00;
    if( s [ 0 ] == '0' && s [ 1 ] == 'x' )
    {
        int sz = s.size();
        for ( int i = sz-1; i >= 2; i-- )
        {
            if ( s [ i ] >= '0' && s [ i ] <= '9' )
            {
                a += ( (s [ i ] - '0' ) * pow(16 , b++ ) );
            }
            else if ( s [ i ] >= 'A' && s [ i ] <= 'F' )
            {
                a += ( ( s [ i ] -'A' + 10 ) * pow ( 16 , b++ ) );
            }
        }
    }
    else
    {
        int sz = s.size();
        d = 0;
        for( int i = 0; i != sz; i++ )
        {
            d*= 10;
            d+= s [ i ] - '0';
        }
        while( d > 0 )
        {
            e = d%16;
            d /= 16;
            if( e <= 9 )s2.insert( s2.begin() , e+ '0' );
            else s2.insert( s2.begin() , 'A' + e-10 );
        }
        if( !s2.size() )s2.insert( s2.begin() , '0');
    }
}
