#include "Lab03_header.h"
//shaker sort
int ShakerSort(int *a, int n)
{
	int comp = 0;
	int Left = 0;
	int Right = n - 1;
	int k = 0;
	while (++comp && Left < Right)
	{
		for (int i = Left;++comp && i < Right; i++)
		{
			if (++comp && a[i] > a[i + 1])
			{
				Swap(a[i], a[i + 1]);
				k = i;
			}
		}
		Right = k;
		for (int i = Right;++comp && i > Left; i--)
		{
			if (++comp && a[i] < a[i - 1])
			{
				Swap(a[i], a[i - 1]);
				k = i;
			}
		}
		Left = k;
	}
	return comp;
}
//radix sort
int RadixSort(int *arr, int n)
{   
    int comp = 0;
    int i, digitPlace = 1;
    int* result=new int[n]; 
    int largest = arr[0];
    for (int i = 1; ++comp && i < n; i++) {
        if (++comp && arr[i] > largest) {
            largest = arr[i];
        }
    }
    while (++comp && largest / digitPlace > 0) {
        int count[10] = { 0 };
         for (i = 0;++comp && i < n; i++)
            count[(arr[i] / digitPlace) % 10]++;
        for (i = 1; ++comp && i < 10; i++)
            count[i] += count[i - 1];
        for (i = n - 1; ++comp && i >= 0; i--)
        {
            result[count[(arr[i] / digitPlace) % 10] - 1] = arr[i];
            count[(arr[i] / digitPlace) % 10]--;
        }
        for (i = 0; ++comp && i < n; i++)
            arr[i] = result[i];
        digitPlace *= 10;
    }
    delete[]result;
    return comp;
}
//shell sort
int ShellSort(int arr[], int n)
{
    int comp = 0;
    for (int gap = n / 2; ++comp && gap > 0; gap /= 2)
    {
        for (int i = gap;++comp && i < n; i += 1)
        {
            int temp = arr[i];
            int j;
            for (j = i; ++comp && j >= gap && ++comp && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
    return comp;
}
int Calculate_Complexity(char* argv[], int pos, double& time, int arr[], int size) {
	if (strcmp(argv[pos], "shaker-sort") == 0) {
        clock_t start, end;
        start = clock();
        int comp = ShakerSort(arr, size);
        end = clock();
        time = (double)(end - start) / CLOCKS_PER_SEC;
        return comp;
	}
	if (strcmp(argv[pos], "radix-sort") == 0) {
        clock_t start, end;
        start = clock();
        int comp = RadixSort(arr, size);
        end = clock();
        time = (double)(end - start) / CLOCKS_PER_SEC;
        return comp;
	}
    if (strcmp(argv[pos], "shell-sort") == 0) {
        clock_t start, end;
        start = clock();
        int comp = ShellSort(arr, size);
        end = clock();
        time = (double)(end - start) / CLOCKS_PER_SEC;
        return comp;
    }
	return -1;
}