#include<stdio.h>
#include<string.h>
int main()
{
    int t,i,j,l,sum;
    char str[101];
    while(scanf("%d",&t)==1)
    {
        getchar();
        for(i=1; i<=t; i++)
        {
            gets(str);
            l=strlen(str);
            sum=0;
            for(j=0; j<l; j++)
            {
                if(str[j]=='a'||str[j]=='j'||str[j]=='t'||str[j]=='w'||str[j]=='m'||str[j]=='d'||str[j]=='g'||str[j]=='p'||str[j]==' ')
                    sum+=1;
                else if(str[j]=='b'||str[j]=='k'||str[j]=='u'||str[j]=='x'||str[j]=='n'||str[j]=='e'||str[j]=='q'||str[j]=='h')
                    sum+=2;
                else if(str[j]=='c'||str[j]=='v'||str[j]=='y'||str[j]=='o'||str[j]=='f'||str[j]=='r'||str[j]=='i'||str[j]=='l')
                    sum+=3;
                else if(str[j]=='s'||str[j]=='z')
                    sum+=4;
            }
            printf("Case #%d: %d\n",i,sum);
        }
    }
    return 0;
}
