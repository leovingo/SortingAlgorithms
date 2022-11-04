#include "Lab03_Header.h"

// BUBBLE SORT
// sap xep tang dan
void Bubble_sort(int* a, int n) { // so phan tu n
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    return;
}

// SELECTION SORT
// sap xep tang dan
void Selection_sort(int* a, int n) {
    int MinIdx = 0;
    for (int i = 0; i < n - 1; i++) {

        // gan vi tri cua phan tu nho nhat cho i
        MinIdx = i;

        // tim vi tri cua phan tu co gia tri nho nhat tu i+1 den het
        for (int j = i + 1; j < n; j++)
        {
            if (a[MinIdx] >= a[j])
                MinIdx = j;
        }

        // hoan doi phan tu thu i va phan tu nho nhat
        int temp = a[i];
        a[i] = a[MinIdx];
        a[MinIdx] = temp;
    }
}

// INSERTION SORT
// sap xep tang dan
void Insertion_sort(int* a, int n) {
    int key, j;
    // chay tu vi tri thu 2 den vi tri cuoi cung
    for (int i = 1; i < n; i++) {

        // gan key cho phan tu i
        key = a[i];

        // j la vi tri cuoi cung cua phan da sap xep
        j = i - 1;

        // so sanh lan luot key voi cac phan tu cua phan da sap xep
        while (key < a[j] && j >= 0) {
            //key< a[j] dam bao tinh on dinh cua day
            a[j + 1] = a[j];
            j--;
        }
        // chen phan tu key vao vi tri chen
        a[j + 1] = key;
    }
}
