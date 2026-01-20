
// Q. write a c program to sort an array using bubble sort.

#include <stdio.h>
void bubble_sort(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++) // Outer loop for each pass
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
        printf("\nafter pass %d our array :", i + 1);
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
    bubble_sort(a, n);         // Sort the array using bubble sort
    printf("\nSorted array:"); // Show the sorted array
    display(a, n);
    return 0;
}
