#include<bits/stdc++.h>
using namespace std;
bool status [ 1000040];
vector < int > prime;
#define ll long long int
void seive();
int main()
{
    seive();
    ll n;
    scanf(" %lld ", &n );
    for ( ll i = 1; i <= n; i++ )
    {
        ll a,b;
        scanf("%lld%lld",&a,&b);
        set < double > st;
        ll sz = prime.size();
        for ( ll j = 0; j != sz; j++ )
        {
            ll cc = prime[ j ];
            ll ff = 2;
            while( 1 )
            {
                double dd = pow( cc , ff++);
                if( dd > b )break;
                if( dd >=a)st.insert(dd);
            }
        }
        sz = st.size();
        printf("%d\n",sz);
    }
    return 0;
}
void seive()
{
    int n = 1000030;
    int sq = sqrt( n );
    int sz = 0 ;
    prime.push_back( 2 );
    for ( int i =3; i <= sq; i+=2)
    {
        if ( !status [ i ])
        {
            sz = i;
            prime.push_back( i );
            for ( int j = i*i ; j <= n; j+= ( i+i ) )status [ j ] = 1;
        }
    }
    for ( int j = sz+2; j <= n; j +=2 )
    {
        if( !status [ j ] )prime.push_back( j );
    }
}
