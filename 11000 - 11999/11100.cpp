#include<bits/stdc++.h>
using namespace std;
int t,n,a,m;
int marker [ 1000002 ];
deque < pair < int , int > > dq;
int main()
{
    while ( scanf("%d",&n) == 1 && n )
    {
        if ( m )putchar( 10 );
        m++;
        dq.clear();
        memset(marker , 0 , sizeof marker );
        for ( int i = 0; i != n; i++ )
        {
            scanf("%d",&a);
            marker [ a ]++;
        }
        for ( int i = 1; i <= n; i++ )
        {
            dq.push_back( pair < int , int > ( marker [ i ] , i ) );
        }
        sort( dq.begin(), dq.end() );
        vector < int > ans [ dq.back().first+2 ];
        int i_i,w_w, l_l = 0,o_o = dq.back().first;
        while ( !dq.empty() )
        {
            w_w = dq.back().second;
            i_i = dq.back().first;
            dq.pop_back();
            for ( int i = 0; i != i_i; i++ )
            {
                ans [ l_l++ ].push_back( w_w );
                if ( l_l == o_o )l_l = 0;
            }
        }
        printf("%d\n",o_o);
        for ( int i = 0; i != o_o; i++ )
        {
            int sz = ans [ i ].size();
            for ( int j = 0; j != sz; j++ )
            {
                if ( j )putchar( 32 );
                printf("%d",ans [ i ] [ j ] );
            }
            putchar( 10 );
        }
    }
    return 0;
}
