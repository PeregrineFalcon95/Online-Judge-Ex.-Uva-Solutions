#include<stdio.h>
int main()
{
    int a,b,c,d,e,f,g,h,i,j,t;
    while(scanf("%d",&t)==1)
    {
        h=0;
        while(t--)
        {
            scanf("%d %d %d %d %d %d %d",&a,&b,&c,&d,&e,&f,&g);
            if(e>f)
            {
                if(f>g)
                    i=(e+f)/2;
                else
                    i=(e+g)/2;
            }
            if(f>g)
            {
                if(g>e)
                    i=(f+g)/2;
                else
                    i=(f+e)/2;
            }
            if(g>e)
            {
                if(f<e)
                    i=(g+e)/2;
                else
                    i=(f+g)/2;
            }
            i=i+a+b+c+d;
            if(i>=90)
                printf("Case %d: A\n",++h);
            if(i<90&&i>=80)
                printf("Case %d: B\n",++h);
            if(i<80&&i>=70)
                printf("Case %d: C\n",++h);
            if(i<70&&i>=60)
                printf("Case %d: D\n",++h);
            if(i<60)
                printf("Case %d: F\n",++h);
        }
    }
    return 0;
}
