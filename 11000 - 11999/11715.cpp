#include<bits/stdc++.h>
using namespace std;
int main()
{
    double u,v,t,s,a;
    int n,m=0;
    while(scanf("%d",&n)==1&&n!=0)
    {
        if(n==1)
        {
            scanf("%lf%lf%lf",&u,&v,&t);
            s=(u+v)*t/2;
            a=(v-u)/t;
            printf("Case %d: %.3lf %.3lf\n",++m,s,a);
        }
        else if(n==2)
        {
            scanf("%lf%lf%lf",&u,&v,&a);
            t=(v-u)/a;
            s=(u+v)*t/2;
            printf("Case %d: %.3lf %.3lf\n",++m,s,t);
        }
        else if(n==3)
        {
            scanf("%lf%lf%lf",&u,&a,&s);
            v=sqrt(u*u+2*a*s);
            t=(v-u)/a;
            printf("Case %d: %.3lf %.3lf\n",++m,v,t);
        }
        else if(n==4)
        {
            scanf("%lf%lf%lf",&v,&a,&s);
            u=sqrt(v*v-2*a*s);
            t=(v-u)/a;
            printf("Case %d: %.3lf %.3lf\n",++m,u,t);
        }
    }
    return 0;
}
