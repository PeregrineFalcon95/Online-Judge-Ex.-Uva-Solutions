#include<bits/stdc++.h>
using namespace std;
int dig1 [ 20 ] , dig [ 20 ] , col [ 10 ];
int k , ar[ 10 ] [ 10 ] , ans [ 10 ] , num , a ,b ,c ;
void backtrack( int idx );
int main()
{
    //freopen("output.txt","w",stdout);
    scanf("%d",&k);
    while ( k-- )
    {
        if ( c )putchar(10);
        c++;
        num = 0;
        memset(dig , 0, sizeof dig );
        memset(dig1 , 0 , sizeof dig1 );
        memset(col , 0 , sizeof col );
        printf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n");
        scanf("%d%d",&b,&a);
        dig [ a + b ] = col [ b ] = dig1 [ a + 8 - b ] = 1;
        ans [ a ] = b;
        backtrack(1);
    }
    return 0;
}
void backtrack( int idx )
{
    if ( idx == 9 )
    {
        printf("%2d      %d %d %d %d %d %d %d %d\n",++num,ans [ 1 ],ans [ 2 ],ans [ 3 ],ans [ 4 ],ans [ 5 ],ans [ 6 ],ans [ 7 ],ans [ 8 ]);
        return;
    }
    if ( idx == a )backtrack( idx + 1 );
    else
    {
        for ( int i = 1; i <= 8; i++ )
        {
            if ( col [ i ] || dig [ idx + i  ] || dig1 [ idx + 8 - i ] )continue;
            dig [ idx + i ] = col [ i ] = dig1 [ idx + 8 - i ] = 1;
            ans [ idx ] = i;
            backtrack( idx + 1 );
            dig [ idx + i ] = col [ i ] = dig1 [ idx + 8 - i ] = 0;
        }
    }
}
