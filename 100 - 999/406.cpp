#include<bits/stdc++.h>
using namespace std;
int status[1020];
int prime[200];
int main()
{
    int m=1010;
    int sq=sqrt(m);
    for(int i=4; i<=m; i+=2)status[i]=1;
    for(int i=3; i<=sq; i+=2)
    {
        if(status[i]==0)
        {
            for(int j=i*i; j<=m; j+=2*i)status[j]=1;
        }
    }
    int num=0;
    for(int i=1; i<=m; i++)
    {
        if(status[i]==0)
        {
            prime[++num]=i;
        }
    }
    int n,c;
    while(scanf("%d%d",&n,&c)==2)
    {
        int b=0;
        for(int i=1; ; i++)
        {
            if(prime[i]<=n) ++b;
            else break;
        }
        if(2*c>=b)
        {
            printf("%d %d:",n,c);
            for(int i=1; i<=b; i++)printf(" %d",prime[i]);
            printf("\n");
        }
        else if(b%2!=0)
        {
            printf("%d %d:",n,c);
            vector <int> v;
            int mid=b/2+1;
            v.push_back(prime[mid]);
            for(int i=mid+1,j=mid-1; j!=(mid-c); i++,j--)
            {
                v.push_back(prime[i]);
                v.push_back(prime[j]);
            }
            sort(v.begin(),v.end());
            for(auto it:v) printf(" %d",it);
            printf("\n");
        }
        else
        {
            printf("%d %d:",n,c);
            vector <int> v;
            int mid=b/2;
            int f=0;
            for(int i=mid,j=mid+1; f!=c; j++,i--)
            {
                f++;
                v.push_back(prime[i]);
                v.push_back(prime[j]);
            }
            sort(v.begin(),v.end());
            for(auto it:v)printf(" %d",it);
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
