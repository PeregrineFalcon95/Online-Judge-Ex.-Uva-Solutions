#include<bits/stdc++.h>
using namespace std;
bool status[2010];
void sieve();
int main()
{
    int n,m=0;
    sieve();
    while(scanf("%d",&n)==1)
    {
        m=0;
        while(n--)
        {
            int ara[65];
            memset(ara, 0, sizeof ara);
            char str[2010];
            scanf("%s",&str);
            int len=strlen(str);
            for(int i=0; i<len; i++)
            {
                if(str[i]>=65&&str[i]<=90)
                {
                    ara[str[i]-55]++;
                }
                else if(str[i]>=48&&str[i]<=57)
                {
                    ara[str[i]-48]++;
                }
                else if(str[i]>=97&&str[i]<=122)
                {
                    ara[str[i]-59]++;
                }
            }
            vector<int>v;
            for(int i=0; i<=63; i++)
            {
                if(status[ara[i]]==0)v.push_back(i);
            }
            printf("Case %d: ",++m);
            int a=0;
            for(int i=0; i!=v.size(); i++)
            {
                if(v[i]>=0&&v[i]<=9)
                {
                    printf("%c",v[i]+48);
                    a++;
                }
                else if(v[i]>=10&&v[i]<=35)
                {
                    printf("%c",v[i]+55);
                    a++;
                }
                else if(v[i]>=36&&v[i]<=63)
                {
                    printf("%c",v[i]+59);
                    a++;
                }
            }
            if(a==0)printf("empty");
            printf("\n");
        }
    }
    return 0;
}
void sieve()
{
    int n=2001;
    status[0]=1;
    status[1]=1;
    int sq=sqrt(n);
    for(int i=4; i<=n; i+=2)status[i]=1;
    for(int i=3; i<=sq; i+=2)
    {
        if(status[i]==0)
        {
            for(int j=i*i; j<=n; j+=2*i)status[j]=1;
        }
    }
}

