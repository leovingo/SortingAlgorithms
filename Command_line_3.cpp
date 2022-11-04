#include "Lab03_header.h"


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
