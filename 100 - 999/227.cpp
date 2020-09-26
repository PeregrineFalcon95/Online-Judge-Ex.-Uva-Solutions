#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(1e5+7)
#define ll long long int
int  cases , n , s , w , m , t , a , b , c , d , e , f , i , j , k , q , row , col ;
char grid [ 8 ] [ 8 ] , ch;
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
deque < char > dq;
bool game();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    while ( 1 )
    {
        dq.clear();
        for ( i = 1; i <= 5; i++ )
        {
            for ( j = 1; j <= 5; j++ )
            {
                scanf("%c",&grid [ i ] [ j ] );
                if ( i == 1 && j == 1 && grid [ i ] [ j ] == 'Z' )return 0;
                if ( grid [ i ] [ j ] == ' ' )row = i , col = j;
            }
            getchar();
        }
        if ( cases )putchar( 10 );
        while( scanf("%c",&ch) && ch != '0' )dq.push_back( ch );
        printf("Puzzle #%d:\n",++cases);
        if ( game() )printf("This puzzle has no final configuration.\n");
        else
        {
            for ( i = 1; i <= 5; i++ )
            {
                for ( j = 1; j <= 5; j++ )
                {
                    if ( j != 1 )putchar(32);
                    putchar( grid [ i ] [ j ] );
                }
                putchar(10);
            }
        }
        getchar();
    }
    return 0;
}
bool game()
{
    c = dq.size();
    for ( i = 0; i != c; i++ )
    {
        if ( dq [ i ] == 'A' )
        {
            a = row - 1;
            b = col;
            if ( a < 1 )return 1;
            swap( grid [ row ] [ col ] , grid [ a ] [ b ] );
            row = a;
            col = b;
        }
        else if ( dq [ i ] == 'B' )
        {
            a = row + 1;
            b = col;
            if ( a > 5 )return 1;
            swap( grid [ row ] [ col ] , grid [ a ] [ b ] );
            row = a;
            col = b;
        }
        else if ( dq [ i ] == 'R' )
        {
            a = row;
            b = col + 1 ;
            if ( b > 5 )return 1;
            swap( grid [ row ] [ col ] , grid [ a ] [ b ] );
            row = a;
            col = b;
        }
        else if ( dq [ i ] == 'L' )
        {
            a = row;
            b = col - 1;
            if ( b < 1 )return 1;
            swap( grid [ row ] [ col ] , grid [ a ] [ b ] );
            row = a;
            col = b;
        }
        else if ( dq [ i ] != 32 && dq [ i ] != 10 )return 1;
    }
    return 0;
}
