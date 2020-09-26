#include<bits/stdc++.h>
using namespace std;
#define inf 999999999
int matrix [ 502 ] [ 502 ] , parent [ 502 ] [ 502 ];
int tax [ 502 ];
int t,n,m,a,b,c,o_o,sz;
vector < int > path;
string s,s2;
void warshall();
void find_path( int source , int target );
int main()
{
    scanf("%d",&t);
    getchar();
    getchar();
    while ( t-- )
    {
        for ( int i = 1; i <= 200; i++ )
        {
            for ( int j = 1; j <= 200; j++ )parent [ i ] [ j ] = j;
        }
        getline( cin , s );
        stringstream ss ( s );
        n = 0;
        while ( ss >> s2 )
        {
            n++;
            a = 0;
            if ( s2 [ 0 ] == '-' )
            {
                matrix [ 1 ] [ n ] = inf;
                continue;
            }
            sz = s2.size();
            for ( int i = 0; i != sz; i++ )
            {
                a*=10;
                a+= s2 [ i ] - '0';
            }
            matrix [ 1 ] [ n ] = a;
        }
        for ( int i = 2; i <= n; i++ )
        {
            getline( cin , s );
            stringstream ss2 ( s );
            o_o = 0;
            while ( ss2 >> s2 )
            {
                o_o++;
                if ( s2 [ 0 ] == '-' )
                {
                    matrix [ i ] [ o_o ] = inf;
                    continue;
                }
                a = 0;
                sz = s2.size();
                for ( int j = 0; j != sz; j++ )
                {
                    a*=10;
                    a+= s2 [ j ] - '0';
                }
                matrix [ i ] [ o_o ] = a;
            }
        }
        getline(cin,s);
        stringstream ss3 ( s );
        o_o = 0;
        while ( ss3 >> s2 )
        {
            o_o++;
            a = 0;
            sz = s2.size();
            for ( int i = 0; i != sz; i++ )
            {
                a*=10;
                a+= s2 [ i ] - '0';
            }
            tax [ o_o ] = a;
        }
        warshall();
        int ll = 0;
        while ( getline( cin,s ) )
        {
            if ( !s.size() )break;
            stringstream ss4 ( s );
            o_o = 0;
            if ( ll )putchar( 10 );
            ll++;
            while ( ss4 >> s2 )
            {
                c = 0;
                int sz = s2.size();
                for ( int i = 0; i != sz; i++ )
                {
                    c*=10;
                    c+= s2 [ i ] - '0';
                }
                if ( !o_o )
                {
                    a = c;
                }
                else b = c;
                o_o++;
            }
            int ans = matrix [ a ] [ b ];
            if( ans == inf ){cout<<a<<" vvv "<<b<<endl;continue;}
            find_path( a , b );
            printf("From %d to %d :\n",a,b);
            ///Path: 1-->5-->4-->3
            sz = path.size();
            printf("Path: ");
            for ( int i = 0; i != sz; i++ )
            {
                if(i)printf("-->");
                printf("%d",path [ i ] );
            }
            putchar( 10 );
            printf("Total cost : %d\n",ans);
        }
    }
    return 0;
}
void warshall()
{
    for ( int k = 1; k <= n; k++ )
    {
        for ( int i = 1; i <= n; i++ )
        {
            for ( int j = 1; j <= n; j++ )
            {
                o_o = matrix [ i ] [ k ] + matrix [ k ] [ j ] + tax [ k ];
                if ( matrix [ i ] [ j ] > o_o )
                {
                    parent [ i ] [ j ] = parent [ i ] [ k ];
                    matrix [ i ] [ j ] = o_o;
                }
            }
        }
    }
}
void find_path( int source , int target )
{
    path.clear();
    int pp = source;
    while ( target != pp )
    {
        path.push_back( pp );
        pp= parent [ pp ] [ target ];
    }
    path.push_back( target );
}
