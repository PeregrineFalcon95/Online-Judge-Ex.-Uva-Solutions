#include<bits/stdc++.h>
using namespace std;
#define sc scanf
#define pi printf
int main()
{
    int n=0,t;
    char str[10];
    while(sc("%s",&str)!=EOF)
    {
        if(strcmp(str,"*")==0)break;
        else if(strcmp(str,"Hajj")==0)pi("Case %d: Hajj-e-Akbar\n",++n);
        else pi("Case %d: Hajj-e-Asghar\n",++n);
    }
    return 0;
}
