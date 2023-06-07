#include <stdio.h>

int main()
{
	int i,nop,ct=0,time_quantum,counter;   //counter means number of process executed
	int total_wait_time=0,total_turnaround_time=0,
	arrival_time[10],burst_time[10],rt[10];
	float average_wait_time,average_turnaround_time;

	printf("Enter the number of processes:\t");
	scanf("%d",&nop);
	counter=nop; //initially total proceee to be exected

	for(i=0;i<nop;i++)
	{
		printf("\n Enter details of proces [%d]\n",i+1);
		printf("Arrival Time : \t");
		scanf("%d",&arrival_time[i]);
		printf("Burst Time : \t");
		scanf("%d",&burst_time[i]);
		rt[i]=burst_time[i];
	}

	printf("\n Enter time quantum: \t");
	scanf("%d",&time_quantum);
	printf("\nProcess id\t burst time\t turn arround time\t waiting time");

	for(ct=0,i=0;counter!=0;)
	{
		if(rt[i]<=time_quantum && rt[i]>0)
		{
			ct=ct+rt[i];
			rt[i]=0;
			counter--;
			printf("\nProcess[%d]\t%d\t\t\t%d\t\t\t%d",i+1,burst_time[i],
				ct-arrival_time[i],ct-arrival_time[i]-burst_time[i]);

			total_wait_time=total_wait_time+ct-arrival_time[i]-burst_time[i];
			total_turnaround_time=total_turnaround_time+ct-arrival_time[i];
		}
		else if(rt[i]>0)
		{
			rt[i]=rt[i]-time_quantum;
			ct=ct+time_quantum;
		}
		if(i==nop-1)
		{
			i=0;
		}
		else if(arrival_time[i+1]<=ct)
		{
			i++;
		}
		else
		{
			i=0;
		}
	}


	average_wait_time=(float)total_wait_time/nop;
	average_turnaround_time=(float)total_turnaround_time/nop;
	
	printf("\nAverage waiting time:\t%f",average_wait_time);
	printf("\nAvg turnaround time:\t%f\n",average_turnaround_time);
	return 0;
}