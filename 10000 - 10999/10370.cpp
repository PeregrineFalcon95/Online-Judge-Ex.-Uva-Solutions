#include<stdio.h>
int main()
{
    int a,b,d,i,j,n,t;
    double c,e,f;
    while(scanf("%d",&n)==1)
    {
        for(i=1; i<=n; i++)
        {
            a=d=0;
            scanf("%d",&t);
            int array[t];
            for(j=0; j<t; j++)
            {
                scanf("%d",&array[j]);
                a+=array[j];
            }
            c=(double)a/t;
            for(j=0; j<t; j++)
            {
                if(array[j]>c)
                    d++;
            }
            f=(double)d/t;
            printf("%.3lf%c\n",f*100,37);
        }
    }
    return 0;
}
