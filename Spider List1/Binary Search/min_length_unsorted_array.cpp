#include<bits/stdc++.h>
using namespace std;

void findUnsortedSubarray(int *arr, int size);
int main(){

    int arr[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
    int size = sizeof(arr)/sizeof(arr[0]);
    findUnsortedSubarray(arr, size);
    return 0;
}

void findUnsortedSubarray(int *arr, int size){

    int l=0, r=size-1;
    for (l = 0; l < size-1; l++)
    {
        if(arr[l] > arr[l+1])break;
    }
    if(l == size-1){
        cout<<"Array is sorted";
        return;
    }

    for (r = size-1; r>0; r--)
    {
        if(arr[r]<arr[r-1])break;
    }
    
    int min = arr[l], max = arr[l];
    for (int i = l+1; i <= r; i++)
    {
        if(arr[i]<min)min = arr[i];
        if(arr[i]>max)max = arr[i];
    }

    for (int i = 0; i < l; i++)
    {
        if(arr[i]>min){
            l = i;
            break;
        }
    }

    for (int i = size-1; i>=r+1; i--)
    {
        if(arr[i]<max){
            r = i;
            break;
        }
    }

    cout<<"Required range is ("<<l<<","<<r<<")\n";
    return;
}