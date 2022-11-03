#include <iostream>

using namespace std;


// template <class T>
// void swap(T &a, T &b) {
//     T temp = a;
//     a = b;
//     b = temp;
// }

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
		swap(a[pos], a[j]);
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
      swap(a[k], a[m]); 
    }
  }
  swap(a[i], a[m]);

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

int main () {
    int* a = new int[19] {1, 3, 4, 5, 8, 2, 9, 7, 6, 101, 3, 4, 5, 8, 2, 9, 7, 6, 10};
    for (int i = 0; i < 19; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    //mergeSort(a, 0, 18);
	//heapSort(a, 19);
    //quickSort(a, 0, 9);
    for (int i = 0; i < 19; i++) {
        cout << a[i] << " ";
    }
    return 0;
}