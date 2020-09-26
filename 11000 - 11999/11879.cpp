#include<bits/stdc++.h>
using namespace std;
#define sc scanf
#define pi printf
int main()
{
    int a,n,c,d;
    char str[1000];
    while(sc("%s",&str)!=EOF)
    {
        if(strcmp(str,"0")==0)break;
        int l=strlen(str);
        a=0;
        for(int i=0;i<l;i++)
        {
            a=(a*10+str[i]-'0')%17;
        }
        if(!a)pi("1\n");
        else pi("0\n");
    }
    return 0;
}
