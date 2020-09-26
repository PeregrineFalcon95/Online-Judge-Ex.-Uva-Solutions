#pragma comment(linker, "/stack:200000000")
#include<bits/stdc++.h>
using namespace std;
#define MOD 2117566807LL//(1e9+7)
#define P ( long long int )(1e8+7)//102019LL//257LL
#define inf (1e9+7)
#define mxs (int)(1e5+7)
#define ll long long int
int  cases , n , m , t , a , b , c , d , e , f , i , j , k , q , sum;
char grid [ 110 ] [ 110 ] ;
int knightx[] = {-2,-2,-1,1,-1,1,2,2};
int knighty[] = {1,-1,-2,-2,2,2,-1,1};
int dx[] = {+0,+0,+1,-1,-1,+1,-1,+1};
int dy[] = {-1,+1,+0,+0,+1,+1,-1,-1};
int fx[] = {+1,-1,+0,+0};
int fy[] = {+0,+0,+1,-1};
//bool check( int xx , int yy ){return !( xx < 0 || yy < 0 || xx == n || yy == m );}
int ar [ 60 ] [ 60 ] ;
void fastscan(int &number)
{
    register int c;
    number = 0;
    c = getchar();
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
}
string s , s2 , s3;
deque < int > dq , v , v2 , temp;
int ans;
double rem , sec , xx;
int brainfuck( );
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    while ( scanf("%d",&n ) == 1 && n )
    {
        dq.clear();
        sum = 0;
        while ( scanf("%d",&a)== 1 )
        {
            sum += a;
            dq.push_back( a );
            if ( sum == n )break;
        }
        ans = dq.size();
        rem = (double)n;
        printf("Output for data set %d, %d bytes:\n",++cases,n);
        a = brainfuck();
        printf("Total time: %d seconds\n",ans);
        printf("\n");
    }
    return 0;
}
int brainfuck( )
{
    a = b = 0;
    while ( !dq.empty() )
    {
        ++a;
        b += dq.front();
        dq.pop_front();
        if ( a == 5 )
        {
            xx = ( double )b;
            b = a = 0;
            if ( xx == 0.00 )printf("   Time remaining: stalled\n");
            else
            {
                rem -= xx;
                //xx = ceil( (double)(rem / (double)( xx / 5.00) ) );
                xx = (5.00*(double)rem)/(double)xx;
                printf("   Time remaining: %d seconds\n",int(ceil(xx)));
            }
        }
    }
    return 0;
}
