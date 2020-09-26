#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(1e5+7)
#define ll long long int
int  cases , n , m , t , a , b , c , d , e , f , g , i , j , k , l , q , ans;
int knightx[] = {-2,-2,-1,1,-1,1,2,2};
int knighty[] = {1,-1,-2,-2,2,2,-1,1};
int dx[] = {+0,+0,+1,-1,-1,+1,-1,+1};
int dy[] = {-1,+1,+0,+0,+1,+1,-1,-1};
int fx[] = {+1,-1,+0,+0};
int fy[] = {+0,+0,+1,-1};
//bool check( int xx , int yy ){return !( xx < 0 || yy < 0 || xx == n || yy == m );}
void fastscan(int &number)
{
    register int cc;
    number = 0;
    cc = getchar();
    for (; (cc>47 && cc<58); cc=getchar())
        number = number *10 + cc - 48;
}
string s, s2 , s3;
deque < pair < int , int > > dq;
vector < int > v;
int game [ 102 ] [ 102 ] , pos [ 102 ] [ 102 ] , score [ 102 ];
void brainfuck();
void finder();
int main()
{
    //cout<<(-1 + 10)%10;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while( cin>>m>>n && m )brainfuck();
    return 0;
}
void brainfuck( )
{
    for ( i = 1; i <= m; i++ )
        for ( j = 1; j <= n; j++ )
        {
            cin>>game [ i ] [ j ];
            pos [ i ] [ game [ i ] [ j ] ] = j;
        }
    //cout<<endl;
    //cout<<pos [ 1 ] [ 1 ]<<" "<<pos [ 1 ] [ 2 ]<<" "<<pos [ 1 ] [ 3 ]<<endl;
    //cout<<game [ 1 ] [ 1 ]<<" "<<game [ 1 ] [ 2 ]<<" "<<game [ 1 ] [ 3 ]<<endl;
    cin>>e;
    while ( e-- )finder();
}
void finder()
{
    memset( score , 0 , sizeof score );
    cin>>k;
    for ( i = 1; i <= k; i++ )
    {
        cin>>a;
        for ( j = 1; j <= m; j++ )
            score [ pos [ j ] [ i ] ] += a;
    }
    //cout<<endl;
    //for ( i = 1 ; i <= n; i++ )cout<<score [ i ]<<" ";
    for ( i = 1; i <= n; i++ )dq.push_back( {score [ i ] , i } );
    sort( dq.begin() , dq.end() );
    reverse( dq.begin() , dq.end() );
    a = dq.front().first;
    b = dq.front().second;
    v.push_back( b );
    dq.pop_front();
    while ( !dq.empty() && dq.front().first == a )
    {
        v.push_back( dq.front().second );
        dq.pop_front();
    }
    sort(v.begin() , v.end() );
    f = v.size();
    for ( i = 0; i != f; i++ )
    {
        if ( i )cout<<" ";
        cout<<v [ i ];
    }
    cout<<"\n";
    dq.clear();
    v.clear();
}

