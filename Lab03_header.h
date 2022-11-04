#ifndef LAB03_HEADER_H
#define LAB03_HEADER_H
#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include <iomanip>
using namespace std;
template <class T>
void Swap(T& a, T& b);
//generate data
void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType);
int data_order(char* argv[], int pos, string &order);
//command 
void Command_line_3(char* argv[]);
void Command_line_5(char* argv[]);
//sorting algorithm
void heapRebuild(int a[], int pos, int n);
void heapConstruct(int a[], int n);
void heapSort(int a[], int n);
void merge(int a[], int first, int mid, int last);
void mergeSort(int a[], int first, int last);
int partition(int a[], int i, int j);
void quickSort(int a[], int first, int last);
int ShakerSort(int* a, int n);
int RadixSort(int* arr, int n);
int ShellSort(int arr[], int n);
int Calculate_Complexity(char* argv[], int pos, double& time, int arr[], int size);
#endif // !HEADER_H


