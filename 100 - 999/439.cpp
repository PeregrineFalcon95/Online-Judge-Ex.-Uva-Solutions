#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define inf ( int )( 1e9 + 10 )
#define mxs (int)( 1e6 + 10 )
#define fast ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie( NULL);
//#define md int mid = ( l + r )>>1;
int dx[]={-2,-2,+1,-1,-1,+1,+2,+2};///Four Directions
int dy[]={-1,+1,-2,-2,+2,+2,-1,+1};///Four directions
// int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
// int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
int t, cases;


class solution{
private:
    bool checker(int x, int y){
        return !(x < 1 || y < 1 || x > 8 || y > 8);
    }
    int shortestPath(int sRow, int sCol, int tRow, int tCol){
        int level [ 9 ] [ 9 ];
        memset( level, -1, sizeof level );
        level [ sRow ] [ sCol ] = 0;
        queue < pair < int, int > > qu;
        qu.push( {sRow, sCol} );
        while( !qu.empty() ){
            int row = qu.front().first;
            int col = qu.front().second;
            if ( row == tRow && col == tCol )return level [ row ] [ col ];
            qu.pop();
            for ( int i = 0; i < 8; i++ ){
                int r = dx [ i ] + row;
                int c = dy [ i ] + col;
                if ( checker(r,c) && level [ r ] [ c ] == -1 ){
                    qu.push({r,c});
                    level [ r ] [ c ] = level [ row ] [ col ] + 1;
                }
            }
        }
    }
    void preCal(map < pair < string , string >, int >& distance){
        for ( int i = 1; i <= 8; i++ )
            for ( int j = 1; j <= 8; j++ )
                for ( int k = i; k <= 8; k++ )
                    for ( int l = 1; l <= 8; l++ ){
                        int dis = shortestPath(i,j,k,l);
                        string s, s2;
                        s = i + 'a' - 1;
                        s += j + '0';

                        s2 = k + 'a' - 1;
                        s2 += l + '0';

                        distance [ {s, s2} ] = dis;
                        distance [ {s2, s} ] = dis;
                    }
    }
public:
    void brainfuck(){
        map < pair <string , string >, int > distance;
        preCal(distance);
        string source, target;
        while( cin>>source>>target ){
            int dis = distance [ {source, target} ];
            cout<<"To get from "<<source<<" to "<<target<<" takes "<<dis<<" knight moves.\n";
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

