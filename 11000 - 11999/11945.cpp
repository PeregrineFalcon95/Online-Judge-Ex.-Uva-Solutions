#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(1e5+7)
#define ll long long int
ll  cases , n , m , t , a , b , c , d , e , f , i , j , k , q ;
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
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    scanf("%d",&n);
    while( n-- )brainfuck();
    return 0;
}
void brainfuck( )
{
    double sum = 0.0000 , xx;
    for ( i = 1; i <= 12; i++ )
    {
        scanf("%lf",&xx);
        sum += xx;
    }
    //cout<<sum<<endl;
    sum /= 12.00;
    //cout<<sum<<endl;
    a = ( ll ) sum;
    s = "";
    //cout<<a<<endl;
    while ( a )
    {
        s += ( ( a % 10 ) + '0' );
        a /= 10;
    }
    //cout<<s<<endl;
    a = ( ll )sum;
    xx = ( double )a;
    sum -= xx;
    printf("%d $",++cases);
    deque < char > dd;
    a = 0;
    for ( i = 0; i != s.size(); i++ )
    {
        a++;
        dd.push_back( s [ i ] );
        if ( a % 3 == 0 && i != s.size() - 1 )
        {
            dd.push_back( ',' );
            a = 0;
        }
    }
    reverse(dd.begin() , dd.end() );
    a = dd.back() - '0';
    dd.pop_back();
    //cout<<a<<endl;
    sum += ( double ) a;
    for ( i = 0; i != dd.size(); i++ )printf("%c",dd [ i ] );
    printf("%.2lf\n",sum);
}
