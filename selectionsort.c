#include <stdio.h>
#include <stdlib.h>

void selectionsort(int arr[],int n) {
    int i;
    for(i = 0; i < n - 1 ;i++) {
        int min_index = i;
        for(int j = i + 1 ; j < n; j++) {
            if(arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}
 
 void main() {
    int arr[50], n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    printf("Enter the elements of array: ");
    for(int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
    selectionsort(arr,n);
    printf("\nSorted array is : \n");
    for(int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }
 }  
