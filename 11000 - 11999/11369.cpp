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
    int t;
    fastscan(t);
    while ( t-- )
    {
        int n,a;
        fastscan(n);
        int v [ n+1 ];
        for ( int i = 0; i != n; i++ )
        {
            fastscan(v [ i ] );
        }
        sort(v,v+n);
        reverse(v,v+n);
        int ans = 0;
        for ( int i = 0; i < n; i+=3 )
        {
           int o_o = 1111111, mi = INT_MAX;
           for ( int j = i ; j < i+3 && j < n ; j++ )
           {
               if ( v [ j ] < mi )mi = v [ j ];
               o_o = j;
           }
           if ( o_o == i+2 )ans+=mi;
        }
        printf("%d\n",ans);
    }
    return 0;
}
