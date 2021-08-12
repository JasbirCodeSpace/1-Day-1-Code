#include<iostream>
using namespace std;

void printArray(int* arr, int i, int n){

    if(i == n)
        return;
    cout<<arr[i]<<" ";
    printArray(arr, i+1, n);
}

void printRevArray(int *arr, int n){
    if(n==0)
        return;
    cout<<arr[n-1]<<" ";
    printRevArray(arr, n-1);
}

int main(int argc, char const *argv[])
{
    int n = 10;
    int arr[n];

    for(int i=0; i<n; i++)
        arr[i] = i+1;

    cout<<"Original Array: ";
    printArray(arr, 0, n);
    cout<<endl;

    cout<<"Reverse array: ";
    printRevArray(arr, n);
    cout<<endl;

    return 0;
}
