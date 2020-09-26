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
vector < string > v , v2 , temp;
map < string , int > mp , mp2;
int brainfuck();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    cases = 0;
    while ( t-- )a = brainfuck();
    return 0;
}
int brainfuck()
{
    if ( cases )cout<<"\n";
    cases = 1;
    cin>>n;
    v.clear();
    v2.clear();
    for ( i = 1; i <= n; i++ )
    {
        cin>>s;
        v.push_back( s );
        sort( s.begin() , s.end() );
        v2.push_back( s );
    }
    while ( cin>>s && s != "END" )
    {
        s2 = s;
        sort( s.begin() , s.end() );
        cout<<"Anagrams for: "<<s2<<"\n";
        a = 0;
        for ( i = 0; i != n; i++ )
            if ( s == v2 [ i ] )cout<<"  "<<++a<<") "<<v [ i ]<<"\n";
        if ( !a )cout<<"No anagrams for: "<<s2<<"\n";
    }
    return a;
}
