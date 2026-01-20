
// Q. write a c program to perform binary search on an array.

#include<stdio.h>
int BinarySearch(int a[], int n, int key){
    int low, mid, high;
    low = 0;
    high = n-1;
    while(low <= high){
    mid = (low + high)/2;
    if(a[mid]==key){
        return mid;
    }
    if(a[mid]<key){
        low = mid + 1;
    }
    else{
        high = mid - 1;
    }
  }
  return -1;
}
int main(){
    int a[100], i, n, key, position;
    printf("enter the size of array :");
    scanf("%d",&n);
    printf("enter the elements of array in assending order :");
    for(i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    printf("enter the element to find: ");
    scanf("%d", &key);
    position = BinarySearch(a,n,key);
    if(position==-1){
        printf("element not found.");
    }
    else{
        printf("element found at index :%d",position);
    }

}