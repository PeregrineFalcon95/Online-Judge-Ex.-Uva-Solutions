#include<bits/stdc++.h>
using namespace std;
double a,b,c,d,e,source,p;
long long int target;
string s,s2,ans;
void make_decimal();
void find_ans();
int main()
{
    while( cin>>s>>source>>target )
    {
        make_decimal();
        find_ans();
        int lol = ans.size();
        if( lol > 7 )printf("  ERROR\n");
        else
        {
            for ( int i = 0; i < 7-lol; i++ )putchar(32);
            cout<<ans<<"\n";
        }
    }
    return 0;
}
void make_decimal()
{
    a = p = 0.00;
    int sz = s.size();
    for ( int i = sz-1; i >= 0; i-- )
    {
        if( s [ i ] >= '0' && s [ i ] <= '9' )
        {
            a += ( ( s [ i ] - '0' ) * pow( source , p++ ) );
        }
        else if ( s [ i ] >= 'A' && s [ i ] <= 'F' )
        {
            a += ( ( s [ i ] - 'A' + 10 ) * pow( source , p++ ) );
        }
    }
}
void find_ans()
{
    long long int lol , o_o = a;
    ans = "";
    while( o_o > 0 )
    {
        lol = o_o% target;
        o_o /= target;
        if( lol <= 9 ) ans.insert( ans.begin(), lol + '0' );
        else ans.insert( ans.begin(), lol+'A'- 10 );
    }
    if(!ans.size() )ans = "0";
}
