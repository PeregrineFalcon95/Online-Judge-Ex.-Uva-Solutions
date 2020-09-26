#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(1e6+7)
#define ll long long int
int  cases , n , s , w , m , t , a , b , c , d , e , f , i , j , k , q , row , col ;
char grid [ 15 ] [ 15 ] , grid2 [ 15 ] [ 15 ];
int kx[] = {-2,-2,-1,1,-1,1,2,2};
int ky[] = {1,-1,-2,-2,2,2,-1,1};
int dx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int dy[]={-1,+1,+0,+0,+1,+1,-1,-1};
bool check( int xx , int yy ){return !( xx < 0 || yy < 0 || xx == n || yy == n || grid [ xx ] [ yy ] != '*' );}
int ar [ mxs ] , pos [ 110 ];
void fastscan(int &number)
{
    register int c;
    number = 0;
    c = getchar();
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cin>>t;
    fastscan( t );
    while ( t-- )
    {
        //cin>>n>>m>>e;
        fastscan(n);
        fastscan(m);
        fastscan(e);
        for ( i = 1; i <= n; i++ )ar [ i ] = 1;
        for ( i = 1; i <= 109; i++ )pos [ i ] = i;
        while ( m-- )
        {
            //cin>>a>>b;
            fastscan(a);
            fastscan(b);
            pos [ a ] = b;
        }
        q = 0;
        b = 1;
        while ( e-- )
        {
            //cin>>a;
            fastscan( a );
            if( q )continue;
            ar [ b ] += a;
            if ( pos [ ar [ b ] ] != ar [ b ] )ar [ b ] = pos [ ar [ b ] ];
            if ( ar [ b ] >= 100 )
            {
                ar [ b ] = 100;
                q = 1;
            }
            b++;
            if ( b > n )b = 1;
        }
        //for ( i = 1; i <= n; i++ )cout<<"Position of player "<<i<<" is "<<ar [ i ]<<".\n";
        for ( i = 1; i <= n; i++ )printf("Position of player %d is %d.\n",i,ar [ i ] );
    }
    return 0;
}

