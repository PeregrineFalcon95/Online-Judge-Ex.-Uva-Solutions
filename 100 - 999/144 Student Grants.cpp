#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int

#define inf ( int )( 1e9 + 10 )
#define mxs (int)( 2e5 + 10 )
#define fast ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie( NULL);
//#define md int mid = ( l + r )>>1;
//int dx[]={+1,-1,+0,+0};///Four Directions
//int dy[]={+0,+0,+1,-1};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions 
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions 
ll t, n, m, cases;
void brainfuck();
int main()
{
    //fast
    #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    #endif
    //cin>>t;
    t = 1;
    while( t-- )brainfuck();
    return 0;
}
void brainfuck() 
{
    while( cin>>n>>m && n )
    {
        int currentCoin = 1;
        int nextCoin = 2;
        queue < int > qu;
        for ( int i = 1; i <= n; i++ )qu.push( i );
        int balance [ n + 1 ];
        memset( balance, 0, sizeof balance );

        while( !qu.empty() )
        {
            int a = qu.front();
            qu.pop();
            if ( currentCoin + balance [ a ] < 40 )
            {
                balance [ a ] += currentCoin;
                currentCoin = nextCoin;
                if ( currentCoin > m )currentCoin = 1;
                nextCoin = currentCoin + 1;
                qu.push( a );
            }
            else
            {
                if ( currentCoin + balance [ a ] == 40 )
                {
                    currentCoin = nextCoin; 
                    if ( currentCoin > m )currentCoin = 1;
                    nextCoin = currentCoin + 1;
                }
                else currentCoin -= (40 - balance [ a ]);
                printf("%3d",a);
            }
        }
        printf("\n");
    }
}
