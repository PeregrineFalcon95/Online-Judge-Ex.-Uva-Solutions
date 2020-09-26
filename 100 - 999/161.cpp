#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(1e5+7)
#define ll long long int
int  cases , n , m , t , a , b , c , d , e , f , i , j , k , q ;
char grid [ 110 ] [ 110 ] ;
int knightx[] = {-2,-2,-1,1,-1,1,2,2};
int knighty[] = {1,-1,-2,-2,2,2,-1,1};
int dx[] = {+0,+0,+1,-1,-1,+1,-1,+1};
int dy[] = {-1,+1,+0,+0,+1,+1,-1,-1};
int fx[] = {+1,-1,+0,+0};
int fy[] = {+0,+0,+1,-1};
//bool check( int xx , int yy ){return !( xx < 0 || yy < 0 || xx == n || yy == m );}
int ar [ 60 ] [ 60 ] ;
void fastscan(int &number)
{
    register int c;
    number = 0;
    c = getchar();
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
}
string s , s2 , s3;
vector < int > v , v2 , temp;
int brainfuck( );
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while ( 1 )
    {
        a = 0;
        v.clear();
        if ( !temp.size() )
        {
            while ( cin>> b && b )
            {
                v.push_back( b );
            }
        }
        else
        {
            v.clear();
            v = temp;
            temp.clear();
        }
        while ( cin>>b && b )
        {
            temp.push_back( b );
        }
        if ( !temp.size() )
        {
            a = brainfuck();
            //cout<<endl<<a<<endl;
            if ( !a )cout<<"Signals fail to synchronise in 5 hours\n";
            else
            {
                int sec = a % 60;
                a -= ( a % 60 );
                int mm = a / 60;
                a = mm;
                mm = mm % 60;
                a = a - ( mm % 60 );
                int hh = a / 60;
                if( hh < 10 )cout<<"0"<<hh<<":";
                else cout<<hh<<":";
                if ( mm < 10 )cout<<"0"<<mm<<":";
                else cout<<mm<<":";
                if ( sec < 10 )cout<<"0"<<sec<<"\n";
                else cout<<sec<<"\n";
            }
            cin>>a>>b;
            return 0;
        }
        a = brainfuck();
        if ( !a )cout<<"Signals fail to synchronise in 5 hours\n";
        else
        {
            int sec = a % 60;
            a -= ( a % 60 );
            int mm = a / 60;
            a = mm;
            mm = mm % 60;
            a = a - ( mm % 60 );
            int hh = a / 60;
            if( hh < 10 )cout<<"0"<<hh<<":";
            else cout<<hh<<":";
            if ( mm < 10 )cout<<"0"<<mm<<":";
            else cout<<mm<<":";
            if ( sec < 10 )cout<<"0"<<sec<<"\n";
            else cout<<sec<<"\n";
        }
    }
    return 0;
}
int brainfuck( )
{
    a = INT_MAX;
    b = v.size();
    for ( i = 0; i != b; i++ )a = min( a , v [ i ] );
    //cout<<a<<endl;
    a = ( a - 5 );
    a++;
    //cout<<a<<endl;
    for ( i = a; i <= 18000; i++ )
    {
        c = 0;
        for ( j = 0; j != b; j++ )
            if ( ( i % ( v [ j ] + v [ j ] ) ) >= v [ j ] - 5 )
            {
                c = 1;
                break;
            }
        if ( !c )return i;
    }
    return 0;
}
