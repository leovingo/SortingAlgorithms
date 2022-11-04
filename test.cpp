#include <iostream>
#include <string.h>
#include <time.h>
#include <math.h>
#include <cmath>
#include <iomanip>

using namespace std;

template <class T>
void Swap(T &a, T &b) {
    T c = a;
    a = b;
    b = c;
}

// HEAP SORT
// Ham dua cac phan tu ve vi tri dung voi cau truc heap
void heapRebuild(int a[], int pos, int n)
{
	while (2 * pos + 1 < n)
	{
		int j = 2 * pos + 1;
		if (j < n - 1) {
			if (a[j] < a[j + 1])
				j = j + 1;
		}
		if (a[pos] >= a[j]) {
			return;
		}
		Swap(a[pos], a[j]);
		pos = j;
	}
}
// Ham xay dung cau truc heap
void heapConstruct(int a[], int n)
{
	for (int i = (n - 1) / 2; i >= 0; i--) {
		heapRebuild(a, i, n);
	}
}
// Heap sort
void heapSort(int a[], int n)
{
	heapConstruct(a, n);
	int r = n - 1;
	while (r > 0)
	{
		swap(a[0], a[r]);
		heapRebuild(a, 0, r);
		r--;
	}
}

// MERGE SORT
// Ham chia de tri
// Chia mang ban dau thanh cac mang con sau do sap xep dung thu tu 
// va tron lai thanh mang da sap xep
void merge(int a[], int first, int mid, int last)
{
	int n1 = mid - first + 1;
	int n2 = last - mid;
	int *L = new int[n1];
	int *R = new int[n2];
	
	// chia mang ben trai
	for (int i = 0; i < n1; i++) {
		L[i] = a[first + i];
	}
	// chia mang ben phai
	for (int j = 0; j < n2; j++) {
		R[j] = a[mid + j + 1];
	}

	int i = 0;
	int j = 0;
	int k = first;
	// so sanh va sap xep theo dung thu tu
	while (i < n1 && j < n2) {
		a[k++] = (L[i] < R[j]) ? L[i++] : R[j++];
	}
	// tron 2 mang trai va phai vao mang ban dau
	while (i < n1) {
		a[k++] = L[i++];
	}
	while (j < n2) {
		a[k++] = R[j++];
	}
	delete[] L;
	delete[] R;
}
// Ham sap xep tron
void mergeSort(int a[], int first, int last)
{
	if (first < last) {
		int mid = (first + last)/2;
		mergeSort(a, first, mid);
		mergeSort(a, mid + 1, last);
		merge(a, first, mid, last);
	}
}


// QUICK SORT
// Ham phan hoach mang ban  dau
int partition(int a[], int i, int j) {
  int pivot = a[i];
  int m = i;

  for (int k = i+1; k <= j; ++k) { 
    if (a[k] < pivot)  { 
      ++m;
      Swap(a[k], a[m]); 
    }
  }
  Swap(a[i], a[m]);

  return m; // return the index of pivot
}
// Ham sap xep
void quickSort(int a[], int first, int last)
{
    if (first < last) {
        int index = partition(a, first, last);

        if (first < index - 1) {
            quickSort(a, first, index - 1);
        }
        if (index < last) {
            quickSort(a, index + 1, last);
        }
    }
}

//-------------------------------------------------

// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(int a[], int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand()%n;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}

// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int) time(NULL));
	for (int i = 0; i < 10; i ++)
	{
		int r1 = rand()%n;
		int r2 = rand()%n;
		Swap(a[r1], a[r2]);
	}
}

void GenerateData(int a[], int n, int dataType)
{
	switch (dataType)
	{
	case 0:	// ngẫu nhiên
		GenerateRandomData(a, n);
		break;
	case 1:	// có thứ tự
		GenerateSortedData(a, n);
		break;
	case 2:	// có thứ tự ngược
		GenerateReverseData(a, n);
		break;
	case 3:	// gần như có thứ tự
		GenerateNearlySortedData(a, n);
		break;
	default:
		printf("Error: unknown data type!\n");
	}
}

int Calculate_Complexity(char* argv[], int pos, double& time, int arr[], int size){
    int comp = 0;
    clock_t start, end;
    if (strcmp(argv[pos], "heap-sort") == 0) {
        start = clock();
        heapSort(arr, size);
        end = clock();
        time = pow(10, 3) * (double(end - start) / double(CLOCKS_PER_SEC));
        // cout << "Time taken by ... Sort is: " << fixed << time_taken << setprecision(6) << " msec " << endl;        
    }
    if (strcmp(argv[pos], "merge-sort") == 0) {
        start = clock();
        mergeSort(arr, 0, size - 1);
        end = clock();
        time = pow(10, 3) * (double(end - start) / double(CLOCKS_PER_SEC));
    }
    if (strcmp(argv[pos], "quick-sort") == 0) {
        start = clock();
        quickSort(arr, 0, size - 1);
        end = clock();
        time = pow(10, 3) * (double(end - start) / double(CLOCKS_PER_SEC));
    }
    return comp;
}



void Command_line_3(char* argv[]) {
	//tính size
	int size = atoi(argv[3]);
    
    // gán biến đầu ra
    int output;
    if (strcmp(argv[4], "-time") == 0) {
        output = 0;
    } else if (strcmp(argv[4], "-comp") == 0) {
        output = 1; 
    } else if (strcmp(argv[4], "-both") == 0) {
        output = 2;
    } else {
        output = -1;
    }

	//vì kích thước mảng có thể lớn nên khuyên mọi người cấp phát động
	int* arr=new int[size];
	double time1, time2, time3, time4;
	int comp1, comp2, comp3, comp4;
	//comp1 = Calculate_Complexcity(argv, 2, time1, arr, size);
	//comp2 = Calculate_Complexcity(argv, 3, time2, arr2, size);
	cout << "ALGORITHM MODE\n";
	cout << "Algorithm:" << argv[2] << endl;
	cout << "Input size: " << size << endl;
	cout << "Input order: Randomize" << endl;
    GenerateData(arr, size, 0);
    comp1 = Calculate_Complexity(argv, 2, time1, arr, size);
	cout << "--------------\n";
    switch (output)
    {
    case 0:
        cout << "Running time: " << fixed << time1 << setprecision(3) << " msec " << endl;  
        break;
    case 1:
        cout << "Comparisions: " << comp1 << endl;
        break;
    case 2:
        cout << "Running time: " << fixed << time1 << setprecision(3) << " msec " << endl;  
        cout << "Comparisions: " << comp1 << endl;
        break;
    default:
        break;
    }
    cout << endl;
    cout << "Input order: Nearly Sorted" << endl;
    GenerateData(arr, size, 3);
    comp2 = Calculate_Complexity(argv, 2, time2, arr, size);
	cout << "--------------\n";
    switch (output)
    {
    case 0:
        //cout << "Running time: " << time2 << endl;
        cout << "Running time: " << fixed << time2 << setprecision(3) << " msec " << endl;  
        break;
    case 1:
        cout << "Comparisions: " << comp2 << endl;
        break;
    case 2:
        //cout << "Running time: " << time2 << endl;
        cout << "Running time: " << fixed << time2 << setprecision(3) << " msec " << endl;  
        cout << "Comparisions: " << comp2 << endl;
        break;
    default:
        break;
    }
    cout << endl;
    cout << "Input order: Sorted" << endl;
    GenerateData(arr, size, 1);
    comp3 = Calculate_Complexity(argv, 2, time3, arr, size);
	cout << "--------------\n";
    switch (output)
    {
    case 0:
        //cout << "Running time: " << time3 << endl;
        cout << "Running time: " << fixed << time3 << setprecision(3) << " msec " << endl;  
        break;
    case 1:
        cout << "Comparisions: " << comp3 << endl;
        break;
    case 2:
        //cout << "Running time: " << time3 << endl;
        cout << "Running time: " << fixed << time3 << setprecision(3) << " msec " << endl;  
        cout << "Comparisions: " << comp3 << endl;
        break;
    default:
        break;
    }
    cout << endl;
    cout << "Input order: Reversed" << endl;
    GenerateData(arr, size, 2);
    comp4 = Calculate_Complexity(argv, 2, time4, arr, size);
	cout << "--------------\n";
    switch (output)
    {
    case 0:
        //cout << "Running time: " << time4 << endl;
        cout << "Running time: " << fixed << time4 << setprecision(3) << " msec " << endl;  
        break;
    case 1:
        cout << "Comparisions: " << comp4 << endl;
        break;
    case 2:
        //cout << "Running time: " << time4 << endl;
        cout << "Running time: " << fixed << time4 << setprecision(3) << " msec " << endl;  
        cout << "Comparisions: " << comp4 << endl;
        break;
    default:
        break;
    }
}


int main(int argc, char*argv2[]) {
    Command_line_3(argv2);
    return 0;
}
