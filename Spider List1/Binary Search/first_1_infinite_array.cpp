#include<iostream>
using namespace std;

void findBounds(int* arr, int &l, int &r){
    l = 0, r = 1;
    while(arr[r]==0){
        l = r;
        r = r << 1;
    }
}

int posOfFirstOne(int *arr){
    int l,r;
    findBounds(arr, l, r);

    int m;
    while(l<=r){
        m = (l+r)/2;
        if(arr[m]==1 && (m==0 || arr[m-1]==0))
            return m;
        else if(arr[m]==1)
            r = m-1;
        else
            l = m+1;
    }

    return m;
}
int main(){
    int arr[] = { 0, 0, 1, 1, 1, 1 };
    cout << "Index = "
         << posOfFirstOne(arr);
    return 0;
}