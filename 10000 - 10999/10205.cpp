#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(1e4+7)
#define ll long long int
string card [ 53 ] , temp [ 53 ] ;
string s , s2;
int ar [ 102 ] [ 54 ];
int n , m , i , j , t , sz , x;
void reset();
void change();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while ( t-- )
    {
        reset();
        cin>>n;
        for ( i = 1; i <= n; i++ )
            for ( j = 1; j <= 52; j++ )cin>>ar [ i ] [ j ];
        cin.ignore();
        while ( getline(cin,s) )
        {
            if ( !s.size() )break;
            sz = s.size();
            n = 0;
            for ( i = 0; i != sz; i++ )
            {
                n *= 10;
                n += s [ i ] - '0';
            }
            change();
        }
        for ( i = 1; i  <= 52; i++ )cout<<card [ i ]<<"\n";
        if ( t )cout<<"\n";
    }
    return 0;
}
void reset()
{
    string suit [ ] = { "Clubs", "Diamonds", "Hearts", "Spades" };
    string values [ ] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };
    x = 1;
    for ( i = 0; i <= 3; i++ )
        for ( j = 0; j <= 12; j++ )card [ x++ ] = values [ j ] + " of " + suit [ i ];
}
void change()
{
    for ( i = 1 ; i <= 52; i++ )temp [ i ] = card [ ar [ n ] [ i ] ];
    for ( i = 1 ; i <= 52; i++ )card [ i ] = temp [ i ];
}

