#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,m;
    while(scanf("%d",&t)==1)
    {
        m=0;
        while(t--)
        {
            char str[210];
            scanf("%s",&str);
            int a=0,b=0,c=0,len=strlen(str);
            printf("Case %d: ",++m);
            char ch,temp[10];
            for(int i=0; i<len; i++)
            {
                if(str[i]>=48&&str[i]<=57)
                {
                    temp[a++]=str[i];
                    temp[a]=0;
                    b=atoi(temp);
                    if(b>c)c=b;
                    b=0;
                }
                if((str[i]>=65&&str[i]<=90&&c>0)||(i==len-1&&c>0))
                {
                    for(int j=1; j<=c; j++)printf("%c",ch);
                    c=0;
                }
                if(str[i]>=65&&str[i]<=90)
                {
                    ch=str[i];
                    a=0;
                }
            }
            printf("\n");
        }
    }
    return 0;
}

