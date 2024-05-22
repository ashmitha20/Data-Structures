/*#include <stdio.h>

void main() {
    int a[50];
    int i,n;
    printf("Enter the limit of array: ");
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        scanf("%d",&a[i]);
    }
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - 1 - i; j++) {
            if(a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    printf("Enter the element to be searched: ");
    int key;
    scanf("%d", &key);
    int strt = 0, end = n-1;
    int found = 0,mid,pos= 0;
   while(strt <= end) {
    mid = (strt + end)/2;
        if(a[mid] == key) {
            found++;
            pos  = mid+1;
            printf("Element is present at index %d\n", pos);
            break;
            }
        else if(key < a[mid]) {
            end = mid - 1;
        }
        else {
            strt = mid+1;
        }
   }
        if(found == 0) {
            printf("Not found");
           }
        }*/

#include <stdio.h>

void main() {
    int n,a[100] ;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    printf("Enter the elements of the array: ");
    for(int i = 0; i < n; i++) {
        scanf("%d",&a[i]);
    }
    // Sorting the array using Bubble sort algorithm
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i -1;j++) {
            if(a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
        }
        }
    }
    int start = 0,  end = n-1;
    int found = 0, pos;
    int key;
    printf("\n Enter the element you want to search : \n");
    scanf("%d",&key);
    while(start <= end) {
        int mid = (start + end)/2;
        if(a[mid] == key) {
            found = 1;
            pos = mid + 1;
            printf("Found at pos %d",pos);
            break;
        }
        else if(a[mid] < key) {
            start = mid+ 1;
        }
        else {
            end = mid - 1;
        }
    }
    if(!found)
    printf("Element is not present in the array.");
}
    


       
        