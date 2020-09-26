#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str,line[100];
    int a=0,len,ma=0;
    while(getline(cin,str))
    {
        line[a++]=str;
        len=str.size();
        ma=max(len,ma);
    }
    for(int i=0; i<ma; i++)
    {
        for(int j=a-1; j>=0; j--)
        {
            if(line[j].size()>i)printf("%c",line[j][i]);
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
}

