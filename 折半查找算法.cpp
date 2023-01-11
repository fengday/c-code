#include <stdio.h>
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int left = 0;
	int a=29;
	int right= sizeof(arr) / sizeof(arr[0])-1;
	//scanf("%d\n", &a);
	while (left<=right)
	{
		int mid = (left + right) / 2;
		if (a > arr[mid])
		{
			left= mid+1;
		}
		else if (a < arr[mid])
		{
			right = mid-1;
		}
		else
		{
			printf("下标为%d\n", mid);
			break;
		}
	}
	if (left > right)
	{
		printf("未找到");
	}
}
