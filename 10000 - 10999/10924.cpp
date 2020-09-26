#include<bits/stdc++.h>
using namespace std;
#define sc scanf
#define pi printf
#define lld long long int
int status[2000];
int main()
{
    int n=1600;
    int a=sqrt(n);
    for(int i=4;i<=n;i+=2)status[i]=1;
    for(int i=3;i<=a;i+=2)
    {
        if(status[i]==0)
        {
            for(int j=i*i;j<=n;j+=2*i)status[j]=1;
        }
    }
    char str[22];
    while(sc("%s",&str)!=EOF)
    {
        int a=0,l=strlen(str);
        for(int i=0;i<l;i++)
        {
            if(str[i]>=65&&str[i]<=90)a+=(str[i]-38);
            else a+=(str[i]-96);
        }
        if(status[a]==0)pi("It is a prime word.\n");
        else pi("It is not a prime word.\n");
    }
    return 0;
}

