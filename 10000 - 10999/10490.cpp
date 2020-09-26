#include<bits/stdc++.h>
using namespace std;
//2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31
//if(p to the power of 2)-1 is a prime number it will be a perfect, if a positive num is the sum of all his prime divisors, it is a perfect number
int main()
{
    bool prime[]= {1,1,0,0,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,1,1,0,1,0};
    int n,a,b;
    while(scanf("%d",&n)==1&&n!=0)
    {
        if(n==2)printf("Perfect: 6!\n");
        else if(n==3)printf("Perfect: 28!\n");
        else if(n==5)printf("Perfect: 496!\n");
        else if(n==7)printf("Perfect: 8128!\n");
        else if(n==13)printf("Perfect: 33550336!\n");
        else if(n==17)printf("Perfect: 8589869056!\n");
        else if(n==19)printf("Perfect: 137438691328!\n");
        else if(n==31)printf("Perfect: 2305843008139952128!\n");
        else if(prime[n]==0)printf("Given number is prime. But, NO perfect number is available.\n");
        else printf("Given number is NOT prime! NO perfect number is available.\n");
    }
    return 0;
}

