#include<stdio.h>
int main()
{
    int a,b,c,i,j;
    while(scanf("%d",&a)==1)
    {
        for(j=1; j<=a; j++)
        {
            scanf("%d",&b);
            int array[b];
            for(i=0; i<b; i++)
            {
                scanf("%d",&array[i]);
            }
            c=array[0];
            for(i=0; i<b; i++)
            {
                if(c<array[i])
                    c=array[i];
            }
            printf("Case %d: %d\n",j,c);
        }
    }
    return 0;
}

