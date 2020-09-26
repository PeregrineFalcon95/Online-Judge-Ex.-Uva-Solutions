#include<stdio.h>
int main()
{
    int t,n,p,q,i,j,k,a,b;
    while(scanf("%d",&t)==1)
    {
        for(j=1; j<=t; j++)
        {
            scanf("%d %d %d",&n,&p,&q);
            int array[n];
            for(i=0; i<n; i++)
            {
                scanf("%d",&array[i]);
            }
            for(k=0; k<n-1; k++)
            {
                for(i=k; i<n; i++)
                {
                    if(array[k]>array[i])
                    {
                        a=array[k];
                        array[k]=array[i];
                        array[i]=a;
                    }
                }
            }
            a=b=0;
            for(i=0; i<p; i++)
            {
                a+=array[i];
                if(a>q || i>=p || i>=n)
                    break;
                b++;
            }
            printf("Case %d: %d\n",j,b);
        }
    }
    return 0;
}
