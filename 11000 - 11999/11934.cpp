#include<stdio.h>
int main()
{
    int a,b,c,d,f,g,l,t,i;
    while(scanf("%d %d %d %d %d",&a,&b,&c,&d,&l)==5&&(a!=0||b!=0||c!=0||d!=0||l!=0))
    {
        g=0;
        for(i=0; i<=l; i++)
        {
            f=a*(i*i)+b*i+c;
            if(f%d==0)
                g++;
        }
        printf("%d\n",g);
    }
    return 0;
}
