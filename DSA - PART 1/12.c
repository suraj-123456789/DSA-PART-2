// Q. write a c program to sort an array using count sort sort. (without comments)

#include <stdio.h>
#include <limits.h>
int maximum(int a[], int n)
{
    int max = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
} 
void count_sort(int a[], int n)
{
    int i, j;
    int max = maximum(a, n);
    int count[max + 1];
    for (i = 0; i <= max; i++)
    {
        count[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        count[a[i]]++;
    }
    i = 0;
    j = 0;
    while (j <= max)
    {
        if (count[j] > 0)
        {
            a[i] = j;
            count[j]--;
            i++;
        }
        else
        {
            j++;
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
