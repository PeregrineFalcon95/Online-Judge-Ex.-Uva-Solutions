#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(1e5+7)
#define ll long long int
int  cases , n , m , t , a , b , c , d , e , f , g , i , j , k , q ;
char grid [ 100 ] [ 200 ] ;
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
string s , s2 , s3 ;
map < string , int > mp;
map < int , string > mp2;
int ar [ 22 ];
void brainfuck( );
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while( cin>>n>>m && n )brainfuck();
    return 0;
}
void brainfuck( )
{
    memset( ar , 0 , sizeof ar );
    mp.clear();
    mp2.clear();
    for ( i = 1; i <= n; i++ )
    {
        cin>>s;
        mp [ s ] = i;
        mp2 [ i ] = s;
    }
    while ( m-- )
    {
        cin>>s>>s2>>a;
        b = mp [ s ];
        c = mp [ s2 ];
        ar [ b ] -= a;
        ar [ c ] += a;
    }
    cout<<"Case #"<<++cases<<"\n";
    s = mp2 [ n ];
    for ( i = 1; i < n; i++ )
    {
        s2 = mp2 [ i ];
        ar [ n ] += ar [ i ];
        if ( ar [ i ] > 0 )cout<<s2<<" "<<s<<" "<<ar [ i ]<<"\n";
        else cout<<s<<" "<<s2<<" "<<abs(ar [ i ])<<"\n";
    }
    cout<<"\n";
}
