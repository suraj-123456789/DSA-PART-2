
// Q. write a c program to sort an array using insertion sort

#include <stdio.h>
void insertion_sort(int a[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = a[i];
        for (j = i - 1; j >= 0 && a[j] > temp; j--)
        {
            a[j + 1] = a[j]; // in this step value which is at a[j] is shifting to a[j+1] position.
        }
        a[j + 1] = temp; // in this step where the position finds there the value of temp is adds.

        printf("\nafter pass %d our array :", i);
        display(a, n);
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
    insertion_sort(a, n);      // Sort the array using bubble sort
    printf("\nSorted array:"); // Show the sorted array
    display(a, n);
}
