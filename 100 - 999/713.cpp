#include<bits/stdc++.h>
using namespace std;
void bigsum(string a, string b);
int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        string a,b;
        cin>>a>>b;
        bigsum(a,b);
    }
    return 0;
}
void bigsum(string a, string b)
{
    char ans[210];
    memset(ans, 0, sizeof ans);
    int len=a.size();
    int len2=b.size();
    int mx=max(len2,len);
    int c,d,e,rem=0,f=0;
    for(int i=0; i<mx; i++)
    {
        if(i<len)c=a[i]-'0';
        else c=0;
        if(i<len2)d=b[i]-'0';
        else d=0;
        e=c+d+rem;
        rem=0;
        if(e>9)
        {
            ans[i]=ans[i]=e%10+'0';
            rem=e/10;
        }
        else ans[i]=e+'0';
        f++;
    }
    if(rem)ans[f++]=rem+'0';
    ans[f]=0;
    c=0;
    for(int i=0; i<f; i++)
    {
        if(c==0&&ans[i]=='0')continue;
        else {printf("%c",ans[i]);c=1;}
    }
    printf("\n");
}

