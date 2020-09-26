#include<bits/stdc++.h>
using namespace std;
#define sc scanf
#define pi printf
int main()
{
    int n,a,b,c,d,i,l;
    char str[10100];
    while(sc("%d",&n)==1)
    {
        while(n--)
        {
            sc(" %[^\n]",&str);
            l=strlen(str);
            a=sqrt(l);
            if((a*a)!=l)pi("INVALID");
            else
            {
                b=c=d=0;
                for(i=0; i<l; i++)
                {
                    pi("%c",str[b]);
                    b+=a;
                    c++;
                    if(c==a)
                    {
                        c=0;
                        d++;
                        b=d;
                    }
                }
            }
            pi("\n");
        }
    }
    return 0;
}

