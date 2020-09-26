#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        double sum=0;
        int a,b,c;
        char ch[3];
        scanf("%d",&a);
        map < char, int > mp;
        string s;
        for(int i=0; i<a; i++){scanf("%s%d",&ch,&b);mp[ch[0]]=b;}
        scanf("%d",&c);
        cin.ignore();
        for(int i=0; i<c; i++)
        {
            getline(cin,s);
            int len=s.size();
            for(int i=0; i<len; i++)
            {
                char e=s[i];
                sum+=mp[e];
            }
        }
        printf("%.2lf$\n",(sum)/100);
    }
    return 0;
}



