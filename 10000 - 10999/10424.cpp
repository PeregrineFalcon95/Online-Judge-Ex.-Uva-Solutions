#include<bits/stdc++.h>
using namespace std;
#define lld long long int
int main()
{
    char name1[30],name2[30];
    while(scanf(" %[^\n]",&name1)!=EOF)
    {
        scanf(" %[^\n]",&name2);
        int len1=strlen(name1);
        int len2=strlen(name2);
        int sum1=0,sum2=0;
        for(int i=0; i<len1; i++)
        {
            if(name1[i]>=65&&name1[i]<=90)sum1+=name1[i]-64;
            else if(name1[i]>=97&&name1[i]<=122)sum1+=name1[i]-96;
        }
        for(int i=0; i<len2; i++)
        {
            if(name2[i]>=65&&name2[i]<=90)sum2+=name2[i]-64;
            else if(name2[i]>=97&&name2[i]<=122)sum2+=name2[i]-96;
        }
        int c=0,d=0;
        while(1)
        {
            int m=0;
            while(sum1>0)
            {
                m+=sum1%10;
                sum1/=10;
            }
            sum1=m;
            if(sum1<=9)break;
        }
        while(1)
        {
            int m=0;
            while(sum2>0)
            {
                m+=sum2%10;
                sum2/=10;
            }
            sum2=m;
            if(sum2<=9)break;
        }
        double a=(double)min(sum1,sum2);
        double b=(double)max(sum1,sum2);
        double ans=a/b*100;
        printf("%.2f %\n",ans);
    }
    return 0;
}
