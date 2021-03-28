#include<bits/stdc++.h>
using namespace std;

int binarySearch(int *arr, int l, int r, int key);

int findPivot(int *arr, int size);                        // O(LogN)
int pivotBinarySearch1(int *arr, int size, int key);     // O(LogN)

int pivotBinarySearch2(int *arr, int size, int key);        // O(LogN)
int main(){

    int arr[] = { 5, 6, 7, 8, 9, 10, 1, 2, 3 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 3;
    cout<<key<<" occurs at position "<<pivotBinarySearch2(arr, size, key);
    return 0;
}

int findPivot(int *arr, int size){
    int l = 0, m, r = size-1;
    while (l<=r)
    {
       m = (l+r)/2;
       if(arr[m]>arr[m+1])return m;
       if(arr[m]<arr[m-1])return m-1;
       if(arr[l]>=arr[m])r = m-1;
       else l = m+1; 
    }
    return -1;
}

int pivotBinarySearch1(int *arr, int size, int key){

    int l = 0, r = size-1;
    int pivot = findPivot(arr, size);
    if(pivot == -1)return -1;
    if(arr[pivot] == key)return pivot;
    if(arr[0]<=key)return binarySearch(arr, l, pivot-1, key);
    return binarySearch(arr, pivot+1, r, key);
}

int pivotBinarySearch2(int *arr, int size, int key){

    int l = 0, m, r = size-1;
    while (l<=r)
    {
        m = (l + r)/2;
        if(arr[m] == key)return m;
        if(arr[l] <= arr[m]){
            if(key>=arr[l] && key<=arr[m])r = m-1;
            else l = m+1;
        }
        else{
            if(key>=arr[m] && key<=arr[r])l = m+1;
            else r = m-1;
        }
    }
    return -1;
}
int binarySearch(int *arr, int l, int r, int key){

    while (r-l>1)
    {
        int m = (l+r)/2;
        if(arr[m]<=key)l = m;
        else r = m-1;
    }
    if(arr[l] == key)return l;
    if(arr[r] == key)return r;
    return -1;
}