#include <stdio.h>

void Downheap(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        Downheap(arr, n, largest);
    }
}

void Heapify(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        Downheap(arr, n, i);
    }
}

void HeapSort(int arr[], int n) {
    Heapify(arr, n);
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        Downheap(arr, i, 0);
    }
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("The array is: ");
    printArr(arr, n);
    printf("\n");
    HeapSort(arr, n);
    printf("The sorted array is: ");
    printArr(arr, n);
    return 0;
}
