#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(1e5+7)
#define ll long long int
int n , m , t , a , b , c , d , ans , ca;
//ll ar [ mxs ] ;
string s;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while ( cin>>s && s != "END" )
    {
        b = s.size();
        if ( s == "1" )
        {
            cout<<"1\n";
            continue;
        }
        ans = 1;
        while ( 1 )
        {
            d = b;
            ans++;
            ca = 0;
            while ( d > 0 )
            {
                d /= 10;
                ca++;
            }
            if ( ca == b )break;
            b = ca;
        }
        cout<<ans<<"\n";
    }
    return 0;
}

