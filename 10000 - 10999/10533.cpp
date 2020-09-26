#include<bits/stdc++.h>
using namespace std;
bool status[1000020];
int prime_digit_number[1000020];
void prime();
int main()
{
    prime();
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        printf("%d\n",prime_digit_number[m]-prime_digit_number[n-1]);
    }
    return 0;
}
void prime()
{
    for(int i=4; i<=1000000; i+=2)status[i]=1;
    status[1]=1;
    int n=1000000;
    int sq=sqrt(n);
    for(int i=3; i<=sq; i+=2)
    {
        if(status[i]==0)
        {
            for(int j=i*i; j<=n; j+=2*i)status[j]=1;
        }
    }
    prime_digit_number[2]=1;
    int c=1;
    for(int i=3; i<=n; i++)
    {
        prime_digit_number[i]=c;
        if(status[i]==0)
        {
            int b=i,a=0;
            while(b>0)
            {
                a+=(b%10);
                b/=10;
            }
            if(status[a]==0)prime_digit_number[i]=++c;
        }
    }
}

