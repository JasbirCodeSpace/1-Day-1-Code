#include<iostream>
#include<fstream>
#include<string>

using namespace std;

string FILE_NAME = "input.txt";
int SIZE;
int *arr;
int key;

int findFixedPoint(int *arr, int size);
void readFile();
void printArray(int arr[], int size);

int main(){
    readFile();
    int idx = findFixedPoint(arr, SIZE);
    cout<<"Fixed point is "<<idx<<"\n";
    return 0;
}

int findFixedPoint(int *arr, int size){

    int l = 0, m, r = size-1;
    while(l<=r){
        m = (l + r)/2;
        if(arr[m] == m)return m;
        else if(arr[m] < m) l = m+1;
        else r = m-1;
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