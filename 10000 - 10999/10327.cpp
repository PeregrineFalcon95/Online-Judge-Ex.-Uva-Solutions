#include<stdio.h>
int main()
{
    int n,b,c,i,j,array[1001];
    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&array[i]);
        }
        b=0;
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(array[i]>array[j])
                {
                    b++;
                }
            }
        }
        printf("Minimum exchange operations : %d\n",b);
    }
    return 0;
}
