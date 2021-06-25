#include<iostream>
#include<string>
#include<fstream>
using namespace std;

string FILE_NAME = "input.txt";
int SIZE;
int *arr;
int key;

int floorValueBS(int arr[], int size, int key);
int ceilValueBS(int arr[], int size, int key);
void readFile();
void printArray(int arr[], int size);
int main(){

    readFile();
    int value = floorValueBS(arr, SIZE, key);
    cout<<"Floor value of "<<key<<" in given array: "<<value<<'\n';
    return 0;
}

int floorValueBS(int arr[], int size, int key){
    int l=0, h=size-1, m;
    int floor=-1;
    while(l<=h){
        m = (l+h)/2;
        if(arr[m]==key)
            return m;
        else if(arr[m]<key){
            floor = m;
            l = m+1;
        }else
            h = m-1;
    }
    return floor;
}

int ceilValueBS(int* arr, int size, int key){
    int l=0, h=size-1, m;
    int ceil = -1;
    while(l<=h){
        m = (l+h)/2;
        if(arr[m]==key)
            return m;
        else if(arr[m]<key)
            l = m+1;
        else{
            ceil = m;
            h = m-1;
        }
    }
    return ceil;
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