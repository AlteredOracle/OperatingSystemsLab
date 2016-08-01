#include <stdio.h>
int main()
{
	int p_size, size, flag;
	char ch;
	printf("Enetr the size of the memory : ");
	scanf("%d",&size);
	ch = 'y';

	while(ch =='y')
	{
		printf("Enetr the size of the job\n");
		scanf("%d",&p_size);
		flag = 0;
		if(size >= p_size)
		{
			flag = 1;

			size = size - p_size;
			printf("Job is executed\n");
			
			printf("The free space is : %d",size);
		}

		else
		{
			printf("No free space is available\n");
		}

		if(flag == 0)
		{
			printf("This job cannot be executed.\n");
		}

		printf("Enter your choice (y or n) : ");
		scanf("%c",&ch);

	}
}