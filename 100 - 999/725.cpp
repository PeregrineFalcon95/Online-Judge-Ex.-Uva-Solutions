#include<bits/stdc++.h>
using namespace std;
int a, b, c, n, d, e;
map < int, vector < pair < int, int > > > ans;
set < int > st;
void pre();
int main()
{
    pre();
    e = 0;
    while( scanf("%d",&n ) == 1 && n )
    {
        if ( e )putchar( 10 );
        e++;
        int sz = ans [ n ].size();
        if( !sz )printf("There are no solutions for %d.\n",n);
        for ( int i = 0; i != sz; i++ )
        {
            a = ans [ n ] [ i ].first;
            b = ans [ n ] [ i ].second;
            if ( b <= 9999 )
            {
                printf("%d / 0%d = %d\n",a, b, n );
            }
            else printf("%d / %d = %d\n",a,b,n);
        }
    }
    return 0;
}
void pre()
{
    for ( int i = 2; i <= 79; i++ )
    {
        a = i;
        while( a <= 98765 )
        {
            a+= i;
            b = a;
            c = d = 0;
            st.clear();
            while( b > 0 )
            {
                e = ( b % 10 ) ;
                if ( !e ) d = 1;
                st.insert( e );
                c++;
                b /= 10;
            }
            if( st.size() == c && ( c == 5  ) )
            {
                b = a / i;
                int f = b;
                c = 0;
                while( b > 0 )
                {
                    e = ( b % 10 ) ;
                    if ( !e ) d = 1;
                    st.insert( e );
                    c++;
                    b /= 10;
                }
                if( st.size() == 10 || ( st.size() == 9 && !d && f < 9999  ) )
                {
                    ans [ i ] . push_back( pair < int,int > ( a, f ) );
                }
            }
        }
    }
}

