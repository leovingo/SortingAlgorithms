#include "Lab03_header.h"
int line_order(char* argv[]) {
	return -1;
}
void Command_line_5(char* argv[]) {
	int size = atoi(argv[4]);
	int* arr = new int[size];
	string order;
	GenerateData(arr, size, data_order(argv, 5,order));
	double time1, time2;
	int ass1, ass2;
	int* arr2 = new int[size];
	for (int i = 0; i < size; i++) {
		arr2[i] = arr[i];
	}
	ass1 = Calculate_Complexity(argv, 2, time1, arr, size);
	ass2 = Calculate_Complexity(argv, 3, time2, arr2, size);
	cout << "COMPARE MODE\n";
	cout << "Algorithm:" << argv[2] << " | " << argv[3] << endl;
	cout << "Input size: " << argv[4] << endl;
	cout << "Input order: "<<order<<endl;
	cout << "--------------\n";
	cout << "Running time: " << time1 << " | " << time2 << endl;
	cout << "Comparisions: " << ass1 << " | " << ass2 << endl;
}