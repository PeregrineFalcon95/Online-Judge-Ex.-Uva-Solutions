#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define inf ( ll )( 1e9 + 10 )
#define mxs (int)( 1e6 + 10 )
#define fast ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie( NULL);
//#define md ll mid = ( l + r )>>1;
int dx[]={+1,-1,+0,+0};///Four Directions
int dy[]={+0,+0,+1,-1};///Four directions
// int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
// int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
int t, cases;

class solution{
private:
    ll findAns(deque < pair < ll, ll > >& nodes, deque < pair < ll, ll > >& lossNodes){
        sort(nodes.begin(), nodes.end());
        sort(lossNodes.begin(), lossNodes.end());
        ll freeSpace = 0, expand = 0;
        while( !nodes.empty() ){
            ll sz = nodes.front().first;
            ll newSz = -nodes.front().second;
            nodes.pop_front();
            if ( freeSpace < sz ){
                expand += sz - freeSpace;
                freeSpace += (sz - freeSpace);
            }
            freeSpace -= sz;
            freeSpace += newSz;
        }
        while( !lossNodes.empty() ){
            int sz = lossNodes.back().second;
            int newSz = lossNodes.back().first;
            lossNodes.pop_back();
            if ( freeSpace < sz ){
                expand += sz - freeSpace;
                freeSpace += (sz- freeSpace);
            }
            freeSpace -= sz;
            freeSpace += newSz;
        }
        return expand;
    }

public:
    void brainfuck(){
        int n;
        while(cin>>n){
            deque < pair < ll, ll > > nodes, lossNodes;
            while( n-- ){
                ll a, b;
                cin>>a>>b;
                if ( a <= b )nodes.push_back({ a, -b });
                else lossNodes.push_back({ b, a });
            }
            cout<<findAns(nodes, lossNodes)<<"\n";
        }
    }
};

solution solve;
int main(){
    fast

    //cin>>t;
    t = 1;
    while( t-- )solve.brainfuck();
    return 0;
}