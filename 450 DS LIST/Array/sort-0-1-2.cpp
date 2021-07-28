#include<iostream>
using namespace std;

/*
    Time: O(N)
    Space: O(1)
*/
void sortArray(int* arr, int n){
    int count[3] = {0, 0, 0};

    for(int i=0; i<n; i++){
        count[arr[i]]++;
    }

    int c=0, i=0;
    while(i<n){
        if(count[c] == 0)
            c++;
        else{
            arr[i++] = c;
            count[c]--;
        }
    }
}

/*
    Time: O(N)
    Space: O(1)
*/
void sortArray2(int* arr, int n){
    int l = 0, m = 0, h = n-1;
    while(m<=h){
        switch (arr[m])
        {
        case 0:
            swap(arr[l++], arr[m++]);
            break;
        case 1:
            m++;
            break;
        case 2:
            swap(arr[m], arr[h--]);
            break;
        }
    }
}
void printArray(int* arr, int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}
int main(int argc, char const *argv[])
{
     int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
    int n = sizeof(arr) / sizeof(int);
 
    sortArray2(arr, n);
    printArray(arr, n);
    return 0;
}
