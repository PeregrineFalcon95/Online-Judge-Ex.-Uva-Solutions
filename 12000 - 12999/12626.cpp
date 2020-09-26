#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a;
    scanf("%d",&n);
    while(n--)
    {
        string s;
        cin>>s;
        int len=s.size();
        map < char , int > mp;
        for(int i=0; i<len; i++){mp[s[i]]++;}
        a=mp['T'];
        if(a>mp['I'])a=mp['I'];
        if(a>mp['G'])a=mp['G'];
        if(a>mp['M'])a=mp['M'];
        if(a>mp['A']/3)a=mp['A']/3;
        if(a>mp['R']/2)a=mp['R']/2;
        printf("%d\n",a);
    }
    return 0;
}
