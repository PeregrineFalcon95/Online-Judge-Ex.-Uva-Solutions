///***This is the main code.***///
#include<bits/stdc++.h>
using namespace std;
int ans [ 20 ];
int a , b , c , i , j , k;
vector < int > v;
set < int > st;
void pre();
int main()
{
    pre();
    while ( scanf("%d",&a) == 1 && a )printf("%d\n",ans [ a ] );
    return 0;
}
void pre()
{
    for ( i = 1; i <= 13; i++ )
    {
        b = 0;
        for ( k = i ; ; k++ )
        {
            a = i + i;
            st.clear();
            v.clear();
            for ( j = i + 1 ; j <= a; j++ )st.insert( j );
            for ( j = 1; j <= a; j++  )v.push_back( j );
            a = 0;
            for ( j = i + i ; j > 1; j-- )
            {
                a = ( a + k - 1 ) % j;
                c = v [ a ];
                if ( st.count( c ) )
                {
                    st.erase( c );
                    v.erase( v.begin() + a );
                    if ( a == j - 1) a = 0;
                    if ( st.empty() )
                    {
                        ans [ i ] = k;
                        b = 1;
                        break;
                    }
                }
                else if ( st.empty() )
                {
                    ans [ i ] = k;
                    b = 1;
                    break;
                }
                else break;
            }
            if ( b )break;
        }
    }
}
/*#include<bits/stdc++.h>
using namespace std;
int ans [ ] = {2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881};
int a , b , c , i , j , k;
int main()
{
    while ( scanf("%d",&a) == 1 && a )printf("%d\n",ans [ a - 1 ] );
    return 0;
}*/
