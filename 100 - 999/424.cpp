#include<bits/stdc++.h>
using namespace std;
char result[105];
void bigsum(char str[105])
{
    int len_result=strlen(result), len_str=strlen(str);
    reverse(result,result+len_result);
    reverse(str,str+len_str);
    int x,carry=0,mlen=max(len_result,len_str);
    for(int i=0; i<mlen; i++)
    {
        if(i>=len_result)result[i]='0';
        if(i>=len_str)str[i]='0';
        x=result[i]+str[i]-'0'-'0'+carry;
        result[i]='0'+x%10;
        carry=x/10;
    }
    while(carry)
    {
        result[mlen++]='0'+(carry%10);
        carry/=10;
    }
    result[mlen]=0;
    reverse(result,result+mlen);
}
int main()
{
    while(1)
    {
        char str[105];
        scanf("%s",&str);
        if(strcmp(str,"0")==0)break;
        bigsum(str);
    }
    printf("%s\n",result);
    return 0;
}

