#include<bits/stdc++.h>
char  one [ 1001000 ] , two [ 1001000 ];
char first , second;
int num , n , t , i , a , b , c;
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
        scanf("%d",&t);
        getchar();
        while( t-- )
        {
                getchar();
                fastscan(n);

                for ( i = 0 ; i < n; i++ )
                {
                        one [ i ] = getchar();
                        getchar();
                        two [ i ] = getchar();
                        getchar();
                }

                c = 0;
                for ( i = n - 1 ; i >= 0 ; i-- )
                {
                        a = ( one [ i ]  + two [ i ] );
                        a -= 96;
                        a += c;
                        one [ i ] = ( a % 10 ) + '0';
                        a /= 10;
                        c = a;
                }

                if ( c )printf("%d",c);
                for ( i = 0 ; i < n; i++ )putchar(one [ i ] );

                putchar(10);
                if( t )putchar(10);
        }
        return 0;
}
