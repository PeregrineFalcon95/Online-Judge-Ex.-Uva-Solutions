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
    while ( cin>>a>>b>>c>>d && a )
    {
        if ( a == c && b == d )cout<<"0\n";
        else if ( a == c || b == d || a - b == c - d || a + b == c + d  )cout<<"1\n";
        else cout<<"2\n";
    }
    return 0;
}
