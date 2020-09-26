#include<bits/stdc++.h>
using namespace std;
bool status[46360];
vector < int > prime;
void seive();
int main()
{
    seive();
    int n;
    while(scanf("%d",&n)==1 && n )
    {
        int m = n;
        vector < int > ans;
        if ( n < 0 )
        {
            ans.push_back(-1);
            n = abs( n );
        }
        int sz = prime.size();
        for ( int i = 0; i != sz; i++)
        {
            int a = prime [ i ];
            if ( !n || n ==1 )break;
            while( n % a == 0)
            {
                ans.push_back(a);
                n/=a;
            }
        }
        if(n!=1 && n != 0 )ans.push_back(n);
        int a = 0;
        printf("%d = ",m);
        for(auto it:ans )
        {
            if( !a )
            {
                printf("%d",it);
                a++;
            }
            else printf(" x %d",it);
        }
        printf("\n");
    }
    return 0;
}
void seive()
{
    int n = 46350;
    int sq = sqrt( n );
    prime.push_back(2);
    int sz = 0;
    for ( int i = 3; i <=sq; i +=2 )
    {
        if(!status [ i ])
        {
            sz = i;
            prime.push_back( i );
            for ( int j = i*i; j <= n; j += (i + i ) )status [ j ] = 1;
        }
    }
    for ( int i = sz + 2; i <= n; i += 2 )
    {
        if(!status [ i ])prime.push_back( i );
    }
}
