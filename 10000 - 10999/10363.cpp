#include<bits/stdc++.h>
using namespace std;
char grid [ 4 ] [ 4 ];
int main()
{
    int n,m,a,b,c,ans,x,y,num_x,num_y;
    scanf("%d",&n);
    m = n-1;
    while ( n-- )
    {
        if ( m != n )getchar();
        a = b = c = num_x = num_y = ans = x = y = 0;
        for ( int i = 0; i != 3; i++ )scanf("%s",&grid [ i ] );
        for ( int i = 0; i <= 2; i++ )
        {
            for ( int j = 0; j != 3 ; j++ )
            {
                if ( grid [ i ] [ j ] == 'X' )num_x++;
                else if ( grid [ i ] [ j ] == 'O' )num_y++;
                else if ( grid [ i ] [ j ] == '.' )continue;
                else c = 1;
            }
        }
        if ( grid [ 0 ] [ 0 ] == 'X' && grid [ 0 ] [ 1 ] == 'X' && grid [ 0 ] [ 2 ] == 'X' )x = 1;
        else if ( grid [ 1 ] [ 0 ] == 'X' && grid [ 0 ] [ 0 ] == 'X' && grid [ 2 ] [ 0 ] == 'X' )x = 1;
        else if ( grid [ 2 ] [ 0 ] == 'X' && grid [ 2 ] [ 1 ] == 'X' && grid [ 2 ] [ 2 ] == 'X' )x = 1;
        else if ( grid [ 0 ] [ 0 ] == 'X' && grid [ 0 ] [ 1 ] == 'X' && grid [ 0 ] [ 2 ] == 'X' )x = 1;
        else if ( grid [ 0 ] [ 2 ] == 'X' && grid [ 1 ] [ 2 ] == 'X' && grid [ 2 ] [ 2 ] == 'X' )x = 1;
        else if ( grid [ 0 ] [ 0 ] == 'X' && grid [ 1 ] [ 1 ] == 'X' && grid [ 2 ] [ 2 ] == 'X' )x = 1;
        else if ( grid [ 2 ] [ 0 ] == 'X' && grid [ 1 ] [ 1 ] == 'X' && grid [ 0 ] [ 2 ] == 'X' )x = 1;
        else if ( grid [ 0 ] [ 0 ] == 'X' && grid [ 1 ] [ 0 ] == 'X' && grid [ 2 ] [ 0 ] == 'X' )x = 1;
        else if ( grid [ 1 ] [ 0 ] == 'X' && grid [ 1 ] [ 1 ] == 'X' && grid [ 1 ] [ 2 ] == 'X' )x = 1;
        else if ( grid [ 0 ] [ 1 ] == 'X' && grid [ 1 ] [ 1 ] == 'X' && grid [ 2 ] [ 1 ] == 'X' )x = 1;

        if ( grid [ 0 ] [ 0 ] == 'O' && grid [ 0 ] [ 1 ] == 'O' && grid [ 0 ] [ 2 ] == 'O' )y = 1;
        else if ( grid [ 1 ] [ 0 ] == 'O' && grid [ 0 ] [ 0 ] == 'O' && grid [ 2 ] [ 0 ] == 'O' )y = 1;
        else if ( grid [ 2 ] [ 0 ] == 'O' && grid [ 2 ] [ 1 ] == 'O' && grid [ 2 ] [ 2 ] == 'O' )y = 1;
        else if ( grid [ 0 ] [ 0 ] == 'O' && grid [ 0 ] [ 1 ] == 'O' && grid [ 0 ] [ 2 ] == 'O' )y = 1;
        else if ( grid [ 0 ] [ 2 ] == 'O' && grid [ 1 ] [ 2 ] == 'O' && grid [ 2 ] [ 2 ] == 'O' )y = 1;
        else if ( grid [ 0 ] [ 0 ] == 'O' && grid [ 1 ] [ 1 ] == 'O' && grid [ 2 ] [ 2 ] == 'O' )y = 1;
        else if ( grid [ 2 ] [ 0 ] == 'O' && grid [ 1 ] [ 1 ] == 'O' && grid [ 0 ] [ 2 ] == 'O' )y = 1;
        else if ( grid [ 0 ] [ 0 ] == 'O' && grid [ 1 ] [ 0 ] == 'O' && grid [ 2 ] [ 0 ] == 'O' )y = 1;
        else if ( grid [ 1 ] [ 0 ] == 'O' && grid [ 1 ] [ 1 ] == 'O' && grid [ 1 ] [ 2 ] == 'O' )y = 1;
        else if ( grid [ 0 ] [ 1 ] == 'O' && grid [ 1 ] [ 1 ] == 'O' && grid [ 2 ] [ 1 ] == 'O' )y = 1;

        if ( y && x ) ans = 1;
        else if ( x && ( num_x-1 != num_y ) )ans = 1;
        else if ( num_y > num_x )ans = 1;
        else if ( y && num_x != num_y )ans = 1;
        else if ( num_x && ( num_x-1 != num_y && num_x != num_y ) && ( !x && !y ) )ans = 1;

        if ( ans || c )printf("no\n");
        else printf("yes\n");
    }
    return 0;
}
