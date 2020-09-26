#include<bits/stdc++.h>
using namespace std;
void fastscan(int &number)
{
    register int c;

    number = 0;
    c = getchar();
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int a,n,ara[102];
    while(scanf("%d",&n)==1 && n )
    {
        getchar();
        for(int i=1; i<=100; i++)ara[i]=0;
        for(int i=1; i<=n; i++)
        {
            fastscan(a);
            ara[a]++;
        }
        int c=0;
        for(int i=1; i<=100; i++)
        {
            if(ara[i]!=0)
            {
                while(ara[i]>0)
                {
                    if(c!=0)printf(" ");
                    printf("%d",i);
                    ara[i]--;
                    c++;
                }
            }
        }
        printf("\n");
    }
    return 0;
}



/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)==1&&n!=0)
    {
        int arra[n];
        for(int i=0;i<n;i++)scanf("%d",&arra[i]);
        sort(arra,arra+n);
        for(int i=0;i<n;i++){
                printf("%d",arra[i]);
                if(i<n-1)printf(" ");
        }
        printf("\n");
    }
    return 0;
}
*/