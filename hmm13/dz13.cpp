#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
void quickSort(int *numbers, int left, int right)
{
    int pivot;
    int l_hold = left;
    int r_hold = right;
    pivot = numbers[left];
    while (left < right) {
        while ((numbers[right] >= pivot) && (left < right)) {
            right--;
        }
        if (left != right) {
            numbers[left] = numbers[right];
            left++;
        }
        while ((numbers[left] <= pivot) && (left < right)) {
            left++;
        }
        if (left != right) {
            numbers[right] = numbers[left];
            right--;
        }
    }
    numbers[left] = pivot;
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot) {
        quickSort(numbers, left, pivot - 1);
    }
    if (right > pivot) {
        quickSort(numbers, pivot + 1, right);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    cout << "\n";
    }
}

int main()
{
    int const n = 100;
    int const a = 1000;
    int const g = 99;
    unsigned int b[n];
    for (int j = 0; j < n; j++) {
        int arr[a];
        for (int i = 0; i < int((sizeof(arr) / sizeof(arr[0]))); i++) {
            arr[i] = rand() % n + 1;
        }
        unsigned int start_time = clock();
        quickSort(arr, 0, g);
        b[j] = clock() - start_time;
        cout << b[j] << endl;
    }
    unsigned int M = 0;
    for (int i = 0; i < n; ++i) {
        M = M + b[i];
    }
    cout << M / a << endl;
}