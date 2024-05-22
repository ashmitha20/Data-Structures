#include <stdio.h>
#include <stdlib.h>

int partition(int a[100], int l, int h) {
    int i = l - 1;
    int pivot = a[h];
    for(int j = l; j <= h - 1;j++) {
        if(a[j] < pivot) {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        }
        int temp = a[i+1];
        a[i+1] = a[h];
        a[h] = temp;

        return i+1;
}
void quicksort(int a[100],int l, int h) {
    if(l < h) {
       int  j = partition(a,l,h);
        quicksort(a,l,j-1);
        quicksort(a,j+1,h);
    }
}
void main() {
    int a[100],n,i;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d",&a[i]);
    }

    quicksort(a, 0 ,n-1);
    printf("\nSorted Array in Ascending Order:\n");
    for(i = 0; i < n; i++) {
        printf("%d ",a[i]);
    }
}
