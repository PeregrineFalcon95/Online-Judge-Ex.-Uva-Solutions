#include<bits/stdc++.h>
using namespace std;
int dx[]={-2,-2,-1,1,-1,1,2,2};
int dy[]={1,-1,-2,-2,2,2,-1,1};
char grid [ 7 ] [ 7 ];
int n , m , a , b , c , j , i;
//bool check( int ii , int jj ){ return !( ii < 1 || jj < 1 || ii > 5 || jj > 5); }
int backtrack( int row , int col , int mo );
int main()
{
    scanf("%d",&n);
    getchar();
    while ( n-- )
    {
        for ( i = 1; i <= 5; i++ )
        {
            for ( j = 1; j <= 5; j++ )scanf("%c",&grid [ i ] [ j ] );
            getchar();
        }
        a = -1;
        for ( i = 1; i <= 5; i++ )
            for ( j = 1; j <= 5; j++ )
                if ( grid [ i ] [ j ] == ' ' )
                {
                    a = backtrack( i , j , 0 );
                    if ( a != -1 )break;
                }
        if ( a < 11 )printf("Solvable in %d move(s).\n",a);
        else printf("Unsolvable in less than 11 move(s).\n");
    }
    return 0;
}
int backtrack( int row , int col , int mo )
{
    if ( mo > 10 )return 11;
    if ( grid [ 1 ] [ 1 ] == '1' && grid [ 1 ] [ 2 ] == '1' && grid [ 1 ] [ 3 ] == '1' && grid [ 1 ] [ 4 ] == '1' && grid [ 1 ] [ 5 ] == '1' )
        if ( grid [ 2 ] [ 1 ] == '0' && grid [ 2 ] [ 2 ] == '1' && grid [ 2 ] [ 3 ] == '1' && grid [ 2 ] [ 4 ] == '1' && grid [ 2 ] [ 5 ] == '1' )
            if ( grid [ 3 ] [ 1 ] == '0' && grid [ 3 ] [ 2 ] == '0' && grid [ 3 ] [ 3 ] == ' ' && grid [ 3 ] [ 4 ] == '1' && grid [ 3 ] [ 5 ] == '1' )
                if ( grid [ 4 ] [ 1 ] == '0' && grid [ 4 ] [ 2 ] == '0' && grid [ 4 ] [ 3 ] == '0' && grid [ 4 ] [ 4 ] == '0' && grid [ 4 ] [ 5 ] == '1' )
                    if ( grid [ 5 ] [ 1 ] == '0' && grid [ 5 ] [ 2 ] == '0' && grid [ 5 ] [ 3 ] == '0' && grid [ 5 ] [ 4 ] == '0' && grid [ 5 ] [ 5 ] == '0' )return mo;
    int xx , yy , lol = 11;
    for ( int l = 0; l != 8; l++ )
    {
        xx = row + dx [ l ];
        yy = col + dy [ l ];
        if ( xx > 0 && yy > 0 && xx < 6 && yy < 6 )//check( xx, yy ) )
        {
            swap( grid [ row ] [ col ] , grid [ xx ] [ yy ] );
            lol = min( lol , backtrack( xx, yy, mo + 1 ) );
            swap( grid [ row ] [ col ] , grid [ xx ] [ yy ] );
        }
    }
    return lol;
}

