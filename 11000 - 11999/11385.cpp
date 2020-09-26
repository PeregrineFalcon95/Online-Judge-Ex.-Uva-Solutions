#include<bits/stdc++.h>
using namespace std;
long long int fibo[48];
void fib();
int main()
{
    fib();
    int n,t;
    while(scanf("%d",&t)==1)
    {
        while(t--)
        {
            scanf("%d",&n);
            int fi[n+1];
            for(int i=1; i<=n; i++)scanf("%d",&fi[i]);
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=47; j++)
                {
                    if(fibo[j]==fi[i])
                    {
                        fi[i]=j;
                        break;
                    }
                }
            }
            int ma=*max_element(fi+1,fi+(n+1));
            char str[205];
            scanf(" %[^\n]",&str);
            int a=1,b=0,len=strlen(str);
            char ans[ma+2];
            memset(ans,' ',sizeof ans);
            for(int i=0; i<len; i++)
            {
                if(a>=(sizeof fi)/4)break;
                if(str[i]>=65&&str[i]<=90)
                {
                    b=fi[a++];
                    ans[b-1]=str[i];
                }
            }
            ans[ma]=0;
            printf("%s\n",ans);
        }
    }
    return 0;
}
void fib()
{
    fibo[1]=1;
    fibo[2]=2;
    for(int i=3; i<=47; i++)fibo[i]=fibo[i-1]+fibo[i-2];
}

