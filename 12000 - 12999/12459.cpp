#include<bits/stdc++.h>
using namespace std;
long long int fibo[81];
void fib()
{
    fibo[1]=1;
    fibo[2]=2;
    for(int i=3; i<=80; i++)fibo[i]=fibo[i-1]+fibo[i-2];
}
int main()
{
    fib();
    int a;
    while(scanf("%d",&a)==1&&a!=0)
    {
        printf("%lld\n",fibo[a]);
    }
    return 0;
}
