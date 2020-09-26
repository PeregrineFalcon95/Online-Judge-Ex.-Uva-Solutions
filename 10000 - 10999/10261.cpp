#include<bits/stdc++.h>
using namespace std;
int n , m , a , b , c , t , e , len , mx , ans;
int ar [ 11000 ] , dp [ 2 ] [ 202 ] [ 10002 ];
int select ( int idx , int port , int star );
void printer( int idx , int port , int star );
int main()
{
    scanf("%d",&t);
    while ( t-- )
    {
        if ( e )putchar(10);
        e++;
        scanf("%d",&len);
        len *= 100;
        n = 0;
        while ( scanf("%d",&ar [ ++n ] ) == 1 && ar [ n ] );
        n--;
        memset( dp , -1 , sizeof dp );
        ans = select( 1 , 0 , 0 );
        printf("%d\n",ans);
        printer( 1 , 0 , 0 );
    }
    return 0;
}
int select ( int idx , int port , int star )
{
    if ( idx > n  || idx > 200 )return (idx - 1);
    if ( dp [ 0 ] [ idx ] [ port ] != -1 )return dp [ 0 ] [ idx ] [ port ];
    int x , y;
    x = y = ( idx - 1 );
    if ( port + ar [ idx ] <= len )x = select ( idx + 1 , port + ar [ idx ] , star );
    if ( star + ar [ idx ] <= len )y = select ( idx + 1 , port , star + ar [ idx ] );
    if ( x >= y )
    {
        if ( x == idx - 1 ) dp [ 0 ] [ idx ] [ port ] = x , dp [ 1 ] [ idx ] [ star ] = -1;
        else dp [ 0 ] [ idx ] [ port ] = x , dp [ 1 ] [ idx ] [ star ] = 0;
    }
    else
    {
        dp [ 0 ] [ idx ] [ port ] = y;
        dp [ 1 ] [ idx ] [ star ] = 1;
    }
    return dp [ 0 ] [ idx ] [ port ];
}
void printer( int idx , int port , int star )
{
    if ( !dp [ 1 ] [ idx ] [ star ] )
    {
        printf("port\n");
        printer ( idx + 1 , port + ar [ idx ] , star );
    }
    else if ( dp [ 1 ] [ idx ] [ star ] == 1 )
    {
        printf("starboard\n");
        printer( idx + 1 , port , star + ar [ idx ] );
    }
    else return;
}
