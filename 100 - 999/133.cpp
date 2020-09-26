#include<bits/stdc++.h>
using namespace std;
#define pii pair < int , int >
vector < pii > ans;
vector < int > v , v2;
int n , m , k , a , b , c , d , i , j ,pos , pos2 ,sz , x , y ;
int main()
{
    while ( scanf("%d%d%d",&n,&k,&m) == 3 && ( n || m || k ) )
    {
        v.clear();
        v2.clear();
        ans.clear();
        for ( i = 1; i <= n ; i++ )v.push_back( i );
        for ( i = n; i >= 1; i-- )v2.push_back( i );
        pos = 0;
        pos2 = 0;
        j = n;
        while ( !v.empty() )
        {
            a = ( pos + k - 1 ) % j;
            b = ( pos2 + m - 1 ) % j;
            if ( v [ a ] == v2 [ b ] )
            {
                ans.push_back( pii ( v [ a ] , -1 ) );
                v.erase( v.begin() + a );
                v2.erase( v2.begin() + b );
                if ( a == v.size() )pos = 0;
                else pos = a;
                if ( b == v2.size() )pos2 = 0;
                else pos2 = b;
                j --;
            }
            else
            {
                c = v [ a ];
                d = v.size();
                y = v2 [ b ];
                for (  i = 0; i != d; i++ )
                {
                    if ( v [ i ] == v2 [ b ] )
                    {
                        d = i;
                        break;
                    }
                }
                if ( d > a )
                {
                    v.erase( v.begin() + d );
                    v.erase( v.begin() + a );
                    if ( a == v.size() )pos = 0;
                    else pos = a;
                }
                else
                {
                    v.erase( v.begin() + a );
                    v.erase( v.begin() + d );
                    if ( a - 1 >= v.size() ) pos = 0;
                    else pos = a - 1 ;
                }
                d = v2.size();
                for ( i = 0; i != d; i++ )
                {
                    if ( v2 [ i ] == c )
                    {
                        d = i;
                        break;
                    }
                }
                if ( d > b )
                {
                    v2.erase( v2.begin() + d );
                    v2.erase( v2.begin() + b );
                    if ( b >= v2.size() )pos2 = 0;
                    else pos2 = b;
                }
                else
                {
                    v2.erase( v2.begin() + b );
                    v2.erase( v2.begin() + d );
                    if ( b - 1 >= v2.size() )pos2 = 0;
                    else pos2 = b - 1;
                }
                j -= 2;
                ans.push_back( pii ( c , y ) );
            }
        }
        a = ans.size();
        for ( i = 0; i != a; i++ )
        {
            if ( ans [ i ].second == - 1 )
            {
                if ( ans [ i ].first < 10 )printf("  %d",ans [ i ].first);
                else printf(" %d",ans [ i ].first);
            }
            else
            {
                if ( ans [ i ].first < 10 )printf("  %d",ans [ i ].first);
                else printf(" %d",ans [ i ].first);
                if ( ans [ i ].second < 10 )printf("  %d",ans [ i ].second);
                else printf(" %d",ans [ i ].second );
            }
            if( i != ans.size() - 1 )putchar ( ',' );
        }
        putchar ( 10 );
    }
    return 0;
}
