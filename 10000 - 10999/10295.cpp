#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a;
    scanf("%d%d",&n,&m);
    map < string , int > value;
    for(int i = 0; i < n; i++)
    {
        cin.ignore();
        string s;
        cin>>s;
        scanf("%d",&a);
        value [ s ] = a;
    }
    for(int i = 0; i != m; i++)
    {
        string s;
        a = 0;
        while(getline(cin,s))
        {
            if(s == ".")break;;
            stringstream ss(s);
            string token;
            while(ss >> token)
            {
                a += value[token];
            }
        }
        printf("%d\n",a);
    }
    return 0;
}
