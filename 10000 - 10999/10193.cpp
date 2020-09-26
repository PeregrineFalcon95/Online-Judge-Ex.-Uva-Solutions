///*** One Last Try ***///
#include<bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#define ll long long int
#define inf ( int )( 1e9 + 1e9 )
#define mxs (int)( 1e6 + 10 )
#define md  int mid = ( l + r )>>1;
#define mod 1000000007//(ll)(1e9)+7
//int dx[]={+1,0,+0,-1};///Four Directions
//int dy[]={+0,-1,+1,+0};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
ll t, n, m, j, k,a, b, c, d, e,f, i,sz,ans,pos,cases;
string s, s2, s3, s4;
void brain();
ll con();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    brain();
    return 0;
}
void brain()
{
    cin>>t;
    while( t-- )
    {
        cin>>s;
        a = con();
        cin>>s;
        b = con();
        cout<<"Pair #"<<++cases<<": ";
        if (__gcd( a , b ) != 1 )cout<<"All you need is love!\n";
        else cout<<"Love is not all you need!\n";
    }
}
ll con()
{
    c = 0;
    d = 1;
    for ( i = s.size() - 1 ; i >= 0; i-- )
    {
        c += ( s [ i ] - '0' ) * d;
        d *= 2;
    }
    return c;
}
