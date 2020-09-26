#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>pbds;
#pragma comment(linker, "/stack:200000000")
#define mod 1000000007
#define ll long long int
#define inf ( ll  )( 1e9 + 10 )
#define mxs (int)( 1e6 + 10 )
//#define md  int mid = ( l + r )>>1;
//int dx[]={+1,-1,+0,+0};///Four Directions
//int dy[]={+0,+0,+1,-1};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
ll ans, t, n, m, i, j, k, a, b, c, d, e, f, g , from , to;
string s , s2, s3, s4;
bool status [ mxs ];
int ar [ mxs ] ;
deque < ll > dq;
void brainfuck();
ll convert_to_base_10();
void convert_to_ans();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    brainfuck();
    return 0;
}
void brainfuck()
{
    while(cin>>from>>to>>s )
    {
        dq.clear();
        n = s.size();
        s2 = s;
        c = 0;
        for ( i = 0 ; i < n; i++ )
        {
            if ( s [ i ] >= '0' && s [ i ] <= '9' )a = s [ i ] - '0';
            else  a = s [ i ] - 'A' + 10;
            if ( a >= from )
            {
                cout<<s<<" is an illegal base "<<from<<" number\n";
                c = 1;
                break;
            }
            dq.push_back( a );
        }
        if ( c )continue;
        a = convert_to_base_10();
        dq.clear();
        convert_to_ans();
        cout<<s2<<" base "<<from<<" = "<<s<<" base "<<to<<"\n";

    }
}
ll convert_to_base_10()
{
    a = 0;
    c = from;
    a = dq.back();
    dq.pop_back();
    while( !dq.empty() )
    {
        b = from * dq.back();
        dq.pop_back();
        a += b;
        from *= c;
    }
    from = c;
    return a;
}
void convert_to_ans()
{
    while( a )
    {
        b = a % to;
        a /= to;
        dq.push_back( b );
    }
    s = "";
    if ( !dq.size() )s += "0";
    while( !dq.empty() )
    {
        a = dq.back();
        dq.pop_back();
        if ( a >= 10 )
        {
            s += a - 10 + 'A';
        }
        else s += a + '0';
    }
}

