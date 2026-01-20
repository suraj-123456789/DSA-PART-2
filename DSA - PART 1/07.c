// Q. write a c program to sort an array using quick sort.

#include<stdio.h>
int partition(int a[], int low, int high){
    int pivot = a[low];
    int start = low+1; // start starts from index 1.
    int end = high; // end starts from index n-1.
    int temp;
    while(start < end){
        while(a[start] <= pivot){
        start ++;   // shift (index) and subarray to right.
    }
        while(a[end] > pivot){
        end --;    // shift (index) and subarray to left.
    }
    if(start < end){  // index checking.
        temp = a[start];
        a[start] = a[end];
        a[end] = temp;
    }
  }
  temp = a[low];
  a[low] = a[end];
  a[end] = temp;
  return end; // value of return end goes in endd and endd value is fix to its exact position.
}
void quick_sort(int a[],int low,int high){
    if(low < high){
    int endd = partition(a,low,high);
    quick_sort(a,low,endd-1); // patition from endd to left side of array and perform recursive quick sort.(recursive means function call by itself)
    quick_sort(a,endd+1,high); // // patition from endd to right side of array and perform recursive quick sort.
    }
}
void display(int a[], int n) // Function to display array elements
{
    int i;
    for(i = 0; i < n; i++){
        printf(" %d", a[i]);
    }
}
int main(){
    int a[100], i, n;
    printf("Enter the size of array: ");     // Take array size input from user
    scanf("%d", &n);
    printf("Enter the elements of array: ");   // Take array elements input from user
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    printf("Unsorted array:");    // Show the array before sorting
    display(a, n);
    quick_sort(a,0,n-1);   // Sort the array using quick sort
    printf("\nSorted array:");    // Show the sorted array
    display(a, n); 
    return 0;
}