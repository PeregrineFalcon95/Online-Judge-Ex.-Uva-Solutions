#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(2e5+7)
#define ll long long int
int  n , m , t , a , b , c , d , e , f , i , j , k , q , row , col ;
int grid [ 10 ] [ 10 ];
int dx[]={+1,-1,+0,+0};
int dy[]={+0,+0,+1,-1};
bool move_();
bool allowed();
bool cont();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while ( cin>>k>>q>>d )
    {
        memset( grid , 0 , sizeof grid );
        if ( k == q )
        {
            cout<<"Illegal state\n";
            continue;
        }
        if ( q == d || move_() )
        {
            cout<<"Illegal move\n";
            continue;
        }
        if ( allowed() )
        {
            cout<<"Move not allowed\n";
            continue;
        }
        if ( cont() )
        {
            cout<<"Continue\n";
            continue;
        }
        cout<<"Stop\n";
    }
    return 0;
}
bool move_()
{
    grid [ k % 8 ] [ k / 8 ] = 1;
    a = q % 8;
    b = q / 8;
    row = d % 8;
    col = d / 8;
    while ( a > 0 )
    {
        a--;
        if ( grid [ a ] [ b ] == 1 ) break;
        if ( a == row && b == col )return 0;
    }
    a = q % 8;
    while ( a < 7 )
    {
        a++;
        if ( grid [ a ] [ b ] == 1 )break;
        if ( a == row && b == col )return 0;
    }
    a = q % 8;
    while ( b > 0 )
    {
        b--;
        if ( grid [ a ] [ b ] == 1 )break;
        if ( a == row && b == col )return 0;
    }
    b = q / 8;
    while ( b < 7 )
    {
        b++;
        if ( grid [ a ] [ b ] == 1 )break;
        if ( a == row && b == col )return 0;
    }
    return 1;
}
bool allowed()
{
    a = k % 8;
    b = k / 8;
    for ( i = 0; i != 4; i++ )
    {
        e = dx [ i ] + a;
        f = dy [ i ] + b;
        //cout<<e<<"  "<<f<<"  "<<row<<"  "<<col<<endl;
        if ( row == e && col == f )return 1;
    }
    return 0;
}
bool cont()
{
    a = row;
    b = col;
    while ( a > 0 )
    {
        a--;
        grid [ a ] [ b ] = 2;
    }
    a = row;
    while ( a < 7 )
    {
        a++;
        grid [ a ] [ b ] = 2;
    }
    a = row;
    while ( b > 0 )
    {
        b--;
        grid [ a ] [ b ] = 2;
    }
    b = col;
    while ( b < 7 )
    {
        b++;
        grid [ a ] [ b ] = 2;
    }

    a = k % 8;
    b = k / 8;
    for ( i = 0; i != 4; i++ )
    {
        e = dx [ i ] + a;
        f = dy [ i ] + b;
        if ( e < 0 || e > 7 || f < 0 || f > 7 )continue;
        if ( grid [ e ] [ f ] != 2 )return 1;
    }
    return 0;
}
