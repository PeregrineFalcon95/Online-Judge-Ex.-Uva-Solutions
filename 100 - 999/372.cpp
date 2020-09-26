#include<bits/stdc++.h>
using namespace std;
string infix, prefix, postfix, temp, temp2, temp3;
int sz, n, m, a, b, c;
stack < char > stk;
int value_finder( char ch );
void Infix_To_Postfix ();
int main()
{
    while ( getline(cin, infix ) )
    {
        getline ( cin, prefix );
        stringstream ss ( infix );
        temp = "";
        while ( ss >> temp2 )
            temp += temp2;
        cout<<"INFIX   => "<<infix<<"\n";
        cout<<"PREFIX  => "<<prefix<<"\n";
        cout<<"POSTFIX => ";
        Infix_To_Postfix();
    }
    return 0;
}
void Infix_To_Postfix ()
{
    sz = temp.size();
    for ( int i = 0; i != sz; i++ )
    {
        if ( temp [ i ] >= 'a' && temp [ i ] <= 'z' )postfix += temp [ i ];
        else
        {
            while ( !stk.empty() && value_finder( temp [ i ] ) < value_finder ( stk.top() ) )
            {
                char ch = stk.top();
                stk.pop();
                postfix += ch;
            }
            stk.push( temp [ i ] );
        }
    }
    while ( !stk.empty() )
    {
        char ch = stk.top();
        postfix += ch;
        stk.pop();
    }
    for ( int i = 0; i != temp.size(); i++ )
    {
        if ( i )putchar(32);
        putchar( postfix [ i ] );
    }
    putchar ( 10 );
}
int value_finder( char ch )
{
    if ( ch == '$' )return 5;
    if ( ch == '*' || ch == '/' )return 4;
    if ( ch == '+' || ch == '-' )return 3;
    if ( ch == '&' || ch == '|' )return 2;
    if ( ch == '!' )return 1;
    return -1;
}

