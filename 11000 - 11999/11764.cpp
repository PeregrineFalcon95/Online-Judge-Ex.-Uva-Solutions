#include<stdio.h>
int main()
{
    int a,b,c,i,j,n;
    while(scanf("%d",&n)==1)
    {
        for(j=1; j<=n; j++)
        {
            scanf("%d",&a);
            int array[a];
            for(i=0; i<a; i++)
            {
                scanf("%d",&array[i]);
            }
            b=c=0;
            if(a>1)
            {
                for(i=0; i<a-1; i++)
                {
                    if(array[i]<array[i+1])
                        b++;
                    if(array[i]>array[i+1])
                        c++;
                }
            }
            if(a==1)
                printf("Case %d: 0 0\n",j);
            else
                printf("Case %d: %d %d\n",j,b,c);
        }
    }
    return 0;
}
