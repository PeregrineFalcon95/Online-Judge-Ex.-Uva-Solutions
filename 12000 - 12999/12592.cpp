#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    map < string , string > slogan;
    cin.ignore();
    for ( int i = 0 ; i != n ; i++ )
    {
        string s,s2;
        getline(cin,s);
        getline(cin,s2);
        slogan [ s ] = s2;
    }
    int m;
    scanf("%d",&m);
    cin.ignore();
    for ( int i = 0 ; i < m ; i++ )
    {
        string s;
        getline(cin,s);
        cout<<slogan [ s ]<<endl;
    }
    return 0;
}
