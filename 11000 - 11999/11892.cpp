#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define inf ( int )( 1e9 + 10 )
#define mxs (int)( 1e6 + 10 )
#define fast ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie( NULL);
//#define md int mid = ( l + r )>>1;
int dx[]={+1,-1,+0,+0};///Four Directions
int dy[]={+0,+0,+1,-1};///Four directions
// int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
// int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
int t, cases;

class solution{
private:
    string getWinner(int n, vector < int >& piles){
        string winner = "poopi";
        int countOne = 0, countTwo = 0;
        for ( int i = 0; i < n; i++ )
            if ( piles [ i ] == 1 )countOne++;
            else countTwo++;
        if ( countOne == n ){
            if ( n&1 )return winner;
            else return "piloop";
        }
        return winner;
    }
public:
    void brainfuck(){
        int n;
        cin>>n;
        vector < int > piles(n);
        for ( int i = 0; i < n; i++ )cin>>piles [ i ];
        cout<< getWinner(n,piles)<<"\n";
    }
};

solution solve;
int main(){
    fast
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    cin>>t;
    //t = 1;
    while( t-- )
    {
        solve.brainfuck();
    }
    return 0;
}

