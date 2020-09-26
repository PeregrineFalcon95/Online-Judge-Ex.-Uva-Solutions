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
deque < int > dq;
string s , s2 , s3;
map < string , bool > mp;
bool check();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while ( cin>>s )
    {
        mp.clear();
        n = s.size();
        for ( i = 0; i != n; i++ )
        {
            s2 = s [ i ];
            mp [ s2 ] = 1;
        }
        for ( i = 0; i != n; i++ )
        {
            s2 = "";
            for ( j = i; j != n; j++ )
            {
                s2 += s [ j ];
                if ( check() )mp [ s2 ] = 1;
            }
        }
        cout<<"The string '"<<s<<"' contains "<<mp.size()<<" palindromes.\n";
    }
    return 0;
}
bool check()
{
    s3 = s2;
    reverse( s3.begin(), s3.end() );
    if ( s3 == s2 )return 1;
    return 0;
}
