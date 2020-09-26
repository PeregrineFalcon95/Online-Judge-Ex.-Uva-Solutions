#include<bits/stdc++.h>
using namespace std;
#define sc scanf
#define pi printf
int main()
{
    int a,b,i,l;
    char ch,str[10002];
    while(sc(" %[^\n]",str))
    {
        if(strcmp(str,"*")==0)break;
        l=strlen(str);
        a=b=0;
        ch=str[0];
        for(i=0; i<l; i++)
        {
            if(a==0)
            {
                if(ch==str[i]||ch==(str[i]+32)||ch==(str[i]-32))
                {
                    b=0;
                }
                else
                {
                    b=1;
                    break;
                }
            }
            a=1;
            if(str[i]==' ')a=0;
        }
        if(b==0)pi("Y\n");
        if(b==1)pi("N\n");
    }
    return 0;
}
