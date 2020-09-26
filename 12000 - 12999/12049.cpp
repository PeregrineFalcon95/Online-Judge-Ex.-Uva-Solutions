#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,n,m,t;
    scanf("%d",&t);
    while ( t-- )
    {
        scanf("%d%d",&n,&m);
        map < int , int > mp;
        for ( int i = 0; i != n; i++ )
        {
            scanf("%d",&a);
            mp [ a ]++;
        }
        map < int , int > mp2;
        for ( int i = 0; i != m; i++ )
        {
            scanf("%d",&a);
            mp2 [ a ]++;
        }
        int ans = 0;
        map < int, int > ::iterator it = mp.begin();
        for ( it = mp.begin(); it != mp.end(); it++ )
        {
            a = it->first;
            if ( mp2.find( a ) == mp2.end() )
            {
                ans+= it->second;
                it->second == 0;
            }
            else
            {
                if ( it->second == mp2 [ a ] )continue;
                else if ( it->second > mp2 [ a ] )
                {
                    ans+= ( it->second - mp2 [ a ] );
                    it->second = mp2 [ a ];
                }
                else
                {
                    ans+= ( mp2 [ a ] - it->second );
                    mp2 [ a ] = it->second;
                }
            }
        }
        for ( it = mp2.begin(); it != mp2.end(); it++ )
        {
            a = it->first;
            if ( mp.find( a ) == mp.end() )
            {
                ans+= it->second;
                it->second == 0;
            }
            else
            {
                if ( it->second == mp [ a ] )continue;
                else if ( it->second > mp [ a ] )
                {
                    ans+= ( it->second - mp [ a ] );
                    it->second = mp [ a ];
                }
                else
                {
                    ans+= ( mp [ a ] - it->second );
                    mp [ a ] = it->second;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
