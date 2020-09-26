#include<bits/stdc++.h>
using namespace std;
map < string, int > pre;
void precal();
int main()
{
    precal();
    string s;
    while(cin>>s)
    {
        int a = 0;
        for(int i = 1; i != s.size(); i++)
        {
            if( s [ i ] <= s [ i-1 ] )
            {
                printf("0\n");
                a = 1;
                break;
            }
        }
        if(a)continue;
        printf("%d\n",pre[s]);
    }
    return 0;
}
void precal()
{
    string s = "a";
    for(int i = 1; i <= 83681; i++)
    {
        pre[s] = i;
        if( s.back() != 'z' )s.back()++;
        else if( s.back() == 'z' )
        {
            int a = s.size()-2;
            if( a >= 0 && s [ a ] < 'y' )
            {
                s [ a ]++;
                s.back() = s [ a ] + 1;
            }
            else if( a-1 >= 0 && s [ a-1 ] < 'x' )
            {
                s [ a-1 ]++;
                s [ a ] = s [ a-1 ]+1;
                s.back() = s [ a ]+1;
            }
            else if( a-2 >= 0 && s [ a-2 ] < 'w' )
            {
                s [ a-2 ]++;
                s [ a-1 ] = s [ a-2 ]+1;
                s [ a ] = s [ a-2 ]+2;
                s.back() = s [ a-2 ]+3;
            }
            else if( a-3 >= 0 && s [ a-3 ] < 'v')
            {
                s [ a-3 ]++;
                s [ a-2 ] = s [ a-3 ]+1;
                s [ a-1 ] = s [ a-2 ]+1;
                s [ a ] = s [ a-1 ]+1;
                s.back() = s [a]+1;
            }
            else if( a < 0 )
            {
                s = "ab";
            }
            else if( a-1 < 0)
            {
                s = "abc";
            }
            else if( a-2 < 0)
            {
                s = "abcd";
            }
            else if( a-3 < 0)
            {
                s = "abcde";
            }
        }
    }
}
