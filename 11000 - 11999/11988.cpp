#include<bits/stdc++.h>
using namespace std;
int main()
{
    char text[100100];
    while(gets(text))
    {
        int d=0,c=0,b=0,a=0,len=strlen(text);
        char sen[len+1];
        stack<string>str;
        char temp[100010];
        temp[0]=0;
        for(int i=0; i<len; i++)
        {
            if(a==1&&text[i]!=']'&&text[i]!='[')temp[b++]=text[i];
            else if(text[i]=='[')
            {
                temp[b]=0;
                str.push(temp);
                a=1;
                b=0;
            }
            else if(text[i]==']')
            {
                a=0;
                temp[b]=0;
                b=0;
                str.push(temp);
            }
            else if(a==0&&text[i]!='['&&text[i]!=']')sen[c++]=text[i];
        }
        sen[c]=0;
        if(b!=0)
        {
            temp[b]=0;
            str.push(temp);
        }
        if(str.size()!=0)
        {
            while(!str.empty())
            {
                cout<<str.top();
                str.pop();
            }
        }
        printf("%s\n",sen);
    }
    return 0;
}


