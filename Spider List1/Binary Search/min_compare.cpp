#include<iostream>
#include<fstream>
#include<string>

using namespace std;

string FILE_NAME = "input.txt";
int SIZE;
int *arr;
int key;

int binarySearch1(int arr[], int size, int key, int &count);
int binarySearch2(int arr[], int size, int key, int &count);
void readFile();
void printArray(int arr[], int size);

int main(){
    readFile();
    int count = 0;
    int idx = binarySearch1(arr, SIZE, key, count);
    cout<<"Total comparisons: "<<count<<'\n';
    cout<<"Searched index: "<<idx<<'\n';

    count = 0;
    idx = binarySearch2(arr, SIZE, key, count);
    cout<<"Total comparisons: "<<count<<'\n';
    cout<<"Searched index: "<<idx<<'\n';
    
    return 0;
}

int binarySearch1(int arr[], int size, int key, int &count){

    int l = 0, r = size-1, m;
    while(l<=r){
        m = l + (r-l)/2;

        count++;
        if(arr[m] == key)return m;

        count++;
        if(arr[m] < key)l = m+1;
        else r = m-1;
    }
    return -1;
}
int binarySearch2(int arr[], int size, int key, int &count){

    int l=0,m,r=size-1;
    while(r-l>1){
        m = l + (r - l)/2;
        count++;
        if(arr[m]<=key)
            l = m;
        else
            r = m;
    }
    count++;
    if(arr[l] == key)return l;
    count++;
    if(arr[r] == key)return r;
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