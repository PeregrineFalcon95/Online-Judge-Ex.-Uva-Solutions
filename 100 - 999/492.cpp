#include<bits/stdc++.h>
using namespace std;
bool isVowel (char);
char str[1000000],temp[1000000],xtra[1000000];
int main()
{
    while(gets(str))
    {
        int len=strlen(str);
        int a=0,b=0;
        for(int i=0; i<len; i++)
        {
            if(str[i]!=' '&&((str[i]>=65&&str[i]<=90)||(str[i]>=97&&str[i]<=122)))temp[a++]=str[i];
            if(((str[i]<65||str[i]>122)||(str[i]>90&&str[i]<97)))xtra[b++]=str[i];
            if(str[i]==' '||i==len-1||(((str[i]<65||str[i]>122)||(str[i]>90&&str[i]<97))))
            {
                if (isVowel(temp[0])==0&&a!=0)
                {
                    temp[a++]='a';
                    temp[a++]='y';
                    temp[a]=0;
                    xtra[b]=0;
                    a=b=0;
                    printf("%s%s",temp,xtra);
                }
                else if(isVowel(temp[0])==1&&a!=0)
                {
                    temp[a++]=temp[0];
                    temp[a++]='a';
                    temp[a++]='y';
                    temp[a]=0;
                    for(int j=1; j<a; j++)printf("%c",temp[j]);
                    printf("%s",xtra);
                    a=b=0;
                }
                else
                {
                    printf("%s",xtra);
                    b=0;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
bool isVowel(char func)
{

    if(func =='a')
        return 0;
    if(func =='e')
        return 0;
    if(func =='i')
        return 0;
    if(func =='o')
        return 0;
    if(func =='u')
        return 0;
    if(func =='A')
        return 0;
    if(func =='E')
        return 0;
    if(func =='I')
        return 0;
    if(func =='O')
        return 0;
    if(func =='U')
        return 0;
    else
        return 1;
}
