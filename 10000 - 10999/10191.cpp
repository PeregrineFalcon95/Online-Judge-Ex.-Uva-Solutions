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
vector < pair < int , int > > v , v2 , temp;
int ans;
int tim;
int brainfuck( );
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    while( scanf("%d",&n) == 1 )
    {
        v.clear();
        for ( i = 0; i != n; i++ )
        {
            scanf("%d:%d %d:%d",&a,&b,&c,&d);
            a = a * 60;
            a += b;
            b = c * 60;
            b += d;
            getline(cin,s);
            v.push_back( { a , b } );
        }
        sort( v.begin() , v.end() );
        ans = 0;
        a = brainfuck();
        int mm = tim % 60;
        int hh = tim / 60;
        printf("Day #%d: the longest nap starts at ",++cases);
        if ( hh < 10 )printf("0\%d:",hh);
        else printf("%d:",hh);
        if ( mm < 10 )printf("0%d",mm);
        else printf("%d",mm);
        mm = ans % 60;
        hh = ans / 60;
        if ( !hh )printf(" and will last for %d minutes.\n",mm);
        else printf(" and will last for %d hours and %d minutes.\n",hh,mm);
    }
    return 0;
}
int brainfuck( )
{
    a = 10 * 60;
    b = 18 * 60;
    c = v.size();
    for ( i = 0; i != c; i++ )
    {
        if ( ans < v [ i ].first - a )
        {
            ans = v [ i ].first - a;
            tim = a;
        }
        a = v [ i ].second;
    }
    if ( ans < b - v.back().second )
    {
        ans = b - v.back().second;
        tim = v.back().second;
    }
    return 0;
}
