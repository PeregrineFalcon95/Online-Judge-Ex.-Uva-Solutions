#include<stdio.h>
#include<string.h>
int main()
{
    int i,n,c;
    char s[1000];
    while(gets(s))
    {
        c=0;

        n=strlen(s);
        for(i=0; i<n; i++)
        {
            if(((s[i]>=65&&s[i]<=90)||(s[i]>=97&&s[i]<=122))&&((s[i+1]<65||s[i+1]>90)&&(s[i+1]<97||s[i+1]>122)))
            {
                c++;
            }
        }
        printf("%d\n",c);
    }
    return 0;
}

