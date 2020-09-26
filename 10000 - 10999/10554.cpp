#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(1e5+7)
#define ll long long int
//int  cases , n , m , t , a , b , c , d , e , f , i , j , k , q ;
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
double xx , fat , fat_p , pro_p , sug_p , st_p , al_p , pro , sug , st , al , total , sum , xxx , yyy ;
void brainfuck();
double finder();
void searcher();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while ( getline( cin , s ) )
    {
        //cin.ignore();
        //cout<<s<<endl;
        for ( int i = 0; i != s.size(); i++ )if ( s [ i ] == '-' )return 0;
        xx = fat = fat_p = pro_p = sug_p = st_p = al_p = pro = sug = st = al = total = sum  = xxx = yyy = 0.0000;
        //cout<<"lol"<<endl;
        do
        {
            //cout<<s<<endl;
            if ( s == "-" )
            {
                brainfuck();
                break;
            }
            xx = fat = fat_p = pro_p = sug_p = st_p = al_p = pro = sug = st = al = total = sum  = 0.00;
            int a = 0;
            stringstream ss ( s );
            s2 = "";
            while ( ss >> s2 )
            {
                xx = finder();
                if ( s2.back() == '%' )
                {
                    if ( !a )fat_p += xx, a = 1;
                    else if ( a == 1 )pro_p = xx , a = 2;
                    else if ( a == 2 )sug_p = xx , a = 3;
                    else if ( a == 3 )st_p = xx , a = 4;
                    else if ( a == 4 )al_p = xx ;
                }
                else if ( s2.back() == 'g' )
                {
                    if ( !a )fat = xx * 9.00, a = 1;
                    else if ( a == 1 )pro = xx * 4.00, a = 2;
                    else if ( a == 2 )sug = xx * 4.00, a = 3;
                    else if ( a == 3 )st = xx * 4.00, a = 4;
                    else if ( a == 4 )al = xx * 7.00;
                }
                else
                {
                    if ( !a )fat = xx, a = 1;
                    else if ( a == 1 )pro = xx , a = 2;
                    else if ( a == 2 )sug = xx , a = 3;
                    else if ( a == 3 )st = xx , a = 4;
                    else if ( a == 4 )al = xx ;
                }
            }
            sum = ( fat + pro + sug + st + al );
            double per = fat_p + pro_p + sug_p + st_p + al_p;
            total = ( sum * 100.00 )/( 100.00 - per );
            fat += ( ( total * fat_p ) / 100.00 );
            xxx += fat;
            yyy += total;
            //cout<<xxx<<"   "<<yyy<<endl;
        }
        while ( getline( cin, s ) );
    }
    return 0;
}
double finder()
{
    double lol = 0.00;
    for ( int i = 0; i != s2.size(); i++ )
    {
        if ( s2 [ i ] >= '0' && s2 [ i ] <= '9' )
        {
            lol *= 10.00;
            lol += s2 [ i ] - '0';
        }
    }
    //cout<<xx<<"  lol\n";
    return lol;
}
void brainfuck( )
{
    double ans = ( 100.00 * xxx ) / yyy;
    ll ccc = ( ll )ans;
    if ( ans + 0.5000 >= (double)(ccc+1) )ccc++;
    cout<<ccc<<"%\n";
}
