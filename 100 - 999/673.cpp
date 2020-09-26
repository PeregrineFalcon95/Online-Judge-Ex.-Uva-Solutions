#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        getc(stdin);
        while(n--)
        {
            char str[130];
            //getchar();
            gets(str);
            //scanf(" %[^\n]",&str);
            int a=0,b=0,c=0,len=strlen(str);
            stack<char>st;
            for(int i=0; i<len; i++)
            {
                if(str[i]==' ')c++;
                if(len==1&&str[0]!=' ')
                {
                    b=1;
                    a=1;
                    printf("No\n");
                    break;
                }
                if(str[i]!=' ')
                {
                    b=1;
                    if(str[i]==']'&&!st.empty()&&st.top()!='[')
                    {
                        printf("No\n");
                        a=1;
                        break;
                    }
                    else if(str[i]==')'&&!st.empty()&&st.top()!='(')
                    {
                        printf("No\n");
                        a=1;
                        break;
                    }
                    else if(str[i]==']'&&!st.empty()&&st.top()=='[')st.pop();
                    else if(str[i]==')'&&!st.empty()&&st.top()=='(')st.pop();
                    else if(str[i]!=')'&&str[i]!=']')st.push(str[i]);
                    else if(str[i]==')'||str[i]==']')
                    {
                        a=1;
                        printf("No\n");
                        break;
                    }
                }
            }
            if(len==c)printf("Yes\n");
            else if((!st.empty()&&a==0)||b==0)printf("No\n");
            else if(a==0)printf("Yes\n");
        }
    }
    return 0;
}



