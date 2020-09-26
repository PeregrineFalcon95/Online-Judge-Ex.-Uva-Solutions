#include<bits/stdc++.h>
using namespace std;
void fastscan(long long int &number)
{
    register long long int c;
    number = 0;
    c = getchar();
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;

}
int main()
{
    long long int r,c,t,cases=0,rem,a;
    fastscan( t );
    while ( t-- )
    {
        fastscan(c );
        fastscan( r );
        rem = c - r;
        if ( c == r)printf("Case %lld: 1\n",++cases);
        else
        {
            vector < long long int > ans;
            int sq = sqrt( rem+1 );
            for (int i=1 ; i <= sq; i++ )
            {
                if ( !(rem % i) )
                {
                    a = rem/i;
                    if ( a > r )ans.push_back( a );
                    if ( i > r && i != a )ans.push_back( i );
                }
            }
            sort( ans.begin(), ans.end());
            printf("Case %lld:",++cases);
            int sz = ans.size();
            if(!sz )printf(" impossible\n");
            else
            {
                for ( int i = 0; i != sz; i++ )printf(" %lld",ans [ i ]);
                printf("\n");
            }
        }
    }
    return 0;
}
