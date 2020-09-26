#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(1e5+7)
#define ll long long int
int  hh , mm , cases , n ,  w , m , t , a , b , c , d , e , f , i , j , k , q , win , mov , x ;
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
void check();
bool pal();
bool dekh();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    scanf("%d",&t);
    while ( t-- )
    {
        scanf("%d:%d",&hh,&mm);
        mm++;
        if ( mm == 60 )mm = 0 , hh++;
        if ( hh == 24 && !mm )
        {
            hh = 0, mm = 0;
            printf("00:00\n");
            continue;
        }
        if ( !hh )
        {
            while( !pal() && mm != 60 )mm++;
            if ( mm != 60 )
            {
                if ( mm < 10 )printf("00:0%d\n",mm);
                else printf("00:%d\n",mm);
                continue;
            }
            mm = 0;
            hh++;
            check();
        }
        else check();
    }
    return 0;
}
void check()
{
    if ( hh == 24 && !mm )
    {
        printf("00:00\n");
        return;
    }
    //cout<<hh<<"  "<<mm<<endl;
    mm--;
    while ( 1 )
    {
        while ( mm != 60 )
        {
            mm++;
            if ( dekh() )
            {
                if ( hh < 10 && mm < 10 )printf("0%d:0%d\n",hh,mm);
                else if ( hh >= 10 && mm < 10 )printf("%d:0%d\n",hh,mm);
                else if ( hh >= 10 && mm >= 10 )printf("%d:%d\n",hh,mm);
                else if ( hh < 10 && mm >= 10 )printf("0%d:%d\n",hh,mm);
                return;
            }
        }
        //cout<<hh<<"  "<<mm<<endl;
        mm = -1;
        hh++;
        if ( hh == 24 )
        {
            printf("00:00\n");
            return;
        }
    }
}
bool pal()
{
    a = mm;
    s = "";
    while ( a )
    {
        s += a % 10 + '0';
        a /= 10;
    }
    s2 = s;
    reverse(s2.begin() , s2.end() );
    if ( s == s2 )return 1;
    return 0;
}
bool dekh()
{
    a = mm;
    s = "";
    while ( a )
    {
        s += a % 10 + '0';
        a /= 10;
    }
    if ( mm < 10 )s += '0';
    a = hh;
    while ( a )
    {
        s += a % 10 + '0';
        a /= 10;
    }
    //if ( mm == 32 )cout<<s<<"  xxx\n";
    s2 = s;
    reverse( s2.begin() , s2.end() );
    if( s2 == s )return 1;
    return 0;
}
