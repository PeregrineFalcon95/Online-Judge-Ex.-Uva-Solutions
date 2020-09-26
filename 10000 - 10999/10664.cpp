#include<bits/stdc++.h>
using namespace std;
int n , m , x , y , t , sum ;
int dp [ 22 ] [ 110 ];
int ar [ 22 ];
string s , s2;
char ch [ 100 ];
int nas ( int i , int j );
int main()
{
    scanf("%d",&t);
    getchar();
    while ( t-- )
    {
        x = sum = 0;
        getline(cin,s);
        stringstream ss ( s );
        while ( ss >> ch )
        {
            ar [ ++x ] = atoi( ch );
            sum += ar [ x ];
            //cout<<ar [ x ]<<endl;
        }
        //cout<<sum<<endl;
        if ( sum & 1 )
        {
            printf("NO\n");
            continue;
        }
        sum /= 2;
        memset(dp, -1 , sizeof dp );
        if ( nas ( 1 , sum ) )printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
int nas ( int i , int j )
{
    if ( i >= x )
    {
        if ( !j )return 1;
        return 0;
    }
    if ( dp [ i ] [ j ] != -1 )return dp [ i ] [ j ];
    int a = 0 , b = 0;
    if ( j - ar [ i ] >= 0)a = nas( i + 1 , j - ar [ i ] );
    b = nas( i + 1 , j );
    return ( dp [ i ] [ j ] = max( a , b ) );
}


