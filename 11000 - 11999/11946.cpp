#include<bits/stdc++.h>
using namespace std;
map < char, char > mp;
int main()
{
    mp [ '3' ] = 'E';
    mp [ '1' ] = 'I';
    mp [ '4' ] = 'A';
    mp [ '9' ] = 'P';
    mp [ '8' ] = 'B';
    mp [ '5' ] = 'S';
    mp [ '0' ] = 'O';
    mp [ '7' ] = 'T';
    mp [ '2' ] = 'Z';
    mp [ '6' ] = 'G';
    int n,m;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&n);
    m = n-1;
    getchar();
    while ( n-- )
    {
        if ( n != m )
        {
            putchar(10);
        }
        string s;
        while(getline(cin,s))
        {
            if ( !s.size() )break;
            for ( int  i = 0; i != s.size(); i++ )
            {
                if ( mp.find( s [ i ] ) != mp.end() )
                {
                    s [ i ] = mp [ s [ i ] ] ;
                }
            }
            cout<<s<<"\n";
        }
    }
    return 0;
}
