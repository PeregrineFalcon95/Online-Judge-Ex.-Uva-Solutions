#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(1e4+7)
#define ll long long int
int n , m , t , a , b , c , d , ans , cases;
ll ar [ mxs ] ;
//string s;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    while ( scanf("%d%d",&a,&b) == 2 && a && b )
    {
        scanf("%d",&ar [ 1 ] );
        ans = c = ( a - ar [ 1 ] );
        for ( int i = 2; i <= b ;i++ )
        {
            scanf("%d",&ar [ i ] );
            if ( a - ar [ i ] > c )
            {
                ans += ( a - ar [ i ] ) - c;
                c = a - ar [ i ];
            }
            else c = a - ar [ i ];
        }
        printf("%d\n",ans);
    }
    return 0;
}

