#include<bits/stdc++.h>
using namespace std;
#define inf 99999999
int t,n,m,a,b,c,source_monjur,source_mig;
char ch,ch2,ch3,ch4;
int matrix [ 2 ] [ 30 ] [ 30 ];
map < char, int > temp;
vector < char > ans;
void warshall( );
int calculate ();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while ( scanf("%d",&t) == 1 && t )
    {
        temp.clear();
        ans.clear();
        for ( int i = 0; i != 2; i++ )
        {
            for ( int j = 0; j != 27; j++ )
            {
                for ( int k = 0; k != 27; k++ )
                {
                    if ( j == k )matrix [ i ] [ j ] [ k ] = 0;
                    else matrix [ i ] [ j ] [ k ] = inf;
                }
            }
        }
        for ( int i = 0; i != t; i++ )
        {
            getchar();
            scanf("%c %c %c %c %d",&ch,&ch2,&ch3,&ch4,&c);
            if ( ch2 == 'U' && ch == 'Y' && ch3 != ch4 )
            {
                a = ch3 - 'A';
                b = ch4 - 'A';
                matrix [ 0 ] [ a ] [ b ] = c;
            }
            else if ( ch2 == 'B' && ch == 'Y' && ch3 != ch4 )
            {
                a = ch3 - 'A';
                b = ch4 - 'A';
                matrix [ 0 ] [ a ] [ b ] = c;
                matrix [ 0 ] [ b ] [ a ] = c;
            }
            else if ( ch2 == 'U' && ch == 'M' && ch3 != ch4 )
            {
                a = ch3 - 'A';
                b = ch4 - 'A';
                matrix [ 1 ] [ a ] [ b ] = c;
            }
            else if ( ch2 == 'B' && ch == 'M' && ch3 != ch4 )
            {
                a = ch3 - 'A';
                b = ch4 - 'A';
                matrix [ 1 ] [ a ] [ b ] = c;
                matrix [ 1 ] [ b ] [ a ] = c;
            }
        }
        getchar();
        scanf("%c %c",&ch,&ch2);
        source_monjur = ch - 'A';
        source_mig = ch2 - 'A';
        warshall();
        int o_o = calculate();
        if ( o_o == inf )
        {
            printf("You will never meet.\n");
            continue;
        }
        printf("%d",o_o);
        for ( int i = 0; i != ans.size(); i++ )
        {
            printf(" %c",ans [ i ] );
        }
        putchar(10);
    }
    return 0;
}
void warshall( )
{
    for ( int k = 0; k != 26; k++ )
    {
        for ( int i = 0; i != 26; i++ )
        {
            for ( int j = 0; j != 26; j++ )
            {
                matrix [ 0 ] [ i ] [ j ] = min(( matrix [ 0 ] [ i ] [ k ] + matrix [ 0 ] [ k ] [ j ] ), matrix [ 0 ] [ i ] [ j ] );
                matrix [ 1 ] [ i ] [ j ] = min(( matrix [ 1 ] [ i ] [ k ] + matrix [ 1 ] [ k ] [ j ] ), matrix [ 1 ] [ i ] [ j ] );
            }
        }
    }
}
int calculate()
{
    for ( int i = 0; i != 26; i++ )
    {
        if ( matrix[ 0 ] [ source_monjur ] [ i ] != inf && matrix [ 1 ] [ source_mig ] [ i ] != inf )
        {
            ch = i + 'A';
            temp [ ch ] = matrix [ 1 ] [ source_mig ] [ i ] + matrix[ 0 ] [ source_monjur ] [ i ];
        }
    }
    int mi = inf;
    map <char, int > ::iterator it = temp.begin();
    for ( ; it != temp.end(); it++ )
    {
        if ( it->second  < mi )
        {
            ans.clear();
            ans.push_back( it->first);
            mi = it->second;
        }
        else if ( it->second == mi )
        {
            ans.push_back ( it->first );
        }
    }
    return mi;
}

