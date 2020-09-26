#include<stdio.h>
int main()
{
	int a,b,c,i,j,n;
	while(scanf("%d",&n)==1)
	{
    	for(i=1; i<=n; i++)
    	{
        	scanf("%d",&a);
        	b=((((((a*567)/9)+7492)*235)/47)-498);
        	for(j=1; j<=2; j++)
        	{
            	c=b%10;
            	b/=10;
        	}
        	if(c<0)
            	c=c*(-1);
        	printf("%d\n",c);
    	}
	}
	return 0;
}