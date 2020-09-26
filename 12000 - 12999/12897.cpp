#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    while ( n-- )
    {
        string s;
        cin>>s;
        map < char, char > mp;
        int m;
        scanf("%d",&m);
        map < char, char >::iterator it = mp.begin();
        for ( int i = 0; i != m; i++ )
        {
            getchar();
            char ch,ch2;
            scanf("%c%c%c",&ch,&ch2,&ch2);
            if ( mp.find(ch2) == mp.end())mp [ ch2 ] = ch;
            for ( it = mp.begin(); it != mp.end(); it++ )
            {
                if (it->second == ch2 )it->second = ch;
            }
        }
        int sz = s.size();
        for ( int i = 0; i != sz; i++ )
        {
            char ch = s [ i ];
            if (mp.find ( ch ) != mp.end() )
            {
                if ( ch =='_')continue;
                s [ i ] = mp [ ch ];
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
