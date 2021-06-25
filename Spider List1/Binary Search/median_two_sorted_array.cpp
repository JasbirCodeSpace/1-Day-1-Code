#include<iostream>
using namespace std;

// Time complexity: O(m+n)
int getMedian(int *a1, int *a2, int m, int n){

    int size = m+n;
    int m1 = -1, m2 = -1;
    int i=0, j=0;
    for(int count=0; count<=(size/2); count++){
        m2 = m1;
        if(i<m && j<n){
            m1 = (a1[i]<a2[j])?a1[i++]:a2[j++];
        }else if(i<m){
            m1 = a1[i++];
        }else{
            m1 = a2[j++];
        }
    }

    if(size&1)
        return m1;
    else
        return (m1+m2)/2;
}
int main(){
    int arr1[] = { -5, 3, 6, 12, 15 };
    int arr2[] = { -12, -10, -6, -3, 4, 10 };
    int m = sizeof(arr1)/sizeof(arr1[0]);
    int n = sizeof(arr2)/sizeof(arr2[0]);

    cout<<"Median: "<<getMedian(arr1, arr2, m, n);
    return 0;
}