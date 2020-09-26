#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while(getline(cin,s))
    {
        int mx=0,l=s.size();
        for(int i=0; i!=l; i++)
        {
            if(s[i]>='0'&&s[i]<='9')mx+=(s[i]-'0');
            else if((s[i]>='A'&&s[i]<='Z')||s[i]=='*'){for(int j=0; j<mx; j++){printf("%c",s[i]);}mx=0;}
            else if(s[i]=='!')printf("\n");
            else if(s[i]=='b'){for(int j=0; j!=mx; j++){printf(" ");}mx=0;}
        }
        printf("\n");
    }
    return 0;
}

