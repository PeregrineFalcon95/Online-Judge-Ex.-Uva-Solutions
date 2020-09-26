//problem-10300
#include<stdio.h>
int main()
{
    int n,i,j,f,a,b,c,sum;
    while(scanf("%d",&n)==1)
    {
        for(i=1; i<=n; i++)
        {
            scanf("%d",&f);
            sum=0;
            for(j=1; j<=f; j++)
            {
                scanf("%d %d %d",&a,&b,&c);
                    sum+=a*c;
            }
            printf("%d\n",sum);
        }

    }
    return 0;
}
