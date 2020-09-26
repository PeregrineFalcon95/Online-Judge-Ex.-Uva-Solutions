#include<bits/stdc++.h>
using namespace std;
#define sc scanf
#define pi printf
int main()
{
    char str[20];
    int n,t=0;
    while(sc("%s",&str))
    {
        if(strcmp(str,"#")==0)break;
        else if(strcmp(str,"HELLO")==0)pi("Case %d: ENGLISH\n",++t);
        else if(strcmp(str,"HOLA")==0)pi("Case %d: SPANISH\n",++t);
        else if(strcmp(str,"HALLO")==0)pi("Case %d: GERMAN\n",++t);
        else if(strcmp(str,"BONJOUR")==0)pi("Case %d: FRENCH\n",++t);
        else if(strcmp(str,"CIAO")==0)pi("Case %d: ITALIAN\n",++t);
        else if(strcmp(str,"ZDRAVSTVUJTE")==0)pi("Case %d: RUSSIAN\n",++t);
        else pi("Case %d: UNKNOWN\n",++t);
    }
    return 0;
}

