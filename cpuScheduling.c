#include <stdio.h>
#include <string.h>
#define MAX 20

void FCFS(int burstTime[], int size);
void SJF(int burstTime[], int size);
void RR(int burstTime[], int size);
void menu();

int main()
{
	int ch, size, burstTime[MAX], flag = 1,i; 
	printf("Enter the number of processes : \n");
	scanf("%d",&size);

	printf("Enter the burst time for each process P\n");
	for (i = 0; i < size; ++i)
		scanf("%d", &burstTime[i]);

	printf("Enter the choice of implementation of CPU Scheduling Algorithm :\n");
	menu();
	
	while(flag)
	{
		scanf("%d",&ch);

		switch(ch)
		{
			case 1 : FCFS(burstTime, size);
			break;

			// case 2 : SJF(burstTime, size);
			// break;

			case 3 : RR(burstTime, size);
			break;

			default : flag = 0;
			continue;
		}
	}
	printf("Thank You for using the program.\n");
}

void menu()
{
	printf("1. FCFS\n");
	printf("2. Shortest Job First\n");
	printf("3. Round Robin\n");
	printf("4. EXIT\n");
}

void RR(int burstTime[], int size)
{
	int tt[size], wt[size], burstCopy[size], i, temp = 0, k;
	int timeSlice, max = 0, totalWT = 0, totalTT = 0;

	//duplicating the array rather than passing the original array to function because : 
	//Apparently, C passing arrays to functions as references only.
	//There is no legitimate way to pass an array with value.
	for(i = 0; i<size; i++)
		burstCopy[i] = burstTime[i];

	printf("Enter the time slice : ");
	scanf("%d",&timeSlice);


	//Initially we have to find the maximum busrt time in the set of processes.
	for (i = 0; i < size; ++i)
	{
		if(max < burstTime[i])
			max = burstTime[i];
	}

	for(k = 0; k <= (max/timeSlice); k++)
		for(i = 0; i < size; i++)
			if(burstTime[i] != 0)
			{
				if(burstTime[i] <= timeSlice)
				{
					printf("IF : k = %d i = %d temp = %d burstTime[i] = %d\n",k,i,temp,burstTime[i] );
					temp = temp + burstTime[i];
					tt[i] = temp;
					burstTime[i] = 0;
					totalTT += tt[i];
				}
				else
				{
					printf("ELSE : k = %d i = %d temp = %d burstTime[i] = %d\n",k,i,temp,burstTime[i] );
					temp = temp + timeSlice;
					burstTime[i] = burstTime[i] - timeSlice;
				}
			}

	//To calculate waiting time of each process we need to use the following formula : 
	// waitingTime[i] = turnAroundTime[i] - burstTime[i]
	//We lost all the data in burstTime of all the process, that is where burstCopy comes into play.
	for (i = 0; i < size; ++i)
	{
		printf("i = %d tt[i] = %d burstCopy[i] = %d\n",i, tt[i], burstCopy[i] );
		wt[i] = tt[i] - burstCopy[i];
		totalWT += wt[i];
	}

	printf("\n\tProcess\t\tBurst Time\tWaiting Time\tTurn Around Time\n");
	for ( i = 0; i < size; ++i)
	{
		printf("\tP%d\t\t%d\t\t%d\t\t%d\n",i, burstCopy[i], wt[i], tt[i] );
		
	}

	printf("Average Waiting Time is : %.3f\n",(float)totalWT/size);
	printf("Average Turn Around Time is : %.3f\n",(float)totalTT/size);


}

void FCFS(int burstTime[], int size)
{
	int tt[size], wt[size],i;
	int totalWT, totalTT;

	wt[0] = 0;
	totalWT = 0;
	tt[0] = burstTime[0];
	totalTT = tt[0];

	for (i = 1; i < size; ++i)
	{
		wt[i] = tt[i-1];
		totalWT += wt[i];
		tt[i] = wt[i] + burstTime[i];
		totalTT += tt[i];
	}

	printf("\n\tProcess\t\tBurst Time\tWaiting Time\tTurn Around Time\n");
	for ( i = 0; i < size; ++i)
	{
		printf("\tP%d\t\t%d\t\t%d\t\t%d\n",i, burstTime[i], wt[i], tt[i] );
		
	}

	printf("Average Waiting Time is : %.3f\n",(float)totalWT/size);
	printf("Average Turn Around Time is : %.3f\n",(float)totalTT/size);
}