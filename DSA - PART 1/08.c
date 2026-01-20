// Q. write a c program to sort an array using merge sort.
#include <stdio.h>
void merge(int a[], int low, int mid, int high)
{
    int i, j, k, b[100];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid) // this while loop is to copy the remaining elements of i.
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= high) // // this while loop is to copy the remaining elements of j.
    {
        b[k] = a[j];
        j++;
        k++;
    }
    for (i = low; i <= high; i++) // for loop to copy elments which is stored in b[100] array to a[100].
    {
        a[i] = b[i]; // here we uses i instead of k because we know the starting and ending value of i but not k we know the staring value of k but we dont know the ending value
    }
}
void merge_sort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        merge_sort(a, low, mid);      // for left side array
        merge_sort(a, mid + 1, high); // for right side array
        merge(a, low, mid, high);     // to merge array
    }
}
void display(int a[], int n) // Function to display array elements
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf(" %d", a[i]);
    }
}
int main()
{
    int a[100], i, n;
    printf("Enter the size of array: "); // Take array size input from user
    scanf("%d", &n);
    printf("Enter the elements of array: "); // Take array elements input from user
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Unsorted array:"); // Show the array before sorting
    display(a, n);
    merge_sort(a, 0, n - 1);   // Sort the array using merge sort
    printf("\nSorted array:"); // Show the sorted array
    display(a, n);
    return 0;
}