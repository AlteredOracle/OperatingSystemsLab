#include <stdio.h>
#include <stdlib.h>


int main()
{
	int bt[100], wt[100], tat[100];
	float wtAvg, tatAvg;
	int i, j,n;

	printf("Enter the number of processes : ");
	scanf("%d",&n);

	for(i = 0; i<n; i++)
	{
		printf("Enter the burst time for process %d : ",i );
		scanf("%d",&bt[i]);
	}

	wt[0] = wtAvg = 0;
	tat[0] = tatAvg = bt[0];

	for(i = 1; i<n; i++)
	{
		wt[i] = wt[i-1] + bt[i-1];
		tat[i] = wt[i] + bt[i];
		wtAvg +=wt[i];
		tatAvg += tat[i];
	}


	printf("\n\tProcess\t\tBurst Time\tWaiting Time\tTurn Around Time\n");
	for ( i = 0; i < n; ++i)
	{
		printf("\tP%d\t\t%d\t\t%d\t\t%d\n",i, bt[i], wt[i], tat[i] );
		
	}

	printf("Average waiting time = %f \n",wtAvg/n);
	printf("Average turn around time = %f\n",tatAvg/n );

}