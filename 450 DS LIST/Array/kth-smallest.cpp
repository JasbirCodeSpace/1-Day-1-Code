#include<iostream>
using namespace std;

void heapify(int* arr, int i, int n){

    int smallest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<n && arr[left]<arr[smallest])
        smallest = left;
    if(right<n && arr[right]<arr[smallest])
        smallest = right;
    if(smallest != i){
        swap(arr[smallest], arr[i]);
        heapify(arr, smallest, n);
    }
}
int kthSmallest(int* arr, int n, int k){

    for(int i=n/2 - 1; i>=0; i--)
        heapify(arr, i, n);
    
    int res;

    for(int i=n-1; i>=n-k; i--){
        swap(arr[i], arr[0]);
        res = arr[i];
        heapify(arr, 0, i);
    }
    return res;
}
int main(int argc, char const *argv[])
{
    
    int arr[] = { 12, 3, 5, 7, 19 };
    int n = sizeof(arr) / sizeof(arr[0]), k = 2;
    cout << "K'th smallest element is " << kthSmallest(arr, n, k)<<endl;
    return 0;
}
