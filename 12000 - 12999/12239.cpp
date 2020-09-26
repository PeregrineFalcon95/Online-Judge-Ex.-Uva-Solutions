#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(1e5+7)
#define ll long long int
int  cases , n , s , w , m , t , a , b , c , d , e , f , i , j , k , q , row , col ;
char grid [ 15 ] [ 15 ] , grid2 [ 15 ] [ 15 ];
int kx[] = {-2,-2,-1,1,-1,1,2,2};
int ky[] = {1,-1,-2,-2,2,2,-1,1};
int dx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int dy[]={-1,+1,+0,+0,+1,+1,-1,-1};
bool check( int xx , int yy ){return !( xx < 0 || yy < 0 || xx == n || yy == n || grid [ xx ] [ yy ] != '*' );}
int ar [ 100 ] , pos [ 10 ] , ladder [ 110 ] , lose [ 110 ];
void fastscan(int &number)
{
    register int c;
    number = 0;
    c = getchar();
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
}
bool marker [ 100 ];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //printf("%d",'Y');
    while ( scanf("%d%d",&n,&m) == 2  && n )
    {
        getchar();
        for ( i = 1; i <= m; i++ )fastscan(ar [ i ] );
        memset( marker , 0 , sizeof marker );
        for ( i = 1; i <= m; i++ )
            for ( j = 1; j <= m; j++ )
                marker [ abs( ar [ i ] - ar [ j ] ) ] = 1;
        a = 0;
        for ( i = 0; i <= n; i++ )
            if ( !marker [ i ] )
            {
                a = 1;
                break;
            }
        if ( !a )putchar(89);
        else putchar(78);
        putchar(10);
    }
    return 0;
}

