#include<bits/stdc++.h>
using namespace std;
int t , c , a , b , n , sz;
string s , s2 , s3;
char ch, ch2;
stack < char > stk;
int value_finder( char o_o );
void Infix_To_Postfix();
int main()
{
    scanf("%d",&t);
    getchar();
    getchar();
    while ( t-- )
    {
        if ( c )putchar ( 10 );
        c++;
        s = "";
        while(getline(cin,s2))
        {
            if ( !s2.size() )break;
            s += s2;
        }
        Infix_To_Postfix();
    }
    return 0;
}
void Infix_To_Postfix()
{
    sz = s.size();
    s2 = "";
    for ( int i = 0; i != sz; i++ )
    {
        if ( s [ i ] >= '0' && s [ i ] <= '9' )s2 += s [ i ];
        else if ( s [ i ] == '(' )stk.push( s [ i ] );
        else if ( s [ i ] == ')' )
        {
            while ( !stk.empty() && stk.top() != '(' )
            {
                ch = stk.top();
                stk.pop();
                s2 += ch;
            }
            stk.pop();
        }
        else
        {
            while ( !stk.empty() && value_finder( s [ i ] ) <= value_finder( stk.top() ) )
            {
                ch = stk.top();
                stk.pop();
                if ( ch != '(' && ch != ')' )s2 += ch;
            }
            stk.push( s [ i ] );
        }
    }
    while ( !stk.empty() )
    {
        ch = stk.top();
        if (ch != '(' && ch != ')' )s2 += ch;
        stk.pop();
    }
    cout<<s2<<"\n";
}
int value_finder( char o_o )
{
    if ( o_o == '*' || o_o == '/' )return 2;
    if ( o_o == '+' || o_o == '-' )return 1;
    return -1;
}
