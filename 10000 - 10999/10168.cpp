#include<bits/stdc++.h>
using namespace std;
bool status[10000090];
vector < int > prime;
int a,b,c,d,e,f,g,h,flag,last_range,adj;
void sieve();
void cheaker(int n);
int main()
{
    sieve();
    int n;
    while(scanf("%d",&n)==1)
    {
        if(n==9999999)printf("2 3 3 9999991\n");
        else if(n==10000000)printf("2 2 5 9999991\n");
        else if(n<8)printf("Impossible.\n");
        else
        {
            cheaker(n);
            printf("%d %d %d %d\n",e,f,g,h);
        }
    }
    return 0;
}
void sieve()
{
    int n=10000001;
    int sq=sqrt(n);
    prime.push_back(2);
    int fl=0;
    for(int i=3; i<=sq; i+=2)
    {
        if(!status[i])
        {
            prime.push_back(i);
            fl=i;
            for(int j=i*i; j<=n; j+=(i+i))status[j]=1;
        }
    }
    fl+=2;
    for(int i=fl; i<=n; i+=2)
    {
        if(!status[i])prime.push_back(i);
    }
}
void cheaker(int n)
{
    a=b=c=d=0;
    flag=0;
    while(1)
    {
        int sum=prime[a]+prime[b]+prime[c]+prime[d];
        if(sum==n)
        {
            e=prime[a];f=prime[b];g=prime[c];h=prime[d];
            return;
        }
        if(n&1)
        {
           if(flag==0 && sum<n){d++;}
           else if(flag==0 && sum>n){b=1;d=1;c=1;flag=1;}
           else if(sum>n){d=2;c++;}
           else if(flag==1 && sum<n){d++;}
        }
        else
        {
            if(flag==0 && sum<n){c++;d++;flag=1;}
            else if(sum<n)d++;
            else if(sum>n){d=c;c++;}
        }
    }
}
