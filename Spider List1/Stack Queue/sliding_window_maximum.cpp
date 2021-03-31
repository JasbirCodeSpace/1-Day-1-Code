#include<bits/stdc++.h>
using namespace std;

void printMax1(int *arr, int size, int k);      // O(n*k)
void printMax2(int *arr, int size, int k);      // O(n)
void printMax3(int *arr, int size, int k);      // O(n*logk)
void printMax4(int *arr, int size, int k);      // O(n*k)
int main(int argc, char const *argv[])
{
    int arr[] = { 12, 1, 78, 90, 57, 89, 56 };
    int size = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    printMax4(arr, size, k);
    return 0;
}

/*
    Time Complexity: O(n*k)
    Space Complexity: O(1)
*/
void printMax1(int *arr, int size, int k){

    int max;
    for (int i = 0; i <= size - k; i++)
    {
       max = arr[i];
       for (int j = 1; j < k; j++)
       {
           if(max<arr[i+j])max  = arr[i+j];
       }
       cout<<max<<" ";
       
    }
    cout<<'\n';
}

/*
    Time Complexity: O(n)
    Space Complexity: O(k)
*/

void printMax2(int *arr, int size, int k){

    deque<int> dq;
    int i;
    for (i = 0; i < k; i++)
    {
        while (!dq.empty() && arr[i]>= arr[dq.back()])
        {
            dq.pop_back();
        }
        
        dq.push_back(i);
    }
    cout<<arr[dq.front()]<<" ";
    for (; i < size; i++)
    {
        while (!dq.empty() && dq.front()<=i-k)
        {
            dq.pop_front();
        }
        while(!dq.empty() && arr[i]>=arr[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
        cout<<arr[dq.front()]<<" ";
    }

    cout<<'\n';
    
}

/*
    Time Complexity: O(n*logk)
    Space Complexity: O(k)
*/
void printMax3(int *arr, int size, int k){

    vector<int> heap(k);
    int i;
    for (i = 0; i < k; i++)
    {
       heap.push_back(arr[i]);
    }

    make_heap(heap.begin(), heap.end());
    cout<<heap.front()<<" ";

    for (; i <size; i++)
    {
        auto idx = find(heap.begin(), heap.end(), arr[i-k]);
        heap.erase(idx);
        heap.push_back(arr[i]);
        make_heap(heap.begin(), heap.end());
        cout<<heap.front()<<" ";
    }
    
    cout<<'\n';
    
}

/*
    Time Complexity: O(n*k)
    Space Complexity: O(k)
*/

int queueMax(queue<int> q){

    int max = q.front();
    while(!q.empty()){
        q.front()>max?max=q.front():max;
        q.pop();
    }
    return max;
}
void printMax4(int *arr, int size, int k){

    queue<int> q;
    for (int i = 0; i < size; i++)
    {
        if(i<k){
            q.push(arr[i]);
        }else{
            cout<<queueMax(q)<<" ";
            q.pop();
            q.push(arr[i]);
        }
        
    }
    cout<<queueMax(q)<<" ";
    cout<<'\n';
}