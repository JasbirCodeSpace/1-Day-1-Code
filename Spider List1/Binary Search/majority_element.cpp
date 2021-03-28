#include<iostream>
#include<string>
#include<fstream>
using namespace std;

string FILE_NAME = "input.txt";
int SIZE;
int *arr;
int key;

bool majorityElement1(int *arr, int size, int key);     // O(N)
bool majorityElement2(int *arr, int size, int key);     // O(Log n)
bool majorityElement3(int *arr, int size, int key);     // O(1)

int binarySearch(int *arr, int size, int key);
void readFile();
void printArray(int arr[], int size);
int main(){

    readFile();
    bool result = majorityElement3(arr, SIZE, key);
    if(result)cout<<key<<" is a majority element";
    else cout<<key<<" is not a majority element";
    return 0;
}

bool majorityElement1(int *arr, int size, int key){

    int lastIdx = size%2? size/2 + 1: size/2;
    for (int i = 0; i < lastIdx; i++)
    {
        if(arr[i] == key && arr[i+size/2] == key)return true;
    }
    return false;
    
}

bool majorityElement2(int *arr, int size, int key){

    int idx = binarySearch(arr, size, key);
    if(idx == -1) return false;

    int last = idx+size/2;
    if((last < size) && arr[last] == key)
        return true;

    return false;
}

int binarySearch(int *arr, int size, int key){

    int l = 0, m, r = size - 1;
    while(l<=r){
        m = (l+r)/2;
        if((m == 0 || arr[m-1]<key) && arr[m] == key)return m;
        else if(arr[m]<key) l = m+1;
        else r = m-1;
    }
    return -1;
}

bool majorityElement3(int *arr, int size, int key){
    if(arr[size/2] == key)return true;
    return false;
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