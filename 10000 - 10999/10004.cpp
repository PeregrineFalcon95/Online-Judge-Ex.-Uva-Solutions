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
    bool isBicolorable(int source, int n, vector < vector < int > >&  graph){
        vector < int > colors (n, 0);
        queue < int > qu;
        qu.push( source );
        colors [ source ] = 1;
        while( !qu.empty() ){
            source = qu.front();
            qu.pop();
            int sz = graph [ source ].size();
            for ( int i = 0; i < sz; i++ ){
                int child = graph [ source ] [ i ];
                if ( !colors [ child ] ){
                    qu.push(child);
                    if ( colors [ source ] == 1 )colors [ child ] = 2;
                    else if ( colors [ source == 2 ] )colors [ child ] = 1;
                }
                else if ( colors [ child ] == colors [ source ] )return false;
            }
        }
        return true;
    }
public:
    void brainfuck(){
        int n, edges, source;
        while( cin>>n && n ){
            vector < vector < int > > graph ( n , vector < int >());
            cin>>edges;
            while( edges-- ){
                int a, b;
                cin>>a>>b;
                source = a;
                graph [ a ].push_back( b );
                graph [ b ].push_back( a );
            }
            if ( isBicolorable(source, n, graph) == true )cout<<"BICOLORABLE.\n";
            else cout<<"NOT BICOLORABLE.\n";
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

