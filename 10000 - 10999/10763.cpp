#include<bits/stdc++.h>
using namespace std;
void fastscan(int &number)
{
    register int c;
    number = 0;
    c = getchar();
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
}
int main()
{
    int t,a,b;
    while ( scanf("%d",&t) == 1 && t )
    {
        getchar();
        map < int, int > cur,tar;
        for ( int i = 0; i != t; i++ )
        {
            //scanf("%d%d",&a,&b);
            fastscan( a );
            fastscan( b );
            cur [ a ]++;
            tar [ b ]++;
        }
        int o_o = 0;
        map < int, int  >::iterator it = cur.begin();
        map < int, int > ::iterator it2 = tar.begin();
        for ( ; it != cur.end(); it++,it2++ )
        {
            if ( ( it->first != it2->first ) || ( it->second != it2->second ) )
            {
                o_o = 1;
                break;
            }
        }
        if ( o_o )printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
