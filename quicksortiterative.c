#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef struct {
    int low;
    int high;
} stack;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void iterative_quicksort(int arr[], int low, int high) {
    stack* stk = (stack*)malloc(sizeof(stack) * MAX_STACK_SIZE);
    int top = -1;
    stk[++top].low = low;
    stk[top].high = high;
    while (top >= 0) {
        low = stk[top].low;
        high = stk[top].high;
        top--;
        int pivot = partition(arr, low, high);
        if (pivot - 1 > low) {
            stk[++top].low = low;
            stk[top].high = pivot - 1;
        }
        if (pivot + 1 < high) {
            stk[++top].low = pivot + 1;
            stk[top].high = high;
        }
    }
    free(stk);
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    iterative_quicksort(arr, 0, n - 1);

    printf("Sorted array: ");
    print_array(arr, n);

    return 0;
}
