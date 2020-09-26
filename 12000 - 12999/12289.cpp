#include<bits/stdc++.h>
using namespace std;
#define sc scanf
#define pi printf
int main()
{
    char str[5];
    int a,l,t,b,c;
    while(sc("%d",&t)==1)
    {
        while(t--)
        {
            sc("%s",&str);
            l=strlen(str);
            if(strcmp(str,"one")==0)pi("1\n");
            else if(strcmp(str,"two")==0)pi("2\n");
            else if(l==5)pi("3\n");
            else
            {
                b=c=0;
                if(str[0]=='o')b++;
                if(str[1]=='n')b++;
                if(str[2]=='e')b++;
                if(str[0]=='t')c++;
                if(str[1]=='w')c++;
                if(str[2]=='o')c++;
                if(b>c)pi("1\n");
                if(c>b)pi("2\n");
            }
        }
    }
    return 0;
}
