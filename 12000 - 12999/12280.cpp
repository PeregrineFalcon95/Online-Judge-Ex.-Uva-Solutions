///***This is the worst problem, I've ever encountered. Fuck this problem. ***/

#include<bits/stdc++.h>
using namespace std;
int i , j , k , n , m , righ , lef , ans , t , cases , flag_right , flag_left ;
char grid [ 20 ] [ 20 ] ;
char ch;
vector < char > v, v2;
int finder();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&t);
    while ( t-- )
    {
        v.clear();
        v2.clear();
        for ( i = 1; i <= 8; i++ )scanf("%s",&grid [ i ] );

        ///***This is a fucking problem***///
        int fil = 0, fir = 0;
        for ( i = 1; i < 8; i++ )
            for ( j = 0; j != 18; j++ )
            {
                if ( !fil && grid [ i ] [ j ] == '/' && j < 7 )fil = i;
                if ( ! fir && grid [ i ] [ j ] == '/' && j > 10 )fir = i;
            }


        ///***Searching in the left ***///
        for ( i = 0; i <= 7; i++ )if ( grid [ 4 ] [ i ] >= 'A' && grid [ 4 ] [ i ] <= 'Z' )flag_left = 4;
        for ( i = 0; i <= 7; i++ )if ( grid [ 5 ] [ i ] >= 'A' && grid [ 5 ] [ i ] <= 'Z' )flag_left = 5;
        for ( i = 0; i <= 7; i++ )if ( grid [ 6 ] [ i ] >= 'A' && grid [ 6 ] [ i ] <= 'Z' )flag_left = 6;

        ///***Searching in the right ***///
        for ( i = 10; i <= 17; i++ )if ( grid [ 4 ] [ i ] >= 'A' && grid [ 4 ] [ i ] <= 'Z' )flag_right = 4;
        for ( i = 10; i <= 17; i++ )if ( grid [ 5 ] [ i ] >= 'A' && grid [ 5 ] [ i ] <= 'Z' )flag_right = 5;
        for ( i = 10; i <= 17; i++ )if ( grid [ 6 ] [ i ] >= 'A' && grid [ 6 ] [ i ] <= 'Z' )flag_right = 6;

        for ( i = 0; i <= 7; i++ )if ( grid [ flag_left ] [ i ] >= 'A' && grid [ flag_left ] [ i ] <= 'Z' )v.push_back( grid [ flag_left ] [ i ] );
        for ( i = 10; i <= 17; i++ )if ( grid [ flag_right ] [ i ] >= 'A' && grid [ flag_right ] [ i ] <= 'Z' )v2.push_back(  grid [ flag_right ] [ i ] );

        lef = righ = 0;
        for ( i = 0; i != v.size(); i++ )
        {
            ch = v [ i ];
            lef += finder();
        }
        for ( i = 0; i != v2.size(); i++ )
        {
            ch = v2 [ i ];
            righ += finder();
        }
        if ( !v.size() )flag_left = 0;
        if ( !v2.size() )flag_right = 0;
        printf("Case %d:\n",++cases);
        if ( ( flag_left || flag_right ) && ( ( lef > righ && ( ( flag_right && flag_right  < flag_left ) || ( !flag_right && fil > fir ) ) ) || ( lef < righ && ( ( flag_left && flag_right > flag_left ) || ( !flag_left && fil < fir ) ) ) || ( lef == righ && flag_right == flag_left ) ) )printf("The figure is correct.\n");
        else if ( !flag_left && !flag_right && fil == fir )printf("The figure is correct.\n");
        else
        {
            while(v.size() != 6 )v.push_back( '.' );
            while (v2.size() != 6 )v2.push_back( '.' );
            if ( lef > righ )
            {
                printf("........||.../");putchar(92);printf("...");putchar(10);
                printf("........||../..");putchar(92);printf("..");putchar(10);
                printf(".../");putchar(92);printf("...||./....");putchar(92);printf(".");putchar(10);
                printf("../..");putchar(92);printf("..||/%c%c%c%c%c%c",v2 [ 0 ] , v2 [ 1 ] , v2 [ 2 ] , v2 [ 3 ] , v2 [ 4 ] , v2 [ 5 ]);putchar( 92 );putchar(10);
                printf("./....");putchar(92);printf(".||");putchar(92);printf("______/");putchar(10);
                printf("/%c%c%c%c%c%c",v [ 0 ] , v [ 1 ] , v [ 2 ] , v [ 3 ] , v [ 4 ] , v [ 5 ]);putchar(92);printf("||........");putchar(10);
                putchar(92);printf("______/||........");putchar(10);
            }
            else if ( lef < righ )
            {
                printf(".../");putchar(92);printf("...||........");putchar(10);
                printf("../..");putchar(92);printf("..||........");putchar(10);
                printf("./....");putchar(92);printf(".||.../");putchar(92);printf("...");putchar(10);
                printf("/%c%c%c%c%c%c",v [ 0 ] , v [ 1 ] , v [ 2 ] , v [ 3 ] , v [ 4 ] , v [ 5 ]);putchar(92);printf("||../..");putchar(92);printf("..");putchar(10);
                putchar(92);printf("______/||./....");putchar(92);printf(".");putchar(10);
                printf("........||/%c%c%c%c%c%c",v2 [ 0 ] , v2 [ 1 ] , v2 [ 2 ] , v2 [ 3 ] , v2 [ 4 ] , v2 [ 5 ]);putchar(92);putchar(10);
                printf("........||");putchar(92);printf("______/");putchar(10);
            }
            else
            {
                printf("........||........");putchar(10);
                printf(".../");putchar(92);printf("...||.../");putchar(92);printf("...");putchar(10);
                printf("../..");putchar(92);printf("..||../..");putchar(92);printf("..");putchar(10);
                printf("./....");putchar(92);printf(".||./....");putchar(92);printf(".");putchar(10);
                printf("/%c%c%c%c%c%c",v [ 0 ] , v [ 1 ] , v [ 2 ] , v [ 3 ] , v [ 4 ] , v [ 5 ]);putchar(92);printf("||/%c%c%c%c%c%c",v2 [ 0 ] , v2 [ 1 ] , v2 [ 2 ] , v2 [ 3 ] , v2 [ 4 ] , v2 [ 5 ]);putchar(92);putchar(10);
                putchar(92);printf("______/||");putchar(92);printf("______/");putchar(10);
                printf("........||........");putchar(10);
            }
        }
    }
    return 0;
}
int finder()
{
    n = 0;
    m = ( int )ch;
    while ( m )
    {
        if ( m % 2 )n += 500;
        else n += 250;
        m /= 2;
    }
    return n;
}


