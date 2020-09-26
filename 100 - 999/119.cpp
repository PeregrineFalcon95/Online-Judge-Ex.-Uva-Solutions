#include<bits/stdc++.h>
using namespace std;
#define sc scanf
#define pi printf
int main()
{
    int gain[15],loss[15],a,b,c,i,j,k,l,n,m,flag=0;
    char str[15],str2[15],name[12][15];
    while(sc("%d",&n)==1)
    {
        if(flag) puts(""); flag = 1;

        for(i=0;i<=n;i++)
        {
            gain[i]=0;
            loss[i]=0;
        }
        for(i=0;i<n;i++)sc("%s",&name[i]);

        for(i=0;i<n;i++)
        {
            sc("%s%d%d",&str,&a,&b);
            if(!b) continue;
            c=a%b;
            for(j=0;j<n;j++)
            {
                if(strcmp(str,name[j])==0)
                {
                    loss[j]+=(a-c);
                    for(k=0;k<b;k++)
                    {
                        sc("%s",str);
                        for(l=0;l<n;l++)
                        {
                            if(strcmp(str,name[l])==0)
                            {
                                gain[l]+=(a/b);
                            }
                        }
                    }

                    break;
                }
            }
        }
        for(i=0;i<n;i++)pi("%s %d\n",name[i],(gain[i]-loss[i]));
    }
    return 0;
}

