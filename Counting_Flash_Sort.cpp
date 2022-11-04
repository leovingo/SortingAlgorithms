#include "Lab03_header.h"

int insertionSort(int a[], int n)
{
	int comp = 0;
	for (int i = 1; ++comp && i < n; i++)
	{
		int k = i - 1;
		int key = a[i];
		while (++comp && a[k] > key && ++comp && k >= 0)
		{
			a[k + 1] = a[k];
			k--;
		}
		a[k + 1] = key;
	}
	return comp;
}

int countingSort(int a[], int n)
{
	int comp = 0;
	int max = a[0];
	for (int i = 1; ++comp && i < n; i++)
		if (++comp && a[i] > max)
			max = a[i];

	int* count = new int[max + 1];
	for (int i = 0; ++comp && i <= max; i++)
		count[i] = 0;

	for (int i = 0; ++comp && i < n; i++)
		count[a[i]]++;

	for (int i = 1; ++comp && i <= max; i++)
		count[i] += count[i - 1];

	int* temp = new int[n];
	for (int i = 0; ++comp && i < n; i++)
	{
		temp[count[a[i]] - 1] = a[i];
		count[a[i]]--;
	}

	for (int i = 0; ++comp && i < n; i++)
		a[i] = temp[i];
	delete[] count;
	delete[] temp;
	return comp;
}

int flashSort(int a[], int n)
{
	int comp = 0;
	int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);
	int* l = new int[m];
	for (int i = 0; ++comp && i < m; i++)
		l[i] = 0;
	for (int i = 1; ++comp && i < n; i++)
	{
		if (++comp && a[i] < minVal)
			minVal = a[i];
		if (++comp && a[i] > a[max])
			max = i;
	}
	if (++comp && a[max] == minVal)
		return comp;
	double c1 = (double)(m - 1) / (a[max] - minVal);
	for (int i = 0; ++comp && i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++l[k];
	}
	for (int i = 1; ++comp && i < m; i++)
		l[i] += l[i - 1];
	HoanVi(a[max], a[0]);
	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
	while (++comp && nmove < n - 1)
	{
		while (++comp && j > l[k] - 1)
		{
			j++;
			k = int(c1*(a[j] - minVal));
		}
		flash = a[j];
		if (++comp && k < 0) break;
		while (++comp && j != l[k])
		{
			k = int(c1*(flash - minVal));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++nmove;
		}
	}
	delete[] l;
	comp += insertionSort(a, n);
	return comp;
}

int Calculate_Complexity(char* argv[], int pos, double& time, int arr[], int size) {
	if(strcmp(argv[pos], "counting-sort") == 0) {
		clock_t start, end;
		start = clock();
		int comp = countingSort(arr, size);
		end = clock();
		time = (double)(end - start) / CLOCKS_PER_SEC;
		return comp;
	}
	if (strcmp(argv[pos], "flash-sort") == 0) {
		clock_t start, end;
		start = clock();
		int comp = flashSort(arr, size);
		end = clock();
		time = (double)(end - start) / CLOCKS_PER_SEC;
		return comp;
	}
	return -1;
}

