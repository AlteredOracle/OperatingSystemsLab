#include <stdio.h>
#include <stdlib.h>


int main()
{
	int p[100], bt[100], wt[100], tat[100], t, ct[100];
	float wtAvg, tatAvg;
	int i, j,n, min, temp = 0;

	printf("Enter the number of processes : ");
	scanf("%d",&n);

	for(i = 0; i<n; i++)
	{ 
		p[i] = i;
		printf("Enter the burst time for process %d : ",i );
		scanf("%d",&bt[i]);
		ct[i] = bt[i]; //Making a copy of burst time.
	}

	printf("Enter the time slice : ");
	scanf("%d",&t);

	tatAvg = wtAvg = 0;

	int max = bt[0]; //Initial burst time

	//To find the process with maximum burst time
	for (i = 0; i < n ; ++i)
		if(max < bt[i])
			max = bt[i];

	printf("Came till here\n");

	for (i = 0; i < (max/t) + 1; ++i)
	{
		for(j = 0; j<n ; j++)
		{
			if(bt[j] != 0) //If the burst time is less than the time slice.
			{
				if(bt[j] <= t)
				{

					tat[j] = temp + bt[j];
					temp = temp + bt[j];
					bt[j] =  0; //Make the burst time of that particular process 0 
								//as it is successfully completed.
				}

				else //If the busrt time is greater than the time slice.
				{
					bt[j] = bt[j] - t;
					temp = temp + t;
				}
			}
		}
	}

	for(i = 0; i<n; i++)
	{
		wt[i] = tat[i] - ct[i];
		tatAvg += tat[i];
		wtAvg = wtAvg + wt[i];
	}


	printf("\n\tProcess\t\tBurst Time\tWaiting Time\tTurn Around Time\n");
	for ( i = 0; i < n; ++i)
	{
		printf("\tP%d\t\t%d\t\t%d\t\t%d\n",p[i], ct[i], wt[i], tat[i] );
		
	}

	printf("Average waiting time = %f \n",wtAvg/n);
	printf("Average turn around time = %f\n",tatAvg/n );
}

	
