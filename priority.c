#include <stdio.h>
#include <stdlib.h>

int main()
{
	int p[100], bt[100], wt[100], tat[100], pri[100];
	float wtAvg, tatAvg;
	int i, j,n, min, temp;

	printf("Enter the number of processes : ");
	scanf("%d",&n);

	for(i = 0; i<n; i++)
	{ 
		p[i] = i;
		printf("Enter the burst time and priority for P%d : ",i );
		scanf("%d %d",&bt[i], &pri[i]);

	}

	

	for (i = 0; i < n; ++i) 
	{
		for(j = i+1; j<n; j++)
		{
			//Sorting the arrays with respect to the priorities of the processes.

			if(pri[i] > pri[j])
			{
				temp = pri[i];
				pri[i] = pri[j];
				pri[j] = temp;

				//Sorting the burst time.
				temp = bt[i];
				bt[i] = bt[j];
				bt[j] = temp;

				//Sorting the process names accordingly with the burst time.
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}


	wt[0] = wtAvg = 0;
	tat[0] = tatAvg = bt[0];

	for (i = 1; i < n; ++i)
	{
		wt[i] = wt[i-1] + bt[i-1];
		tat[i] = wt[i] + bt[i];

		wtAvg +=wt[i];
		tatAvg += tat[i];
	}


	printf("\n\tProcess\t\tPriority\t\tBurst Time\tWaiting Time\tTurn Around Time\n");
	for ( i = 0; i < n; ++i)
	{
		printf("\tP%d\t%d\t\t%d\t\t%d\t\t%d\n",p[i], pri[i], bt[i], wt[i], tat[i] );
		
	}

	printf("Average waiting time = %f \n",wtAvg/n);
	printf("Average turn around time = %f\n",tatAvg/n );

}


