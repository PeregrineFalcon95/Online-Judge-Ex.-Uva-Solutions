#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(2e5+7)
#define ll long long int
int  cases,n , m , t , a , b , c , d , e , f , i , j , k , q , row , col ;
char grid [ 15 ] [ 15 ] , grid2 [ 15 ] [ 15 ];
int kx[] = {-2,-2,-1,1,-1,1,2,2};
int ky[] = {1,-1,-2,-2,2,2,-1,1};
int dx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int dy[]={-1,+1,+0,+0,+1,+1,-1,-1};
bool check( int xx , int yy ){return !( xx < 0 || yy < 0 || xx == n || yy == n || grid [ xx ] [ yy ] != '*' );}
int ar [ 10002 ] , gu [ 10002 ] , temp [ 10002 ];
string s;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while ( cin>>n && n )
    {
        for ( i = 1; i <= n; i++ )cin>>ar [ i ];
        cout<<"Game "<<++cases<<":\n";
        while(1)
        {
            c = 0;
            for ( i = 1; i <= n; i++ )
            {
                cin>>gu [ i ];
                if ( gu [ i ] )c = 1;
            }
            if ( !c )break;
            for ( i = 1; i <= n; i++ )temp [ i ] = ar [ i ];
            a = b = 0;
            for ( i = 1; i <= n; i++ )
            {
                if ( temp [ i ] == gu [ i ] )
                {
                    a++;
                    temp [ i ] = gu [ i ] = -1;
                }
            }
            //for ( i = 1; i <= n; i++ )cout<<gu [ i ]<<"  lol "<<endl;
            for ( i = 1; i <= n; i++ )
                if ( gu [ i ] != -1 )
                    for ( j = 1; j <= n; j++ )
                        if ( temp [ j ] == gu [ i ] )
                        {
                            gu [ i ] = temp [ j ] = -1;
                            b++;
                            break;
                        }
            //cout<<a<<"   lol   "<<b<<endl;
            cout<<"    ("<<a<<","<<b<<")\n";
        }
    }
    return 0;
}

