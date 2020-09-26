#include<stdio.h>
int main()
{
    unsigned long int i,a,b,c,d,e;
    int count;
    while(scanf("%lu %lu",&a,&b)==2)
    {
        if(a==0 && b==0)
            break;
        count=e=0;
        for(i=1; i<10; i++)
        {
                c=a%10;
                d=b%10;
            if(c+d+e>=10)
            {
                e=0;
                count++;
                e++;
            }
            else
                e=0;
            a/=10;
            b/=10;
        }
        if(count==0)
            printf("No carry operation.\n");
        else if(count==1)
            printf("1 carry operation.\n");

        else
            printf("%d carry operations.\n",count);
    }
    return 0;
}
