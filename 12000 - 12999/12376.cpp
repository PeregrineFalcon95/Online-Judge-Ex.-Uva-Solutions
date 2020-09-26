#include<bits/stdc++.h>
using namespace std;
void fastscan(int &number)
{
    register int c;
    number = 0;
    c = getchar_unlocked();
    for (; (c>47 && c<58); c=getchar_unlocked())
        number = number *10 + c - 48;
}
int t,cases,n,m,a,b,ans,node,sz,mx,o_o;
int value [ 110 ];
vector < int > graph [ 110 ];
int main()
{
    fastscan( t );
    while ( t-- )
    {
        getchar();
        //scanf("%d%d",&n,&m);
        fastscan( n );
        fastscan( m );
        for ( int i = 0; i != n; i++ )
        {
            graph [ i ].clear();
            //scanf("%d",&value [ i ] );
            fastscan( value [ i ] );
        }
        for ( int i = 0; i != m; i++ )
        {
            //scanf("%d%d",&a,&b);
            fastscan( a );
            fastscan( b );
            graph [ a ].push_back ( b );
        }
        ans = node = 0;
        queue < int > qu;
        qu.push( 0 );
        ans  = 0 ;
        while ( !qu.empty() )
        {
            int front_ = qu.front();
            qu.pop();
            sz  = graph [ front_ ] .size();
            mx = 0;
            for ( int i = 0; i != sz ; i++ )
            {
                o_o = graph [ front_ ] [ i ];
                if( mx < value [ o_o ] )
                {
                    mx = value [ o_o ];
                    node = o_o;
                }
            }
            if ( mx )
            {
                qu.push( node );
                ans += value [ node ];
            }
        }
        printf("Case %d: %d %d",++cases,ans,node);
        putchar(10);
    }
    return 0;
}
