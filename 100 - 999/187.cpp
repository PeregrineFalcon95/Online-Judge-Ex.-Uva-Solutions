#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(1e5+7)
#define ll long long int
ll  cases , n , m , t , a , b , c , d , e , f , i , j , k , q , sum;
char grid [ 110 ] [ 110 ] ;
int knightx[] = {-2,-2,-1,1,-1,1,2,2};
int knighty[] = {1,-1,-2,-2,2,2,-1,1};
int dx[] = {+0,+0,+1,-1,-1,+1,-1,+1};
int dy[] = {-1,+1,+0,+0,+1,+1,-1,-1};
int fx[] = {+1,-1,+0,+0};
int fy[] = {+0,+0,+1,-1};
//bool check( int xx , int yy ){return !( xx < 0 || yy < 0 || xx == n || yy == m );}
int ar [ mxs ] ;
void fastscan(int &number)
{
    register int c;
    number = 0;
    c = getchar();
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
}
string s , s2 , s3;
deque < pair < ll , ll > > dq;
deque < ll > marker;
map < ll , string > mp;
void brainfuck();
void cal();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    while ( getline( cin , s ) )
    {
        if ( s [ 0 ] == '0' && s [ 1 ] == '0' && s [ 2 ] == '0' )break;
        a = 0;
        a += s [ 0 ] - '0';
        a *= 10;
        a += s [ 1 ] - '0';
        a *= 10;
        a += s [ 2 ] - '0';
        s2 = "";
        n = s.size();
        for ( i = 3; i < n; i++ )s2 += s [ i ];
        mp [ a ] = s2;
    }
    while ( cin>>s>>c )
    {
        if ( s [ 0 ] == '0' && s [ 1 ] == '0' && s [ 2 ] == '0' )break;
        a = 0;
        a += s [ 0 ] - '0';
        a *= 10;
        a += s [ 1 ] - '0';
        a *= 10;
        a += s [ 2 ] - '0';
        marker.push_back( a );
        b = 0;
        b += s [ 3 ] - '0';
        b *= 10;
        b += s [ 4 ] - '0';
        b *= 10;
        b += s [ 5 ] - '0';
        dq.push_back( { b , c } );
    }
    brainfuck();
    return 0;
}
void brainfuck( )
{
    while ( !marker.empty() )
    {
        b = 1;
        a = marker.front();
        marker.pop_front();
        while ( !marker.empty() && marker.front() == a )
        {
            //cout<<a<<endl;
            b++;
            marker.pop_front();
        }
        cal();
    }
}
void cal()
{
    c = 0;
    for ( i = 0; i != b; i++ )c += dq [ i ].second;
    //cout<<b<<"  "<< c<<"  lol\n";
    if ( !c )
    {
        while ( b-- )dq.pop_front();
        return;
    }
    printf("*** Transaction %3lld is out of balance ***\n",a);
    while( b-- )
    {
        e = dq.front().first;
        f = dq.front().second;
        dq.pop_front();
        printf("%3lld ",e);
        cout<<mp [ e ];
        q = 1 + 30 - mp [ e ].size();
        for ( i = 0; i != q; i++ )putchar( 32 );
        double xx = (double)f;
        printf("%10.2lf\n",(double)(xx/100.00));
    }
    double xx = (double)c;
    printf("999 Out of Balance                 %10.2lf\n",abs((double)(xx/100.00)));
    putchar(10);
}
