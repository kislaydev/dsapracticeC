#include<stdio.h>
int selectionsort(int a[], int n){
    int i,j,min,temp;
    for(i = 0; i<n; i++){
        min = i;
        for(j = i+1; j<n; j++){
            if(a[j]<a[min]){
                min = j;
            }
        }
        if(min != i){
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
    for(i = 0; i<n; i++){
        printf("%d\n", a[i]);
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
    selectionsort(a, num);
}