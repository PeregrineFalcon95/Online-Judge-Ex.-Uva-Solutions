#include<bits/stdc++.h>
using namespace std;
#define sc scanf
#define pi printf
int main()
{
    int i,n,l,a,b,ar[30];
    char str[210];
    while(sc("%d",&n)==1)
    {
        while(n--)
        {
            for(i=1; i<27; i++)ar[i]=0;
            sc(" %[^\n]",&str);
            l=strlen(str);
            for(i=0; i<l; i++)
            {
                if(str[i]>=65&&str[i]<=90)
                {
                    a=str[i]-64;
                    ar[a]++;
                }
                else if(str[i]>=97&&str[i]<=122)
                {
                    a=str[i]-96;
                    ar[a]++;
                }
            }
            a=0;
            for(i=1; i<=26; i++)
            {
                if(ar[i]>=a)a=ar[i];
            }
            b=0;
            for(i=1; i<=26; i++)
            {
                if(ar[i]==a)
                {
                    str[b+1]=i+96;
                    b++;
                }
            }
            for(i=1; i<=b; i++)pi("%c",str[i]);
            pi("\n");
        }
    }
    return 0;
}

