#include<iostream>
#include<string>
#include<fstream>
using namespace std;

string FILE_NAME = "input.txt";
int SIZE;
int *arr;
int key;

int floorValueBS(int arr[], int size, int key);
void readFile();
void printArray(int arr[], int size);
int main(){

    readFile();
    int value = floorValueBS(arr, SIZE, key);
    cout<<"Floor value of "<<key<<" in given array: "<<value<<'\n';
    return 0;
}

int floorValueBS(int arr[], int size, int key){
    if(key<arr[0])return -1;
    int l = 0, r = size-1, m;

    while (r - l > 1)
    {
        m = l + (r-l)/2;
        if(arr[m]<=key) l = m;
        else r = m;
    }

    if(arr[r] < key)return arr[r];
    return arr[l];
    
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