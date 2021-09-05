#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define inf ( int )( 1e9 + 10 )
#define mxs (int)( 1e5 + 10 )
#define fast ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie( NULL);
//#define md int mid = ( l + r )>>1;
int dx[]={+1,-1,+0,+0};///Four Directions
int dy[]={+0,+0,+1,-1};///Four directions
// int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions 
// int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions 
int t, n, m, cases;
string s, s2, s3;
string HexToBin(string hexdec);
char grid [ 210 ] [ 210 ];
bool visited [ 210 ] [ 210 ];
bool checker( int x , int y )
{
    return !( x < 0 || y < 0 || x > 205 || y > 205 );
}
int outputFinder( int row, int col );
void bfs(int row, int col);
void brainfuck();
int main()
{
    fast
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
        memset( visited, 0 , sizeof visited );
        memset( grid, '0', sizeof grid );
        for ( int i = 0; i < n; i++ )
        {
            cin>>s;
            s2 = HexToBin( s );
            int sz = s2.size();
            for ( int j = 0; j < sz; j++ )
                grid [ i + 1 ] [ j + 1 ] = s2 [ j ];
        }
        bfs( 0 , 0 );
        s = "";
        for ( int i = 0; i < 205; i++ )
        {
            for ( int j = 0; j < 205; j++ )
            {
                if ( grid [ i ] [ j ] == '1' && !visited [ i ] [ j ] )
                {
                    int a = outputFinder( i , j );
                    if ( a == 0 )s += "W";
                    else if ( a == 1 )s += "A";
                    else if ( a == 2 )s += "K";
                    else if ( a == 3 )s += "J";
                    else if ( a == 4 )s += "S";
                    else if ( a == 5 )s += "D";
                }
            }
        }
        sort( s.begin(), s.end() );
        cout<<"Case "<<++cases<<": "<<s<<"\n";
    }
}
void bfs(int row, int col)
{
    queue < pair < int , int > > qu;
    qu.push( { row, col } );
    visited [ row ] [ col ] = true;
    while( !qu.empty() )
    {
        row = qu.front().first;
        col = qu.front().second;
        qu.pop();
        for ( int i = 0; i < 4; i++ )
        {
            int a = dx [ i ] + row;
            int b = dy [ i ] + col;
            if ( checker( a , b ) && !visited [ a ] [ b ] && grid [ a ] [ b ] == '0' )
            {
                qu.push( { a , b } );
                visited [ a ] [ b ] = true;
            }
        }
    }
}
int outputFinder( int row, int col )
{
    int counter = 0;
    queue < pair < int , int > > qu;
    qu.push( { row, col } );
    visited [ row ] [ col ] = true;
    while( !qu.empty() )
    {
        row = qu.front().first;
        col = qu.front().second;
        qu.pop();
        for ( int i = 0; i < 4; i++ )
        {
            int a = dx [ i ] + row;
            int b = dy [ i ] + col;
            if ( checker( a , b ) && !visited [ a ] [ b ] && grid [ a ] [ b ] == '1' )
            {
                qu.push( { a , b } );
                visited [ a ] [ b ] = 1;
            }
            else if ( checker( a , b ) && grid [ a ] [ b ] == '0' && !visited [ a ] [ b ] )
            {
                counter++;
                bfs( a , b );
            }
        }
    }
    return counter;
}
string HexToBin(string hexdec)
{
    string temp = "";
    long int i = 0;
 
    while (hexdec[i]) {
 
        switch (hexdec[i]) {
        case '0':
            temp += "0000";
            break;
        case '1':
            temp += "0001";
            break;
        case '2':
            temp += "0010";
            break;
        case '3':
            temp += "0011";
            break;
        case '4':
            temp += "0100";
            break;
        case '5':
            temp += "0101";
            break;
        case '6':
            temp += "0110";
            break;
        case '7':
            temp += "0111";
            break;
        case '8':
            temp += "1000";
            break;
        case '9':
            temp += "1001";
            break;
        case 'A':
        case 'a':
            temp += "1010";
            break;
        case 'B':
        case 'b':
            temp += "1011";
            break;
        case 'C':
        case 'c':
            temp += "1100";
            break;
        case 'D':
        case 'd':
            temp += "1101";
            break;
        case 'E':
        case 'e':
            temp += "1110";
            break;
        case 'F':
        case 'f':
            temp += "1111";
            break;
        default:
            break;
        }
        i++;
    }
    return temp;
}
