#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(1e5+7)
#define ll long long int
int t ,  n , m , a , b , c , d , e , sz ,  r , i , j , k , l , o , mx;
//ll ar [ mxs ] [ 4 ];
//string s , s2 , s3;
int marker [ 1026 ] [ 1026 ];
bool check( int x, int y ){return !( x < 0 || y < 0 || x > 1024 || y > 1024 );}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while ( t-- )
    {
        cin>>d;
        cin>>n;
        memset( marker , 0 , sizeof marker );
        for ( o = 1;  o <= n; o++ )
        {
            cin>>a>>b>>c;
            for ( i = a - d; i <= a + d; i++ )
                for ( j = b - d; j <= b + d; j++ )if ( check( i , j ) )marker [ i ] [ j ] += c;
        }
        a = 0 , b = 0 , mx = 0;
        for ( i =0 ; i <= 1024; i++ )
            for ( j = 0; j <= 1024; j++ )
            {
                if ( marker [ i ] [ j ] > mx )
                {
                    mx = marker [ i ] [ j ];
                    a = i;
                    b = j;
                }
            }
        cout<<a<<" "<<b<<" "<<mx<<"\n";
    }
    return 0;
}

