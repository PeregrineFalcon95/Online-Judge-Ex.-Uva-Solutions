#include<bits/stdc++.h>
using namespace std;
int n , m , a , b , c , i , cases , source , d , mx;
vector < int > graph [ 102 ];
queue < int > qu;
int level [ 102 ];
int main()
{
    while ( scanf("%d",&n) == 1 && n )
    {
        for ( i = 1; i <= n; i++ )
        {
            level [ i ] = 0;
            graph [ i ].clear();
        }
        scanf("%d",&source);
        while ( scanf("%d%d",&a,&b) == 2 && ( a || b ) )graph [ a ].push_back ( b );
        mx = 0;
        d = 1;
        qu.push( source );
        while ( !qu.empty() )
        {
            a = qu.front();
            qu.pop();
            b = graph [ a ].size();
            for ( i = 0; i != b; i++ )
            {
                c = graph [ a ] [ i ];
                if ( level [ a ] + 1 > level [ c ] )
                {
                    qu.push( c );
                    level [ c ] = level [ a ] + 1;
                    if ( mx <= level [ c ] )
                    {
                        if ( mx == level [ c ] && c < d )d = c;
                        else if( mx < level [ c ] )mx = level [ c ],d = c;
                    }
                }
            }
        }
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",++cases,source,mx,d);
    }
    return 0;
}
