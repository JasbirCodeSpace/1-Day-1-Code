#include<iostream>
using namespace std;

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
int partition(int *arr, int l, int h){
    int pivot = arr[h];
    int i = l-1;

    for(int j=l; j<h; j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[h]);
    return i+1;
}
void quickSort(int *arr, int l, int h){
    if(l>=h)
        return;
    
    int p = partition(arr, l, h);
    quickSort(arr, l, p-1);
    quickSort(arr, p+1, h);
}

void printArray(int *arr, int n){
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){

    int arr[] = {10, 7, 8, 9, 1, 5}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    quickSort(arr, 0, n - 1); 
    cout << "Sorted array: \n"; 
    printArray(arr, n); 
    return 0; 
}