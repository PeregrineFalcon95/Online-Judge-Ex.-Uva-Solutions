#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        if( n == 2)
        {
            printf("00\n01\n81\n");
        }
        else if ( n == 4 )
        {
            printf("0000\n0001\n2025\n3025\n9801\n");
        }
        else if ( n == 6 )
        {
            printf("000000\n000001\n088209\n494209\n998001\n");
        }
        else if ( n == 8)
        {
            printf("00000000\n00000001\n04941729\n07441984\n24502500\n25502500\n52881984\n60481729\n99980001\n");
        }
    }
    return 0;
}



/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    vector < string > ans[10];
    int flag = n-1;
    for( n = 2; n <=8; n+=2 )
    {
        string s;
        for ( int i = 0; i != n; i++ )s.insert(s.end(),'0');
        ans[n].push_back(s);
        while( 1 )
        {
            if ( n == 2 )
            {
                if( s [ 1 ] == '9' )
                {
                    s [ 1 ] = '0';
                    if ( s [ 0 ] != '9')s [ 0 ]++;
                    else break;
                    int a = s [ 0 ]- '0';
                    int b = s [ 1 ]- '0';
                    int c = s [ 0 ]- '0';
                    c*=10;
                    c+= s [ 1 ] - '0';
                    if( (a+b)*(a+b) == c )
                    {
                        ans[n].push_back(s);
                    }
                }
                else
                {
                    s [ 1 ]++;
                    int a = s [ 0 ]- '0';
                    int b = s [ 1 ]- '0';
                    int c = s [ 0 ]- '0';
                    c*=10;
                    c+= s [ 1 ]-'0';
                    if((a+b)*(a+b) == c ) ans[n].push_back(s);
                }
            }
            else if ( n == 4 )
            {
                if( s [ 3 ] != '9')s [ 3 ]++;
                else if ( s [ 2 ] != '9' )
                {
                    s [ 3 ] = '0';
                    s [ 2 ]++;
                }
                else if ( s [ 1 ] != '9' )
                {
                    s [ 3 ] = '0';
                    s [ 2 ] = '0';
                    s [ 1 ]++;
                }
                else if ( s [ 0 ] != '9' )
                {
                    s [ 3 ] = '0';
                    s [ 2 ] = '0';
                    s [ 1 ] = '0';
                    s [ 0 ]++;
                }
                else break;
                int a = (s [ 2 ]- '0')*10;
                a+=s [ 3 ]-'0';
                int b = (s [ 0 ]-'0')*10;
                b+=s [ 1 ]-'0';
                int c = 0;
                for ( int i = 0; i != n; i++ )
                {
                    c*=10;
                    c+=s[ i ]-'0';
                }
                if((a+b)*(a+b) == c )ans[n].push_back( s );
            }
            else if ( n == 6 )
            {
                if ( s [ 5 ] != '9' )s [ 5 ]++;
                else if (s [ 4 ] != '9' )
                {
                    s [ 5 ] = '0';
                    s [ 4 ]++;
                }
                else if ( s [ 3 ] != '9' )
                {
                    s [ 5 ] = '0';
                    s [ 4 ] = '0';
                    s [ 3 ]++;
                }
                else if ( s [ 2 ] != '9' )
                {
                    s [ 2 ]++;
                    s [ 5 ] = '0';
                    s [ 4 ] = '0';
                    s [ 3 ] = '0';
                }
                else if ( s [ 1 ] != '9' )
                {
                    s [ 1 ]++;
                    s [ 5 ] = '0';
                    s [ 4 ] = '0';
                    s [ 3 ] = '0';
                    s [ 2 ] = '0';
                }
                else if ( s [ 0 ] != '9' )
                {
                    s [ 0 ]++;
                    s [ 1 ] = '0';
                    s [ 2 ] = '0';
                    s [ 3 ] = '0';
                    s [ 4 ] = '0';
                    s [ 5 ] = '0';
                }
                else break;
                int a = 0;
                for ( int i = 0; i !=3; i++)
                {
                    a*=10;
                    a+= s [ i ] - '0';
                }
                int b = 0;
                for ( int i = 3; i != 6; i++ )
                {
                    b*=10;
                    b+= s[ i ] - '0';
                }
                int c = 0;
                for ( int i = 0; i !=n; i++ )
                {
                    c*=10;
                    c+= s [ i ] - '0';
                }
                if( (a+b)*(a+b) == c )ans[n].push_back(s);
            }
            else if ( n == 8 )
            {
                if( s [ 7 ] != '9' )s [ 7 ]++;
                else if ( s [ 6 ] != '9' )
                {
                    s [ 7 ] = '0';
                    s [ 6 ]++;
                }
                else if ( s [ 5 ] != '9' )
                {
                    s [ 7 ] = '0';
                    s [ 6 ] = '0';
                    s [ 5 ]++;
                }
                else if ( s [ 4 ] != '9')
                {
                    s [ 4 ]++;
                    s [ 5 ] = '0';
                    s [ 6 ] = '0';
                    s [ 7 ] = '0';
                }
                else if ( s [ 3 ] != '9' )
                {
                    s [ 3 ]++;
                    for ( int i = 4; i !=8; i++ )s [ i ] = '0';
                }
                else if ( s [ 2 ] != '9' )
                {
                    s [ 2 ]++;
                    for( int i = 3; i != 8; i++ )s [ i ] = '0';
                }
                else if ( s [ 1 ] != '9' )
                {
                    s [ 1 ]++;
                    for ( int i = 2; i != 8; i++ )s [ i ] = '0';
                }
                else if ( s [ 0 ] != '9' )
                {
                    s [ 0 ]++;
                    for ( int i = 1; i != 8; i++ )s [ i ] = '0';
                }
                else break;
                //cout<<s<<endl;
                int a = 0;
                for ( int i = 0; i != 4; i++ )
                {
                    a*=10;
                    a+=s [ i ] - '0';
                }
                int b = 0;
                for ( int i = 4; i != 8; i++ )
                {
                    b*=10;
                    b+=s [ i ] - '0';
                }
                int c = 0;
                for ( int i = 0; i != 8; i++)
                {
                    c*=10;
                    c+= s [ i ]-'0';
                }
                //cout<<a<<" "<<b<<" "<<c<<endl;
                if ( (a+b)*(a+b) == c )ans[n].push_back(s);
            }
        }
        //reverse(ans[n].begin(),ans[n].end());
    }
    while( scanf("%d",&n)==1 )
    {
        for ( int i = 0 ; i != ans[ n ].size(); i++ )
        {
            cout<<ans[n][i]<<endl;
        }
    }
    return 0;
}*/
