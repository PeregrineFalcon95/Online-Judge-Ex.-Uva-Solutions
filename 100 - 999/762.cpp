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
    void findPath(int source, int target, int total, vector < vector < int > >& graph, vector < int >& path){
        queue < int > qu;
        vector < int > parent ( total + 1, 0);
        qu.push( source );
        parent [ source ] = source;
        while( !qu.empty() ){
            int node = qu.front();
            qu.pop();
            int sz = graph [ node ].size();
            if ( node == target )break;
            for ( int i = 0; i < sz; i++ ){
                int child = graph [ node ] [ i ];
                if ( !parent [ child ] ){
                    parent [ child ] = node;
                    qu.push( child );
                }
            }
        }
        if ( !parent [ target ] )return;
        for ( ; target != source ; target = parent [ target ] )
            path.push_back( target );
        path.push_back( target );
    }
    int compressStr(string& s, int& marker, map < string , int >& strToNum, map < int , string >& numToStr){
        if ( strToNum.find( s ) == strToNum.end() ){
            strToNum [ s ] = ++marker;
            numToStr [ marker ] = s;
            return marker;
        }
        else return strToNum [ s ];
    }
public:
    void brainfuck(){
        int numOfEdges;
        while( cin>>numOfEdges ){
            if ( cases++ )cout<<"\n";
            string s, s2;
            map < string , int > strToNum;
            map < int , string > numToStr;
            vector < vector < int > > graph ( numOfEdges+numOfEdges+2, vector < int > ());
            vector < int > path;

            int marker = 0;
            while( numOfEdges-- ){
                cin>>s>>s2;
                int a, b;
                a = compressStr(s, marker, strToNum, numToStr);
                b = compressStr(s2, marker, strToNum, numToStr);
                graph [ a ].push_back( b );
                graph [ b ].push_back( a );
            }
            cin>>s>>s2;
            int source = compressStr(s, marker, strToNum, numToStr);
            int target = compressStr(s2, marker, strToNum, numToStr);
            findPath(source, target, marker, graph, path);

            int n = path.size();
            if ( !n ){
                cout<<"No route\n";
                continue;
            }

            for ( int i = n - 1; i > 0; i-- )
                cout<<numToStr [ path [ i ] ]<<" "<<numToStr [ path [ i - 1 ] ]<<"\n";
        }
    }
};

solution solve;
int main(){
    fast
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    //cin>>t;
    t = 1;
    while( t-- )solve.brainfuck();
    
    return 0;
}

