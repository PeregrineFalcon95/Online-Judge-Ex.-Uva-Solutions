#include<stdio.h>
int main()
{
    int n,i,j,a,b,c,d,e,f,array[3002],array2[3002];
    while(scanf("%d",&n)==1)
    {
        d=0;
        e=0;
        if(n==1)
        {
            e=1;
            scanf("%d",&f);
            d=0;
        }
        else if(e==0)
        {
            for(i=0; i<n; i++)
            {
                scanf("%d",&array[i]);
            }
            c=0;
            for(i=0; i<n-1; i++)
            {
                array2[i]=array[i]-array[i+1];
                c++;
            }
            for(i=0; i<c; i++)
            {
                if(array2[i]<0)
                    array2[i]=array2[i]*(-1);
            }
            for(j=0; j<c-1; j++)
            {
                for(i=j+1; i<c; i++)
                {
                    if(array2[i]<array2[j])
                    {
                        a=array2[i];
                        array2[i]=array2[j];
                        array2[j]=a;
                    }
                }
            }
            for(i=0; i<c;)
            {
                if(array2[i]!=++i)
                {
                    d=1;
                    break;
                }
            }
        }
        if(d==0)
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    }
    return 0;
}
