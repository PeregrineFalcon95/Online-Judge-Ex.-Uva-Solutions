#include<stdio.h>
#include<string.h>
int main()
{
    int t,n,i,k,l,a,b,c,e,g,f,h;
    char str[22];
    while(scanf("%d",&t)==1)
    {
        for(k=1; k<=t; k++)
        {
            scanf("%d",&n);
            int array[n],array2[n];
            for(l=0; l<n; l++)
            {
                scanf("%s",str);
                c=strlen(str);
                a=0;
                for(i=0; i<c; i++)
                {
                    a+=str[i];
                }
                array[l]=a;
                scanf("%d",&b);
                array2[l]=b;
            }
            scanf("%d",&g);
            scanf("%s",str);
            c=strlen(str);
            a=0;
            for(i=0; i<c; i++)
            {
                a+=str[i];
            }
            h=0;
            for(i=0; i<n; i++)
            {
                if(array[i]==a)
                {
                    e=array2[i];
                    h=1;
                    break;
                }
            }
            if(h==0)
                e=g+7;
            f=g+5;
            if(g>=e)
                printf("Case %d: Yesss\n",k);
            else if(g<e && e<=f)
                printf("Case %d: Late\n",k);
            else
                printf("Case %d: Do your own homework!\n",k);
        }
    }
    return 0;
}
