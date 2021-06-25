#include<bits/stdc++.h>
using namespace std;

#define NA -1

void moveToEnd(int* arr, int n){

    int j=n-1;
    for(int i=n-1; i>=0; i--){
        if(arr[i] != NA){
            arr[j] = arr[i];
            j--;
        }
    }
}

void merge(int *a, int *b, int m, int n){

    int i=n;
    int j=0;
    int k=0;

    while(k < m+n){
        if((j==n)||((i<m+n) && a[i]<=b[j])){
            a[k++]=a[i++];
        }else{
            a[k++]=b[j++];
        }
    }
}
void printArray(int *arr, int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){

   int mPlusN[] = {2, 8, NA, NA, NA, 13, NA, 15, 20};
   int N[] = {5, 7, 9, 25};
    
   int n = sizeof(N) / sizeof(N[0]);
   int m = sizeof(mPlusN) / sizeof(mPlusN[0]) - n;
 
   moveToEnd(mPlusN, m + n);
 
    merge(mPlusN, N, m, n);

   printArray(mPlusN, m+n);
}