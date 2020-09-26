#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P  102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(1e6+2)
#define ll unsigned long long int
int ar [ mxs ];
int n , m , a , b , c , t , ans , cases;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while ( t-- )
    {
        cin>>n;
        for ( int i = 1; i <= n; i++ )cin>>ar [ i ];
        a = 1;
        for ( int i = 1; i <= n; i++ )if ( ar [ i ] == a )a++;
        cout<<"Case "<<++cases<<": "<<n-a+1<<"\n";
    }
    return 0;
}
