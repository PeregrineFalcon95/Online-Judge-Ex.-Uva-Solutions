#include<bits/stdc++.h>
using namespace std;
vector < string > fi;
string s="1";
string s2="1";
void fibo(int n);
int main()
{
    fi.push_back("0");
    fi.push_back(s);
    fi.push_back(s2);
    fibo(3);
    int t;
    while(scanf("%d",&t)==1)cout<<fi[t]<<endl;
    return 0;
}
void fibo(int n)
{
    if(n==5001)return;
    char st[1100];
    reverse(s.begin(),s.end());
    reverse(s2.begin(),s2.end());
    int len1=s.size();
    int len2=s2.size();
    int rem=0,a=0,b=0,c=0,e=0,mx=max(len1,len2);
    for(int i=0; i<mx; i++)
    {
        if(i<len1)a=s[i]-'0';
        else a=0;
        if(i<len2)b=s2[i]-'0';
        else b=0;
        c=a+b+rem;
        rem=0;
        if(c>9){st[i]=c%10+'0';rem=c/10;}
        else st[i]=c+'0';
        e++;
    }
    if(rem)st[e++]=rem+'0';
    st[e]=0;
    s=s2;
    s2=st;
    reverse(s.begin(),s.end());
    reverse(s2.begin(),s2.end());
    fi.push_back(s2);
    fibo(n+1);
}


