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
map < char , int > mp;
map < int , char > re;
int brainfuck();
int main()
{
    char ch , ch2;
    a = 0;
    for (  ch = 'A' , ch2 = 'a'; ch <= 'Z'; ch++, ch2++ )
    {
        mp [ ch ] = ++a;
        re [ a ] = ch;
        mp [ ch2 ] = ++a;
        re [ a ] = ch2;
    }
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while( t-- )a = brainfuck();
    return 0;
}
int brainfuck()
{
    cin>>s2;
    dq.clear();
    for ( i = 0; i != s2.size(); i++ )dq.push_back( mp [ s2 [ i ] ] );
    sort(dq.begin() , dq.end() );
    //cout<<s2<<"\n";
    a = dq.size();
    for ( i = 0; i != a; i++ )
    {
        cout<<re [ dq [ i ] ];
    }
    cout<<"\n";
    while ( next_permutation( dq.begin() , dq.end() ) )
    {
        for ( i = 0; i != a; i++ )
        {
            cout<<re [ dq [ i ] ];
        }
        cout<<"\n";
    }
    return a;
}
