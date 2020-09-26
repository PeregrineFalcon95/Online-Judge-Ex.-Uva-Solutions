#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(2e5+7)
#define ll long long int
int val , n , m , cases , t , a , b , c , d , e , i , j ;
set < int > x , y;
set < int > ::iterator it;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while ( cin>>n>>m && n )
    {
        x.clear();
        y.clear();
        for ( i = 0; i != n; i++ )
        {
            cin>>a;
            x.insert( a );
        }
        for ( i = 0; i != m; i++ )
        {
            cin>>a;
            y.insert( a );
        }
        a = b = 0;
        for ( it = x.begin(); it != x.end(); it++ )
        {
            if ( y.count( *it ) )continue;
            else a++;
        }
        for ( it = y.begin(); it != y.end(); it++ )
        {
            if ( x.count( *it ) )continue;
            else b++;
        }
        cout<<min( a , b )<<"\n";
    }
    return 0;
}

