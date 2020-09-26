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
    cin>>t;
    cin.ignore();
    while ( t-- ){brainfuck();}
    return 0;
}
void brainfuck( )
{
    getline( cin , s );
    double xx , yy ;
    n = s.size();
    a = 0;
    xx = yy = 0.0000;
    for ( i = 0; i != n; i++ )
    {
        if ( s [ i ] >= '0' && s [ i ] <= '9' )
        {
            if ( !a )
            {
                xx *= 10.00;
                xx += ( double )( s [ i ] - '0' );
            }
            else if( s [ i ] >= '0' && s [ i ] <= '9' )
            {
                yy *= 10.00;
                yy += ( double )( s [ i ] - '0' );
            }
        }
        else if( xx )a = 1;
    }
    xx *= 0.500000;
    if ( yy )xx += ( yy * 0.05000 );
    cout<<"Case "<<++cases<<": "<<xx<<"\n";
}

