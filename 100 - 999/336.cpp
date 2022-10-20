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
    int numOfReachable(int source, int range, unordered_map < int , vector < int > >& graph){
        queue < int > qu;
        unordered_map < int, int > level;
        qu.push(source);
        level [ source ] = 0;
        int nodeCount = 0;
        while( !qu.empty() ){
            source = qu.front();
            qu.pop();
            nodeCount++;
            auto it = graph [ source ];
            int sz = it.size();
            for ( int i = 0; i < sz; i++ ){
                int child = it [ i ];
                if ( level.find( child ) == level.end() && level [ source ] < range ){
                    level [ child ] = level [ source ] + 1;
                    qu.push( child );
                }
            }
        }
        return nodeCount;
    }
public:
    void brainfuck(){
        int numOfEdges;
        while( cin>>numOfEdges && numOfEdges ){
            unordered_map < int , vector < int > > graph;
            int a, b;
            while( numOfEdges-- ){
                cin>>a>>b;
                graph [ a ].push_back( b );
                graph [ b ].push_back( a );
            }

            while( cin>>a>>b && (a || b) ){
                int totalNodes = graph.size();
                if ( graph.find(a) == graph.end() )totalNodes++;
                cout<<"Case "<<++cases<<": "<<totalNodes - numOfReachable(a,b,graph)<<" nodes not reachable from node "<<a<<" with TTL = "<<b<<".\n";
            }
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

