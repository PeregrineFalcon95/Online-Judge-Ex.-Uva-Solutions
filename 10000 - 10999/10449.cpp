///** One Last Try ***///
#include<bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#define mod 1000000007
#define ll long long int
#define inf ( ll  )( 1e15 + 10 )
#define mxs (int)( 1e6 + 10 )
//#define md  int mid = ( l + r )>>1;
//int dx[]={+1,-1,+0,+0};///Four Directions
//int dy[]={+0,+0,+1,-1};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
ll ans, t, n, m, i, j, a, b, c, d,cases, sum , num , pos;
string s, s2, s3, s4, s5, s6;
ll cost [ 300 ] , ar [ mxs ];
struct data
{
    ll x , y , z;
};
vector < data > v;
void brainfuck();
void Bellman()
{
    int source = 1;
    for ( i = 1 ; i <= n; i++ )cost [ i ] = inf;
    cost [ source ] = 0;

    for ( i = 1 ; i < n; i++ )
        for ( j = 0 ; j < m; j++ )
            if ( cost [ v [ j ].x ] != inf && cost [ v [ j ].x ] + v [ j ].z < cost [ v [ j ].y ] )
                cost [ v [ j ].y ] = cost [ v [ j ].x ] + v [ j ].z;

    for ( j = 0 ; j < m; j++ )
            if ( cost[ v [ j ].x ] != inf && cost [ v [ j ].x ] + v [ j ].z < cost [ v [ j ].y ] )
                cost [ v [ j ].y ] = -inf;

}
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
    data lol;
    while( cin>> n )
    {
        v.clear();
        for ( i = 1 ; i <= n; i++ )cin>>ar [ i ];
        cin>>m;
        for ( i = 1 ; i <= m; i++ )
        {
            cin>>a>>b;
            lol.x = a;
            lol.y = b;
            c = ar [ b ] - ar [ a ];
            c = c * c * c;
            lol.z = c;
            v.push_back( lol );
        }
        Bellman();
        cout<<"Set #"<<++cases<<"\n";

        int q;
        cin>>q;
        while( q-- )
        {
            cin>>a;
            if ( cost [ a ] == inf || cost [ a ] < 3 )cout<<"?\n";
            else cout<<cost [ a ]<<"\n";
        }
    }
}
/*

5 6 7 8 9 10
6
1 2
2 3
3 4
1 5
5 4
4 5
2
4
5

*/
