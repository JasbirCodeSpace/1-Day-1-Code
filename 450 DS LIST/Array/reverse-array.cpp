#include<iostream>
using namespace std;

void reverseArray(int* arr, int n){
    int l = 0, r = n-1;
    while(l<r){
        swap(arr[l], arr[r]);
        l++;
        r--;
    }
}

void printArray(int* arr, int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){

    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    reverseArray(arr, n);
    printArray(arr, n);
    return 0;
}