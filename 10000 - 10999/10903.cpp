#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(1e5+7)
#define ll long long int
int  cases , n ,  w , m , t , a , b , c , d , e , f , i , j , k , q , row , col ;
char grid [ 8 ] [ 8 ] , ch;
int kx[] = {-2,-2,-1,1,-1,1,2,2};
int ky[] = {1,-1,-2,-2,2,2,-1,1};
int dx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int dy[]={-1,+1,+0,+0,+1,+1,-1,-1};
bool check( int xx , int yy ){return !( xx < 0 || yy < 0 || xx == n || yy == n || grid [ xx ] [ yy ] != '*' );}
int ar [ 110 ] , lose [ 110 ];
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
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    col = 0;
    while ( cin>>n && n )
    {
        if ( col )putchar(10);
        col = 1;
        cin>>k;
        k = ( k * n * ( n - 1 ) ) /2;
        memset( ar , 0 , sizeof ar );
        memset( lose , 0 , sizeof lose );
        while ( k-- )
        {
            cin>>a>>s>>b>>s2;
            if ( s == s2 )continue;
            else if ( s == "paper" && s2 == "rock" )
            {
                ar [ a ]++;
                lose [ b ]++;
            }
            else if ( s == "scissors" && s2 == "paper" )
            {
                ar [ a ]++;
                lose [ b ]++;
            }
            else if ( s == "rock" && s2 == "scissors" )
            {
                ar [ a ]++;
                lose [ b ]++;
            }
            else if ( s2 == "paper" && s == "rock" )
            {
                ar [ b ]++;
                lose [ a ]++;
            }
            else if ( s2 == "scissors" && s == "paper" )
            {
                ar [ b ]++;
                lose [ a ]++;
            }
            else if ( s2 == "rock" && s == "scissors" )
            {
                ar [ b ]++;
                lose [ a ]++;
            }
        }
        for ( i = 1; i <= n; i++ )
        {
            if ( ar [ i ] + lose [ i ] == 0 )printf("-\n");
            else printf("%.3f\n",(double)(ar [ i ] / (double)( ar [ i ] + lose [ i ] )) );
        }
    }
    return 0;
}
