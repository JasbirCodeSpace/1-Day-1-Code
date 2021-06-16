#include<iostream>
#include<string>
#include<fstream>
using namespace std;


string FILE_NAME = "input.txt";
int SIZE;
int *arr;
int key;

int binarySearch(int arr[], int size, int key);
int floorValue(int* arr, int size, int key);
int ceilingValue(int* arr, int size, int key);
int countOccurence(int *arr, int size, int key);
int getRightPosition(int* arr, int size, int key);
int getLeftPosition(int* arr, int size, int key);
int minRotatedArray(int* arr, int size);
void readFile();
void printArray(int arr[], int size);

int main(){
    readFile();
    int idx = binarySearch(arr, SIZE, key);
    cout<<key<<" found at index: "<<idx<<endl;
    cout<<minRotatedArray(arr, size)<<endl;
    return 0;
}

int binarySearch(int* arr, int size, int key){
    int l=0, r=size-1, m;
    while(r-l>1){
        m = (l+r)/2;
        if(arr[m] <= key)
            l = m;
        else
            r = m;
    }

    if(arr[l] == key)return l;
    if(arr[r] == key)return r;
    return -1;
}

int floorValue(int* arr, int size, int key){

    int l = 0, r = size-1, m;
    while(r-l>1){
        m = (l+r)/2;
        if(arr[m]<=key)
            l = m;
        else
            r = m;
    }
    return arr[l];
}

int ceilingValue(int* arr, int size, int key){
    int l = 0, r = size-1, m;
    while(r-l>1){
        m = (l+r)/2;
        if(arr[m]<=key)
            l = m;
        else
            r = m;
    }

    return arr[r];
}

int countOccurence(int* arr, int size, int key){
    int l = getLeftPosition(arr, size, key);
    int r = getRightPosition(arr, size, key);

    return (arr[l]==key && arr[r]==key)?(r-l+1):0;
}
int getRightPosition(int* arr, int size, int key){
    int l = 0, r = size-1, m;
    while(r-l>1){
        m = (l+r)/2;
        if(arr[m]<=key)
            l = m;
        else
            r = m;
    }

    return l;
}

int getLeftPosition(int* arr, int size, int key){
    int l = 0, r = size-1, m;
    while(r-l>1){
        m = (l+r)/2;
        if(arr[m]>=key)
            r = m;
        else
            l = m;
    }
    return r;
}

int minRotatedArray(int* arr, int size){
    int l = 0, r = size-1, m;
    if(arr[l]<=arr[r])return l;

    while(l<=r){
        if(l == r)
            return l;
        
        m = (l+r)/2;
        if(arr[m]<r)
            r = m;
        else
            l = m+1;
    }
    return -1;

}
void readFile(){
    ifstream file;
    file.open(FILE_NAME);
    if(file.is_open()){
        file >> SIZE;
        arr = new int[SIZE];
        for (int i = 0; i < SIZE; i++)
        {
            file >> arr[i];
        }
        file >> key;
    }
    file.close();
}

void printArray(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
       cout<<arr[i]<<" ";
    }
    
}