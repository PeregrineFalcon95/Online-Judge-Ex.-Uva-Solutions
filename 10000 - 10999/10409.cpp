#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(2e5+7)
#define ll long long int
int  cases , n , s , w , m , t , a , b , c , d , e , f , i , j , k , q , row , col ;
char grid [ 15 ] [ 15 ] , grid2 [ 15 ] [ 15 ];
int kx[] = {-2,-2,-1,1,-1,1,2,2};
int ky[] = {1,-1,-2,-2,2,2,-1,1};
int dx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int dy[]={-1,+1,+0,+0,+1,+1,-1,-1};
bool check( int xx , int yy ){return !( xx < 0 || yy < 0 || xx == n || yy == n || grid [ xx ] [ yy ] != '*' );}
int ar [ 10002 ] , gu [ 10002 ] , temp [ 10002 ];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int bottom , top , north , south , east , west;
    string x;
    while ( cin>>m && m )
    {
        top = 1;
        north = 5;
        south = 2;
        west = 4;
        east = 3;
        bottom = 6;
        for ( i = 0; i != m; i++ )
        {
            cin>>x;
            if ( x [ 0 ] == 'n' )
            {
                n = north;
                s = south;
                e = east;
                w = west;
                t = top;
                b = bottom;
                top = n;
                south = t;
                bottom = s;
                north = b;
            }
            else if ( x [ 0 ] == 's' )
            {
                b = bottom;
                t = top;
                n = north;
                s = south;
                e = east;
                w = west;
                top = s;
                south = b;
                bottom = n;
                north = t;
            }
            else if ( x [ 0 ] == 'e' )
            {
                t = top;
                b = bottom;
                n = north;
                s = south;
                e = east;
                w = west;
                top = e;
                east = b;
                west = t;
                bottom = w;
            }
            else if ( x [ 0 ] == 'w' )
            {
                t = top;
                b = bottom;
                n = north;
                s = south;
                e = east;
                w = west;
                top = w;
                east = t;
                west = b;
                bottom = e;
            }
        }
        cout<<top<<"\n";
    }
    return 0;
}

