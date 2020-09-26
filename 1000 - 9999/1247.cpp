#include<bits/stdc++.h>
using namespace std;
#define inf 9999999
int n,m,t,a,b,c;
char ch, ch2, ch3;
int matrix [ 30 ] [ 30 ] , parent [ 30 ] [ 30 ];
vector < int > path;
set < int > st;
void warshall();
void path_finder(int source , int target );
int main()
{
    for ( int i = 0; i != 27; i++ )
    {
        for ( int j = 0; j != 27; j++ )
        {
            parent [ i ] [ j ] = j;
            if ( i != j )matrix [ i ] [ j ] = inf;
            else matrix [ i ] [ j ] = 0;
        }
    }
    scanf("%d%d",&n,&m);
    for ( int i = 0; i != m; i++ )
    {
        scanf(" %c %c %d",&ch,&ch2,&c);
        a = ch - 'A';
        b = ch2 - 'A';
        matrix [ a ] [ b ] = c;
        matrix [ b ] [ a ] = c;
    }
    warshall();
    scanf("%d",&t);
    for ( int i = 0; i != t; i++ )
    {
        scanf(" %c %c",&ch,&ch2);
        a = ch - 'A';
        b = ch2 - 'A';
        path_finder( a , b );
        int sz = path.size();
        for ( int j = 0; j != sz; j++ )
        {
            if ( j )putchar( 32 );
            printf("%c",path[ j ] + 'A' );
        }
        putchar( 10 );
    }
    return 0;
}
void warshall()
{
    for ( int k = 0; k != 26; k++ )
    {
        for ( int i = 0; i != 26; i++ )
        {
            for ( int j = 0; j != 26; j++ )
            {
                int o_o = matrix [ i ] [ k ] + matrix [ k ] [ j ];
                int w_w = matrix [ i ] [ j ];
                if ( w_w >= o_o && o_o && o_o < inf )
                {
                    int w_w_sz = inf;
                    if ( w_w > o_o )
                    {
                        parent [ i ] [ j ] = parent [ i ] [ k ];
                        matrix [ i ] [ j ] = o_o;
                        continue;
                    }
                    if ( w_w < inf )
                    {
                        path_finder( i , j );
                        w_w_sz = path.size();
                    }
                    if ( w_w_sz == inf )
                    {
                        parent [ i ] [ j ] = parent [ i ] [ k ];
                        matrix [ i ] [ j ] = o_o;
                        continue;
                    }
                    st.clear();
                    path_finder( i , k  );
                    int sz = path.size();
                    for ( int l = 0; l != sz; l++ )
                    {
                        st.insert( path [ l ] );
                    }
                    path_finder( k , j );
                    sz = path.size();
                    for ( int l = 0; l != sz; l++ )
                    {
                        st.insert( path [ l ] );
                    }
                    if ( st.size() < w_w_sz )
                    {
                        matrix [ i ] [ j ] = o_o;
                        parent [ i ] [ j ] = parent [ i ] [ k ];
                    }
                }
            }
        }
    }
}
void path_finder( int source , int target )
{
    path.clear();
    int lol = source;
    while ( lol != target )
    {
        path.push_back( lol );
        lol = parent [ lol ] [ target ];
    }
    path.push_back( target );
}
