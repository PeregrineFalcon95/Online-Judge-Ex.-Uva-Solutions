#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(1e4+7)
#define ll long long int
int  cases , n , m , t , a , b , c , d , e , f , g , i , j , k , q , ans;
int knightx[] = {-2,-2,-1,1,-1,1,2,2};
int knighty[] = {1,-1,-2,-2,2,2,-1,1};
int dx[] = {+0,+0,+1,-1,-1,+1,-1,+1};
int dy[] = {-1,+1,+0,+0,+1,+1,-1,-1};
int fx[] = {+1,-1,+0,+0};
int fy[] = {+0,+0,+1,-1};
//bool check( int xx , int yy ){return !( xx < 0 || yy < 0 || xx == n || yy == m );}
void fastscan(int &number)
{
    register int c;
    number = 0;
    c = getchar();
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
}
string s, s2 , s3;
deque < int > aa , bb , cc;
int one [ mxs ] , two [ mxs ] , three [ mxs ];
void brainfuck();
void finder( );
void printer( int xx );
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t -- )brainfuck();
    return 0;
}
void brainfuck( )
{
    for ( i = 0; i <= 10000; i++ )one [ i ] = two [ i ] = three [ i ] = 0;
    cin>>a;
    while ( a-- )
    {
        cin>>b;
        one [ b ]  = 1;
    }
    cin>>a;
    while ( a-- )
    {
        cin>>b;
        two [ b ] = 1;
    }
    cin>>a;
    while ( a-- )
    {
        cin>>b;
        three [ b ] = 1;
    }
    cout<<"Case #"<<++cases<<":\n";
    finder();
}
void finder( )
{
    aa.clear();
    bb.clear();
    cc.clear();
    for ( i = 0; i <= 10000; i++ )
    {
        if ( one [ i ] && !two [ i ] && !three [ i ] )aa.push_back( i );
        else if ( two [ i ] && !one [ i ] && !three [ i ] )bb.push_back( i );
        else if ( three [ i ] && !one [ i ] && !two [ i ] )cc.push_back( i );
    }
    a = aa.size();
    b = bb.size();
    c = cc.size();
    if ( a > b && a > c )printer( 1 );
    else if ( b > a && b > c )printer( 2 );
    else if ( c > a && c > b )printer( 3 );
    else if ( a == b && a > c )
    {
        printer( 1 );
        printer( 2 );
    }
    else if ( a == c && a > b )
    {
        printer( 1 );
        printer( 3 );
    }
    else if ( b == c && b > a )
    {
        printer( 2 );
        printer( 3 );
    }
    else if ( a == b && b == c )
    {
        printer( 1 );
        printer( 2 );
        printer( 3 );
    }
}
void printer( int xx )
{
    cout<<xx<<" ";
    if ( xx == 1 )
    {
        sort( aa.begin() , aa.end() );
        cout<<aa.size();
        while ( !aa.empty() )
        {
            cout<<" "<<aa.front();
            aa.pop_front();
        }
        cout<<"\n";
    }
    else if ( xx == 2 )
    {
        sort( bb.begin() , bb.end() );
        cout<<bb.size();
        while ( !bb.empty() )
        {
            cout<<" "<<bb.front();
            bb.pop_front();
        }
        cout<<"\n";
    }
    else if ( xx == 3 )
    {
        sort( cc.begin() , cc.end() );
        cout<<cc.size();
        while ( !cc.empty() )
        {
            cout<<" "<<cc.front();
            cc.pop_front();
        }
        cout<<"\n";
    }
}
