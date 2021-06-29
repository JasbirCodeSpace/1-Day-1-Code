#include<iostream>
using namespace std;


void merge(int *arr, int l, int m, int h){
    int n1 = m-l+1;
    int n2 = h-m;

    int left[n1];
    int right[n2];
    for(int i=0; i<n1; i++)
        left[i] = arr[l+i];
    for(int i=0; i<n2; i++)
        right[i] = arr[m+i+1];
    
    int i=0, j=0, k=l;
    while(i<n1 && j<n2){
        if(left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    while(i<n1)
        arr[k++] = left[i++];
    while(j<n2)
        arr[k++] = right[j++];
}

void mergeSort(int *arr, int l, int h){
    if(l<h){
        int mid = (l+h)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, h);
        merge(arr, l, mid, h);
    }
}

void printArray(int *arr, int n){
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main(){

    int arr[] = { 12, 11, 13, 5, 6, 7 };
    auto arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;

    return 0;
}