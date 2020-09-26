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
string s , s2 , s3;
deque < double > A , B , C , D , E;
void brainfuck();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    A.push_back( 0.1000 );
    A.push_back( 0.0600 );
    A.push_back( 0.0200 );
    B.push_back( 0.2500 );
    B.push_back( 0.1500 );
    B.push_back( 0.0500 );
    C.push_back( 0.5300 );
    C.push_back( 0.3300 );
    C.push_back( 0.1300 );
    D.push_back( 0.8700 );
    D.push_back( 0.4700 );
    D.push_back( 0.1700 );
    E.push_back( 1.4400 );
    E.push_back( 0.8000 );
    E.push_back( 0.3000 );
    while( cin>>s && s != "#" )brainfuck();
    return 0;
}
void brainfuck( )
{
    double x , y , z;
    e = f = g = 0;
    x = y = z = 0.00;
    cin>>s2>>a>>b>>c>>d;
    a *= 60;
    a += b;
    b = c * 60 + d;
    //cout<<a<<"  lol "<<b<<endl;
    if ( a < b )
    {
        if ( ( a <= 480 && b >= 480 ) || ( a <= 480 && b <= 480 ) )
        {
            c = 0;
            if ( b <= 480 )
            {
                c = b - a;
                //a = b;
                //a = b = 0;
            }
            else
            {
                c = 480 - a;
                a = 480;
                //a = b;
                //a = b = 0;
            }
            if ( s == "A" )z = A [ 2 ] * ( double )c;
            else if ( s == "B" )z = B [ 2 ] * ( double )c;
            else if ( s == "C" )z = C [ 2 ] * ( double )c;
            else if ( s == "D" )z = D [ 2 ] * ( double )c;
            else if ( s == "E" )z = E [ 2 ] * ( double )c;
            g = c;
        }
        if ( a >= 480 && a <= 1080 )
        {
            c = 0;
            if ( b >= 1080 || b <= 480 )
            {
                c = 1080 - a;
                a = 1080;
            }
            else c = b - a ;
            if ( s == "A" )x = A [ 0 ] * ( double )c;
            else if ( s == "B" )x = B [ 0 ] * ( double )c;
            else if ( s == "C" )x = C [ 0 ] * ( double )c;
            else if ( s == "D" )x = D [ 0 ] * ( double )c;
            else if ( s == "E" )x = E [ 0 ] * ( double )c;
            e = c;
        }
        if ( a >= 1080 && a <= 1320 )
        {
            c = 0;
            if ( b >= 1320 || b <= 480 )
            {
                c = 1320 - a;
                a = 1320;
            }
            else c = b - a;
            if ( s == "A" )y = A [ 1 ] * ( double )c;
            else if ( s == "B" )y = B [ 1 ] * ( double )c;
            else if ( s == "C" )y = C [ 1 ] * ( double )c;
            else if ( s == "D" )y = D [ 1 ] * ( double )c;
            else if ( s == "E" )y = E [ 1 ] * ( double )c;
            f = c;
        }
        if ( a >= 1320 && a <= 1440 )
        {
            c = 0;
            if ( b <= 480 )
            {
                c = 1439 - a;
                a = 0;
            }
            else c = b - a;
            if ( s == "A" )z += A [ 2 ] * ( double )c;
            else if ( s == "B" )z += B [ 2 ] * ( double )c;
            else if ( s == "C" )z += C [ 2 ] * ( double )c;
            else if ( s == "D" )z += D [ 2 ] * ( double )c;
            else if ( s == "E" )z += E [ 2 ] * ( double )c;
            g += c;
        }
        z += ( x + y );
    }
    else
    {
        //cout<<a<<"  "<<b<<endl;
        if ( a <= 480 )
        {
            c = 480 - a;
            a = 480;
            if ( s == "A" )z = A [ 2 ] * ( double )c;
            else if ( s == "B" )z = B [ 2 ] * ( double )c;
            else if ( s == "C" )z = C [ 2 ] * ( double )c;
            else if ( s == "D" )z = D [ 2 ] * ( double )c;
            else if ( s == "E" )z = E [ 2 ] * ( double )c;
            g = c;
        }
        if ( a <= 1080 )
        {
            c = 1080 - a ;
            a = 1080;
            if ( s == "A" )x = A [ 0 ] * ( double )c;
            else if ( s == "B" )x = B [ 0 ] * ( double )c;
            else if ( s == "C" )x = C [ 0 ] * ( double )c;
            else if ( s == "D" )x = D [ 0 ] * ( double )c;
            else if ( s == "E" )x = E [ 0 ] * ( double )c;
            e = c;
        }
        if ( a <= 1320 )
        {
            c = 1320 - a;
            a = 1320;
            if ( s == "A" )y = A [ 1 ] * ( double )c;
            else if ( s == "B" )y = B [ 1 ] * ( double )c;
            else if ( s == "C" )y = C [ 1 ] * ( double )c;
            else if ( s == "D" )y = D [ 1 ] * ( double )c;
            else if ( s == "E" )y = E [ 1 ] * ( double )c;
            f = c;
        }
        if ( a <= 1440 )
        {
            c = 1440 - a;
            a = 0;
            if ( s == "A" )z += A [ 2 ] * ( double )c;
            else if ( s == "B" )z += B [ 2 ] * ( double )c;
            else if ( s == "C" )z += C [ 2 ] * ( double )c;
            else if ( s == "D" )z += D [ 2 ] * ( double )c;
            else if ( s == "E" )z += E [ 2 ] * ( double )c;
            g += c;
        }
        //cout<<e<<"  "<<"  "<<f<<"  "<<g<<"  "<<z<<" "<<x<<"  "<<y<<"  "<<endl;
        if ( b <= 480 )
        {
            c = b;
            b = 0;
            if ( s == "A" )z += A [ 2 ] * ( double )c;
            else if ( s == "B" )z += B [ 2 ] * ( double )c;
            else if ( s == "C" )z += C [ 2 ] * ( double )c;
            else if ( s == "D" )z += D [ 2 ] * ( double )c;
            else if ( s == "E" )z += E [ 2 ] * ( double )c;
            g += c;
        }
        else if ( b >= 480 && b <= 1080 )
        {
            c = 480;
            if ( s == "A" )z += A [ 2 ] * ( double )c;
            else if ( s == "B" )z += B [ 2 ] * ( double )c;
            else if ( s == "C" )z += C [ 2 ] * ( double )c;
            else if ( s == "D" )z += D [ 2 ] * ( double )c;
            else if ( s == "E" )z += E [ 2 ] * ( double )c;
            g += c;

            c = b - 480 ;
            b = 0;
            if ( s == "A" )x += A [ 0 ] * ( double )c;
            else if ( s == "B" )x += B [ 0 ] * ( double )c;
            else if ( s == "C" )x += C [ 0 ] * ( double )c;
            else if ( s == "D" )x += D [ 0 ] * ( double )c;
            else if ( s == "E" )x += E [ 0 ] * ( double )c;
            e += c;
        }
        else if ( b >= 1080 && b <= 1320 )
        {
            c = 480;
            if ( s == "A" )z += A [ 2 ] * ( double )c;
            else if ( s == "B" )z += B [ 2 ] * ( double )c;
            else if ( s == "C" )z += C [ 2 ] * ( double )c;
            else if ( s == "D" )z += D [ 2 ] * ( double )c;
            else if ( s == "E" )z += E [ 2 ] * ( double )c;
            g += c;

            c = 1080 - 480;
            if ( s == "A" )x += A [ 0 ] * ( double )c;
            else if ( s == "B" )x += B [ 0 ] * ( double )c;
            else if ( s == "C" )x += C [ 0 ] * ( double )c;
            else if ( s == "D" )x += D [ 0 ] * ( double )c;
            else if ( s == "E" )x += E [ 0 ] * ( double )c;
            e += c;

            c =  b - 1080;
            if ( s == "A" )y += A [ 1 ] * ( double )c;
            else if ( s == "B" )y += B [ 1 ] * ( double )c;
            else if ( s == "C" )y += C [ 1 ] * ( double )c;
            else if ( s == "D" )y += D [ 1 ] * ( double )c;
            else if ( s == "E" )y += E [ 1 ] * ( double )c;
            f += c;
        }
        else if ( b >= 1320 && b <= 1440 )
        {
            c = 480;
            if ( s == "A" )z += A [ 2 ] * ( double )c;
            else if ( s == "B" )z += B [ 2 ] * ( double )c;
            else if ( s == "C" )z += C [ 2 ] * ( double )c;
            else if ( s == "D" )z += D [ 2 ] * ( double )c;
            else if ( s == "E" )z += E [ 2 ] * ( double )c;
            g += c;

            c = 1080 - 480;
            if ( s == "A" )x += A [ 0 ] * ( double )c;
            else if ( s == "B" )x += B [ 0 ] * ( double )c;
            else if ( s == "C" )x += C [ 0 ] * ( double )c;
            else if ( s == "D" )x += D [ 0 ] * ( double )c;
            else if ( s == "E" )x += E [ 0 ] * ( double )c;
            e += c;

            c = 1320 - 1080;
            if ( s == "A" )y += A [ 1 ] * ( double )c;
            else if ( s == "B" )y += B [ 1 ] * ( double )c;
            else if ( s == "C" )y += C [ 1 ] * ( double )c;
            else if ( s == "D" )y += D [ 1 ] * ( double )c;
            else if ( s == "E" )y += E [ 1 ] * ( double )c;
            f += c;

            c = b - 1320 ;
            if ( s == "A" )z += A [ 2 ] * ( double )c;
            else if ( s == "B" )z += B [ 2 ] * ( double )c;
            else if ( s == "C" )z += C [ 2 ] * ( double )c;
            else if ( s == "D" )z += D [ 2 ] * ( double )c;
            else if ( s == "E" )z += E [ 2 ] * ( double )c;
            g += c;
        }
        z += ( x + y );
    }
    printf("  ");
    a = s2.size();
    a -= 8;
    a = abs(a);
    while ( a-- )putchar(32);
    cout<<s2;printf("   %3d   %3d   %3d  ",e,f,g);cout<<s;
    if( z < 10 )printf("    ");
    else if ( z < 100 )printf("   ");
    else if ( z < 1000 )printf("  ");
    else if ( z < 10000 )printf(" ");
    printf("%.2lf\n",z);
}
