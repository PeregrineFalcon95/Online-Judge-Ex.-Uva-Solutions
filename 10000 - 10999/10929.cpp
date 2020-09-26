#include<bits/stdc++.h>
using namespace std;
#define sc scanf
#define pi printf
int main()
{
    char str[1002];
    while(sc("%s",&str)!=EOF)
    {
        if(strcmp(str,"0")==0)break;
        int a=0,l=strlen(str);
        for(int i=0; i<l; i++)
        {
            a=(a*10+str[i]-'0')%11;
        }
        if(!a)pi("%s is a multiple of 11.\n",str);
        else pi("%s is not a multiple of 11.\n",str);
    }
    return 0;
}

