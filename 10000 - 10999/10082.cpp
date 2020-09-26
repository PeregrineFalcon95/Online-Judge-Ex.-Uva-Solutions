//problem: 10079
#include<stdio.h>
int main()
{
    long long int N,p;
    while(scanf("%lld",&N)==1){
        if(N<0){
            return 0;
        }
        else if(0<=N<=210000000){
            p=1+N*(N+1)/2;
            printf("%lld\n",p);
        }
    }
}
