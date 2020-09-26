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
    char ch;
    while ( t-- )
    {
        cin>>ch>>n>>m;
        if ( ch == 'Q' || ch == 'r' )cout<<min( n , m )<<"\n";
        else if ( ch == 'K' )cout<<( ( n + 1 ) / 2 ) * ( ( m + 1 ) / 2 )<<"\n";
        else if ( n&1 && m&1 )cout<<( n * m + 1 )/2<<"\n";
        else cout<<( n*m )/2<<"\n";
    }
    return 0;
}
