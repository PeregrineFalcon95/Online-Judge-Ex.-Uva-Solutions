#include<bits/stdc++.h>
using namespace std;
#define pii pair < int , int >
pii o_o;
int graph [ 50010 ] , counter [ 50010 ];
bool visited [ 50010 ];
set < int > st;
int t , n , a , b , z , cases , i ;
set < int >::iterator it;
pair < int , int > dfs ( int source );
int main()
{
    scanf("%d",&t);
    while ( t-- )
    {
        scanf("%d",&n);
        for ( i = 0; i != n; i++ )
        {
            scanf("%d%d",&a,&b);
            graph [ a ] = b;
            visited [ a ] = visited [ b ] = counter [ a ] = counter [ b ] = 0;
        }
        for ( i = 1 ; i <= n; i++ )
        {
            if ( !visited [ i ] )
            {
                st.clear();
                o_o = dfs ( i );
            }
        }
        a = 0;
        b = 1;
        for ( int i = 1; i <= n; i++ )
        {
            if ( counter [ i ] > a )
            {
                a = counter [ i ];
                b = i;
            }
        }
        printf("Case %d: %d\n",++cases,b);
    }
    return 0;
}
pair < int , int >  dfs ( int source )
{
    st.insert ( source );
    visited [ source ] = 1;
    pii y;
    y.second = -1;
    int  x = graph [ source ];
    if ( !visited [ x ] )
    {
        y = dfs ( x );
        if ( y.second == source )
        {
            y.first++;
            for ( it = st.begin(); it != st.end(); it++ )
            {
                counter [ *it ] = y.first;
            }
            st.clear();
            y.second = -1;
            return y;
        }
        else
        {
            counter [ source ] = ++y.first;
            return y;
        }
    }
    else
    {
        y = pii ( 1 , x );
        if ( st.count( x ) )return y;
        a = counter [ x ] + 1;
        y = pii ( a , -1 );
        counter [ source ] = a;
        return y;
    }
}
