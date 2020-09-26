#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(1e5+7)
#define ll long long int
int  cases , n , m , t , a , b , c , d , e , f , i , j , k , q , sum;
char grid [ 110 ] [ 110 ] ;
int knightx[] = {-2,-2,-1,1,-1,1,2,2};
int knighty[] = {1,-1,-2,-2,2,2,-1,1};
int dx[] = {+0,+0,+1,-1,-1,+1,-1,+1};
int dy[] = {-1,+1,+0,+0,+1,+1,-1,-1};
int fx[] = {+1,-1,+0,+0};
int fy[] = {+0,+0,+1,-1};
//bool check( int xx , int yy ){return !( xx < 0 || yy < 0 || xx == n || yy == m );}
int ar [ mxs ] ;
bool marker [ 110 ];
void fastscan(int &number)
{
    register int c;
    number = 0;
    c = getchar();
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
}
string s , s2 , s3;
queue < int > qu;
map < char , double > mp;
void brainfuck( );
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mp [ 'W' ] = 1.00000000;
    mp [ 'H' ] = 0.50000000;
    mp [ 'Q' ] = 0.25000000;
    mp [ 'E' ] = 0.12500000;
    mp [ 'T' ] = 0.03125000;
    mp [ 'X' ] = 0.01562500;
    mp [ 'S' ] = 0.06250000;
    while ( cin>>s && s != "*" )
    {
        brainfuck();
    }
    return 0;
}
void brainfuck( )
{
    a = c = 0;
    n = s.size();
    double xx  = 0.00;
    for ( i = 0; i != n; i++ )
    {
        if ( s [ i ] == '/' && i )
        {
            //cout<<xx<<"  lol "<<s [ i - 1 ]<<"  "<<i<<endl;
            if ( xx == 1.00000000000000000000 )c++;
            xx = 0.00;
        }
        else xx += mp [ s [ i ] ];
    }
    cout<<c<<"\n";
}
