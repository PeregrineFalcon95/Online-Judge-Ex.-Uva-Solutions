#include<stdio.h>
int main()
{
    int a,b,x,y,n,i;
    while(scanf("%d",&n)==1 && n!=0)
    {
        scanf("%d %d",&x,&y);
        for(i=1; i<=n; i++)
        {
            scanf("%d %d",&a,&b);
            if(a>x && b>y)
                printf("NE\n");
            else if(a<x && b>y)
                printf("NO\n");
            else if(a<x && b<y)
                printf("SO\n");
            else if(a>x && b<y)
                printf("SE\n");
            else
                printf("divisa\n");
        }
    }
    return 0;
}
