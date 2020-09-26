#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,n,m,a=0,b=1;
    while(scanf("%d %d",&n,&m)==2 &&(n!=0||m!=0))
    {
        char str[n][m];
        if(a!=0)
            printf("\n");
        for(i=0; i<n; i++)
        {
            scanf("%s",str[i]);
            for(j=0; j<m; j++)
            {
                if(str[i][j]!='*')
                    str[i][j]='0';
            }
        }
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(str[i][j]=='*')
                {
                    if(str[i-1][j-1]!='*'&&(i-1)>=0&&(j-1)>=0)
                        str[i-1][j-1]++;
                    if(str[i-1][j]!='*'&& (i-1)>=0)
                        str[i-1][j]++;
                    if(str[i-1][j+1]!='*'&&(i-1)>=0&&(j+1)<m)
                        str[i-1][j+1]++;
                    if(str[i][j-1]!='*'&&(j-1)>=0)
                        str[i][j-1]++;
                    if(str[i][j+1]!='*'&&(j+1)<m)
                        str[i][j+1]++;
                    if(str[i+1][j-1]!='*'&&(i+1)<n&&(j-1)>=0)
                        str[i+1][j-1]++;
                    if(str[i+1][j]!='*'&&(i+1)<n)
                        str[i+1][j]++;
                    if(str[i+1][j+1]!='*'&&(i+1)<n&&(j+1)<m)
                        str[i+1][j+1]++;
                }
            }
        }
        printf("Field #%d:\n",b);
        b++;
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                printf("%c",str[i][j]);
            }
            printf("\n");
        }
        a++;
    }
    return 0;
}
