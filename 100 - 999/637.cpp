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
void brainfuck( );
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while ( cin>>n && n )brainfuck();
    return 0;
}
void brainfuck( )
{
    cout<<"Printing order for "<<n<<" pages:\n";
    memset( marker , 0 , sizeof marker );
    for ( i = 1; i <= n; i++ )marker [ i ] = 1;
    int xx = 1;
    if ( !(n%4) )a = n;
    else a = ( n + 4 ) - ( ( n + 4 ) %4 );
    b = 1;
    while ( a > b )
    {
        //cout<<a<<"  "<<b<<endl;
        if ( xx == 1 )
        {
            qu.push( a );
            qu.push( b );
            b++;
            a--;
            xx = 2;
        }
        else
        {
            qu.push( b );
            qu.push( a );
            a--;
            b++;
            xx = 1;
        }
    }
    xx = 1;
    c = 1;
    while ( !qu.empty() )
    {
        a = qu.front();
        qu.pop();
        b = qu.front();
        qu.pop();
        if ( xx == 1 )
        {
            xx = 2;
            if ( marker [ a ] && marker [ b ] )cout<<"Sheet "<<c<<", front: "<<a<<", "<<b<<"\n";
            else if ( marker [ a ] && !marker [ b ] )cout<<"Sheet "<<c<<", front: "<<a<<", Blank"<<"\n";
            else if ( !marker [ a ] && marker [ b ] )cout<<"Sheet "<<c<<", front: Blank, "<<b<<"\n";
        }
        else
        {
            xx = 1;
            if ( marker [ a ] && marker [ b ] )cout<<"Sheet "<<c<<", back : "<<a<<", "<<b<<"\n";
            else if ( marker [ a ] && !marker [ b ] )cout<<"Sheet "<<c<<", back : "<<a<<", Blank"<<"\n";
            else if ( !marker [ a ] && marker [ b ] )cout<<"Sheet "<<c<<", back : Blank, "<<b<<"\n";
            c++;
        }
    }
}
