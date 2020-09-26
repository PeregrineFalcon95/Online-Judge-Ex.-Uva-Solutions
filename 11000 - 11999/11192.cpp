#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    char ch,str[110];
    while(scanf("%d",&n)==1&&n!=0)
    {
        scanf("%c%s",&ch,&str);
        int len=strlen(str);
        int b=0,a=len/n;
        while(b!=len)
        {
            reverse(str+b,str+(b+a));
            b+=a;
        }
        printf("%s\n",str);
    }
    return 0;
}
