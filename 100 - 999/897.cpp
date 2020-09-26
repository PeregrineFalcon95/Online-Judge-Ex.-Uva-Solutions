#include<bits/stdc++.h>
using namespace std;
bool status[10000002];
vector < int > prime;
map < int, int > anagrammatic_prime;
void seive();
void solution(int n);
int main()
{
    seive();
    int n;
    while(scanf("%d",&n)==1 && n!=0)
    {
        if(n>=991)printf("0\n");
        else
        {
            int mi=INT_MAX,num=0;
            for(map < int, int >::iterator it=anagrammatic_prime.begin(); it!=anagrammatic_prime.end(); it++)
            {
                if(n < it->first && mi > it->first-n){mi=it->first-n;num=it->first;}
            }
            int c=0;
            int a=n;
            while(a)
            {
                c++;
                a/=10;
            }
            int d=0,f=num;
            while(f)
            {
                d++;
                f/=10;
            }
            if(d==c)printf("%d\n",num);
            else printf("0\n");
        }
    }
    return 0;
}
void seive()
{
    int n=10000000;
    int sq=sqrt(n+1);
    prime.push_back(2);
    int wz=0;
    status[0]=1;
    status[1]=1;
    for(int i=4; i<=n; i+=2)status[i]=1;
    for(int i=3; i<=sq; i+=2)
    {
        if(!status[i])
        {
            wz=i;
            prime.push_back(i);
            for(int j=(i*i); j<=n; j+=(i+i))status[j]=1;
        }
    }
    for(int i=wz+2; i<=n; i+=2)
    {
        if(!status[i])prime.push_back(i);
    }
    int sz=prime.size();
    anagrammatic_prime[2]=1;
    for(int i=0; i!=sz; i++)
    {
        wz=0;
        char s[10];
        int c=prime[i];
        int d=0;
        while(c)
        {
            int ee=(c%10)+'0';
            if((ee%2==0 && ee!=2)||ee==0){wz=1;break;}
            s[d++]=ee;
            c/=10;
        }
        s[d]=0;
        sort(s,s+d);
        int e=atoi(s);
        vector < int > temp;
        if(status[e])wz=1;
        temp.push_back(prime[i]);
        while(!wz &&next_permutation(s,s+d))
        {
            int a=atoi(s);
            if(status[a])
            {
                wz=2;
                break;
            }
            temp.push_back(a);
        }
        if(!wz)
        {
            while(!temp.empty())
            {
                anagrammatic_prime[temp.back()];
                temp.pop_back();
            }
        }
    }
}


/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)==1 && n!=0)
    {
        if(n>=991)printf("0\n");
        else if(n<2)printf("2\n");
        else if(n<3)printf("3\n");
        else if(n<5)printf("5\n");
        else if(n<7)printf("7\n");
        else if(n==10)printf("11\n");
        else if(n<13 && n>10)printf("13\n");
        else if(n<17 && n>10)printf("17\n");
        else if(n<31 && n>10)printf("31\n");
        else if(n<37 && n>10)printf("37\n");
        else if(n<71 && n>10)printf("71\n");
        else if(n<73 && n>10)printf("73\n");
        else if(n<79 && n>10)printf("79\n");
        else if(n<97 && n>10)printf("97\n");
        else if(n<113 && n>=100)printf("113\n");
        else if(n<131 && n>110)printf("131\n");
        else if(n<199 && n>110)printf("199\n");
        else if(n<311 && n>110)printf("311\n");
        else if(n<337 && n>110)printf("337\n");
        else if(n<373 && n>110)printf("373\n");
        else if(n<733 && n>110)printf("733\n");
        else if(n<919 && n>110)printf("919\n");
        else if(n<991 && n>110)printf("991\n");
        else printf("0\n");
    }
    return 0;
}*/
