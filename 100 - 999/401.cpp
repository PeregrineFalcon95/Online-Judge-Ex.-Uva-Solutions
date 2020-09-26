#include<stdio.h>
#include<string.h>
int main()
{
    int a,b,c,d,i,j;
    char str[21],str2[21];
    while(scanf("%s",str)!=EOF)
    {
        b=c=d=0;
        a=strlen(str);
        for(i=0; i<a; i++)
        {
            if(str[i]!=str[a-i-1])
            {
                b=1;
                break;
            }
        }
        strcpy(str2,str);
        for(i=0; i<a; i++)
        {
            if(str2[i]=='A')
            {
                d=1;
            }
            else if(str2[i]=='E')
            {
                d=1;
                str2[i]='3';
            }
            else if(str2[i]=='H')
            {
                d=1;
            }
            else if(str2[i]=='I')
            {
                d=1;
            }
            else if(str2[i]=='J')
            {
                d=1;
                str2[i]='L';
            }
            else if(str2[i]=='L')
            {
                d=1;
                str2[i]='J';
            }
            else if(str2[i]=='M')
            {
                d=1;
            }
            else if(str2[i]=='O')
            {
                d=1;
            }
            else if(str2[i]=='S')
            {
                d=1;
                str2[i]='2';
            }
            else if(str2[i]=='T')
            {
                d=1;
            }
            else if(str2[i]=='U')
            {
                d=1;
            }
            else if(str2[i]=='V')
            {
                d=1;
            }
            else if(str2[i]=='W')
            {
                d=1;
            }
            else if(str2[i]=='X')
            {
                d=1;
            }
            else if(str2[i]=='Y')
            {
                d=1;
            }
            else if(str2[i]=='Z')
            {
                d=1;
                str2[i]='5';
            }
            else if(str2[i]=='1')
            {
                d=1;
            }
            else if(str2[i]=='2')
            {
                d=1;
                str2[i]='S';
            }
            else if(str2[i]=='3')
            {
                d=1;
                str2[i]='E';
            }
            else if(str2[i]=='5')
            {
                d=1;
                str2[i]='Z';
            }
            else if(str2[i]=='8')
            {
                d=1;
            }
            else
            {
                d=0;
                break;
            }
        }
        if(d==1)
        {
            for(i=0; i<a; i++)
            {
                if(str[i]!=str2[a-i-1])
                {
                    c=0;
                    break;
                }
                c=1;
            }
        }
        if(b==1 && c==0)
            printf("%s -- is not a palindrome.\n\n",str);
        if(b==0 && c==0)
            printf("%s -- is a regular palindrome.\n\n",str);
        if(b==1 && c==1)
            printf("%s -- is a mirrored string.\n\n",str);
        if(b==0 && c==1)
            printf("%s -- is a mirrored palindrome.\n\n",str);
    }
    return 0;
}
