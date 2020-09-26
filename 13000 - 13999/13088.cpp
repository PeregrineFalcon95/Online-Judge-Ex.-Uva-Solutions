#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P  102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(1e6+2)
#define ll unsigned long long int
string s;
map < char , int > mp;
map < char , int >::iterator it;
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
        cin>>s;
        mp.clear();
        n = s.size();
        for ( int i = 0; i != n; i++ )
        {
            mp [ s [ i ] ]++;
        }
        b = a = 0;
        for ( it = mp.begin(); it != mp.end(); it++ )
        {
            if ( b ){a+= it->second - 1;it->second = 1;}
            b++;
        }
        it = mp.begin();
        it->second += a;
        for ( it = mp.begin(); it != mp.end(); it++ )
        {
            a = it->second;
            while ( a-- )cout<<it->first;
        }
        cout<<endl;
    }
    return 0;
}
