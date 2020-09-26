/*#include<bits/stdc++.h>
using namespace std;
#define inf 999999
double o_o;
int n , m , a , b , c , i , j , lol , ans;
int mp [ 8 ] , marker [ 1001 ] ;
int ar [ ] = { 0 , 5 , 10 , 20 , 50 , 100 , 200 };
int dp [ 8 ] [ 502 ] , mark [ 1001 ] , dp2 [ 8 ] [ 1001 ] [ 102 ];
int calculation( int idx , int amount );
int coin( int idx , int amount , int have );
int main()
{
    //freopen ("output.txt","w",stdout);
    memset(dp , -1 , sizeof dp );
    marker [ 500 ] = calculation( 1, 500 );
    while(scanf("%d%d%d%d%d%d",&mp[ 1 ],&mp[ 2 ],&mp[ 3 ],&mp[ 4 ],&mp[ 5 ],&mp[ 6 ] ) == 6 && ( mp [ 1 ]||mp [ 2 ]||mp[ 3 ]||mp[ 4 ]||mp[ 5 ]||mp [ 6 ] ) )
    {
        memset( dp2 , -1, sizeof dp2 );
        scanf("%lf",&o_o);
        lol = ( int ) ( ( double )(o_o * 100.00) + 0.001 );
        ans = inf;
        mark [ 0 ] = inf;
        for ( i = 5; i <= 500; i+= 5 )mark [ i ] = inf;
        a = coin( 1 , lol , min(mp [ 1 ] , 102 ) );
        //cout<<lol<<endl;
        printf("%3d\n",a);
    }
    return 0;
}
int calculation( int idx , int amount )
{
    if ( idx > 6 || amount <= 0 )
    {
        if ( !amount )return 0;
        return inf;
    }
    if ( dp [ idx ] [ amount ] != -1 )return dp [ idx ] [ amount ];
    int x = inf, y ;
    if ( amount - ar [ idx ] > 0 )x = calculation( idx , amount - ar [ idx ] ) + 1;
    else if ( amount - ar [ idx ] == 0 )x = 1;
    y = calculation( idx + 1 , amount );
    marker [ amount ] = min( x , y );
    return ( dp [ idx ] [ amount ] = min( x , y ) );
}
int coin( int idx , int amount , int have )
{
    if ( idx > 6 || amount <= 0 )
    {
        if ( !amount )return 0;
        if ( amount < 0 )return ( marker [ -amount ] );
        return inf;
    }
    if ( dp2 [ idx ] [ amount ] [ have ] != -1 )return dp2 [ idx ] [ amount ] [ have ];
    int x = inf , y;
    if ( have ) x = coin( idx , amount - ar [ idx ] , min( have - 1 , 102 ) ) + 1;
    y = coin( idx + 1 , amount , min( mp [ idx + 1 ] , 102 ) );
    return ( dp2 [ idx ] [ amount ] [ have ] = min( x , y ) );
}*/
#include<bits/stdc++.h>
using namespace std;
#define inf 999999
double o_o;
int n , m , a , b , c , i , j , lol , ans;
int mp [ 8 ] , marker [ 1001 ] ;
int ar [ ] = { 0 , 5 , 10 , 20 , 50 , 100 , 200 };
int dp [ 8 ] [ 502 ] , mark [ 1001 ] , dp2 [ 8 ] [ 1001 ] [ 102 ];
int calculation( int idx , int amount );
int coin( int idx , int amount , int have );
int main()
{
    //freopen ("output.txt","w",stdout);
    memset(dp , -1 , sizeof dp );
    marker [ 500 ] = calculation( 1, 500 );
    while(scanf("%d%d%d%d%d%d",&mp[ 1 ],&mp[ 2 ],&mp[ 3 ],&mp[ 4 ],&mp[ 5 ],&mp[ 6 ] ) == 6 && ( mp [ 1 ]||mp [ 2 ]||mp[ 3 ]||mp[ 4 ]||mp[ 5 ]||mp [ 6 ] ) )
    {
        memset( dp2 , -1, sizeof dp2 );
        scanf("%lf",&o_o);
        lol = ( int ) ( ( double )(o_o * 100.00) + 0.001 );
        ans = inf;
        mark [ 0 ] = inf;
        for ( i = 5; i <= 500; i+= 5 )mark [ i ] = inf;
        for ( i = lol; i <= 1000; i += 5 )
        {
            memset( dp2 , -1, sizeof dp2 );
            mark [ i ] = coin( 1 , i , min(mp [ 1 ] , 102 ) );
            //cout<<"i = "<<i<<" "<<"mar = "<<mark[i]<<endl;
            if(mark[i] >= inf) continue;
            a = mark [ i ] + marker [ i - lol ];
            //cout<<mark [ i ]<<"   "<<i<<endl;
            ans = min( ans , a );
        }
        //cout<<lol<<endl;
        printf("%3d\n",ans);
    }
    return 0;
}
int calculation( int idx , int amount )
{
    if ( idx > 6 || amount <= 0 )
    {
        if ( !amount )return 0;
        return inf;
    }
    if ( dp [ idx ] [ amount ] != -1 )return dp [ idx ] [ amount ];
    int x = inf, y ;
    if ( amount - ar [ idx ] > 0 )x = calculation( idx , amount - ar [ idx ] ) + 1;
    else if ( amount - ar [ idx ] == 0 )x = 1;
    y = calculation( idx + 1 , amount );
    marker [ amount ] = min( x , y );
    return ( dp [ idx ] [ amount ] = min( x , y ) );
}
int coin( int idx , int amount , int have )
{
    if ( idx > 6 || amount <= 0 )
    {
        if ( !amount )return 0;
        return inf;
    }
    if ( dp2 [ idx ] [ amount ] [ have ] != -1 )return dp2 [ idx ] [ amount ] [ have ];
    int x = inf , y;
    if ( have && amount - ar [ idx ] > 0 ) x = coin( idx , amount - ar [ idx ] , min( have - 1 , 102 ) ) + 1;
    else if ( have && !(amount - ar [ idx ] ) ) x = 1;
    y = coin( idx + 1 , amount , min( mp [ idx + 1 ] , 102 ) );
    return ( dp2 [ idx ] [ amount ] [ have ] = min( x , y ) );
}
