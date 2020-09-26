#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,cases;
    while(scanf("%d",&n)==1)
    {
        getchar();
        cases=0;
        while(n--)
        {
            char wife[20],meeting[20];
            gets(wife);
            gets(meeting);
            char *p;
            p=strtok(wife," :");
            int a=0,wife_start_hour,wife_start_mint,wife_end_hour,wife_end_mnt;
            while(p!=NULL)
            {
                if(a==0)wife_start_hour=atoi(p);
                else if(a==1)wife_start_mint=atoi(p);
                else if(a==2)wife_end_hour=atoi(p);
                else if(a==3)wife_end_mnt=atoi(p);
                p=strtok(NULL," :");
                a++;
            }
            int b=0,meeting_start_hour,meeting_start_mnt,meeting_end_mnt,meeting_end_hour;
            p=strtok(meeting," :");
            while(p!=NULL)
            {
                if(b==0)meeting_start_hour=atoi(p);
                else if(b==1)meeting_start_mnt=atoi(p);
                else if(b==2)meeting_end_hour=atoi(p);
                else if(b==3)meeting_end_mnt=atoi(p);
                p=strtok(NULL," :");
                b++;
            }
            if(wife_end_hour<=meeting_start_hour)
            {
                if(wife_end_mnt<meeting_start_mnt&&wife_end_hour==meeting_start_hour)printf("Case %d: Hits Meeting\n",++cases);
                else if(wife_end_hour<meeting_start_hour)printf("Case %d: Hits Meeting\n",++cases);
                else printf("Case %d: Mrs Meeting\n",++cases);
            }
            else if(meeting_end_hour<=wife_start_hour)
            {
                if(meeting_end_mnt<wife_start_mint&&meeting_end_hour==wife_start_hour)printf("Case %d: Hits Meeting\n",++cases);
                else if(meeting_end_hour<wife_start_hour)printf("Case %d: Hits Meeting\n",++cases);
                else printf("Case %d: Mrs Meeting\n",++cases);
            }
            else printf("Case %d: Mrs Meeting\n",++cases);
        }
    }
    return 0;
}

