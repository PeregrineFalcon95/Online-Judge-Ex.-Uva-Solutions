#include<stdio.h>
int main()
{
    int k,i,j,c,f,l,t;
    while(scanf("%d %d",&i,&j)==2)
    {
        printf("%d %d ",i,j);
        if(i>j){
            t=i;
            i=j;
            j=t;
        }
        f=0;
        for(l=i; l<=j; l++)
        {
            k=l;
            c=1;
            while(k>1)
            {
                if(k%2!=0)
                {
                    k=3*k+1;
                }
                else
                {
                    k/=2;
                }
                c++;
            }
            if(c>f)
            {
                f=c;
            }
        }
        printf("%d\n",f);

    }
    return 0;
}

