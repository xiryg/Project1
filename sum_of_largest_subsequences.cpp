#include <iostream>


auto sum_of_largest_subsequences(const int A[], int N) -> int
{
	int i, j, k;

	int MaxSum = 0;
	for (int i = 0; i < N; i++)
	{
		for (j = i; j < N; j++)
		{
			int ThisSum = 0;
			for (k = i; k <= j; k++)
			{
				ThisSum += A[k];
			}
			if (ThisSum > MaxSum)
			{
				MaxSum = ThisSum;
			}

		}
	}
	return MaxSum;
}
