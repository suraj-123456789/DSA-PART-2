
// Q. write a c program to perform linear search on an array.

#include <stdio.h>
int LinearSearch(int a[100], int key, int n){
    int i;
    for(i=0; i<n; i++){
        if(a[i]==key){
            return i;
        }
    }
    return -1;
}
int main() {
    int a[100], i, n, key, position;
    printf("enter the size of array :");
    scanf("%d",&n);
    printf("enter the elements of array :");
    for(i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    printf("enter the element to find:");
    scanf("%d",&key);
    position = LinearSearch(a, key, n);
    if(position==-1){
        printf("element not found.");
    }
    else{
        printf("element found at index :%d",position);
    }
    return 0;
}
