#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(1e5+7)
#define ll long long int
int  cases , n ,  w , m , t , a , b , c , d , e , f , i , j , k , q , win , mov , x ;
char grid [ 60 ] [ 60 ] , temp [ 60 ] [ 60 ] , temp2 [ 60] [ 60 ] , ch;
int nx[] = {-2,-2,-1,1,-1,1,2,2};
int ny[] = {1,-1,-2,-2,2,2,-1,1};
int dx[] = {+0,+0,+1,-1,-1,+1,-1,+1};
int dy[] = {-1,+1,+0,+0,+1,+1,-1,-1};
int kx[] = {+1,-1,+0,+0};
int ky[] = {+0,+0,+1,-1};
bool check( int xx , int yy ){return !( xx < 0 || yy < 0 || xx == n || yy == m );}
int ar [ 60 ] [ 60 ] ;
void fastscan(int &number)
{
    register int c;
    number = 0;
    c = getchar();
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
}
deque < char > dq;
string s , s2;
map < vector < int > , bool > mp;
vector < int > v , v2 , v3 , v4 , v1;
void maker();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while ( cin>>n && n )
    {
        mp.clear();
        memset( grid , ' ' , sizeof grid );
        memset( temp , ' ' , sizeof temp );
        c = n + n;
        q = 0;
        win = mov = -1;
        e = f = 1;
        while ( c-- )
        {
            cin>>a>>b>>s;
            v.clear();
            if ( q )continue;
            if ( s == "-" )grid [ a ] [ b ] = ' ';
            else grid [ a ] [ b ] = '.';
            for ( i = 1; i <= n; i++ )
                for ( j = 1; j <= n; j++ )
                    if ( grid [ i ] [ j ] == '.' )x = i * n + j,v.push_back( x );
            sort( v.begin() , v.end() );
            v1 = v;
            for ( i = 1; i <= n; i++ )
                for ( j = 1; j <= n; j++ )
                    temp [ i ] [ j ] = grid [ i ] [ j ];
            maker();
            v2 = v;
            maker();
            v3 = v;
            maker();
            v4 = v;
            if ( mp.find( v1 ) != mp.end() || mp.find( v2 ) != mp.end() || mp.find( v3 ) != mp.end() || mp.find( v2 ) != mp.end() )
            {
                mov = f;
                if( e == 1 )win = 2;
                else win = 1;
                q = 1;
                continue;
            }
            mp [ v1 ] = 1;
            mp [ v2 ] = 1;
            mp [ v3 ] = 1;
            mp [ v4 ] = 1;
            f++;
            if ( e == 1 )e = 2;
            else e = 1;
        }
        if ( mov == -1 )cout<<"Draw\n";
        else cout<<"Player "<<win<<" wins on move "<<mov<<"\n";
    }
    return 0;
}
void maker()
{
    v.clear();
    for ( i = 1 ; i <= n; i++ )
    {
        for ( j = 1 , b = n; j <= n; j++ , b-- )
        {
            temp2 [ i ] [ j ] = temp [ b ] [ i ];
            if ( temp2 [ i ] [ j ] == '.' )x = i * n + j,v.push_back( x );
        }
    }
    sort(v.begin() , v.end() );
    for ( i = 1; i <= n; i++ )
        for ( j = 1; j <= n; j++ )temp [ i ] [ j ] = temp2 [ i ] [ j ];
}
