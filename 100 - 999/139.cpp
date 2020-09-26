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
int ar [ mxs ] ;
void fastscan(int &number)
{
    register int c;
    number = 0;
    c = getchar();
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
}
char ans [ 100 ];
string s , s2 , s3 , num , name;
double xx , yy , zz ;
deque < char > dq;
map < string , pair < string , double > > mp;
void brainfuck();
void make_it();
void local();
void idd();
void sdd();
void string_maker();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while( getline(cin,s ) )
    {
        a = 0;
        for ( i = 0; i != s.size(); i++ )
        {
            if ( s [ i ] != '0' )break;
            else a++;
        }
        if ( a == 6 )break;
        make_it();
    }
    while(cin>>s && s != "#" )brainfuck();
    return 0;
}
void brainfuck( )
{
    s2 = s3 = num = name = "";
    dq.clear();
    xx = yy = zz = 0.00;
    a = c = 0;
    cin>>xx;
    b = ( int )xx;
    n = s.size();
    if( s.size() > 2 && s [ 0 ] == '0' && s [ 1 ] == '0' )idd();
    else if ( s [ 0 ] == '0' )sdd();
    else local();
    string_maker();
}
void make_it()
{
    n = s.size();
    s2 = "";
    for ( i = 0; s [ i ] != ' ' && i < n ; i++ )s2 += s [ i ];
    while( s [ i ] == ' ' )i++;
    s3 = "";
    for ( ; s [ i ] != '$' ; i++ )s3 += s [ i ];
    xx = 0.00;
    for ( i++; i < n; i++ )
        if ( s [ i ] >= '0' && s [ i ] <= '9' )xx *= 10.00,xx += s [ i ] - '0';
    mp [ s2 ] = { s3 , xx };
}
void local()
{
    yy = zz = 0.00;
    num = s;
    name = "Local";
}
void idd()
{
    i = 0;
    s2 = "";
    while ( 1 )
    {
        if ( i >= n - 1  )
        {
            c = -1;
            name = "Unknown";
            break;
        }
        s2 += s [ i++ ];
        if ( mp.find( s2 ) != mp.end() )
        {
            zz = mp [ s2 ].second;
            name = mp [ s2 ].first;
            num = "";
            f = i;
            for ( ; i < n; i++ )if ( s [ i ] >= '0' && s [ i ] <= '9' )num += s [ i ];
            if ( num.size() > 10 )
            {
                i = f;
                num = "";
                continue;
            }
            yy = ( double )xx * zz;
            break;
        }
    }
    if (  num.size() < 4 )
    {
        c = -1;
        name = "Unknown";
    }
}
void sdd()
{
    i = 0;
    s2 = "";
    while ( 1 )
    {
        if ( i == n - 1 )
        {
            c = -1;
            name = "Unknown";
            break;
        }
        s2 += s [ i++ ];
        if ( mp.find( s2 ) != mp.end() )
        {
            zz = mp [ s2 ].second;
            name = mp [ s2 ].first;
            num = "";
            f = i;
            for ( ; i < n; i++ )if ( s [ i ] >= '0' && s [ i ] <= '9' )num += s [ i ];
            if ( num.size() > 7 )
            {
                i = f;
                num = "";
                continue;
            }
            yy = ( double )xx * zz;
            break;
        }
    }
    if (  num.size() < 4 )
        {
            c = -1;
            name = "Unknown";
        }
}
void string_maker()
{
    memset( ans, ' ' , sizeof ans );
    for ( i = 1; i <= n; i++ )ans [ i ] = s [ i - 1 ];
    n = name.size();
    d = 17;
    for ( i = 0; i != n; i++ )ans [ d++ ] = name [ i ];
    dq.clear();
    while ( b )
    {
        dq.push_back( b % 10 + '0' );
        b /= 10;
    }
    d = 56;
    while ( !dq.empty() )
    {
        ans [ d-- ] = dq.front();
        dq.pop_front();
    }
    if ( c == -1 )
    {
        ans [ 65 ] = '-';
        ans [ 66 ] = '1';
        ans [ 67 ] = '.';
        ans [ 68 ] = ans [ 69 ] = '0';
    }
    else
    {
        dq.clear();
        n = num.size();
        for ( i = n - 1; i >= 0; i-- )dq.push_back( num [ i ] );
        d = 51;
        while ( !dq.empty() )
        {
            ans [ d-- ] = dq.front();
            dq.pop_front();
        }
        b = (int)zz;
        e = 0;
        while ( b )
        {
            dq.push_back( b % 10 + '0' );
            b /= 10;
            e++;
            if ( e == 2 )dq.push_back( '.' );
        }
        if( !e )
        {
            dq.push_back( '0' );
            dq.push_back( '0' );
            dq.push_back( '.' );
            dq.push_back( '0' );
        }
        else if ( e == 1 )
        {
            dq.push_back( '0' );
            dq.push_back( '.' );
            dq.push_back( '0' );
        }
        else if ( e == 2 )dq.push_back( '0' );
        d = 62;
        while ( !dq.empty() )
        {
            ans [ d-- ] = dq.front();
            dq.pop_front();
        }

        b = (int)yy;
        e = 0;
        while ( b )
        {
            dq.push_back( b % 10 + '0' );
            b /= 10;
            e++;
            if ( e == 2 )dq.push_back( '.' );
        }
        if( !e )
        {
            dq.push_back( '0' );
            dq.push_back( '0' );
            dq.push_back( '.' );
            dq.push_back( '0' );
        }
        else if ( e == 1 )
        {
            dq.push_back( '0' );
            dq.push_back( '.' );
            dq.push_back( '0' );
        }
        else if ( e == 2 )dq.push_back( '0' );
        d = 69;
        while ( !dq.empty() )
        {
            ans [ d-- ] = dq.front();
            dq.pop_front();
        }
    }
    for ( i = 1; i <= 69; i++ )cout<<ans [ i ];
    cout<<"\n";
}
