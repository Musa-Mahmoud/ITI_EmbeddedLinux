#include <stdio.h>

int binary_search(int *arr, int size, int target);

int main(void)
{
	int a[] = {1, 2, 3, 4, 5};
	int is_found = -1;
	int found_result = binary_search(a, 5, 4);

	if (found_result != 0)
	{
		printf( "Element found at index %d\n",found_result);
	}
	else
	{
		printf( "Element NOT found at index \n");
	}
	
	found_result = binary_search(a, 5, 0);
	if (found_result != 0)
	{
		printf( "Element found at index %d\n",found_result);
	}
	else
	{
		printf( "Element NOT found at index \n");
	}

	return 0;
}

int binary_search(int *arr, int size, int target)
{
	int ret = -1;
	int l = 0, m = 0, r = size - 1;

	while (l <= r)
	{
		m = (l + r) / 2;
		if (arr[m] == target)
		{
			ret = m;
			break;
		}
		else if (arr[m] > target)
		{
			r = m - 1;
		}
		else
		{
			l = m + 1;
		}
	}

	return ret;
}

