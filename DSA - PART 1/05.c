// Q. write a c program to sort an array using selection sort.

#include<stdio.h>
void selectin_sort(int a[], int n){
    int i,j,min,temp;
    for(i=0; i<n-1; i++){
        min = i;
        for(j=i+1; j<n; j++){
            if(a[j] < a[min]){
                min = j; // iss step mai index 1 se end min ki value update hoti rahti hai. 
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
        printf("\nafter pass %d our array :",i+1);
        display(a,n);  
    }
}
void display(int a[], int n)
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
    selectin_sort(a, n);   // Sort the array using bubble sort
    printf("\nSorted array:");    // Show the sorted array
    display(a, n);
  }