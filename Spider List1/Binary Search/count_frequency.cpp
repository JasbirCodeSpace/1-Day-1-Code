#include<iostream>
#include<string>
#include<fstream>
using namespace std;

string FILE_NAME = "input.txt";
int SIZE;
int *arr;
int key;

int binarySearch(int *arr, int size, int key);
int countFrequency1(int *arr, int size, int key);   // O(Logn + freq)

int firstOcc(int *arr, int l, int r, int size, int key);
int lastOcc(int *arr, int l, int r, int size, int key);
int countFrequency2(int *arr, int size, int key);   // O(Logn)
void readFile();

int main(){

    readFile();
    int count = countFrequency2(arr, SIZE, key);
    cout<<key<<" occurs "<<count<<" times\n";
    return 0;
}

int binarySearch(int *arr, int size, int key){

    int l = 0, m, r = size-1;
    while(r-l > 1){
        m = l + (r - l)/2;
        if(arr[m]<= key) l = m;
        else r = m-1;
    }
    if(arr[r] == key)return r;
    if(arr[l] == key)return l;
    return -1;

}

// O(Logn + freq)
int countFrequency1(int *arr, int size, int key){

    int idx = binarySearch(arr, size, key);
    if(idx == -1)return 0;

    int count = 1;
    int l = idx-1, r = idx+1;
    while(l>=0 && arr[l]==key){
        l--;
        count++;
    } 
    while(r<size && arr[r]==key){
        r++;
        count++;
    }
    return count;
}

int firstOcc(int *arr, int l, int r, int size, int key){

    if(r >= l){
        int m = (l + r)/2;
        if( (m == 0 || arr[m-1]<key) && arr[m] == key)return m;
        else if(arr[m]<key) return firstOcc(arr, m+1, r, size, key);    // these orders are important
        else return firstOcc(arr, l, m-1, size, key);
    }
    return -1;
}

int lastOcc(int *arr, int l, int r, int size, int key){

    if(r >= l){
        int m = (l + r)/2;
        if((m==size-1 || arr[m+1] > key) && arr[m] == key) return m;
        else if(key < arr[m]) return lastOcc(arr, l, m-1, size, key);   // these orders are important
        else return lastOcc(arr, m+1, r, size, key);
    }
    return -1;
}

int countFrequency2(int *arr, int size, int key){
    int first = firstOcc(arr, 0, size-1, size, key);
    if(first == -1) return 0;

    int last = lastOcc(arr, 0, size-1, size, key);
    return last - first + 1;

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