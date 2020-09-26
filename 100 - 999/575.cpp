#include<bits/stdc++.h>
using namespace std;
int main()
{
    char skew[32];
    while(scanf("%s",&skew)!=EOF)
    {
        if(skew[0]=='0'&&skew[1]=='\0')break;
        int a,b,c,l=strlen(skew);
        int dec=0;
        for(int i=0; i<l; i++)
        {
            if(skew[i]==48)dec+=0;
            else if(skew[i]==49)dec+=(pow(2,l-i)-1);
            else if(skew[i]==50)dec+=2*(pow(2,l-i)-1);
        }
        printf("%d\n",dec);
    }
    return 0;
}
