#include<bits/stdc++.h>
using namespace std;
int ar [ 2 ] [ 100000 ];
vector < string > v;
string s;
int n , m , a , t , b , c , d , e , f , x , y , i , z ;
int main()
{
    //freopen ("input.txt" , "r", stdin );
    //freopen ("output.txt","w",stdout);
    scanf("%d",&t);
    z = t-1;
    while ( t-- )
    {
        if ( z != t )putchar ( 10 );
        v.clear();
        scanf("%d",&d);
        for ( i = 0 ; i < d; i++ )
        {
            cin>>s;
            scanf("%d%d",&ar[ 0 ] [ i ] ,&ar [ 1 ] [ i ] );
            v.push_back( s );
        }
        scanf("%d",&y);
        while ( y-- )
        {
            scanf("%d",&x);
            a = 0;
            for ( i = 0; i != d; i++ )
            {
                if ( x >= ar [ 0 ] [ i ] && x <= ar [ 1 ] [ i ] )
                {
                    a++;
                    s = v [ i ];
                    if ( a > 1 )break;
                }
            }
            if ( !a || a > 1 )
            {
                printf("UNDETERMINED");
            }
            else cout<<s;
            putchar ( 10 );
        }
    }
    return 0;
}
