// heap sort without comments

#include<stdio.h>

void Heapify(int arr[], int n, int i){
    int largest = i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;

    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest != i){
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        Heapify(arr,n,largest);
    }
}

void HeapSort(int arr[], int n){
    for(int i = (n/2)-1; i >= 0; i--){
        Heapify(arr,n,i);
    }
    for(int i = n-1; i > 0; i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        Heapify(arr,i,0); // i is now current sorted array size here
    }
}

void display(int arr[], int n){
    for(int i=0; i<n; i++){
        printf(" %d",arr[i]);
    }
}

int main(){
    int arr[10],i,n;
    printf("\nEnter the size of Array :");
    scanf("%d",&n);

    printf("Enter the elements : \n");
    for(i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    printf("\nOriginal Array : ");
    display(arr,n);

    HeapSort(arr,n);

    printf("\nSorted Array : ");
    display(arr,n);

    return 0;
}