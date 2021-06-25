#include<iostream>
using namespace std;

int minElem(int *arr, int l, int r){

    int mid=0;
    while(l<r){
        mid = (l+r)/2;
        if(mid>l && arr[mid]<arr[mid-1]){
            return arr[mid];
        }
        else if(mid<r && arr[mid+1]<arr[mid]){
            return arr[mid+1];
        }
        else if(arr[mid]<arr[r])
            r = mid-1;
        else
            l = mid+1;
    }
    return arr[l];
}
int main(){
    int arr1[] = {5, 6, 1, 2, 3, 4};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    cout << "The minimum element is " << minElem(arr1, 0, n1-1) << endl;
  
    int arr2[] = {1, 2, 3, 4};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    cout << "The minimum element is " << minElem(arr2, 0, n2-1) << endl;
  
    int arr3[] = {1};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    cout<<"The minimum element is "<<minElem(arr3, 0, n3-1)<<endl;
  
    int arr4[] = {1, 2};
    int n4 = sizeof(arr4)/sizeof(arr4[0]);
    cout<<"The minimum element is "<<minElem(arr4, 0, n4-1)<<endl;
  
    int arr5[] = {2, 1};
    int n5 = sizeof(arr5)/sizeof(arr5[0]);
    cout<<"The minimum element is "<<minElem(arr5, 0, n5-1)<<endl;
  
    int arr6[] = {5, 6, 7, 1, 2, 3, 4};
    int n6 = sizeof(arr6)/sizeof(arr6[0]);
    cout<<"The minimum element is "<<minElem(arr6, 0, n6-1)<<endl;
  
    int arr7[] = {1, 2, 3, 4, 5, 6, 7};
    int n7 = sizeof(arr7)/sizeof(arr7[0]);
    cout << "The minimum element is " << minElem(arr7, 0, n7-1) << endl;
  
    int arr8[] = {2, 3, 4, 5, 6, 7, 8, 1};
    int n8 = sizeof(arr8)/sizeof(arr8[0]);
    cout << "The minimum element is " << minElem(arr8, 0, n8-1) << endl;
  
    int arr9[] = {3, 4, 5, 1, 2};
    int n9 = sizeof(arr9)/sizeof(arr9[0]);
    cout << "The minimum element is " << minElem(arr9, 0, n9-1) << endl;
  
    return 0;
}