#include<bits/stdc++.h>
using namespace std;
char ch [ 15 ] , temp [ 15 ];
bool visited [ 15 ];
int n , m , t , ans  , j ;
long long int a;
void backtrack ( int idx );
int main()
{
    scanf("%d",&t);
    while ( t-- )
    {
        memset ( visited , 0 , sizeof visited );
        scanf("%s %d",&ch,&m);
        n = strlen( ch );
        sort(ch, ch + n );
        ans = 0;
        backtrack ( 0 );
        printf("%d\n",ans);
    }
    return 0;
}
void backtrack ( int idx )
{
    if ( idx == n )
    {
        a = 0;
        temp [ n ] = 0;
        for ( j = 0; j != n; j++ )
        {
            a *= 10;
            a += ( temp [ j ] - '0' );
        }
        if ( a % m == 0 )ans++;
        return ;
    }
    bool vis [ 10 ];
    memset ( vis, 0 , sizeof vis );
    for ( int i = 0; i != n; i++ )
    {
        if ( !visited [ i ] && !vis [ ch [ i ] - '0' ] )
        {
            vis [ ch [ i ] - '0' ] = 1;
            visited [ i ] = 1;
            temp [ idx ] = ch [ i ];
            backtrack( idx + 1 );
            visited [ i ] = 0;
        }
    }
}




/*#include<bits/stdc++.h>
using namespace std;
char ch [ 15 ] , temp [ 15 ];
string x;
bool visited [ 15 ];
int n , m , t , ans  , j ;
long long int a;
int main()
{
    scanf("%d",&t);
    while ( t-- )
    {
        memset ( visited , 0 , sizeof visited );
        scanf("%s %d",&ch,&m);
        n = strlen( ch );
        sort(ch, ch + n );
        ans = 0;
        a = 0;
        ch [ n ] = 0;
        for ( j = 0; j != n; j++ )
        {
            a *= 10;
            a += ( ch [ j ] - '0' );
        }
        if ( a % m == 0 )ans++;
        for ( j = 0; j != n; j++ )temp [ j ] = ch [ j ] ;
        while ( next_permutation( ch , ch + n ) == 1 )
        {
            a = 0;
            ch [ n ] = 0;
            for ( j = 0; j != n; j++ )
            {
                a *= 10;
                a += ( ch [ j ] - '0' );
            }
            if ( a % m == 0 )
            {
                for ( j = 0; j != n; j++ )
                    if ( ch [ j ] != temp [ j ] )
                    {
                        ans++;
                        break;
                    }
            }
            for ( j = 0; j != n; j++ )temp [ j ] = ch [ j ] ;
        }
        printf("%d\n",ans);
    }
    return 0;
}
*/
