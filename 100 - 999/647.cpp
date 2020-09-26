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
int ar [ mxs ] , pos [ 10 ] , ladder [ 110 ] , lose [ 110 ];
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
    n = 0;
    while( cin>>ar [ ++n ] && ar [ n ] );
    while ( cin>>m && m )
    {
        memset( pos , 0 , sizeof pos );
        for ( i = 1; i <= 100; i++ )ladder [ i ] = i;
        memset( lose , 0 , sizeof lose );
        while ( cin>>a>>b && ( a && b ) )ladder [ a ] = b;
        while ( cin>>a && a )
        {
            if ( a > 0 )lose [ a ] = 1;
            else lose [ abs(a) ] = -1;
        }
        q = k = b = 0;
        for ( i = 1; i <= n; i++ )
        {
            if ( q )break;
            a = ar [ i ];
            b++;
            if ( b > m )b = 1;
            if ( a + pos [ b ] > 100 || lose [ a + pos [ b ] ] == -1 )continue;
            if ( ladder [ a + pos [ b ] ] != a + pos [ b ] )pos [ b ] = ladder [ pos [ b ] + a ];
            else pos [ b ] += a;
            if ( pos [ b ] == 100 )q = 1, k = b;
            if ( lose [ pos [ b ] ] == 1 )b--;
        }
        //for ( i = 1; i <= m; i++ )cout<<"\n"<<pos [ i ]<<" lol ";
        cout<<k<<"\n";
    }
    return 0;
}

