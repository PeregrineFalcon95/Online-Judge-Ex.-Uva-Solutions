#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(1e2+7)
#define ll long long int
int n , m , t , a , b , c , d , ans , cases;
ll ar [ mxs ] ;
//string s;
char s [ 1000000 ];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    scanf("%d",&t);
    while ( t-- )
    {
        memset( ar , 0 , sizeof ar );
        scanf("%s",&s);
        a = strlen(s);
        b = 1;
        for ( int i = 0; i != a; i++ )
        {
            if ( s [ i ] == '.' )continue;
            else if ( s [ i ] == '>' )
            {
                b++;
                if ( b == 101 )b = 1;
            }
            else if ( s [ i ] == '<' )
            {
                b--;
                if ( !b )b = 100;
            }
            else if ( s [ i ] == '+' )
            {
                ar [ b ]++;
                if ( ar [ b ] == 256 )ar [ b ] = 0;
            }
            else if ( s [ i ] == '-' )
            {
                ar [ b ]--;
                if ( ar [ b ] == -1 )ar [ b ] = 255;
            }
        }
        printf("Case %d:",++cases);
        for ( int i = 1; i <= 100; i++ )printf(" %02X",ar [ i ] );
        putchar(10);
    }
    return 0;
}

