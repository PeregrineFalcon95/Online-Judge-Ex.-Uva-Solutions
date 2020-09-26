#include<stdio.h>
#include<string.h>
int a[12];
int main()
{
    int i,n;
    char s[10];
    while(scanf("%d",&n)==1&&n!=0)
    {
        scanf(" %[^\n]",s);
        if(strcmp(s,"too high")==0)
        {
            for(i=n; i<=10; i++)
                a[i]=-1;
        }
        else if(strcmp(s,"too low")==0)
        {
            for(i=n; i>=1; i--)
                a[i]=-1;
        }
        else
        {
            if(a[n]==0)
                printf("Stan may be honest\n");
            else
                printf("Stan is dishonest\n");

            for(i=1; i<=10; i++)
                a[i]=0;
        }
    }
    return 0;
}
