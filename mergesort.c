#include <stdio.h>
#include <stdlib.h>

void merge(int a[50], int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;
    int temp[50];
    while (i <= mid && j <= high) {
        if (a[i] < a[j]) {
            temp[k] = a[i];
            k++; i++;
        } else {
            temp[k] = a[j];
            k++; j++;
        }
    }
    while (i <= mid) {
        temp[k] = a[i];
        k++; i++;
    }
    while (j <= high) {
        temp[k] = a[j];
        k++; j++;
    }
    for (i = low; i <= high; i++) {
        a[i] = temp[i];
    }
}

void mergesort(int arr[50], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    int arr[50], n, i;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    printf("Enter the elements of array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    mergesort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
