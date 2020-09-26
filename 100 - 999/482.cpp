#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    scanf("%d",&n);
    m = n-1;
    cin.ignore();
    while( n-- )
    {
        cin.ignore();
        if( m != n )
        {
            printf("\n");
        }
        string s;
        getline(cin,s);
        string token;
        stringstream ss( s );
        int flag = 0;
        vector < int > v;
        while( ss >> token )
        {
            int sz = token.size();
            int a = 0;
            for ( int i = 0; i != sz; i++ )
            {
                a*=10;
                a+=token[ i ]- '0';
            }
            v.push_back( a );
            flag++;
        }
        getline(cin,s);
        stringstream sss(s);
        token = "";
        vector < string > vv;
        while(sss >> token)
        {
            vv.push_back(token);
        }
        int sz = v.size();
        int arrr[ flag+1 ];
        for ( int i = 0; i != flag; i++ )
        {
            arrr [ v[ i ]-1 ] = i ;
        }
        for ( int i = 0; i != flag; i++ )
        {
            cout<<vv[ arrr [ i ] ]<<endl;
        }
    }
    return 0;
}
