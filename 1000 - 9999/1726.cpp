#include<bits/stdc++.h>
using namespace std;
char ch,ch2;
int i , j  , num , a , b , c;
void fastscan(int &number)
{
    bool negative = false;
    register int c;
    number = 0;
    c = getchar_unlocked();
    for (; (c>47 && c<58); c=getchar_unlocked())
        number = number *10 + c - 48;
}

void fastscan2(register int &number)
{
    register int c;
    number = 0;
    c = getchar();
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
    ch = getchar();
    ch2 = getchar();
}
int main()
{
    int t;
int leaked [ 11 ],not_leaked[ 11 ];
    fastscan(t);
    while( t-- )
    {
        num ;
        fastscan(num);
for ( int i = 0; i != 11 ;i++ ){ leaked [ i ] = 0; not_leaked [ i ] = 0; } 
        for ( i = 0; i != num; i++ )
        {
            a,b,c;
            while(1){fastscan(a);if(a)break;}
            fastscan2(b);
            if ( ch == 'i' && !b )
            {
                not_leaked [ a ]++;
            }
            else if ( ch == 'c' && b )
            {
                leaked [ a ]++;
            }
        }
        int ans = 0;
        for ( i = 1; i <=10; i++ )
        {
            for ( j = i+1; j <= 10; j++ )
            {
                ans+=( leaked[ j ] * not_leaked[ i ] );
            }
        }
        printf("%d",ans);
        putchar ( 10 );
    }
    return 0;
}
