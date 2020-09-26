#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(2e5+7)
#define ll long long int
int  n , m , t , a , b , c , d , e , f , i , j , k , q , row , col ;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while ( t-- )
    {
        cin>>q;
        cin>>n;
        while ( q-- )
        {
            cin>>a>>b>>c>>d;
            if ( a == c && b == d )cout<<"0\n";
            else if ( ( a - b == c - d ) || ( a + b == c + d ) )cout<<"1\n";
            else if ( ( ( a&1 && b&1 ) || ( a%2 == 0 && b % 2 == 0 ) ) && ( ( c&1 && d&1 ) || ( c%2 == 0 && d%2 == 0 ) ) )cout<<"2\n";
            else if ( ( ( a&1 && b%2 == 0 ) || ( a%2 == 0 && b&1 ) ) && ( ( c&1 && d%2 == 0 ) || ( c%2 == 0 && d&1 ) ) )cout<<"2\n";
            else cout<<"no move\n";
        }
    }
    return 0;
}
