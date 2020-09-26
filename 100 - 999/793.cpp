#include<bits/stdc++.h>
using namespace std;
int ar [ 10000007 ];
void make_friend( int a , int b );
int find_rep( int a );
int find_ans ( int a , int b );
int main()
{
    int t , a , b , c , ans_yes , ans_no , n , m;
    scanf("%d",&t);
    string s;
    char ch;
    m = t-1;
    while ( t-- )
    {
        if ( t != m )putchar(10);
        scanf("%d ",&n);
        for ( int i = 0; i <= n; i++ )ar [ i ] = i;
        ans_yes = ans_no = 0;
        while( getline(cin , s ) )
        {
            if ( s.empty() )break;
            sscanf(s.c_str(),"%c %d %d",&ch,&a,&b);
            if ( ch == 'c' )
            {
                make_friend( a , b );
            }
            else
            {
                if ( find_ans( a , b ) )ans_yes++;
                else ans_no++;
            }
        }
        printf("%d,%d\n",ans_yes,ans_no);
    }
    return 0;
}
void make_friend( int a , int b )
{
    int u = find_rep( a );
    int v = find_rep( b );
    if ( u != v )
    {
        ar [ u ] = v;
    }
}
int find_rep( int a )
{
    if ( ar [ a ] == a )return a;
    ar [ a ] = find_rep( ar [ a ] );
    return ar [ a ];
}
int find_ans ( int a , int b )
{
    int u = find_rep( a );
    int v = find_rep( b );
    if ( u == v )return 1;
    else return 0;
}
