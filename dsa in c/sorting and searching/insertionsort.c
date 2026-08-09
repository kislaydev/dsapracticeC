#include<stdio.h>
int insertionsort(int a[], int n){
    int temp,i, j;
    for(i = 1; i < n;i++){
        temp = a[i];
        j = i-1;
        while(j>=0 && a[j]>temp){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
    for(i = 0; i<n; i++){
        printf("%d ", a[i]);
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
    insertionsort(a, num);
}