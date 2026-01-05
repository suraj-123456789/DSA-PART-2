// heap sort with comments

#include <stdio.h>

/* Heapify a subtree rooted at index i
   n = size of heap */
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // check left child
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // check right child
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // if root is not largest, swap and heapify again
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

/* Heap Sort function */
void heapSort(int arr[], int n)
{
    // 1️⃣ Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // 2️⃣ Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) // to sort the array
    {
        // move current root to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // call heapify on reduced heap
        heapify(arr, i, 0);
    }
}

/* Print array */
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}
