#include<bits/stdc++.h>
using namespace std;
int n, m, a, b, c;
int ar [ 20 ];
bool vis [ 20 ];
bool status [ 40 ];
void back_ ( int in );
int main()
{
    status [ 2 ] = status [ 3 ] = status [ 5 ] = status [ 7 ] = status [ 11 ] = status [ 13 ] = status [ 17 ] = status [ 19 ] = status [ 23 ] = status [ 29 ] = status [ 31 ] = status [ 37 ] = 1;
    while(scanf("%d",&n) == 1 )
    {
        if ( a )putchar( 10 );
        ar [ 1 ] = 1;
        printf("Case %d:\n",++a);
        back_( 2 );
        //putchar(10);
    }
    return 0;
}
void back_ ( int in )
{
    if ( in > n )
    {
        for ( int i = 1 ; i <= n; i++ )
        {
            if ( i != 1 )
                putchar( 32 );
            printf("%d",ar [ i ] );
        }
        putchar( 10 );
        return;
    }
    for ( int i = 2 ; i <= n ; i++ )
        if ( !vis [ i ] && status [ i + ar [ in - 1 ] ] )
        {
            if ( in == n && !status [ i + 1 ] )
                continue;
            vis [ i ] = 1;
            ar [ in ] = i;
            back_( in + 1 );
            vis [ i ] = 0;
        }
}


