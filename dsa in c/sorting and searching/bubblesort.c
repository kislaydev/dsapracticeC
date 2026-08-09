#include<stdio.h>
int bubblesort(int arr[], int n){
    int temp;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;   
            }
        }
    }
    for(int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }
}
int main(){
    int num;
    printf("Enter number of elements in the array");
    scanf("%d",&num);
    int a[num];
    for(int i = 0; i<num; i++){
        printf("Enter element :");
        scanf("%d",&a[i]);
    }
    bubblesort(a, num);
}