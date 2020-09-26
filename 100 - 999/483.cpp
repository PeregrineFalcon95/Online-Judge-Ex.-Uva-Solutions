#include<stdio.h>
#include<string.h>
int main()
{
    int a,b,c,i,j;
    char str[1002];
    while(gets(str))
    {
        a=strlen(str);
        b=-1;
        for(i=0; i<a; i++)
        {
            if(str[i]==' ')
            {
                for(j=i-1; j>b; j--)
                {
                    printf("%c",str[j]);
                }
                printf(" ");
                b=i;
            }
        }
        for(i=a-1; i>b; i--)
            printf("%c",str[i]);
        printf("\n");
    }
    return 0;
}
