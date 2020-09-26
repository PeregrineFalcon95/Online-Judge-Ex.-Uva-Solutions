#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m=0;
    scanf("%d",&n);
    while(n--)
    {
        getchar();
        char jud[22],con[22];
        gets(con);
        int e=0,f=0,l=strlen(con);
        for(int i=0; i<l; i++)if(con[i]!=' ')e++;
        scanf("%s",&jud);
        int a=0,b=0,len_jud=strlen(jud),len_con=strlen(con);
        for(int i=0; i<len_jud; i++)
        {
            for(int j=b; j<len_con; j++)
            {
                if(jud[i]==con[j])
                {
                    b=j+1;
                    a++;
                    break;
                }
            }
        }
        if(strcmp(con,jud)==0)printf("Case %d: Yes\n",++m);
        else if(a==len_jud&&e==len_jud)printf("Case %d: Output Format Error\n",++m);
        else printf("Case %d: Wrong Answer\n",++m);
    }
    return 0;
}
