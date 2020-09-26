#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void fastscan(long long int &number)
{
    bool negative = false;
    register int c;
    number = 0;
    c = getchar();
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
}
int main()
{
    ll num;
    ios_base::sync_with_stdio(false);
    while ( scanf("%lld",&num)==1 && num )
    {
       getchar();
        multiset < ll > st;
        multiset < ll >::iterator it,it2;
        ll ans = 0;
        while ( num-- )
        {
            ll n,a;
            fastscan(n);
            while( n-- )
            {
                fastscan(a);
                st.insert(a);
            }
            it = st.begin();
            it2 = st.end();
            it2--;
            ans+=  *it2 - *it;
            st.erase(it);
            st.erase(it2);
        }
        printf("%lld\n",ans);
    }
    return 0;
}


