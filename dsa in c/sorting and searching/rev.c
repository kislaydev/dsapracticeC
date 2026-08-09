#include<stdio.h>
void linersearch(int arr[], int key, int n){
    for(int i = 0; i<n; i++){
        if(arr[i] == key){
            printf("element %d found at %d", key, i);
            return;
        }
    }
    printf("Element not found");
}
void binsearch(int a[], int key, int n){
    int l = 0, r = n-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(a[mid] == key){
            printf("element found at %d", mid);
            return;
        }
        else if(key>a[mid]){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    printf("element not found");
}
void bubblesort(int a[], int n){
    int temp;
    for(int i = 0; i<n-1; i++){
        for(int j = 0; j<n-i-1; j++){
            if(a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1]=temp;
            }
        } 
    }
}
