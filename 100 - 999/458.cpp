//UVA-458
#include<stdio.h>
#include<string.h>
int main()
{
    int a,i;
    char str[1000];
    while(gets(str))
    {
        a=strlen(str);
        for(i=0; i<a; i++)
        {
            str[i]=str[i]-7;
        }
        printf("%s\n",str);
    }
    return 0;
}

