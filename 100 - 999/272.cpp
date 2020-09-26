//problem-272
#include<stdio.h>
#include<string.h>
int main()
{
    int i,l,count=0;
    char str[10000];
    while(gets(str)!=0)
    {
        l=strlen(str);
        for(i=0; i<strlen(str); i++)
        {
            if(str[i]==34&&count==0)
            {
                printf("%c%c",96,96);
                count=1;
            }
            else if(str[i]==34&&count==1)
            {
                printf("%c%c",39,39);
                count=0;
            }
            else
            {
                printf("%c",str[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
