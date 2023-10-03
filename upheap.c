#include <stdio.h>
#include <stdlib.h>

void upHeapify(int arr[], int index) {
    int parent = (index - 1) / 2;

    while (index > 0 && arr[index] > arr[parent]) {
        int temp = arr[index];
        arr[index] = arr[parent];
        arr[parent] = temp;

        index = parent;
        parent = (index - 1) / 2;
    }
}

void insertElement(int arr[], int *n, int element) {
    (*n)++;
    arr[*n - 1] = element;
    upHeapify(arr, *n - 1);
}

void printHeap(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100];
    int n = 0, ch, ele;
    while (1)
    {
        printf("1. Insert\n2. Print\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &ele);
                insertElement(arr, &n, ele);
                break;
            case 2:
                printHeap(arr, n);
                break;
            case 3:
                exit(0);
        }
    }
    return 0;
}
