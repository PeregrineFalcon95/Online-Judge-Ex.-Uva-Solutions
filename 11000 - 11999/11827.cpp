#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    while( n-- )
    {
        //getchar();
        string s;
        getline(cin, s );
        vector < long long int > v;
        stringstream ss ( s );
        string token;
        while ( ss >> token )
        {
            int sz = token.size();
            long long int a = 0;
            for ( int i = 0; i != sz; i++ )
            {
                a*=10;
                a+= token [ i ] - '0';
            }
            v.push_back ( a );
        }
        int sz = v.size();
        long long int mx = 0;
        for ( int i = 0; i != sz; i++ )
        {
            for ( int j = 0; j != sz; j++ )
            {
                if ( i != j )
                {
                    mx = max(__gcd( v [ i ] , v [ j ] ) , mx);
                }
            }
        }
        printf("%lld\n",mx);
    }
    return 0;
}
