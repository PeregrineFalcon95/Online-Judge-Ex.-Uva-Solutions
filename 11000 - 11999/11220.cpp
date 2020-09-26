#include<bits/stdc++.h>
using namespace std;
int n,cases,o_o,w_w;
int main()
{
    scanf("%d",&n);
    getchar();
    getchar();
    while ( n-- )
    {
        string s,s2;
        if( cases )putchar(10);
        printf("Case #%d:\n",++cases);
        while ( getline(cin,s) )
        {
            w_w = s.size();
            if ( !w_w )break;
            stringstream ss( s );
            s2 = "";
            o_o = 0;
            while ( ss >> s2 )
            {
                w_w = s2.size();
                if ( o_o >= w_w )continue;
                else printf("%c",s2 [ o_o++ ]);
            }
            putchar(10);
        }
    }
    return 0;
}
