#include<bits/stdc++.h>
using namespace std;
#define sc scanf
#define pi printf
int status[1001000];
int main()
{
    char str[300];
    int i,a,j,n=1000000;

    for(i=4; i<=n; i+=2)status[i]=1;
    a=sqrt(n);
    for(i=3; i<=a; i+=2)
    {
        if(status[i]==0)
            for(j=i*i; j<=n; j+=i)status[j]=1;
    }
    status[1]=1;

    while(sc("%s",&str))
    {
         int l=strlen(str);
        if(l==1&&str[0]=='0')break;
        int a,b,ar[1000];
        b=0;

        for(i=0; i<l; i++)
        {
            int fi=5;
            char temp[10],sz=0;
            for(j=i;(j<l)&& fi--; j++)
            {
                temp[sz++]=str[j];
                temp[sz]='\0';
                a=atoi(temp);
                if(status[a]==0&&a<=100000)
                {
                    ar[b]=a;
                    b++;
                }
            }
        }
        a=0;
        for(i=0; i<b; i++)
        {
            if(ar[i]>a)a=ar[i];
        }
        pi("%d\n",a);
    }
    return 0;
}

