#include<stdio.h>
int main()
{
    int a,n,i,j,array[10];
    while(scanf("%d",&n)==1)
    {
        printf("Lumberjacks:\n");
        for(j=1; j<=n; j++)
        {
            for(i=0; i<10; i++)
            {
                scanf("%d",&array[i]);
            }
            a=0;
            if(array[0]>array[1])
            {
                for(i=0; i<9; i++)
                {
                    if(array[i]>array[i+1])
                        a=0;
                    if(array[i]<array[i+1])
                    {
                        a=1;
                        break;
                    }
                }
            }
            if(array[0]<array[1])
            {
                for(i=0; i<9; i++)
                {
                    if(array[i]<array[i+1])
                        a=0;
                    if(array[i]>array[i+1])
                    {
                        a=1;
                        break;
                    }
                }
            }
            if(a==0)
                printf("Ordered\n");
            if(a==1)
                printf("Unordered\n");
        }
    }
    return 0;
}





//another

#include<stdio.h>
int main()
{
    int a,b,c,d,n,k,i,array[10];
    while(scanf("%d",&n)==1)
    {
        printf("Lumberjacks:\n");
        for(k=0; k<n; k++)
        {
            a=c=d=0;
            b=101;
            for(i=0; i<10; i++)
            {
                scanf("%d",&array[i]);
                if(d==0 || d==1)
                {
                    if(b>=array[i])
                    {
                        c++;
                        b=array[i];
                    }
                }
                if(c==0 || c==1)
                {
                    if(a<=array[i])
                    {
                        d++;
                        a=array[i];
                    }
                }
            }
            if(c==10 || d==10)
            {
                printf("Ordered\n");
            }
            else
            {
                printf("Unordered\n");
            }
        }
    }
    return 0;
}
