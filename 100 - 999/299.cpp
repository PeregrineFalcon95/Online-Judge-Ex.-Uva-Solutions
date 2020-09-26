#include<stdio.h>
int main()
{
    int a,b,c,d,i,j,n;
    while(scanf("%d",&n)==1)
    {
        for(a=1;a<=n;a++)
        {
            d=0;
            scanf("%d",&b);
            int array[b];
            for(i=0;i<b;i++)
            {
                scanf("%d",&array[i]);
            }
            for(i=0;i<b-1;i++)
            {
                for(j=i+1;j<b;j++)
                {
                    if(array[i]>array[j])
                    {
                        c=array[i];
                        array[i]=array[j];
                        array[j]=c;
                        d++;
                    }
                }
            }
            printf("Optimal train swapping takes %d swaps.\n",d);
        }
    }
    return 0;
}
