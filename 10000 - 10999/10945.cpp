#include<bits/stdc++.h>
using namespace std;
int main()
{
    char sentence[100000];
    while(scanf(" %[^\n]",&sentence)!=EOF)
    {
        int len=strlen(sentence);
        char cpy[len];
        if(strcmp(sentence,"DONE")==0)break;
        int a=0;
        for(int i=0; i<len; i++)
        {
            sentence[i]=tolower(sentence[i]);
            if((sentence[i]>=65&&sentence[i]<=90)||(sentence[i]>=90&&sentence[i]<=122))cpy[a++]=sentence[i];
        }
        cpy[a]=0;
        int len2=strlen(cpy);
        char c[len2];
        strcpy(c,cpy);
        reverse(c,c+len2);
        if(strcmp(cpy,c)==0)printf("You won't be eaten!\n");
        else printf("Uh oh..\n");
    }
    return 0;
}
