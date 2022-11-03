#include <iostream>
#include <string.h>

using namespace std;
template <class T>
void HoanVi(T &a, T &b)
{
	T x = a;
	a = b;
	b = x;
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
		HoanVi(a[r1], a[r2]);
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

int data_order(char* argv[], int pos) {
	if (strcmp(argv[4], "-rand") == 1)
		return 0;
	if (strcmp(argv[4], "-nsorted") == 1)
		return 1;
	if (strcmp(argv[4], "-sorted") == 1)
		return 2;
	if (strcmp(argv[4], "-rev") == 1)
		return 3;
	return -1;
}

int Calculate_Complexity(char* argv[], int pos, int& time, int arr[], int size){
if (strcmp(argv[pos], "shaker-sort") == 0) {
		//calculate time & return the number of comparisons
	}
	if (strcmp(argv[pos], "radix-sort") == 0) {
		//calculate time & return the number of comparisons
	}
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
	int time1, time2, time3, time4;
	int ass1, ass2, ass3, ass4;
	//ass1 = Calculate_Complexcity(argv, 2, time1, arr, size);
	//ass2 = Calculate_Complexcity(argv, 3, time2, arr2, size);
	cout << "ALGORITHM MODE\n";
	cout << "Algorithm:" << argv[2] << endl;
	cout << "Input size: " << size << endl;
	cout << "Input order: Randomize" << endl;
	cout << "--------------\n";
    switch (output)
    {
    case 0:
        cout << "Running time: " << time1 << endl;
        break;
    case 1:
        cout << "Comparisions: " << ass1 << endl;
        break;
    case 2:
        cout << "Running time: " << time1 << endl;
        cout << "Comparisions: " << ass1 << endl;
        break;
    default:
        break;
    }
    	cout << "Input order: Nerly Sorted" << endl;
	cout << "--------------\n";
    switch (output)
    {
    case 0:
        cout << "Running time: " << time2 << endl;
        break;
    case 1:
        cout << "Comparisions: " << ass2 << endl;
        break;
    case 2:
        cout << "Running time: " << time2 << endl;
        cout << "Comparisions: " << ass2 << endl;
        break;
    default:
        break;
    }
    cout << "Input order: Sorted" << endl;
	cout << "--------------\n";
    switch (output)
    {
    case 0:
        cout << "Running time: " << time3 << endl;
        break;
    case 1:
        cout << "Comparisions: " << ass3 << endl;
        break;
    case 2:
        cout << "Running time: " << time3 << endl;
        cout << "Comparisions: " << ass3 << endl;
        break;
    default:
        break;
    }
    cout << "Input order: Reversed" << endl;
	cout << "--------------\n";
    switch (output)
    {
    case 0:
        cout << "Running time: " << time4 << endl;
        break;
    case 1:
        cout << "Comparisions: " << ass4 << endl;
        break;
    case 2:
        cout << "Running time: " << time4 << endl;
        cout << "Comparisions: " << ass4 << endl;
        break;
    default:
        break;
    }
}
