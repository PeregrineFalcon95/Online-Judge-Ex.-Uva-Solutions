#include<bits/stdc++.h>
using namespace std;
map < char, int > value;
void mapping();
int main()
{
    mapping();
    int n,m;
    scanf("%d",&n);
    m = n-1;
    while(n--)
    {
        if( n != m )printf("\n");
        int m;
        scanf("%d",&m);
        map< string, int > mp;
        for ( int i = 0; i != m; i++ )
        {
            string s,t;
            cin>>s;
            int sz =s .size();
            int a = 0;
            for( int i = 0; i != sz; i++ )
            {
                if( t.size() == 3 && !a )
                {
                    t.insert(t.end(),'-');
                    a = 1;
                }
                if( ( s [ i ] >='0' && s [ i ] <= '9' ) || ( s [ i ] >= 'A' && s [ i ] <= 'Z' ) )
                {
                    if( s[ i ] >= 'A' && s[ i ] <= 'Z' )s [ i ] = value [ s [ i ] ]+'0';
                    t.insert(t.end(), s [ i ] );
                }
            }
            mp [ t ] ++;
        }
        int f = 0;
        for( map < string, int > ::iterator it = mp.begin(); it != mp.end(); it++ )
        {
           if( it->second > 1 )
           {
              f++;
              cout<<it->first<<" "<<it->second<<endl;
           }
        }
        if( !f )printf("No duplicates.\n");

    }
    return 0;
}
void mapping()
{
    value [ 'A' ] = 2;
    value [ 'B' ] = 2;
    value [ 'C' ] = 2;
    value [ 'D' ] = 3;
    value [ 'E' ] = 3;
    value [ 'F' ] = 3;
    value [ 'G' ] = 4;
    value [ 'H' ] = 4;
    value [ 'I' ] = 4;
    value [ 'J' ] = 5;
    value [ 'K' ] = 5;
    value [ 'L' ] = 5;
    value [ 'M' ] = 6;
    value [ 'N' ] = 6;
    value [ 'O' ] = 6;
    value [ 'P' ] = 7;
    value [ 'R' ] = 7;
    value [ 'S' ] = 7;
    value [ 'T' ] = 8;
    value [ 'U' ] = 8;
    value [ 'V' ] = 8;
    value [ 'W' ] = 9;
    value [ 'X' ] = 9;
    value [ 'Y' ] = 9;
}
