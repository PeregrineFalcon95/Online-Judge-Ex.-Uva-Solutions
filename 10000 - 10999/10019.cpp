#include<bits/stdc++.h>
using namespace std;
int decimal_converter(int n);
int hexa_converter(int n);
int main()
{
    int n,m;
    while(scanf("%d",&m)==1)
    {
        while(m--)
        {
            scanf("%d",&n);
            int a=decimal_converter(n);
            int b=hexa_converter(n);
            printf("%d %d\n",a,b);
        }
    }
    return 0;
}

int decimal_converter(int n)
{
    char str[100];
    int c=0;
    while(n>0)
    {
        str[c++]=n%2+'0';
        n/=2;
    }
    str[c]=0;
    int d=0;
    int l=strlen(str);
    for(int i=0; i<l; i++)
    {
        if(str[i]=='1')d++;
    }
    return d;
}

int hexa_converter(int n)
{
    char str[100];
    str[0]=0;
    while(n>0)
    {
        int a=n%10;
        n/=10;
        if(a==0)strcat(str,"0000");
        else if(a==1)strcat(str,"0001");
        else if(a==2)strcat(str,"0010");
        else if(a==3)strcat(str,"0011");
        else if(a==4)strcat(str,"0100");
        else if(a==5)strcat(str,"0101");
        else if(a==6)strcat(str,"0110");
        else if(a==7)strcat(str,"0111");
        else if(a==8)strcat(str,"1000");
        else if(a==9)strcat(str,"1001");
    }
    int l=strlen(str);
    int d=0;
    for(int i=0; i<l; i++)
    {
        if(str[i]=='1')d++;
    }
    return d;
}

