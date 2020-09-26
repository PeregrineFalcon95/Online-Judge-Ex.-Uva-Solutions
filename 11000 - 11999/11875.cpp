#include<stdio.h>
int main()
{
    int a,b,c,i,j,k,n;
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
            for(k=0; k<a-1; k++)
            {
                for(i=k; i<a; i++)
                {
                    if(array[k]>array[i])
                    {
                        b=array[i];
                        array[i]=array[k];
                        array[k]=b;
                    }
                }
            }
            c=a/2;
            printf("Case %d: %d\n",j,array[c]);
        }
    }
    return 0;
}
