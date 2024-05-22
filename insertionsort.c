#include <stdio.h>
#include <stdlib.h>

void insertionsort(int arr[],int n) {
    for(int i = 1; i <= n; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
void main() {
    int arr[50],n,i;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    printf("\nEnter elements of array:\n");
    for(i  = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
    insertionsort(arr,n);

    printf("Sorted array is: \n");
    for(i = 0; i < n; i++) {
        printf("%d ",arr[i]);

}
}
        