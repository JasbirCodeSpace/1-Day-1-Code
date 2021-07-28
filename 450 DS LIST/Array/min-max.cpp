#include<iostream>
using namespace std;

struct Pair{
    int min;
    int max;
};

Pair getMinMax(int* arr, int n){
    Pair p;
    if(n==1){
        p.min = arr[0];
        p.max = arr[0];
        return p;
    }
    if(arr[0]>arr[1]){
        p.min = arr[1];
        p.max = arr[0];
    }else{
        p.max = arr[1];
        p.min = arr[0];
    }

    for(int i=2; i<n; i++){
        if(arr[i]<p.min)
            p.min = arr[i];
        if(arr[i]>p.max)
            p.max = arr[i];
    }

    return p;
}

int main(int argc, char const *argv[])
{
    int arr[] = { 1000, 11, 445, 1, 330, 3000 };
    int n = 6;
    Pair p = getMinMax(arr, n);
    cout<<"Minimum: "<<p.min<<endl;
    cout<<"Maximum: "<<p.max<<endl;
    return 0;
}
