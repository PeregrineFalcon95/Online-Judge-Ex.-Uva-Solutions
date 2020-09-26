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
string s , s2 , s3;
vector < string > v , v2 , words , temp;
map < string , int > mp , mp2;
int brainfuck();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    cin.ignore();
    cases = 0;
    while ( t-- )a = brainfuck();
    return 0;
}
int brainfuck()
{
    vector < pair < string , string > > ans;
    if ( cases )cout<<"\n";
    cases = 1;
    //cin.ignore();
    v.clear();
    v2.clear();
    while( getline(cin,s) && !s.size() );
    v.push_back( s );
    a = 0;
    while ( getline( cin , s ) && s.size() )v.push_back( s );
    a = v.size();
    sort(v.begin() , v.end() );
    for ( i = 0; i < a; i++ )
    {
        s = v[ i ];
        stringstream ss( s );
        s3 ="";
        while ( ss>>s2 )s3 += s2;
        sort( s3.begin() , s3.end() );
        v2.push_back( s3 );
    }
    for ( i = 0; i <= a; i++ )
        for ( j = i + 1 ; j <= a; j++ )
            if ( v2 [ i ] == v2 [ j ] )ans.push_back( { v [ i ] , v [ j ] } );
    a = ans.size();
    sort(ans.begin() , ans.end() );
    for ( i = 0; i != a; i++ )cout<<ans [ i ].first<<" = "<<ans [ i ].second<<"\n";
    return a;
}
