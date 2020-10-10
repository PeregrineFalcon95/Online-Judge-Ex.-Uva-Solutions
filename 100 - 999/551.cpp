
#include<bits/stdc++.h>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>pbds;
//#pragma comment(linker, "/stack:200000000")
#define fast ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
#define mod ( ll  ) ( 1e9 + 7 )  //( 1e9 + 7 )
#define ll long long int
#define inf ( ll  )( 1e9 + 10 )
#define mxs (int)(1e6+100)
#define CHECK_BIT(var,pos) ((var) & (1LL<<(pos)))
//#define md  int mid = ( l + r )>>1;
//int dx[]={+1,-1,+0,+0};///Four Directions
//int dy[]={+0,+0,+1,-1};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
//int dx[]={-2,-2,-1,1,-1,1,2,2};///Knight moves
//int dy[]={1,-1,-2,-2,2,2,-1,1};///Knight moves
int n, m, t, ans , cases;
string s , s2;
int ar [ mxs ] ;
int checker();
void brainfuck();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    fast
    //cin>>t;
    t = 1;
    while( t-- )brainfuck();
    return 0;
}
void brainfuck()
{
    while( getline(cin,s) )
    {
        m = checker();
        if ( m == -1 )cout<<"YES\n";
        else cout<<"NO "<<m<<'\n';
    }
}
int checker()
{
    stack < int > stk ;
    n = s.size();

    s2 = "";
    for ( int i = 0; i < n; i++ )
    {
        if ( s [ i ] == '(' )
        {
            if ( i + 1 < n && s [ i + 1 ] == '*' )
            {
                s [ i + 1 ] = '!';
                s2 += "!";
            }
            else s2 += "(";
        }
        else if ( s [ i ] == ')' )
        {
            if (  i - 1 >= 0 && s [ i - 1 ] == '*' )
            {
                s2 += "#";
            }
            else s2 += s [ i ];
        }
        else if ( s [ i ] == '*' )
        {
            if ( i + 1 < n && s [ i + 1 ] == ')' )continue;
            s2 += "*";
        }
        else if ( s [ i ] != '!')s2 += s [ i ];
    }
    s = s2;

    n = s.size();
    //cerr<<s<<endl;
    for ( int i = 0 ; i < n; i++ )
    {
        if ( s [ i ] == '(' )
        {
            stk.push( 1 );
        }
        else if ( s [ i ] == '!'  )
        {
            stk.push( 2 );
        }
        else if ( s [ i ] == ')'  )
        {
            if ( stk.empty() )return i + 1;
            if ( stk.top() != 1 )
            {
                return i + 1;
            }
            stk.pop();
        }
        else if ( s [ i ] == '#' )
        {
            if ( stk.empty() )return i  +1;
            if ( stk.top() != 2 )
            {
                return i + 1;
            }
            stk.pop();
        }
        else if ( s [ i ] == '[' )
        {
            stk.push( 3 );
        }
        else if ( s [ i ] == ']' )
        {
            if ( stk.empty() )return i + 1;
            if ( stk.top() != 3 )
            {
                return i + 1;
            }
            stk.pop();
        }
        else if ( s [ i ] == '{' )
        {
            stk.push( 4 );
        }
        else if ( s [ i ] == '}' )
        {
            if ( stk.empty() )return i + 1;
            if ( stk.top() != 4 )
            {
                return i + 1;
            }
            stk.pop();
        }
        else if ( s [ i ] == '<' )
        {
            stk.push( 5 );
        }
        else if ( s [ i ] == '>' )
        {
            if ( stk.empty() )return i + 1;
            if ( stk.top() != 5 )
            {
                return i + 1 ;
            }
            stk.pop();
        }
    }
    if ( !stk.empty() )
    {
        return s.size() + 1;
    }

    return -1;
}
