#include<bits/stdc++.h>
using namespace std;
int t , c , d , e , n , m;
double a , b , ans , sz;
string s,s2,s3;
void decimal();
void make_binary();
int main()
{
    scanf("%d",&t);
    while( t-- )
    {
        cin>>s>>s2>>s3;
        decimal();
        s = "";
        s3 = "";
        if( s2 == "+" )ans = a+b;
        else if( s2 == "-" )ans = a - b;
        make_binary();
        cout<<s<<" "<<s2<<" "<<s3<<" = "<<ans<<endl;;
    }
    return 0;
}
void decimal()
{
    a = b = ans = 0.00;
    sz = s.size();
    double p = 0.00;
    for ( double i = sz-1; i >= 0; i-- )
    {
        if( s [ i ] >= '0' && s [ i ] <= '9' )
        {
            a+= ( ( s [ i ]-'0' ) * pow( 16.00 , p ) );
        }
        else if ( s [ i ] >= 'A' && s [ i ] <= 'F' )
        {
            a+= ( ( s [ i ]-'A' + 10 ) * pow( 16.00 , p ) ) ;
        }
        p++;
    }
    sz = s3.size();
    p = 0.00;
    for ( double i = sz-1; i >= 0; i-- )
    {
        if( s3 [ i ] >= '0' && s3 [ i ] <= '9' )
        {
            b+= ( ( s3 [ i ]-'0' ) * pow( 16.00 , p ) );
        }
        else if ( s3 [ i ] >= 'A' && s3 [ i ] <= 'F' )
        {
            b+= ( ( s3 [ i ]-'A' + 10 ) * pow( 16.00 , p ) ) ;
        }
        p++;
    }
}
void make_binary()
{
    long long int v = a;
    long long int x = b;
    while( v >= 1 )
    {
        s.insert(s.begin(), ( v%2 ) + '0' );
        v /= 2;
    }
    while( x >= 1 )
    {
        s3.insert(s3.begin(), ( x%2 ) + '0' );
        x /= 2;
    }
    int lol = s.size();
    while( lol != 13 )
    {
        s.insert( s.begin(), '0' );
        lol++;
    }
    lol = s3.size();
    while( lol != 13 )
    {
        s3.insert( s3.begin(), '0' );
        lol++;
    }
}
