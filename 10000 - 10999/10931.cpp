#include<bits/stdc++.h>
using namespace std;
char binary[35];
void converter(int n)
{
    int i=0;
    while(n>=1)
    {
        binary[i++]=n%2+'0';
        n/=2;
    }
    binary[i]=0;
}
int main()
{
    int n;
    while(scanf("%d",&n)==1&&n!=0)
    {
        converter(n);
        int l=strlen(binary),m=0;
        reverse(binary,binary+l);
        for(int i=0; i<l; i++)if(binary[i]=='1')m++;
        printf("The parity of %s is %d (mod 2).\n",binary,m);
    }
    return 0;
}
