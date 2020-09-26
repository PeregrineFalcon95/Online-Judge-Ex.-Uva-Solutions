#include<bits/stdc++.h>
using namespace std;
string s,ans;
int a,b,c;
int main()
{
    while ( getline(cin,s))
    {
        ans = "";
        if( s [ 0 ] >= '0' && s [ 0 ] <= '9' )
        {
            for ( int i = s.size()-1; i >=0; )
            {
                if ( s [ i ] == '1' )
                {
                    a = s [ i ] - '0';
                    a*=10;
                    a+= s [ --i ] - '0';
                    a*=10;
                    a+= s [ --i ] - '0';
                    i--;
                    char ch = a;
                    ans.insert( ans.end(), ch );
                }
                else
                {
                    a = s [ i ] - '0';
                    a*=10;
                    a+= s [ --i ] - '0';
                    char ch = a;
                    ans.insert( ans.end(), ch );
                    i--;
                }
            }
        }
        else
        {
            for ( int i = s.size()-1; i >= 0; i-- )
            {
                a = s [ i ];
                while ( a > 0 )
                {
                    b = a%10;
                    a/=10;
                    ans.insert( ans.end(), b+'0');
                }
            }
        }
        cout<<ans;
        putchar(10);
    }
    return 0;
}
