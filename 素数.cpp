#include<math.h>
#include<stdio.h>
int main()
{
	//for (int i = 100; i <= 200; i++)
	for (int i = 101; i <= 200; i+=2)
	{
		int j;
		for (j = 2; j<sqrt((double)i); j++)
        //for (j = 2; j<i; j++)
		{
			if (i%j == 0)
			{
				break;
			}
		}
		//if (j==i))
		if (j>sqrt((double)i))
		{
			printf("%d\n", i);
		}

	}

	return 0;
} 
