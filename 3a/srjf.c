#include<stdio.h>
int arrival_t[100],burst_t[100],ct[100],temp[100];
int main()
{
    int i,smallest,count=0,j,n;
    double avg_wt=0,avg_tat=0,end;
 
    printf("Enter total number of processes : ");
    scanf("%d",&n);
 
    printf("Enter details of %d processes :\n ",n);
    for(int i=0;i<n;i++)
    {
        printf("\nEnter arrival time for p%d :",i+1);
        scanf("%d",&arrival_t[i]);
        printf("Enter Burst time for p%d : ",i+1);
        scanf("%d",&burst_t[i]);
        temp[i]=burst_t[i];
    }
    burst_t[99]=1000;
    for(int i=0;count!=n;i++)
    {
        smallest=99;
        for(int j=0;j<n;j++)
        {
            if(arrival_t[j]<=i && burst_t[j]<burst_t[smallest] && burst_t[j]>0)
            {
                smallest=j;
            }
        }
        burst_t[smallest]--;
        if(burst_t[smallest] ==0)
        {
            count++;
            ct[smallest]=i+1;
        }
    }
    for(int i=0;i<n;i++)
    {
        int TAT=ct[i]-arrival_t[i];
        avg_tat+=TAT;
        avg_wt+=TAT-temp[i];
 
    }

    printf("\nAverage TAT : %lf\n",avg_tat/n);
    printf("\nAverage WT : %lf\n",avg_wt/n);
    return 0;
}