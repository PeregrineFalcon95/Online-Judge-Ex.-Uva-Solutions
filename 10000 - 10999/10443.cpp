#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(1e5+7)
#define ll long long int
int  cases , n ,  w , m , t , a , b , c , d , e , f , i , j , k , q , row , col ;
char grid [ 110 ] [ 110 ] , temp [ 110 ] [ 110 ] ,ch;
int nx[] = {-2,-2,-1,1,-1,1,2,2};
int ny[] = {1,-1,-2,-2,2,2,-1,1};
int dx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int dy[]={-1,+1,+0,+0,+1,+1,-1,-1};
int kx[] = {+1,-1,+0,+0};
int ky[] = {+0,+0,+1,-1};
bool check( int xx , int yy ){return !( xx < 0 || yy < 0 || xx == n || yy == m );}
int ar [ 110 ] , lose [ 110 ];
void fastscan(int &number)
{
    register int c;
    number = 0;
    c = getchar();
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
}
deque < char > dq;
string s , s2;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    scanf("%d",&t);
    while ( t-- )
    {
        scanf("%d%d%d",&n,&m,&a);
        for ( i = 0; i < n; i++ )scanf("%s",&grid [ i ] );
        while ( a-- )
        {
            memset( temp , '.' , sizeof temp );
            for ( i = 0; i < n; i++ )
            {
                for ( j = 0; j < m; j++ )
                {
                    ch = grid [ i ] [ j ];
                    for ( k = 0; k != 4; k++ )
                    {
                        b = i + kx [ k ];
                        c = j + ky [ k ];
                        if ( check( b , c ) )
                        {
                            if ( ch == 'R' && grid [ b ] [ c ] == 'S' )temp [ b ] [ c ] = 'R';
                            else if ( ch == 'S' && grid [ b ] [ c ] == 'P' )temp [ b ] [ c ] = 'S';
                            else if ( ch == 'P' && grid [ b ] [ c ] == 'R' )temp [ b ] [ c ] = 'P';
                        }
                    }
                }
            }
            for ( i = 0; i != n; i++ )
                for ( j = 0; j != m; j++ )
                {
                    if ( temp [ i ] [ j ] == '.' )continue;
                    grid [ i ] [ j ] = temp [ i ] [ j ];
                }
        }
        for ( i = 0; i != n; i++ )
        {
            for ( j = 0; j != m; j++ )putchar( grid [ i ] [ j ] );
            putchar( 10 );
        }
        if ( t )putchar(10);
    }
    return 0;
}
