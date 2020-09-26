#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(1e4+7)
#define ll long long int
int  cases , n , m , t , a , b , c , d , e , f , g , i , j , k , q , pos;
int knightx[] = {-2,-2,-1,1,-1,1,2,2};
int knighty[] = {1,-1,-2,-2,2,2,-1,1};
int dx[] = {+0,+0,+1,-1,-1,+1,-1,+1};
int dy[] = {-1,+1,+0,+0,+1,+1,-1,-1};
int fx[] = {+1,-1,+0,+0};
int fy[] = {+0,+0,+1,-1};
//bool check( int xx , int yy ){return !( xx < 0 || yy < 0 || xx == n || yy == m );}
//int ar [ mxs ] ;
void fastscan(int &number)
{
    register int c;
    number = 0;
    c = getchar();
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
}
bool visited [ 60 ];
string s [ 60 ], s2 , s3;
void brainfuck();
map < char , int > mp;
int finder( int xx );
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //mp [ 'A' ] = mp [ '2' ] = mp [ '6' ] = mp [ 'T' ]  = 3;
    //mp [ '4' ] = mp [ '5' ] = mp [ '9' ] = mp [ 'J' ] = mp [ 'K' ] = 4;
    //mp [ '3' ] = mp [ '7' ] = mp [ '8' ] = mp [ 'Q' ] = 5;
    while( cin>>n && n )brainfuck();
    return 0;
}
void brainfuck( )
{
    pos = 0;
    memset( visited, 0 , sizeof visited );
    for ( j = 1; j <= n; j++ )
    {
        cin>>s2>>s3;
        e = finder( /*mp [ s2 [ 0 ] ]*/s3.size() );
        //cout<<e<<endl;
        s [ e ] = s2;
    }
    for ( i = 1; i <= n; i++ )
    {
        if( i != 1 )cout<<" ";
        cout<<s [ i ];
    }
    if(n)cout<<"\n";
}
int finder( int xx )
{
    while ( xx-- )
    {
        b = 0;
        for ( i = pos + 1; i <= n; i++ )
        {
            if ( !visited [ i ] )
            {
                b = 1;
                pos = i;
                break;
            }
        }
        if ( !b )
        {
            for ( i = 1; i <= n; i++ )
            {
                if ( !visited [ i ] )
                {
                    pos = i;
                    break;
                }
            }
        }
    }
    visited [ pos ] = 1;
    return pos;
}
