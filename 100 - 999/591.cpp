#include<stdio.h>
int main()
{
    int a,b=1,c,n,d,i;
    while(scanf("%d",&n) && n!=0)
    {
        a=d=0;
        int array[n];
        for(i=0;i<n;i++)
        {
            scanf("%d",&array[i]);
            a+=array[i];
        }
        c=a/n;
        for(i=0;i<n;i++)
        {
            if(array[i]>c)
            d+=array[i]-c;
        }
        printf("Set #%d\nThe minimum number of moves is %d.\n\n",b,d);
        b++;
    }
    return 0;
}

