#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d,e,n,t;
    while(scanf("%d",&n)==1&&n!=0)
    {
        while(n--)
        {
            scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
            if(a>127&&b>127&&c>127&&d>127&&e<=127)printf("E\n");
            else if(a>127&&b>127&&c>127&&e>127&&d<=127)printf("D\n");
            else if(a>127&&b>127&&d>127&&e>127&&c<=127)printf("C\n");
            else if(a>127&&c>127&&d>127&&e>127&&b<=127)printf("B\n");
            else if(b>127&&c>127&&d>127&&e>127&&a<=127)printf("A\n");
            else printf("*\n");
        }
    }
    return 0;
}
