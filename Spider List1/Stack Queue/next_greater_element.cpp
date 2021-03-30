#include<bits/stdc++.h>
using namespace std;

void nextGreaterElement1(int *arr, int size);        // O(n^2)
void nextGreaterElement2(int *arr, int size);       // O(n); order of element is not maintained
void nextGreaterElement3(int *arr, int size);      // O(n): order is maintained
int main(int argc, char const *argv[])
{
    int arr[] = {11, 13, 21, 3};
    int size = sizeof(arr)/sizeof(arr[0]); 
    nextGreaterElement3(arr, size); 
    return 0;
}

void nextGreaterElement1(int *arr, int size){

    int next;
    for (int i = 0; i < size; i++)
    {
        next = -1;
        for (int j = i+1; j < size; j++)
        {
            if(arr[j]>arr[i]){
                next = arr[j];
                break;
            }
        }
        cout<<arr[i]<<" -> "<<next;
        cout<<'\n';
    }
    
}

void nextGreaterElement2(int *arr, int size){

    stack<int> s;
    for (int i = 0; i < size; i++)
    {
        if(s.empty()){
            s.push(arr[i]);
            continue;
        }
        while(!s.empty() && arr[i] > s.top()){
            cout<<s.top()<<" -> "<<arr[i]<<'\n';
            s.pop();
        }
        s.push(arr[i]);
    }

    while (!s.empty())
    {
        cout<<s.top()<<" -> "<<-1<<'\n';
        s.pop();
    }
    
    
}

void nextGreaterElement3(int *arr, int size){

    stack<int> s;
    unordered_map<int, int> m;
    for (int i = 0; i < size; i++)
    {
        m[arr[i]] = -1;

        if(s.empty()){
            s.push(arr[i]);
            continue;
        }

        while (!s.empty() && arr[i] > s.top())
        {
            m[s.top()] = arr[i];
            s.pop();
        }

        s.push(arr[i]);
        
    }

    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" -> "<<m[arr[i]]<<'\n';
    }
    
    
}