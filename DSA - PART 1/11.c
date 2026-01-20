// Q. write a c program to sort an array using count sort sort. (with comments)

#include <stdio.h>
#include <limits.h> // For INT_MIN

int maximum(int a[], int n)
{
    int max = a[0]; // // Assume first element is the maximum
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i]; // Update max if a bigger value is found
        }
    }
    return max;
}

void count_sort(int a[], int n)
{
    int i, j;
    int max = maximum(a, n);
    int count[max + 1]; // Indexes 0 to max
    for (i = 0; i <= max; i++)
    {
        count[i] = 0; // Initialize all counts to 0
    }
    // For every element in 'a', increment its count in 'count[]'
    for (i = 0; i < n; i++)
    {
        count[a[i]]++;
    }
    // Step 4: Rebuild the sorted array
    j = 0; // 'j' is the index of count sort
    i = 0; // 'i' is the index in the array 'a[]'
    while (j <= max)
    {
        if (count[j] > 0) // jo paryant count[i] madhi element 0 hot nahi toh paryant.
        {
            a[i] = j;   // put index of j in a[j] array.
            count[j]--; // reduce the element of count array.
            i++;        // Move to next position in 'a[]'
        }
        else
        {
            j++; // Move to next value if current count is 0
        }
    }
}
void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d", a[i]);
    }
}
int main()
{
    int a[20], i, n;
    printf("Enter how many data: ");
    scanf("%d", &n);
    printf("Enter the data: ");
    for (i = 0; i < n; i++)
    {
        scanf(" %d", &a[i]);
    }
    printf("Unsorted array:");
    display(a, n);
    count_sort(a, n);
    printf("\nSorted array:");
    display(a, n);
    return 0;
}
