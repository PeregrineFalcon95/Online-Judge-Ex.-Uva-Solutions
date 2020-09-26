#include<bits/stdc++.h>
using namespace std;
#define mx 1000100
#define ll long long int
ll i , j , n , m , k , a , b , hi , lo , t , cases , ans;
ll ar [ mx ] , marker [ 110 ];
set < ll > st;
int main()
{
    ar [ 1 ] = 1;
    ar [ 2 ] = 2;
    ar [ 3 ] = 3;
    scanf("%lld",&t);
    while ( t-- )
    {
        //ans = n + 1;
        scanf("%lld%lld%lld",&n,&m,&k);
        ans = n + 1;
        for ( i = 4; i <= n; i++ )ar [ i ] = ( ( ar [ i - 1 ] + ar [ i - 2 ] + ar [ i - 3 ] )%m ) + 1;
        st.clear();
        hi = lo = 0;
        memset( marker , 0 , sizeof marker );
        while ( hi <= n )
        {
            a = st.size();
            if ( a >= k )
            {
                ans = min ( ans , ( hi - lo + 1 ) );
                if ( hi == lo )break;
            }
            if ( a >= k && hi > lo )
            {
                if ( ar [ lo ] <= k ){ marker [ ar [ lo ] ]--;
                if ( !marker [ ar [ lo ] ] && st.count( ar [ lo ] )  )st.erase( ar [ lo ] );
                }
                lo++;
            }
            else if ( a < k  )
            {

                hi++;
                if ( ar [ hi ] <= k  )
                {
                    st.insert( ar [ hi ] );
                    marker [ ar [ hi ] ]++;
                }
            }
        }
        if ( ans <= n ) printf("Case %lld: %lld\n",++cases,ans);
        else printf("Case %lld: sequence nai\n",++cases);
    }
    return 0;
}

