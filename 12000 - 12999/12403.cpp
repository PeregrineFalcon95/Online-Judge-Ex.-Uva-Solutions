#include<stdio.h>
int main()
{
    int a,b,c=0,i,j,n;
    char str[10];
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%s",str);
        if(str[0]==100)
        {
            scanf("%d",&b);
            c+=b;
        }
        if(str[0]==114)
        {
            printf("%d\n",c);
        }
    }
    return 0;
}
