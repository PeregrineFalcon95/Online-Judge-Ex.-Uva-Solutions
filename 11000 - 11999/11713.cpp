#include<bits/stdc++.h>
using namespace std;
bool isVowel(char ch);
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        while(n--)
        {
            char name[22],name2[22];
            scanf("%s",&name);
            scanf("%s",&name2);
            if(strlen(name)==strlen(name2))
            {
                if(strcmp(name,name2)==0)printf("Yes\n");
                else
                {
                    int a=0,len=strlen(name);
                    for(int i=0; i<len; i++)
                    {
                        if(name2[i]==name[i])a=0;
                        else if(isVowel(name2[i])==0&&isVowel(name[i])==0)a=0;
                        else
                        {
                            a=1;
                            break;
                        }
                    }
                    if(a==0)printf("Yes\n");
                    else printf("No\n");
                }
            }
            else printf("No\n");
        }
    }
    return 0;
}
bool isVowel(char ch)
{

    if(ch =='a')
        return 0;
    if(ch =='e')
        return 0;
    if(ch =='i')
        return 0;
    if(ch =='o')
        return 0;
    if(ch =='u')
        return 0;
    else
        return 1;
}

