#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P  102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(1e6+2)
#define ll unsigned long long int
string s;
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
        a = b = -1;
        for ( int i = 1; i <= 5; i++ )
        {
            cin>>s;
            for ( int j = 0; j != 5; j++ )
            {
                if ( s [ j ] == '|' )c = j;
                else if ( s [ j ] == '>' )a = j;
                else if ( s [ j ] == '<' )b = j;
            }
        }
        cin.ignore();
        if( a != -1 && a > c )cout<<"Case "<<++cases<<": No Ball\n";
        else if ( a != -1 && a < c )cout<<"Case "<<++cases<<": Thik Ball\n";
        else if ( b != -1 && b < c )cout<<"Case "<<++cases<<": No Ball\n";
        else if ( b != -1 && b > c )cout<<"Case "<<++cases<<": Thik Ball\n";
    }
    return 0;
}
