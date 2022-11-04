#include "Lab03_header.h"
void Command_line_2(char* argv[]) {

    //tính size
    int size = atoi(argv[4]);
    int* arr = new int[size];
    string order;
    GenerateData(arr, size, data_order(argv, 5, order));
    // gán biến đầu ra
    int output;
    if (strcmp(argv[4], "-time") == 0) {
        output = 0;
    }
    else if (strcmp(argv[4], "-comp") == 0) {
        output = 1;
    }
    else if (strcmp(argv[4], "-both") == 0) {
        output = 2;
    }
    else {
        output = -1;
    }

    //vì kích thước mảng có thể lớn nên khuyên mọi người cấp phát động
    
    double time1;
    int comp1;
    comp1 = Calculate_Complexity(argv, 2, time1, arr, size);
    cout << "ALGORITHM MODE\n";
    cout << "Algorithm:" << argv[2] << endl;
    cout << "Input size: " << argv[4] << endl;
    cout << "Input order: " << order << endl;
    GenerateData(arr, size, 0);
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
   

}


int main(int argc, char* argv[]) {
    Command_line_2(argv);
    return 0;
}
