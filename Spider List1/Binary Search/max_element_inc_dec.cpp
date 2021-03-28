#include<iostream>
#include<fstream>
#include<string>

using namespace std;

string FILE_NAME = "input.txt";
int SIZE;
int *arr;
int key;

int findMaxElement1(int *arr, int size);        // O(N)
int findMaxElement2(int *arr, int size);        // O(Logn)
void readFile();
void printArray(int arr[], int size);

int main(){
    readFile();
    int result = findMaxElement2(arr, SIZE);
    cout<<"The maximum element is "<<result<<"\n";
    return 0;
}

int findMaxElement1(int *arr, int size){

    int l = 0, h = size-1;
    int max= arr[l];
    for (int i = l+1; i <= h; i++)
    {
        if(arr[i] >= max) max = arr[i];
        else break;
    }

    return max;
}

int findMaxElement2(int *arr, int size){

    int l = 0, m, r=size-1;
    if(l == r)return arr[l];
    while(l<=r){
        m = (l+r)/2;
        if(arr[m] > arr[m-1] && arr[m] > arr[m+1])return arr[m];
        else if(arr[m] > arr[m+1] && arr[m] < arr[m-1]) r = m-1;
        else if(arr[m] > arr[m-1] && arr[m] < arr[m+1]) l = m+1;
    }
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