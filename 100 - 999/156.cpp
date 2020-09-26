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
bool check( int xx , int yy ){return !( xx < 0 || yy < 0 || xx == n || yy == m );}
int ar [ 60 ] [ 60 ] ;
void fastscan(int &number)
{
    register int c;
    number = 0;
    c = getchar();
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
}
deque < int > dq;
string s , s2 , s3;
vector < string > v , v2;
int brainfuck();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while ( getline(cin,s) )
    {
        if ( s == "#" )break;
        stringstream ss ( s );
        while ( ss >> s2 )
        {
            v2.push_back( s2 );
            for ( i = 0; i != s2.size(); i++ )if ( s2 [ i ] >= 'A' && s2 [ i ] <= 'Z' )s2 [ i ] += 32;
            sort( s2.begin(), s2.end() );
            v.push_back( s2 );
        }
    }
    a = brainfuck();
    return 0;
}
int brainfuck()
{
    map < string , bool > mp;
    n = v.size();
    for ( i = 0; i < n; i++ )
    {
        if ( v [ i ] == "!" )continue;
        a = 0;
        for ( j = i + 1; j < n; j++ )
            if ( v [ i ] == v [ j ] )
            {
                v [ j ] = "!";
                a = 1;
            }
        if ( a ) v [ i ] = "!";
    }
    for ( i = 0; i != n; i++ )
        if ( v [ i ] != "!" )mp [ v2 [ i ] ] = 1;
    map < string , bool >::iterator it = mp.begin();
    for (; it != mp.end(); it++)cout<<it->first<<"\n";
    return a;
}
